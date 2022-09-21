#include "IG2App.h"

#include <OgreEntity.h>
#include <OgreInput.h>
#include <SDL_keycode.h>
#include <OgreMeshManager.h>
#include <OgreBitesConfigDialog.h>

using namespace Ogre;

bool IG2App::keyPressed(const OgreBites::KeyboardEvent& evt)
{
  if (evt.keysym.sym == SDLK_ESCAPE)
  {
    getRoot()->queueEndRendering();
  }
  else if (evt.keysym.sym == SDLK_g) {
	  mSM->getSceneNode("nClock")->roll(Degree(1));

  }
  else if (evt.keysym.sym == SDLK_h) {
	  for (int i = 0; i < 12; i++)
	  {

	  }
	  mSM->getSceneNode("Hours")->pitch(Degree(1));
  }
  
  return true;
}

void IG2App::shutdown()
{
  mShaderGenerator->removeSceneManager(mSM);  
  mSM->removeRenderQueueListener(mOverlaySystem);  
					
  mRoot->destroySceneManager(mSM);  

  delete mTrayMgr;  mTrayMgr = nullptr;
  delete mCamMgr; mCamMgr = nullptr;
  
  // do not forget to call the base 
  IG2ApplicationContext::shutdown();
}

void IG2App::setup(void)
{
  // do not forget to call the base first
	mRoot->showConfigDialog(OgreBites::getNativeConfigDialog());
  IG2ApplicationContext::setup();

  mSM = mRoot->createSceneManager();  

  // register our scene with the RTSS
  mShaderGenerator->addSceneManager(mSM);

  mSM->addRenderQueueListener(mOverlaySystem);

  mTrayMgr = new OgreBites::TrayManager("TrayGUISystem", mWindow.render);  
  mTrayMgr->showFrameStats(OgreBites::TL_BOTTOMLEFT);
  addInputListener(mTrayMgr);

  addInputListener(this);   
  setupScene();
}

void IG2App::setupScene(void)
{
  // create the camera
  Camera* cam = mSM->createCamera("Cam");
  cam->setNearClipDistance(1); 
  cam->setFarClipDistance(10000);
  cam->setAutoAspectRatio(true);
  //cam->setPolygonMode(Ogre::PM_WIREFRAME); 
  
  mCamNode = mSM->getRootSceneNode()->createChildSceneNode("nCam");
  mCamNode->attachObject(cam);

  mCamNode->setPosition(0, 0, 1000);
  mCamNode->lookAt(Ogre::Vector3(0, 0, 0), Ogre::Node::TS_WORLD);
  //mCamNode->setDirection(Ogre::Vector3(0, 0, -1));  
  
  // and tell it to render into the main window
  Viewport* vp = getRenderWindow()->addViewport(cam);
  vp->setBackgroundColour(Ogre::ColourValue(0.7, 0.8, .9));

  //------------------------------------------------------------------------

  // without light we would just get a black screen 

  Light* luz = mSM->createLight("Luz");
  luz->setType(Ogre::Light::LT_DIRECTIONAL);
  luz->setDiffuseColour(0.75, 0.75, 0.75);

  mLightNode = mSM->getRootSceneNode()->createChildSceneNode("nLuz");
  //mLightNode = mCamNode->createChildSceneNode("nLuz");
  mLightNode->attachObject(luz);

  mLightNode->setDirection(Ogre::Vector3(-1, -1, -1));  //vec3.normalise();
  //lightNode->setPosition(0, 0, 1000);
 
  //------------------------------------------------------------------------

  // finally something to render
  /*
  Ogre::Entity* ent = mSM->createEntity("facial.mesh");

  mSinbadNode = mSM->getRootSceneNode()->createChildSceneNode("nSinbad");
  mSinbadNode->attachObject(ent);

  //mSinbadNode->setPosition(400, 100, -300);
  mSinbadNode->setScale(20, 20, 20);
  //mSinbadNode->yaw(Ogre::Degree(-45));
  //mSinbadNode->showBoundingBox(true);
  //mSinbadNode->setVisible(false);

  Ogre::Entity* floor = mSM->createEntity("RomanBathLower.mesh");
  Ogre::SceneNode* mFloorNode = mSM->getRootSceneNode()->createChildSceneNode("nSuelo");
  Ogre::Entity* cielin = mSM->createEntity("RomanBathUpper.mesh");
  Ogre::SceneNode* mCielinNode = mSM->getRootSceneNode()->createChildSceneNode("nTecho");

  mFloorNode->attachObject(floor);
  mCielinNode->attachObject(cielin);
  */

  //Ogre::Entity* sph = mSM->createEntity("sphere.mesh");

  Ogre::SceneNode* clock = mSM->getRootSceneNode()->createChildSceneNode("nClock");
  Ogre::SceneNode* hours = clock->createChildSceneNode("Hours");

  for (int i = 0; i < 12; i++) {

	  int angl = 360 / 12 * i;

	  Ogre::SceneNode* horita = hours->createChildSceneNode("Hora " + std::to_string(i));
	  Ogre::Entity* sph = mSM->createEntity("sphere.mesh");
	  horita->attachObject(sph);
		  if (i%2 == 0) horita->setScale(Vector3(0.5, 0.5, 0.5));
		  else horita->setScale(Vector3(0.3, 0.3, 0.3));
	  horita->setPosition(Vector3(Ogre::Math::Cos(Degree(angl)) * 300, Ogre::Math::Sin(Degree(angl)) * 300, 0));
  }


  Ogre::SceneNode* HourH = clock->createChildSceneNode("horasMan");
  Ogre::SceneNode* MinH = clock->createChildSceneNode("minMan");
  Ogre::SceneNode* SecH = clock->createChildSceneNode("secMan");

  Ogre::Entity* rec0 = mSM->createEntity("cube.mesh");
  HourH->attachObject(rec0);
  HourH->setScale(Vector3(0.3, 2, 0.1));
  HourH->roll(Ogre::Radian(Ogre::Math::PI / 2));
  HourH->setPosition(Vector3(75, 0, 0));
  Ogre::Entity* rec1 = mSM->createEntity("cube.mesh");
  MinH->attachObject(rec1);
  MinH->setScale(Vector3(0.2, 3, 0.1));
  //MinH->roll(Ogre::Radian(Ogre::Math::PI / 2));
  MinH->setPosition(Vector3(0, 100, 0));
  Ogre::Entity* rec2 = mSM->createEntity("cube.mesh");
  SecH->attachObject(rec2);
  SecH->setScale(Vector3(0.1, 3.5, 0.1));
  SecH->roll(Ogre::Radian(3 * Ogre::Math::PI / 4));
  SecH->setPosition(Vector3(-50, -50, 0));
  



  //------------------------------------------------------------------------

  mCamMgr = new OgreBites::CameraMan(mCamNode);
  addInputListener(mCamMgr);
  mCamMgr->setStyle(OgreBites::CS_ORBIT);  
  


  //mCamMgr->setTarget(mSinbadNode);  
  //mCamMgr->setYawPitchDist(Radian(0), Degree(30), 100);

  //------------------------------------------------------------------------

}


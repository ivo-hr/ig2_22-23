#ifndef __IG2App_H__
#define __IG2App_H__

#include "IG2ApplicationContext.h"
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreTrays.h>
#include <OgreCameraMan.h>

#include "Plano.h"
#include "Noria.h"
#include "Muñeco.h"
#include "Avion.h"
#include "Dron.h"
#include "Sinbad.h"

using namespace Ogre;

class IG2App : public  OgreBites::IG2ApplicationContext, OgreBites::InputListener 
{
public:
  explicit IG2App() : IG2ApplicationContext("IG2App") { };  // new -> setup()  
  virtual ~IG2App() { };   // delete -> shutdown()  
 
protected:
  virtual void setup();
  virtual void shutdown();
  virtual void setupScene();

  virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);  // InputListener
      
  SceneManager* mSM = nullptr;
  OgreBites::TrayManager* mTrayMgr = nullptr;    
  SceneNode* mLightNode = nullptr;
  SceneNode* mCamNode = nullptr;
  //SceneNode* mSinbadNode = nullptr;

  /// <summary>
  /// Reloj
  /// </summary>
  SceneNode* mClockNode = nullptr;
  SceneNode* mHoursNode = nullptr;
  SceneNode* mSphereNode = nullptr;
  SceneNode* mClockHandNode = nullptr;
  Entity* ent = nullptr;

  /// <summary>
  /// Plano
  /// </summary>
  Plano* plano;
  SceneNode* mPlaneNode = nullptr;

  /// <summary>
  /// Noria
  /// </summary>
  Noria* noria;
  SceneNode* mNoriaNode = nullptr;

  /// <summary>
  /// Muñeco
  /// </summary>
  Muñeco* muñeco;
  SceneNode* mMuñecoNode = nullptr;

  /// <summary>
  /// Avion
  /// </summary>
  Avion* avion;
  SceneNode* mAvionNode = nullptr;

  /// <summary>
  /// Dron
  /// </summary>
  Dron* dron;
  SceneNode* mDronNode = nullptr;
  std::vector <SceneNode*> avispas;
  int vivas = 400;


  /// <summary>
  /// Planeta
  /// </summary>
  SceneNode* mPlanetNode = nullptr;

  /// <summary>
/// Sinbad
/// </summary>
  Sinbad* sinbad;
  SceneNode* mSinbadNode = nullptr;

  /// <summary>
  /// Nodo ficticio
  /// </summary>
  SceneNode* mFictitiusNode = nullptr;

  OgreBites::CameraMan* mCamMgr = nullptr;
 
};

#endif

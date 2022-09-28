#include "AspaNoria.h"




AspaNoria::AspaNoria(Ogre::SceneNode* node) {
	mNode = node;
	mSM = mNode->getCreator();

	Ogre::SceneNode* Aspa1 = mNode->createChildSceneNode();
	Ogre::SceneNode* Aspa2 = mNode->createChildSceneNode();
	Ogre::SceneNode* Cubo = mNode->createChildSceneNode();

	Ogre::Entity* rec0 = mSM->createEntity("cube.mesh");
	Aspa1->attachObject(rec0);
	Aspa1->setScale(Vector3(10, 1, 0.1));
	Aspa1->setPosition(Vector3(0, 0, 100));

	Ogre::Entity* rec1 = mSM->createEntity("cube.mesh");
	Aspa2->attachObject(rec1);
	Aspa2->setScale(Vector3(10, 1, 0.1));
	Aspa2->setPosition(Vector3(0, 0, -100));


	Ogre::Entity* rec2 = mSM->createEntity("cube.mesh");
	Cubo->attachObject(rec2);
	Cubo->setScale(Vector3(2, 2, 2));
	Cubo->setPosition(Vector3(400, 0, 0));
	Cubo->setInheritOrientation(false);
  
}

AspaNoria::~AspaNoria()
{
}
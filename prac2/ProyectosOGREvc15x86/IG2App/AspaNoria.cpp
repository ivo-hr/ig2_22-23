#include "AspaNoria.h"


AspaNoria::AspaNoria(Ogre::SceneNode* node) : EntidadIG(node) {
	mNode = node;
	mSM = mNode->getCreator();

	Ogre::SceneNode* Aspa1 = mNode->createChildSceneNode();
	Ogre::SceneNode* Aspa2 = mNode->createChildSceneNode();
	cubo = mNode->createChildSceneNode();

	Ogre::Entity* rec0 = mSM->createEntity("cube.mesh");
	rec0->setMaterialName("Practica1/aspa");
	Aspa1->attachObject(rec0);
	Aspa1->setScale(Vector3(10, 1, 0.1));
	Aspa1->setPosition(Vector3(0, 0, 100));

	Ogre::Entity* rec1 = mSM->createEntity("cube.mesh");
	rec1->setMaterialName("Practica1/aspa");
	Aspa2->attachObject(rec1);
	Aspa2->setScale(Vector3(10, 1, 0.1));
	Aspa2->setPosition(Vector3(0, 0, -100));


	Ogre::Entity* rec2 = mSM->createEntity("cube.mesh");
	rec2->setMaterialName("Practica1/caja");
	cubo->attachObject(rec2);
	cubo->setScale(Vector3(2, 2, 2));
	cubo->setPosition(Vector3(400, 0, 0));
	//Cubo->setInheritOrientation(false);
  
}

AspaNoria::~AspaNoria()
{
}

SceneNode* AspaNoria::getCube()
{
	return cubo;
}

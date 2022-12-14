#include "AspaNoria.h"

AspaNoria::AspaNoria(SceneNode* node) : EntidadIG(node)
{
	//La constructora pasa el nodo asociado al objeto creado, como parámetro
	mNode = node;

	mSM = mNode->getCreator();

	for (int i = 0; i < 2; i++) 
	{
		mAspaNode = mNode->createChildSceneNode();
		mAspaNode->setPosition(Ogre::Vector3(-50 + 100 * i, 0, 0));
		mAspaNode->setScale(.1, .5, 14.5);

		ent = mSM->createEntity("cube.mesh");
		ent->setMaterialName("Practica1/brown");
		mAspaNode->attachObject(ent);
	}

	mAspaNode = mNode->createChildSceneNode();
	mAspaNode->setInheritOrientation(false);
	mAspaNode->setPosition(Ogre::Vector3(0, 0, -700));
	ent = mSM->createEntity("cube.mesh");
	ent->setMaterialName("Practica1/bucket");
	mAspaNode->attachObject(ent);
}
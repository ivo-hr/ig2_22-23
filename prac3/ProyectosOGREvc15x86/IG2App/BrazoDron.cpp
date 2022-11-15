#include "BrazoDron.h"

BrazoDron::BrazoDron(SceneNode* node) : EntidadIG(node) 
{
	//La constructora pasa el nodo asociado al objeto creado, como parámetro
	mNode = node;

	mSM = mNode->getCreator();

	mBrazoDronNode = mNode->createChildSceneNode();
	ent = mSM->createEntity("Barrel.mesh");
	ent->setMaterialName("Practica1/droneArm");
	mBrazoDronNode->attachObject(ent);
	mBrazoDronNode->translate(0, 140, 0);
	mBrazoDronNode->setScale(8, 20, 8);

	mBrazoDronNode = mNode->createChildSceneNode();
	ent = mSM->createEntity("sphere.mesh");
	ent->setMaterialName("Practica1/orange");
	mBrazoDronNode->attachObject(ent);
	mBrazoDronNode->translate(0, 240, 0);
	mBrazoDronNode->setScale(.5, .5, .5);

	mBrazoDronNode = mNode->createChildSceneNode();
	mBrazoDronNode->translate(50, 250, 0);
	blades.push_back(new AspasNave(mBrazoDronNode, 3));
}

#include "Aspa.h"

Aspa::Aspa(SceneNode* node) : EntidadIG(node) 
{
	//La constructora pasa el nodo asociado al objeto creado, como parámetro
	mNode = node;

	mSM = mNode->getCreator();

	mAspaNode = mNode->createChildSceneNode();
	ent = mSM->createEntity("cube.mesh");
	ent->setMaterialName("Practica1/brown");
	mAspaNode->attachObject(ent);
	mAspaNode->translate(0, 0, 10);
	mAspaNode->scale(.01, .1, .2);
	mAspaNode->roll(Degree(90));

	mAspaNode = mNode->createChildSceneNode();
	ent = mSM->createEntity("Barrel.mesh");
	ent->setMaterialName("Practica1/red");
	mAspaNode->attachObject(ent);
	mAspaNode->setInheritOrientation(false);
	mAspaNode->translate(0, 0, 17.5);
	mAspaNode->scale(.3, 1, .3);
}
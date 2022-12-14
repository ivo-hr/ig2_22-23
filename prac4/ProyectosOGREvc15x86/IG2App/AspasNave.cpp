#include "AspasNave.h"

AspasNave::AspasNave(SceneNode* node, int n) : EntidadIG(node) 
{
	//La constructora pasa el nodo asociado al objeto creado, como parámetro
	mNode = node;

	mSM = mNode->getCreator();

	mAspaNaveNode = mNode->createChildSceneNode();
	ent = mSM->createEntity("Barrel.mesh");
	ent->setMaterialName("Practica1/dirt");
	mAspaNaveNode->attachObject(ent);
	mAspaNaveNode->setScale(3, 1, 3);
	mAspaNaveNode->roll(Degree(90));

	for (int i = 0; i < n; i++) 
	{
		int angle = (360 / n) * i;

		mAspaNode = mAspaNaveNode->createChildSceneNode();
		mAspaNode->yaw(Degree(angle));
		blades.push_back(new Aspa(mAspaNode));
	}
}

void AspasNave::moveCylinders(int angle) 
{
	for (auto e : blades) 
		e->getCylinder()->roll(Degree(-angle));
}

void AspasNave::rotateCylinders(int angle) 
{
	for (auto e : blades)
		e->getCylinder()->yaw(Degree(angle));
}

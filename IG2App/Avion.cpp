#include "Avion.h"

Avion::Avion(SceneNode* node) : EntidadIG(node)
{
	//La constructora pasa el nodo asociado al objeto creado, como parámetro
	mNode = node;

	mSM = mNode->getCreator();

	mAvionNode = mNode->createChildSceneNode();
	ent = mSM->createEntity("sphere.mesh");
	ent->setMaterialName("Practica1/red");
	mAvionNode->attachObject(ent);
	mAvionNode->translate(0, 50, 0);

	for (int i = 0; i < 2; i++)
	{
		mAvionNode = mNode->createChildSceneNode();
		ent = mSM->createEntity("cube.mesh");
		ent->setMaterialName("Practica1/chess");
		mAvionNode->attachObject(ent);
		mAvionNode->translate(0, 50, -150 + 300 * i);
		mAvionNode->setScale(1, .15, 2);

		mAvionNode = mNode->createChildSceneNode();
		mAvionNode->translate(50, 50, -150 + 300 * i);
		blades.push_back(new AspasNave(mAvionNode, 5));
	}

	mAvionNode = mNode->createChildSceneNode();
	ent = mSM->createEntity("Barrel.mesh");
	ent->setMaterialName("Practica1/orange");
	mAvionNode->attachObject(ent);
	mAvionNode->translate(100, 50, 0);
	mAvionNode->setScale(10.5, 3, 10.5);
	mAvionNode->roll(Degree(90));

	mAvionNode = mNode->createChildSceneNode();
	ent = mSM->createEntity("ninja.mesh");
	ent->setMaterialName("Practica1/yellow");
	mAvionNode->attachObject(ent);
	mAvionNode->yaw(Degree(-90));
}

bool Avion::keyPressed(const OgreBites::KeyboardEvent& evt) 
{
	if (evt.keysym.sym == SDLK_h) 
	{
		mNode->getParentSceneNode()->roll(Degree(-1));

		for (auto e : blades) 
		{
			e->getBlade()->yaw(Degree(5));
			e->moveCylinders();
		}

	}
	else if (evt.keysym.sym == SDLK_j) 
	{
		mNode->getParentSceneNode()->yaw(Degree(1));

		for (auto e : blades)
		{
			e->rotateCylinders();
		}
	}

	return true;
}
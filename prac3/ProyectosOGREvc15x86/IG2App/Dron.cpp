#include "Dron.h"

Dron::Dron(SceneNode* node, int n, TYPE type) : EntidadIG(node) 
{
	//La constructora pasa el nodo asociado al objeto creado, como parámetro
	mNode = node;

	mSM = mNode->getCreator();

	//mFictitiusNode = mNode->createChildSceneNode();

	mDronNode = mNode->createChildSceneNode();
	ent = mSM->createEntity("sphere.mesh");
	mDronNode->roll(Degree(90));

	switch (type)
	{
	case MOTHERSHIP: ent->setMaterialName("Practica1/red"); break;
	case WASP: ent->setMaterialName("Practica1/head"); break;
	default: break;
	}

	mDronNode->attachObject(ent);

	for (int i = 0; i < n; i++) 
	{
		int angle = (360 / n) * i + 30;

		mArmNode = mDronNode->createChildSceneNode();
		mArmNode->pitch(Degree(angle));
		if (i == n - 1) mArmNode->scale(1.2, 1.2, 1.2);
		arms.push_back(new BrazoDron(mArmNode));
	}

	addListener(this);
}

void Dron::frameRendered(const FrameEvent& evt) 
{
	for (auto e : arms) 
		e->getArm()->pitch(Degree(-10));

	if (isMoving)
	{
		mNode->getParentSceneNode()->pitch(Degree(-1));

		if (myTimer->getMilliseconds() > 2000)
		{
			dir = Math::RangeRandom(0, 2);

			isMoving = !isMoving;
			myTimer->reset();
		}
	}
	else 
	{
		mNode->getParentSceneNode()->yaw(Degree(2 * dir - 1));

		if (myTimer->getMilliseconds() > Math::RangeRandom(1000, 2000)) 
		{
			isMoving = !isMoving;
			myTimer->reset();
		}
	}
}

#include "Avion.h"

Avion::Avion(SceneNode* node) : EntidadIG(node)
{
	//La constructora pasa el nodo asociado al objeto creado, como parámetro
	mNode = node;

	mSM = mNode->getCreator();

	mFictitiusNode = mNode->createChildSceneNode();

	mAvionNode = mFictitiusNode->createChildSceneNode();
	ent = mSM->createEntity("sphere.mesh");
	ent->setMaterialName("Practica1/red");
	mAvionNode->attachObject(ent);
	mAvionNode->translate(0, 50, 0);

	for (int i = 0; i < 2; i++)
	{
		mAvionNode = mFictitiusNode->createChildSceneNode();
		ent = mSM->createEntity("cube.mesh");
		ent->setMaterialName("Practica1/chess");
		mAvionNode->attachObject(ent);
		mAvionNode->translate(0, 50, -150 + 300 * i);
		mAvionNode->setScale(1, .15, 2);

		mAvionNode = mFictitiusNode->createChildSceneNode();
		mAvionNode->translate(50, 50, -150 + 300 * i);
		blades.push_back(new AspasNave(mAvionNode, 5));
	}

	mAvionNode = mFictitiusNode->createChildSceneNode();
	ent = mSM->createEntity("Barrel.mesh");
	ent->setMaterialName("Practica1/orange");
	mAvionNode->attachObject(ent);
	mAvionNode->translate(100, 50, 0);
	mAvionNode->setScale(10.5, 3, 10.5);
	mAvionNode->roll(Degree(90));

	mAvionNode = mFictitiusNode->createChildSceneNode();
	ent = mSM->createEntity("ninja.mesh");
	ent->setMaterialName("Practica1/yellow");
	mAvionNode->attachObject(ent);
	mAvionNode->yaw(Degree(-90));

	// BillboardSet
	BillboardSet* bbSet = mSM->createBillboardSet("panel", 1);
	bbSet->setDefaultDimensions(100, 50);
	bbSet->setMaterialName("Practica1/panel");
	mAvionNode->attachObject(bbSet);

	// Billboard
	Billboard* bb = bbSet->createBillboard(Vector3(0.0, 100.0, 150.0));

	// Sistema de particulas
	pSysWake = mSM->createParticleSystem("psWake", "Practica1/smoke");
	pSysWake->setEmitting(true);
	mPSNode = mNode->createChildSceneNode();
	mPSNode->attachObject(pSysWake);

	// Explosion del avion
	pSysExplosion = mSM->createParticleSystem("psExplosionPlane", "Practica1/explosion");
	pSysExplosion->setEmitting(false);
	mPSNode->attachObject(pSysExplosion);
}

bool Avion::keyPressed(const OgreBites::KeyboardEvent& evt) 
{
	if (evt.keysym.sym == SDLK_h) 
	{
		//mNode->getParentSceneNode()->roll(Degree(-angle));
		mFictitiusNode->yaw(Degree(-angle));

		for (auto e : blades) 
		{
			e->getBlade()->yaw(Degree(angle));
			e->moveCylinders(angle);
		}
	}
	else if (evt.keysym.sym == SDLK_j) 
	{
		//mNode->getParentSceneNode()->yaw(Degree(angle));
		mNode->getParentSceneNode()->roll(Degree(-angle), Node::TS_PARENT);

		for (auto e : blades) 
		{
			e->getBlade()->yaw(Degree(angle));
			e->rotateCylinders(angle);
		}
	}
	else if (evt.keysym.sym == SDLK_r) 
	{
		if (pSysWake->getEmitting()) 
		{
			mFictitiusNode->setVisible(false);
			pSysWake->setEmitting(false);
			pSysExplosion->setEmitting(true);

			sendEvent(MessageType::msgMuerte, this);
		}
	}

	return true;
}

void Avion::frameRendered(const FrameEvent& evt) 
{
	//mNode->yaw(Degree(-1));
	mNode->getParentSceneNode()->yaw(Degree(1));

	for (auto e : blades)
		e->getBlade()->yaw(Degree(angle));
}
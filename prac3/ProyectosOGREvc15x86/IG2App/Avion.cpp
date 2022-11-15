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
		SceneNode* ala = mAvionNode->createChildSceneNode();
		ent = mSM->createEntity("cube.mesh");
		ent->setMaterialName("Practica1/chess");
		ala->attachObject(ent);
		ala->translate(0, 0, -150 + 300 * i);
		ala->setScale(1, .15, 2);

		SceneNode* aspa = mAvionNode->createChildSceneNode();
		aspa->translate(50, 0, -150 + 300 * i);
		blades.push_back(new AspasNave(aspa, 5));
	}

	SceneNode* nariz = mAvionNode->createChildSceneNode();
	ent = mSM->createEntity("Barrel.mesh");
	ent->setMaterialName("Practica1/orange");
	nariz->attachObject(ent);
	nariz->translate(100, 0, 0);
	nariz->setScale(10.5, 3, 10.5);
	nariz->roll(Degree(90));

	SceneNode* ninja = mAvionNode->createChildSceneNode();
	ent = mSM->createEntity("ninja.mesh");
	ent->setMaterialName("Practica1/yellow");
	ninja->attachObject(ent);
	ninja->yaw(Degree(-90));

	// Sistema de particulas
	pSys = mSM->createParticleSystem("psSmoke", "Practica1/smoke");
	pSys->setEmitting(true);
	mPSNode = mNode->createChildSceneNode();
	mPSNode->attachObject(pSys);

	/*RibbonTrail* ribbonTrail = mSM->createRibbonTrail();
	ribbonTrail->setTrailLength(100);
	ribbonTrail->setMaterialName("Practica1/ribbon");
	mAvionNode->attachObject(ribbonTrail);*/

	addListener(this);
}

bool Avion::keyPressed(const OgreBites::KeyboardEvent& evt) 
{
	/*if (evt.keysym.sym == SDLK_h)
	{
		//mNode->getParentSceneNode()->roll(Degree(-angle));
		mNode->yaw(Degree(-angle));

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
	}*/

	if (evt.keysym.sym == SDLK_r && !boom)
	{
		pSys->setEmitting(false);

		ParticleSystem* pSys2 = mSM->createParticleSystem("psFallen", "Practica1/fallen");
		pSys2->setEmitting(true);
		mPSNode->attachObject(pSys2);
		
		boom = true;
			
		mAvionNode->setVisible(false);

		sendEvent(msgAvionBoom, this);
	}

	return true;
}

void Avion::frameRendered(const FrameEvent& evt) 
{
	if (!boom){
			mNode->getParentSceneNode()->yaw(Degree(1));

			for (auto e : blades)
				e->getBlade()->yaw(Degree(angle));
	}
	
	
	//mNode->yaw(Degree(-1));

}
#include "Noria.h"

#include <SDL_keycode.h>

Noria::Noria(SceneNode* node, int n) : EntidadIG(node)
{
	//La constructora pasa el nodo asociado al objeto creado, como parámetro
	mNode = node;

	mSM = mNode->getCreator();

	for (int i = 0; i < n; i++) 
	{
		int angle = (360 / n) * i;

		mNoriaNode = mNode->createChildSceneNode();
		mNoriaNode->pitch(Degree(angle));
		blades.push_back(new AspaNoria(mNoriaNode));
	}

	mNoriaNode = mNode->createChildSceneNode();
	ent = mSM->createEntity("Barrel.mesh");
	ent->setMaterialName("Practica1/stones");
	mNoriaNode->attachObject(ent);

	//mNoriaNode->setInheritOrientation(false);
	mNoriaNode->setScale(30, 25, 30);
	mNoriaNode->roll(Degree(90));

	addListener(this);
}

bool Noria::keyPressed(const OgreBites::KeyboardEvent& evt) 
{
	if (evt.keysym.sym == SDLK_q && !isMoving) 
	{
		mNode->pitch(Degree(-1));
	}

	return true;
}

void Noria::frameRendered(const Ogre::FrameEvent& evt) 
{
	if(isMoving)
		mNode->pitch(Degree(1));
}

void Noria::moveBlades() 
{
	for (auto e : blades)
		e->getBlade()->yaw(Degree(1));
}

void Noria::receiveEvent(MessageType msgType, EntidadIG* entidad) 
{
	switch (msgType)
	{
	case msgNoria:
		isMoving = !isMoving; 
		break;
	default:
		break;
	}
}

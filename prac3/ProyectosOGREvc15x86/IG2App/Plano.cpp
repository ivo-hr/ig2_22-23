#include "Plano.h"
#include "Noria.h"
#include "Muñeco.h"

using namespace Ogre;

Plano::Plano(SceneNode* node) : EntidadIG(node)
{
	MeshManager::getSingleton().createPlane("mPlane3000x5000",
		ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
		Plane(Vector3::UNIT_Y, 0),
		3000, 5000, 100, 80, true, 1, 1.0, 1.0, Vector3::UNIT_Z);
	ent = mSM->createEntity("mPlane3000x5000");
	ent->setMaterialName("Practica1/water");
	mNode->attachObject(ent);

	addListener(this);
}

bool Plano::keyPressed(const OgreBites::KeyboardEvent& evt) 
{
	/*if (evt.keysym.sym == SDLK_r)
	{
		if (isActive) 
		{
			isMoving = !isMoving;

			if (isMoving) ent->setMaterialName("Practica1/water");
			else ent->setMaterialName("Practica1/stopWater");
		}

		sendEvent(MessageType::msgNoria, this);
		sendEvent(MessageType::msgMuñeco, this);
	}*/
	if (evt.keysym.sym == SDLK_t) 
	{
		sendEvent(MessageType::msgBomba, this);
		sendEvent(MessageType::msgPlano, this);
	}

	return true;
}

void Plano::frameRendered(const FrameEvent& evt) 
{
	if (isWater) 
	{
		if (!isActive && myTimer->getMilliseconds() > 5000)
		{
			isWater = !isWater;
			ent->setMaterialName("Practica1/stones");
		}
	}
}

void Plano::receiveEvent(MessageType msgType, EntidadIG* entidad) 
{
	switch (msgType)
	{
	case msgPlano: 
		if (isActive)
		{
			isActive = !isActive;
			ent->setMaterialName("Practica1/stopWater");
			myTimer->reset();
		}
		break;
	default:
		break;
	}
}

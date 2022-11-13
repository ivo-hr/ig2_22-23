#include "Plano.h"
#include "Noria.h"
#include "Muñeco.h"

using namespace Ogre;

Plano::Plano(SceneNode* node) : EntidadIG(node)
{
	MeshManager::getSingleton().createPlane("mPlane3000x3000",
		ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
		Plane(Vector3::UNIT_Y, 0),
		3000, 3000, 100, 80, true, 1, 1.0, 1.0, Vector3::UNIT_Z);
	ent = mSM->createEntity("mPlane3000x3000");
	ent->setMaterialName("Practica1/water");
	mNode->attachObject(ent);

	addListener(this);
}

bool Plano::keyPressed(const OgreBites::KeyboardEvent& evt) 
{
	if (evt.keysym.sym == SDLK_r)
	{
		isMoving = !isMoving;

		if (isMoving) ent->setMaterialName("Practica1/water");
		else ent->setMaterialName("Practica1/stopWater");

		sendEvent(MessageType::msgNoria, this);
		sendEvent(MessageType::msgMuñeco, this);
	}

	return true;
}
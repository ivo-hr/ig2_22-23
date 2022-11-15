#pragma once

#include <OgreInput.h>
#include <OgreSceneNode.h>
#include <OgreSceneManager.h>
#include <OgreEntity.h>

#include "EntidadIG.h"

using namespace Ogre;

class Bomba : public EntidadIG
{
public:
	Bomba(SceneNode* node);
	~Bomba() {};

protected:
	SceneNode* mNode;
	SceneManager* mSM;

	SceneNode* mBombaNode = nullptr;
	Entity* ent = nullptr;

	SceneNode* mPSNode = nullptr;
	ParticleSystem* pSys;

	AnimationState* animationState = nullptr;
	float duration = 16.0;
	float distance = 2.0;

	bool isMoving = true;

	virtual void frameRendered(const FrameEvent& evt);
	virtual void receiveEvent(MessageType msgType, EntidadIG* entidad);
};

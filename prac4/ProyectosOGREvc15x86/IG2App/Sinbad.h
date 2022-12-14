#pragma once

#include <OgreInput.h>
#include <OgreSceneNode.h>
#include <OgreSceneManager.h>
#include <OgreEntity.h>

#include "AspasNave.h"
#include "EntidadIG.h"

using namespace Ogre;

class Sinbad : public EntidadIG
{
public:
	Sinbad(SceneNode* node);
	~Sinbad() {};

	void arma(bool hand);
	void cambiaArma();
	void arma();

	void changeAnimation();

protected:
	SceneNode* mNode;
	SceneManager* mSM;

	SceneNode* mSinbadNode = nullptr;
	Entity* ent = nullptr;

	AnimationState* runBase = nullptr;
	AnimationState* runTop = nullptr;
	AnimationState* dance = nullptr;
	AnimationState* idleBase = nullptr;
	AnimationState* idleTop = nullptr;
	AnimationStateSet* aux = nullptr;

	Timer* myTimer = new Timer();
	bool isActive = true;

	Entity* sword = nullptr;
	bool leftSword = false;
	bool rightSword = false;

	AnimationState* animationState = nullptr;
	float duration = 20.0;
	float distance = 40.0;

	bool dead = false;

	virtual void frameRendered(const FrameEvent& evt);
	virtual void receiveEvent(MessageType msgType, EntidadIG* entidad);

	void runAnimation();
	void danceAnimation();
	void deathAnimation();
};

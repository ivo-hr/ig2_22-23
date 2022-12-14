#pragma once

#include <OgreInput.h>
#include <OgreSceneNode.h>
#include <OgreSceneManager.h>
#include <OgreEntity.h>
#include <OgreTimer.h>

#include "BrazoDron.h"
#include "EntidadIG.h"

using namespace Ogre;

class Dron : public EntidadIG
{
public:
	enum TYPE { MOTHERSHIP, WASP };

	Dron(SceneNode* node, int n, TYPE type);
	~Dron() {};

	void changeColor() { ent->setMaterialName("Practica1/yellow"); };

protected:
	SceneNode* mNode;
	SceneManager* mSM;

	SceneNode* mDronNode = nullptr;
	SceneNode* mArmNode = nullptr;
	SceneNode* mFictitiusNode = nullptr;
	Entity* ent = nullptr;

	std::vector<BrazoDron*> arms;

	Timer* myTimer = new Timer();
	bool isMoving = true;
	int dir = -1;

	virtual void frameRendered(const FrameEvent& evt);
};

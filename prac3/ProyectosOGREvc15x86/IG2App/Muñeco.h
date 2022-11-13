#pragma once

#include <OgreInput.h>
#include <OgreSceneNode.h>
#include <OgreSceneManager.h>
#include <OgreEntity.h>

#include "EntidadIG.h"

using namespace Ogre;

class Mu�eco : public EntidadIG
{
public:
	Mu�eco(SceneNode* node);
	~Mu�eco() {};

protected:
	SceneNode* mNode;
	SceneManager* mSM;
	bool isMoving = false;
	bool isRed = false;

	SceneNode* mMu�ecoHeadNode = nullptr;
	SceneNode* mMu�ecoBodyNode = nullptr;
	//SceneNode* mMu�ecoNoseNode = nullptr;
	SceneNode* mMu�ecoNavelNode = nullptr;
	Entity* ent = nullptr;
	Entity* head = nullptr;
	Entity* body = nullptr;

	virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);
	//virtual void frameRendered(const FrameEvent& evt);
	virtual void receiveEvent(MessageType msgType, EntidadIG* entidad);
};


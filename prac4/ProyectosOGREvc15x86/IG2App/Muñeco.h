#pragma once

#include <OgreInput.h>
#include <OgreSceneNode.h>
#include <OgreSceneManager.h>
#include <OgreEntity.h>

#include "EntidadIG.h"

using namespace Ogre;

class Muñeco : public EntidadIG
{
public:
	Muñeco(SceneNode* node);
	~Muñeco() {};

protected:
	SceneNode* mNode;
	SceneManager* mSM;
	bool isMoving = false;
	bool isRed = false;

	SceneNode* mMuñecoNode = nullptr;
	SceneNode* mMuñecoHeadNode = nullptr;
	SceneNode* mMuñecoBodyNode = nullptr;
	//SceneNode* mMuñecoNoseNode = nullptr;
	SceneNode* mMuñecoNavelNode = nullptr;
	Entity* ent = nullptr;
	Entity* head = nullptr;
	Entity* body = nullptr;

	AnimationState* animationState = nullptr;
	float duration = 20.0;
	float distance = 600.0;

	virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);
	virtual void frameRendered(const FrameEvent& evt);
	virtual void receiveEvent(MessageType msgType, EntidadIG* entidad);
};


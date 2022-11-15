#pragma once

#include <OgreInput.h>
#include <OgreSceneNode.h>
#include <OgreSceneManager.h>
#include <OgreEntity.h>

#include "AspasNave.h"
#include "EntidadIG.h"

using namespace Ogre;

class Avion : public EntidadIG
{
public:
	Avion(SceneNode* node);
	~Avion() {};

protected:
	SceneNode* nNode;
	SceneNode* mNode;
	SceneManager* mSM;
	SceneManager* pSM;
	SceneNode* mAvionNode = nullptr;
	Entity* ent = nullptr;
	ParticleSystem* pSys;

	int angle = 10;
	std::vector<AspasNave*> blades;

	SceneNode* mPSNode = nullptr;

	bool boom = false;
	
	virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);
	virtual void frameRendered(const FrameEvent& evt);
};

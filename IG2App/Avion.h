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
	SceneNode* mNode;
	SceneManager* mSM;

	SceneNode* mAvionNode = nullptr;
	SceneNode* mFictitiusNode = nullptr;
	Entity* ent = nullptr;

	std::vector<AspasNave*> blades;

	virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);
};

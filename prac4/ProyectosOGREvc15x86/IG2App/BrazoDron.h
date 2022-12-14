#pragma once

#include <OgreInput.h>
#include <OgreSceneNode.h>
#include <OgreSceneManager.h>
#include <OgreEntity.h>

#include "AspasNave.h"
#include "EntidadIG.h"

using namespace Ogre;

class BrazoDron : public EntidadIG
{
public:
	BrazoDron(SceneNode* node);
	~BrazoDron() {};

	SceneNode* getArm() { return mBrazoDronNode; };

protected:
	SceneNode* mNode;
	SceneManager* mSM;

	SceneNode* mBrazoDronNode = nullptr;
	Entity* ent = nullptr;

	std::vector<AspasNave*> blades;
};

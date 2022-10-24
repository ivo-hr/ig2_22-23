#pragma once

#include <OgreInput.h>
#include <OgreSceneNode.h>
#include <OgreSceneManager.h>
#include <OgreEntity.h>

#include "EntidadIG.h"

using namespace Ogre;

class Aspa : public EntidadIG
{
public:
	Aspa(SceneNode* node);
	~Aspa() {};

	SceneNode* getCylinder() { return mAspaNode; };

protected:
	SceneNode* mNode;
	SceneManager* mSM;

	SceneNode* mAspaNode = nullptr;
	Entity* ent = nullptr;
};

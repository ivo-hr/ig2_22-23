#pragma once

#include <OgreInput.h>
#include <OgreSceneNode.h>
#include <OgreSceneManager.h>
#include <OgreEntity.h>
#include <OgreInput.h>
#include <SDL_keycode.h>

#include "EntidadIG.h"

using namespace Ogre;

class AspaNoria : public EntidadIG
{
public:
	AspaNoria(SceneNode* node);
	~AspaNoria() {};

	SceneNode* getBlade() { return mAspaNode; };

protected:
	SceneNode* mNode;
	SceneManager* mSM;

	SceneNode* mAspaNode = nullptr;
	Entity* ent = nullptr;
};


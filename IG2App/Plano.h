#pragma once

#include <OgreInput.h>
#include <OgreSceneNode.h>
#include <OgreSceneManager.h>
#include <OgreEntity.h>
#include <OgreMeshManager.h>
#include <OgreInput.h>
#include <SDL_keycode.h>

#include "EntidadIG.h"

using namespace Ogre;

class Plano : public EntidadIG
{
public:
	Plano(SceneNode* node);
	~Plano() {};

protected:
	Entity* ent = nullptr;
	bool isMoving = true;

	virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);
};


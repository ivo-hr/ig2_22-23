#pragma once
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreEntity.h>
#include <OgreMeshManager.h>
#include <OgreInput.h>
#include <SDL_keycode.h>
#include <OgreFrameListener.h>
#include <OgreAnimation.h>
#include <OgreKeyFrame.h>
#include <iostream>

#include "AspaNoria.h"

using namespace Ogre;

class Noria : public OgreBites::InputListener {

public:
	Noria(SceneNode* node, int n, int q);
	~Noria();

	virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);
	virtual void frameRendered(const Ogre::FrameEvent& evt);



protected:
	SceneNode* mNode;
	SceneManager* mSM;
	int numAspas = 4;
	int speed = 1;

};





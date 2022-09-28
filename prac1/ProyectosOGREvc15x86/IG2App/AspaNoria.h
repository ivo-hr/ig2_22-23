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

using namespace Ogre;

class AspaNoria : public OgreBites::InputListener {

public:
	AspaNoria(SceneNode* node);
    ~AspaNoria();

protected:
	SceneNode* mNode;
	SceneManager* mSM;
	
};





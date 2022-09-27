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

class AspaNoria : public OgreBites::InputListener {

public:
	void Noria(Ogre::SceneNode* node);
    ~Noria();

protected:
	SceneNode* mNode;
	SceneManager* mSM;
};





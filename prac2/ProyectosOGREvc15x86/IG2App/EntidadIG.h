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
#include <vector>

class EntidadIG : public OgreBites::InputListener
{
public:
	EntidadIG(Ogre::SceneNode* node);
	virtual ~EntidadIG() {};


	static std::vector<EntidadIG*> appListeners;

	static void addListener(EntidadIG* entidad);

	enum MessageType {
		msg_Ferris,
		msg_Man
	};


protected:
	Ogre::SceneNode* mNode;
	Ogre::SceneManager* mSM;

	virtual bool keyPressed(const OgreBites::KeyboardEvent& evt) { return false; };
	virtual void frameRendered(const Ogre::FrameEvent& evt) {};
	void sendEvent(MessageType msgType, EntidadIG* ent);
	virtual void receiveEvent(MessageType msgType, EntidadIG* ent) {};
};


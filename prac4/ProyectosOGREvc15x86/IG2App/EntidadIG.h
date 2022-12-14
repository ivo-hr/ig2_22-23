#pragma once

#include <OgreInput.h>
#include <OgreSceneNode.h>
#include <OgreSceneManager.h>
#include <OgreEntity.h>
#include <OgreKeyFrame.h>
#include <OgreAnimation.h>
#include <OgreBillboardSet.h>
#include <OgreParticleSystem.h>
#include <OgreRibbonTrail.h>
#include <OgreTimer.h>

#include "IG2ApplicationContext.h"

using namespace Ogre;

class EntidadIG : public OgreBites::InputListener 
{
public:
	EntidadIG(SceneNode* node);
	~EntidadIG();

	//Vector estático de listeners
	static std::vector<EntidadIG*> appListeners;

	//Añadir entidad como listener al vector
	static void addListener(EntidadIG* entidad) { appListeners.push_back(entidad); };

	// Tipos de mensaje
	enum MessageType { msgNoria, msgMuñeco, msgBomba, msgPlano, msgMuerte, msgExplosion };

protected:
	SceneNode* mNode;
	SceneManager* mSM;

	virtual bool keyPressed(const OgreBites::KeyboardEvent& evt) { return false; };
	virtual void frameRendered(const Ogre::FrameEvent& evt) {};

	void sendEvent(MessageType msgType, EntidadIG* entidad);
	virtual void receiveEvent(MessageType msgType, EntidadIG* entidad) {};
};
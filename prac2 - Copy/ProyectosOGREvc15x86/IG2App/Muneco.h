#pragma once
#include "EntidadIG.h"


using namespace Ogre;

class Muneco : public EntidadIG {

public:
	Muneco(SceneNode* node);
	~Muneco();


protected:
	virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);
	virtual void frameRendered(const Ogre::FrameEvent& evt);
	virtual void receiveEvent(MessageType msgType, EntidadIG* ent);

	SceneNode* cuello;
	SceneNode* cabeza;
	SceneNode* cuerpo;

	Entity* cul;

	Entity* cab;

	SceneManager* mSM;
	bool isRot = false;

};





#pragma once
#include "EntidadIG.h"

#include "AspasNave.h"

using namespace Ogre;

class Nave : public EntidadIG {

public:
	Nave(SceneNode* node, int n, int q);
	~Nave();



protected:
	virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);
	virtual void frameRendered(const Ogre::FrameEvent& evt);
	virtual void receiveEvent(MessageType msgType, EntidadIG* ent);
	void unroll(AspasNave* aspa, int angl);

	SceneNode* mNode;
	

	SceneManager* mSM;
	int numAspas = 4;
	int speed = 1;
	bool isRot = false;
	std::vector<AspasNave*> aspas;
};





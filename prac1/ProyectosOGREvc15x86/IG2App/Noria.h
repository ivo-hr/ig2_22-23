#pragma once
#include "EntidadIG.h"

#include "AspaNoria.h"

using namespace Ogre;

class Noria : public EntidadIG {

public:
	Noria(SceneNode* node, int n, int q);
	~Noria();

	virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);
	virtual void frameRendered(const Ogre::FrameEvent& evt);
	virtual void receiveEvent(MessageType msgType, EntidadIG* ent);
	void unroll(AspaNoria* aspa, int angl);

protected:
	SceneNode* mNode;
	SceneManager* mSM;
	int numAspas = 4;
	int speed = 1;
	bool isRot = true;
	std::vector<AspaNoria*> aspas;
};





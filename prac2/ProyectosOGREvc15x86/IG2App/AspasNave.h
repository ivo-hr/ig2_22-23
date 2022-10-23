#pragma once
#include "EntidadIG.h"

using namespace Ogre;

class AspasNave : public EntidadIG
{

public:
	AspasNave(SceneNode* node, int num, int speed);
	~AspasNave();

	void unroll(SceneNode* obj, int angl);

	std::vector <SceneNode*> cyl;
protected:
	SceneNode* mNode;
	virtual void receiveEvent(MessageType msgType, EntidadIG* ent);
	virtual void frameRendered(const Ogre::FrameEvent& evt);
	SceneManager* mSM;
	int numAspas, vel;
	bool isRot = true;

};





#pragma once

#include <OgreInput.h>
#include <OgreSceneNode.h>
#include <OgreSceneManager.h>
#include <OgreEntity.h>

#include "AspasNave.h"
#include "EntidadIG.h"

using namespace Ogre;

class Avion : public EntidadIG
{
public:
	Avion(SceneNode* node, int speed);
	~Avion() {};

	void AvionWin();

protected:
	SceneNode* mNode;
	SceneManager* mSM;

	Entity* ninja;
	int vel = 5;
	SceneNode* mAvionNode = nullptr;
	SceneNode* mFictitiusNode = nullptr;
	Entity* ent = nullptr;

	std::vector<AspasNave*> blades;

	virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);
};

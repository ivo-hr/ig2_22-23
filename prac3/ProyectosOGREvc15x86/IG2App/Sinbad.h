#pragma once

#include <OgreInput.h>
#include <OgreSceneNode.h>
#include <OgreSceneManager.h>
#include <OgreEntity.h>

#include "EntidadIG.h"

using namespace Ogre;

class Sinbad : public EntidadIG
{
public:
	Sinbad(SceneNode* node, int speed);
	~Sinbad() {};



protected:
	SceneNode* mNode;
	SceneManager* mSM;

	Entity* what;
	int vel = 5;
	SceneNode* mSinbadNode = nullptr;
	SceneNode* mFictitiusNode = nullptr;
	Entity* ent = nullptr;
	std::vector <Entity*> swords;
	float oldYaw = 0;

	AnimationState* topAnim;
	AnimationState* botAnim;

	virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);
	virtual void frameRendered(const FrameEvent& evt);

	void SinbadAnim();
	void arma(bool izqDer);
	int weapon = 0;
	void arma();
	void cambiaEspada();
	void swordEraser();
	

};

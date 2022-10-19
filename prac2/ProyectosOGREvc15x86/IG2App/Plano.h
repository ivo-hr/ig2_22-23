#pragma once
#include "EntidadIG.h"

class Plano : public EntidadIG
{
public:
	Plano(Ogre::SceneNode* node);
	virtual ~Plano() {};

protected:
	virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);

	bool anim = true;

	Ogre::Entity* plane;
};


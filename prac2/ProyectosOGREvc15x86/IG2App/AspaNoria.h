#pragma once
#include "EntidadIG.h"

using namespace Ogre;

class AspaNoria : public EntidadIG
{

public:
	AspaNoria(SceneNode* node);
    ~AspaNoria();

	SceneNode* getCube();

protected:
	SceneNode* mNode;
	SceneNode* cubo;
	SceneManager* mSM;
	
};





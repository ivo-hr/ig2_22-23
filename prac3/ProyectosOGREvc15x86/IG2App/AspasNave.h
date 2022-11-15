#pragma once

#include <OgreInput.h>
#include <OgreSceneNode.h>
#include <OgreSceneManager.h>
#include <OgreEntity.h>

#include "Aspa.h"
#include "EntidadIG.h"

using namespace Ogre;

class AspasNave : public EntidadIG
{
public:
	AspasNave(SceneNode* node, int n);
	~AspasNave() {};

	SceneNode* getBlade() { return mAspaNaveNode; };

	void moveCylinders(int angle);
	void rotateCylinders(int angle);

protected:
	SceneNode* mNode;
	SceneManager* mSM;

	SceneNode* mAspaNaveNode = nullptr;
	SceneNode* mAspaNode = nullptr;
	Entity* ent = nullptr;

	std::vector<Aspa*> blades;
};

#pragma once

#include <OgreInput.h>
#include <OgreSceneNode.h>
#include <OgreSceneManager.h>
#include <OgreEntity.h>

#include "AspaNoria.h"
#include "EntidadIG.h"

using namespace Ogre;

class Noria : public EntidadIG
{
public:
	Noria(SceneNode* node, int n);
	~Noria() {};

	void moveBlades();

protected:
	SceneNode* mNode;
	SceneManager* mSM;
	bool isMoving = true;

	SceneNode* mNoriaNode = nullptr;
	Entity* ent = nullptr;

	std::vector<AspaNoria*> blades;

	virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);
	virtual void frameRendered(const FrameEvent& evt);
	virtual void receiveEvent(MessageType msgType, EntidadIG* entidad);
};


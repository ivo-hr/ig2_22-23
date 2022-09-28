#include "Noria.h"

Noria::Noria(SceneNode* node, int n, int q)
{
	mNode = node;
	mSM = mNode->getCreator();
	speed = q;

	Ogre::SceneNode* barr = mNode->createChildSceneNode();
	barr->attachObject(mSM->createEntity("Barrel.mesh"));
	barr->pitch(Degree(90));
	barr->setScale(40, 40, 50);
	barr->setInheritOrientation(false);

	for (int i = 0; i < n; i++) {

		int angl = 360 / n * i;

		Ogre::SceneNode* noria = mNode->createChildSceneNode();
		
		new AspaNoria(noria);

		noria->roll(Degree(angl));
		noria->translate(500, 0, 0, Ogre::Node::TS_LOCAL);


	}
}

Noria::~Noria()
{
}

bool Noria::keyPressed(const OgreBites::KeyboardEvent& evt)
{
	if (evt.keysym.sym == SDLK_q) {
		mNode->roll(Degree(speed));
	}

	return false;
}

void Noria::frameRendered(const Ogre::FrameEvent& evt)
{
	mNode->roll(Degree(-speed));
}

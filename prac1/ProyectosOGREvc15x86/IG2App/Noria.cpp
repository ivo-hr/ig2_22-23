#include "Noria.h"

Noria::Noria(SceneNode* node, int n, int q) : EntidadIG(node)
{
	mNode = node;
	mSM = mNode->getCreator();
	speed = q;

	Ogre::SceneNode* barr = mNode->createChildSceneNode();
	barr->attachObject(mSM->createEntity("Barrel.mesh"));
	barr->pitch(Degree(90));
	barr->setScale(40, 50, 40);
	//barr->setInheritOrientation(false);

	for (int i = 0; i < n; i++) {

		int angl = 360 / n * i;

		Ogre::SceneNode* aspa = mNode->createChildSceneNode();
		
		AspaNoria* asp = new AspaNoria(aspa);

		aspas.push_back(asp);
		aspa->roll(Degree(angl));
		unroll(asp, angl);
		aspa->translate(500, 0, 0, Ogre::Node::TS_LOCAL);


	}
}

Noria::~Noria()
{
}

bool Noria::keyPressed(const OgreBites::KeyboardEvent& evt)
{
	if (evt.keysym.sym == SDLK_q && !isRot) {
		mNode->roll(Degree(speed));

		for (auto aspa : aspas)
			unroll(aspa, speed);
		
	}

	return false;
}

void Noria::frameRendered(const Ogre::FrameEvent& evt)
{
	if (isRot) {
		mNode->roll(Degree(-speed));
		for (auto aspa : aspas)
			unroll(aspa, -speed);
	}
}

void Noria::receiveEvent(MessageType msgType, EntidadIG* ent)
{
	switch (msgType) {
	case msg_Ferris:
		isRot = !isRot;
		std::cout << "Noria rotation = " + isRot << std::endl;
		break;
	default:
		break;
	}
}

void Noria::unroll(AspaNoria* aspa, int angl)
{
	aspa->getCube()->roll(Degree(-angl));
}

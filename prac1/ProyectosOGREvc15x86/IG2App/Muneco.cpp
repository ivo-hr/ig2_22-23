#include "Muneco.h"

Muneco::Muneco(SceneNode* node) : EntidadIG(node)
{
	cuello = node;
	mSM = cuello->getCreator();
		
	cabeza = cuello->createChildSceneNode();
	cabeza->attachObject(mSM->createEntity("sphere.mesh"));
	cabeza->scale(.5, .5, .5);
	cabeza->translate(0, 20, 0);
	Ogre::SceneNode* nariz = cabeza->createChildSceneNode();
	nariz->attachObject(mSM->createEntity("sphere.mesh"));
	nariz->scale(.1, .1, .1);
	nariz->translate(100, 0, 0);

	cuerpo = cuello->createChildSceneNode();
	cuerpo->attachObject(mSM->createEntity("sphere.mesh"));
	cuerpo->scale(1, 1, 1);
	cuerpo->translate(0, -100, 0);
	Ogre::SceneNode* ombligo = cuerpo->createChildSceneNode();
	ombligo->attachObject(mSM->createEntity("sphere.mesh"));
	ombligo->scale(.1, .1, .1);
	ombligo->translate(100, 0, 0);
}

Muneco::~Muneco()
{

}

bool Muneco::keyPressed(const OgreBites::KeyboardEvent& evt)
{
	return false;
}

void Muneco::frameRendered(const Ogre::FrameEvent& evt)
{
	if (isRot) {
		cabeza->yaw(Degree(-1));
		cuerpo->yaw(Degree(1));
	}
}

void Muneco::receiveEvent(MessageType msgType, EntidadIG* ent)
{
	switch (msgType){
	case msg_Man:
		isRot = !isRot;
		std::cout << "Muneco recieved message!"<< std::endl;
		break;
	default:
		break;
	}
}

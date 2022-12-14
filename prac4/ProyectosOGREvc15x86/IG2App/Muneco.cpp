#include "Muneco.h"

Muneco::Muneco(SceneNode* node) : EntidadIG(node)
{
	cuello = node;
	mSM = cuello->getCreator();
		
	cabeza = cuello->createChildSceneNode();
	cab = mSM->createEntity("sphere.mesh");
	cab->setMaterialName("Practica1/cabeza");
	cabeza->attachObject(cab);
	cabeza->scale(.5, .5, .5);
	cabeza->translate(0, 20, 0);
	/*Ogre::SceneNode* nariz = cabeza->createChildSceneNode();
	Entity* nar = mSM->createEntity("sphere.mesh");
	nar->setMaterialName("Practica1/nariz");
	nariz->attachObject(nar);
	nariz->scale(.1, .1, .1);
	nariz->translate(100, 0, 0);*/

	cuerpo = cuello->createChildSceneNode();
	cul = mSM->createEntity("sphere.mesh");
	cul->setMaterialName("Practica1/culo");
	cuerpo->attachObject(cul);
	cuerpo->scale(1, 1, 1);
	cuerpo->translate(0, -100, 0);
	Ogre::SceneNode* ombligo = cuerpo->createChildSceneNode();
	Entity* omb = mSM->createEntity("sphere.mesh");
	omb->setMaterialName("Practica1/ombligo");
	ombligo->attachObject(omb);
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
		cul->setMaterialName("Practica1/culoRojo");
		cab->setMaterialName("Practica1/cabezaRoja");
	}
	else {
		cul->setMaterialName("Practica1/culo");
		cab->setMaterialName("Practica1/cabeza");
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

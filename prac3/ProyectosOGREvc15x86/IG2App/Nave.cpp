#include "Nave.h"

Nave::Nave(SceneNode* node, int n, int q) : EntidadIG(node)
{
	mNode = node;
	mSM = mNode->getCreator();
	speed = q;

	Ogre::SceneNode* barr = mNode->createChildSceneNode();
	Entity* cyl = mSM->createEntity("Barrel.mesh");
	cyl->setMaterialName("Practica1/nariz");
	barr->attachObject(cyl);
	barr->setScale(10, 10, 10);
	barr->pitch(Degree(90));
	barr->setPosition(0, 0, -90);

	Ogre::SceneNode* cuerpo = mNode->createChildSceneNode();
	Entity* s = mSM->createEntity("sphere.mesh");
	s->setMaterialName("Practica1/ombligo");
	cuerpo->attachObject(s);
	cuerpo->setScale(1, 1, 1);

	Ogre::SceneNode* ninja = mNode->createChildSceneNode();
	Entity* nj = mSM->createEntity("ninja.mesh");
	nj->setMaterialName("Practica1/ninja");
	ninja->attachObject(nj);
	ninja->setScale(1, 1, 1);
	ninja->setPosition(0, -50, 0);

	Ogre::SceneNode* wing0 = mNode->createChildSceneNode();
	Entity* c1 = mSM->createEntity("cube.mesh");
	c1->setMaterialName("Practica1/ala");
	wing0->attachObject(c1);
	wing0->setScale(3, 0.1, 1);
	wing0->setPosition(-200, 0, 0);


	Ogre::SceneNode* wing1 = mNode->createChildSceneNode();
	Entity* c2 = mSM->createEntity("cube.mesh");
	c2->setMaterialName("Practica1/ala");
	wing1->attachObject(c2);
	wing1->setScale(3, 0.1, 1);
	wing1->setPosition(200, 0, 0);

	Ogre::SceneNode* rotor0 = mNode->createChildSceneNode();
	AspasNave* asp0 = new AspasNave(rotor0, n, speed*2);
	rotor0->setPosition(-200, 0, -50);
	rotor0->setScale(0.1, 0.1, 0.1);
	aspas.push_back(asp0);

	Ogre::SceneNode* rotor1 = mNode->createChildSceneNode();
	AspasNave* asp1 = new AspasNave(rotor1, n, speed*2);
	rotor1->setPosition(200, 0, -50);
	rotor1->setScale(0.1, 0.1, 0.1);
	aspas.push_back(asp1);


	addListener(asp0);
	addListener(asp1);
}

Nave::~Nave()
{
}

bool Nave::keyPressed(const OgreBites::KeyboardEvent& evt)
{

	switch (evt.keysym.sym) {
	case SDLK_w:
		mNode->translate(Vector3(0, 0, -1) * speed, Ogre::Node::TS_LOCAL);
		isRot = true;
		break;
	case SDLK_a:
		mNode->yaw((Degree)1 * speed);
		isRot = true;
		break;
	case SDLK_d:
		mNode->yaw((Degree)-1 * speed);
		isRot = true;
		break;
	case SDLK_s:
		mNode->translate(Vector3(0, 0, 1) * speed, Ogre::Node::TS_LOCAL);
		isRot = true;
		break;
	}
	return false;
	
}

void Nave::frameRendered(const Ogre::FrameEvent& evt)
{
		for (auto aspa : aspas)
			aspa->setRot(isRot);

		isRot = false;
}

void Nave::receiveEvent(MessageType msgType, EntidadIG* ent)
{
	switch (msgType) {
	case msg_Ferris:
		isRot = !isRot;
		std::cout << "Plane recieved message!" << std::endl;
		break;
	default:
		break;
	}
}

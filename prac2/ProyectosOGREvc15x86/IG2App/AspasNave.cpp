#include "AspasNave.h"


AspasNave::AspasNave(Ogre::SceneNode* node, int num, int speed) : EntidadIG(node) {
	mNode = node;
	mSM = mNode->getCreator();
	numAspas = num;
	vel = speed;
	Ogre::SceneNode* centre = mNode->createChildSceneNode();
	Ogre::Entity* centro = mSM->createEntity("Barrel.mesh");
	centro->setMaterialName("Practica1/ejeAspa");
	centre->attachObject(centro);
	centre->setScale(Vector3(30, 30, 30));
	centre->pitch(Degree(90));


	for (int i = 0; i < numAspas; i++) {

		int angl = 360 / numAspas * i;

		Ogre::SceneNode* Aspa = mNode->createChildSceneNode();
		Ogre::Entity* rec = mSM->createEntity("cube.mesh");
		rec->setMaterialName("Practica1/aspa");
		Aspa->attachObject(rec);
		Aspa->setScale(Vector3(10, 1, 0.1));

		Ogre::SceneNode* Cilindro = Aspa->createChildSceneNode();
		Ogre::Entity* cil = mSM->createEntity("Barrel.mesh");
		cil->setMaterialName("Practica1/ombligo");
		Cilindro->attachObject(cil);
		Cilindro->setScale(Vector3(1, 20, 100));
		Cilindro->setPosition(Vector3(40, 0, -400));

		cyl.push_back(Cilindro);

		Aspa->roll(Degree(angl));
		unroll(Cilindro, angl);

		Aspa->translate(500, 0, 0, Ogre::Node::TS_LOCAL);
	}

}

AspasNave::~AspasNave()
{
}

void AspasNave::unroll(SceneNode* obj, int angl)
{
	obj->roll(Degree(-angl));
}

void AspasNave::frameRendered(const Ogre::FrameEvent& evt)
{
	if (isRot) {
		mNode->roll(Degree(-vel));
		for (SceneNode* cl : cyl)
			unroll(cl, -vel);
	}
}

void AspasNave::receiveEvent(MessageType msgType, EntidadIG* ent)
{
	switch (msgType) {
	case msg_Ferris:
		isRot = !isRot;
		std::cout << "Rotor recieved message!" << std::endl;
		break;
	default:
		break;
	}
}

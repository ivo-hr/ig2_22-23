#include "Mu�eco.h"

Mu�eco::Mu�eco(SceneNode* node) : EntidadIG(node)
{
	//La constructora pasa el nodo asociado al objeto creado, como par�metro
	mNode = node;

	mSM = mNode->getCreator();

	mMu�ecoHeadNode = mNode->createChildSceneNode();
	head = mSM->createEntity("sphere.mesh");
	head->setMaterialName("Practica1/head");
	mMu�ecoHeadNode->attachObject(head);
	mMu�ecoHeadNode->translate(0, 150, 0);
	mMu�ecoHeadNode->setScale(.6, .6, .6);

	mMu�ecoBodyNode = mNode->createChildSceneNode();
	body = mSM->createEntity("sphere.mesh");
	body->setMaterialName("Practica1/body");
	mMu�ecoBodyNode->attachObject(body);

	/*mMu�ecoNoseNode = mMu�ecoHeadNode->createChildSceneNode();
	ent = mSM->createEntity("sphere.mesh");
	ent->setMaterialName("Practica1/orange");
	mMu�ecoNoseNode->attachObject(ent);
	mMu�ecoNoseNode->translate(100, 0, 0);
	mMu�ecoNoseNode->setScale(.1, .1, .1);*/

	mMu�ecoNavelNode = mMu�ecoBodyNode->createChildSceneNode();
	ent = mSM->createEntity("sphere.mesh");
	ent->setMaterialName("Practica1/red");
	mMu�ecoNavelNode->attachObject(ent);
	mMu�ecoNavelNode->translate(100, 0, 0);
	mMu�ecoNavelNode->setScale(.15, .15, .15);

	addListener(this);
}

bool Mu�eco::keyPressed(const OgreBites::KeyboardEvent& evt) 
{
	if (evt.keysym.sym == SDLK_UP) mNode->translate(0, 0, 10);
	else if (evt.keysym.sym == SDLK_DOWN) mNode->translate(0, 0, -10);
	else if (evt.keysym.sym == SDLK_LEFT) mNode->yaw(Degree(1));
	else if (evt.keysym.sym == SDLK_RIGHT) mNode->yaw(Degree(-1));

	return true;
}

//void Mu�eco::frameRendered(const FrameEvent& evt) 
//{
//	if (isMoving) 
//	{
//		mMu�ecoHeadNode->yaw(Degree(1));
//		mMu�ecoBodyNode->yaw(Degree(-1));
//	}
//}

void Mu�eco::receiveEvent(MessageType msgType, EntidadIG* entidad) 
{
	switch (msgType)
	{
	case msgMu�eco:
		//isMoving = !isMoving;
		isRed = !isRed;

		if(isRed)
		{
			head->setMaterialName("Practica1/redHead");
			body->setMaterialName("Practica1/redBody");
		}
		else 
		{
			head->setMaterialName("Practica1/head");
			body->setMaterialName("Practica1/body");
		}
	default:
		break;
	}
}
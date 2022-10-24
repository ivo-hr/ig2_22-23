#include "Muñeco.h"

Muñeco::Muñeco(SceneNode* node) : EntidadIG(node)
{
	//La constructora pasa el nodo asociado al objeto creado, como parámetro
	mNode = node;

	mSM = mNode->getCreator();

	mMuñecoHeadNode = mNode->createChildSceneNode();
	head = mSM->createEntity("sphere.mesh");
	head->setMaterialName("Practica1/head");
	mMuñecoHeadNode->attachObject(head);
	mMuñecoHeadNode->translate(0, 150, 0);
	mMuñecoHeadNode->setScale(.6, .6, .6);

	mMuñecoBodyNode = mNode->createChildSceneNode();
	body = mSM->createEntity("sphere.mesh");
	body->setMaterialName("Practica1/body");
	mMuñecoBodyNode->attachObject(body);

	/*mMuñecoNoseNode = mMuñecoHeadNode->createChildSceneNode();
	ent = mSM->createEntity("sphere.mesh");
	ent->setMaterialName("Practica1/orange");
	mMuñecoNoseNode->attachObject(ent);
	mMuñecoNoseNode->translate(100, 0, 0);
	mMuñecoNoseNode->setScale(.1, .1, .1);*/

	mMuñecoNavelNode = mMuñecoBodyNode->createChildSceneNode();
	ent = mSM->createEntity("sphere.mesh");
	ent->setMaterialName("Practica1/red");
	mMuñecoNavelNode->attachObject(ent);
	mMuñecoNavelNode->translate(100, 0, 0);
	mMuñecoNavelNode->setScale(.15, .15, .15);

	addListener(this);
}

bool Muñeco::keyPressed(const OgreBites::KeyboardEvent& evt) 
{
	if (evt.keysym.sym == SDLK_UP) mNode->translate(0, 0, 10);
	else if (evt.keysym.sym == SDLK_DOWN) mNode->translate(0, 0, -10);
	else if (evt.keysym.sym == SDLK_LEFT) mNode->yaw(Degree(1));
	else if (evt.keysym.sym == SDLK_RIGHT) mNode->yaw(Degree(-1));

	return true;
}

//void Muñeco::frameRendered(const FrameEvent& evt) 
//{
//	if (isMoving) 
//	{
//		mMuñecoHeadNode->yaw(Degree(1));
//		mMuñecoBodyNode->yaw(Degree(-1));
//	}
//}

void Muñeco::receiveEvent(MessageType msgType, EntidadIG* entidad) 
{
	switch (msgType)
	{
	case msgMuñeco:
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
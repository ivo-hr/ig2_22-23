#include "Sinbad.h"

Sinbad::Sinbad(SceneNode* node, int speed) : EntidadIG(node)
{
	//La constructora pasa el nodo asociado al objeto creado, como parámetro
	mNode = node;
	vel = speed;
	mSM = mNode->getCreator();

	mSinbadNode = mNode->createChildSceneNode();
	ent = mSM->createEntity("Sinbad.mesh");
	//ent->setMaterialName("Sinbad");
	mSinbadNode->attachObject(ent);

	topAnim = ent->getAnimationState("RunBase");
	botAnim = ent->getAnimationState("RunTop");

	topAnim->setEnabled(true); topAnim->setLoop(true);
	botAnim->setEnabled(true); botAnim->setLoop(true);
	
	for (int i = 0; i < 2; i++)
	swords.push_back(mSM->createEntity("Sword.mesh"));
}

void Sinbad::SinbadAnim()
{
	oldYaw += Math:: Math::RangeRandom(-1, 1);
	mNode->getParentSceneNode()->yaw((Degree)oldYaw);
	mNode->getParentSceneNode()->pitch(Degree(1));
}

void Sinbad::arma(bool izqDer)
{
	if (izqDer)
	{
		ent->attachObjectToBone("Handle.L", swords.at(0));
		weapon = 1;
	}
	else
	{
		ent->attachObjectToBone("Handle.R", swords.at(1));
		weapon = 2;
	}
}

void Sinbad::arma()
{
	if (weapon != 3) {
		ent->attachObjectToBone("Handle.L", swords.at(0));
		ent->attachObjectToBone("Handle.R", swords.at(1));
		weapon = 3;
	}
	else weapon = 0;

}

void Sinbad::cambiaEspada()
{
	if (weapon == 1) arma(false);
	else if (weapon == 2) arma(true);
	else arma();
}


void Sinbad::swordEraser() {
	for (int i = 0; i < swords.size(); i++)
		ent->detachObjectFromBone(swords.at(i));
}



bool Sinbad::keyPressed(const OgreBites::KeyboardEvent& evt)
{
	if (evt.keysym.sym == SDLK_h)
	{
		mNode->getParentSceneNode()->pitch(Degree(vel));

		AnimationStateSet* aux = ent->getAllAnimationStates();
		auto it = aux->getAnimationStateIterator().begin();
		while (it != aux->getAnimationStateIterator().end())
		{
			auto s = it->first; ++it;
		}

	}
	else if (evt.keysym.sym == SDLK_j)
	{
		mNode->getParentSceneNode()->yaw(Degree(vel));
	}
	
	else if (evt.keysym.sym == SDLK_1) {
		swordEraser();
		arma(true);
	}
		
	else if (evt.keysym.sym == SDLK_2) {
		swordEraser();
		arma(false);
	}

	else if (evt.keysym.sym == SDLK_3) {
		swordEraser();
		arma();
	}

	else if (evt.keysym.sym == SDLK_4) {
		swordEraser();
		cambiaEspada();
	}

	
		

	return true;
}

void Sinbad::frameRendered(const FrameEvent& evt)
{
	SinbadAnim();

	topAnim->addTime(evt.timeSinceLastFrame);
	botAnim->addTime(evt.timeSinceLastFrame);
}

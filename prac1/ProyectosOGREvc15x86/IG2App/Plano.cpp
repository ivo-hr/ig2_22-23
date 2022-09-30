#include "Plano.h"
#include "Noria.h"
#include "Muneco.h"

using namespace Ogre;
Plano::Plano(SceneNode* node) : EntidadIG(node) {

	Entity* plane = mSM->createEntity("mPlane5000x");
	mNode->attachObject(plane);

	SceneNode* mNoriaN = mNode->createChildSceneNode();
	Noria* mNoria = new Noria(mNoriaN, 10, 5);
	mNoriaN->scale(0.5, 0.5, 0.5);


	SceneNode* mMunecoN = mNode->createChildSceneNode();
	Muneco* mMuneco = new Muneco(mMunecoN);
	mMunecoN->translate(200, 100, 200);
	mMunecoN->scale(0.5, 0.5, 0.5);

	addListener(this);
	addListener(mNoria);
	addListener(mMuneco);
}

bool Plano::keyPressed(const OgreBites::KeyboardEvent& evt) {
	if (evt.keysym.sym == SDLK_p)
		mNode->yaw(Degree(-1));
	
	else if (evt.keysym.sym == SDLK_r) {
		sendEvent(EntidadIG::msg_Ferris, this);
		sendEvent(EntidadIG::msg_Man, this);
	}


	return true;
}
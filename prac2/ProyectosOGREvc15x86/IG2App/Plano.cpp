#include "Plano.h"
#include "Noria.h"
#include "Muneco.h"

using namespace Ogre;
Plano::Plano(SceneNode* node) : EntidadIG(node) {

	Entity* plane = mSM->createEntity("mPlane5000x");
	mNode->attachObject(plane);
}

bool Plano::keyPressed(const OgreBites::KeyboardEvent& evt) {
	if (evt.keysym.sym == SDLK_p)
		mNode->yaw(Degree(-1));
	
	else if (evt.keysym.sym == SDLK_r) {
		sendEvent(EntidadIG::msg_Ferris, this);
		sendEvent(EntidadIG::msg_Man, this);
		std::cout << "Messages sent!" << std::endl;
	}


	return true;
}
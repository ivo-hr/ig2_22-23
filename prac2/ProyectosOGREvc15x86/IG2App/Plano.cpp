#include "Plano.h"
#include "Noria.h"
#include "Muneco.h"

using namespace Ogre;
Plano::Plano(SceneNode* node) : EntidadIG(node) {

	plane = mSM->createEntity("mPlane5000x");
	plane->setMaterialName("Practica1/agua");
	mNode->attachObject(plane);
}

bool Plano::keyPressed(const OgreBites::KeyboardEvent& evt) {
	if (evt.keysym.sym == SDLK_p)
		mNode->yaw(Degree(-1));
	
	else if (evt.keysym.sym == SDLK_r) {
		sendEvent(EntidadIG::msg_Ferris, this);
		sendEvent(EntidadIG::msg_Man, this);
		std::cout << "Messages sent!" << std::endl;

		if (anim)
			plane->setMaterialName("Practica1/aguaParada");
		else
			plane->setMaterialName("Practica1/agua");

		anim = !anim;
	}


	return true;
}
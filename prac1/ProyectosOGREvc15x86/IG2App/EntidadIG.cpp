#include "EntidadIG.h"


std::vector<EntidadIG*> EntidadIG::appListeners = std::vector<EntidadIG*>();

EntidadIG::EntidadIG(Ogre::SceneNode* node) {
	mNode = node;
	mSM = mNode->getCreator();
}

void EntidadIG::addListener(EntidadIG* entidad) {
	appListeners.push_back(entidad);
}

void EntidadIG::sendEvent(MessageType msgType, EntidadIG* ent) {
	for (auto e : appListeners)
		e->receiveEvent(msgType, this);
}


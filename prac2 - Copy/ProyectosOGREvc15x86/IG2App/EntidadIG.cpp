#include "EntidadIG.h"

// Inicializacion del vector de listeners
std::vector<EntidadIG*> EntidadIG::appListeners = std::vector<EntidadIG*>(0, nullptr);

EntidadIG::EntidadIG(SceneNode* node) 
{
	//La constructora pasa el nodo asociado al objeto creado, como parámetro
	mNode = node;

	mSM = mNode->getCreator();
}

EntidadIG::~EntidadIG() 
{
	for (auto ent : appListeners) {
		delete ent;
		ent = nullptr;
	}
}

void EntidadIG::sendEvent(MessageType msgType, EntidadIG* entidad) 
{
	for (EntidadIG* e : appListeners) 
	{
		e->receiveEvent(msgType, this);
	}
}
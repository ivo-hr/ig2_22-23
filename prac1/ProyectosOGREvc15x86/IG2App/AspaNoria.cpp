#include "AspaNoria.h"

using namespace Ogre;


void AspaNoria::Noria(Ogre::SceneNode* node) {
	mNode = node;
	mSM = mNode->getCreator();
}

~Noria()
{
}

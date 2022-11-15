#include "Sinbad.h"

Sinbad::Sinbad(SceneNode* node) : EntidadIG(node)
{
	//La constructora pasa el nodo asociado al objeto creado, como parámetro
	mNode = node;

	mSM = mNode->getCreator();

	mSinbadNode = mNode->createChildSceneNode();
	ent = mSM->createEntity("Sinbad.mesh");
	mSinbadNode->attachObject(ent);

	// Animacion tren inferior
	runBase = ent->getAnimationState("RunBase");
	runBase->setLoop(true);

	// Animacion tren superior
	runTop = ent->getAnimationState("RunTop");
	runTop->setLoop(true);

	// Animacion baile
	dance = ent->getAnimationState("Dance");
	dance->setLoop(true);

	idleBase = ent->getAnimationState("IdleBase");
	idleBase->setLoop(true);
	idleTop = ent->getAnimationState("IdleTop");
	idleBase->setLoop(true);
	// Animacion inicial
	runAnimation();

	// Muestra en consola los estados de animacion
	aux = ent->getAllAnimationStates();
	auto it = aux->getAnimationStateIterator().begin();
	while (it != aux->getAnimationStateIterator().end()) 
	{
		LogManager::getSingleton().logMessage(it->first);
		++it;
	}

	/*auto it2 = aux->getEnabledAnimationStateIterator().begin();
	while (it2 != aux->getEnabledAnimationStateIterator().end()) 
	{
		auto s = ent->getAnimationState(it2);
		s->setEnabled(true);
		s->setLoop(true);
		++it;
	}*/

	// Animacion desplazamiento
	Animation* animation = mSM->createAnimation("animS", duration);
	NodeAnimationTrack* track = animation->createNodeTrack(0);
	track->setAssociatedNode(mSinbadNode);
	Vector3 keyframePos(0.0, 0.0, 0.0); // Posicion del keyframe
	Real durPaso = duration / 5.0; // 6 keyframes

	TransformKeyFrame* kf;

	// Keyframe 0: origen
	kf = track->createNodeKeyFrame(durPaso * 0);
	kf->setTranslate(keyframePos);

	// Keyframe 1: rotacion
	kf = track->createNodeKeyFrame(durPaso * 1);
	Quaternion q1 = Quaternion(Degree(135), Vector3(0.0, 1.0, 0.0));
	kf->setRotation(q1);

	// Keyframe 2: movimiento
	kf = track->createNodeKeyFrame(durPaso * 2);
	keyframePos += Vector3::UNIT_X * distance;
	keyframePos += Vector3::NEGATIVE_UNIT_Z * distance;
	kf->setTranslate(keyframePos);
	kf->setRotation(q1);

	// Keyframe 3: rotacion
	kf = track->createNodeKeyFrame(durPaso * 3);
	Quaternion q2 = Quaternion(Degree(180), Vector3(0.0, -1.0, 0.0));
	Quaternion q3 = q2 * q1;
	kf->setTranslate(keyframePos);
	kf->setRotation(q3);

	// Keyframe 4: movimiento
	kf = track->createNodeKeyFrame(durPaso * 4);
	keyframePos += Vector3::NEGATIVE_UNIT_X * distance;
	keyframePos += Vector3::UNIT_Z * distance;
	kf->setTranslate(keyframePos);
	kf->setRotation(q3);

	// Keyframe 5: rotacion
	kf = track->createNodeKeyFrame(durPaso * 5);
	Quaternion q4 = Quaternion(Degree(45), Vector3(0.0, 1.0, 0.0));
	Quaternion q5 = q4 * q3;
	kf->setTranslate(keyframePos); // Quitar para movimiento diagonal
	kf->setRotation(q5);
	
	/// <summary>
	/// Movimiento en cuadrado
	/// </summary>
	/// <param name="node"></param>
	//// Keyframe 1: rotacion
	//kf = track->createNodeKeyFrame(durPaso * 1);
	//Quaternion q1 = Quaternion(Degree(90), Vector3(0.0, 1.0, 0.0));
	//kf->setRotation(q1);

	//// Keyframe 2: movimiento
	//kf = track->createNodeKeyFrame(durPaso * 2);
	//keyframePos += Vector3::UNIT_X * distance;
	////keyframePos += Vector3::NEGATIVE_UNIT_Z * distance;
	//kf->setTranslate(keyframePos);
	//kf->setRotation(q1);

	//// Keyframe 3: rotacion
	//kf = track->createNodeKeyFrame(durPaso * 3);
	//Quaternion q2 = q1 * q1;
	//kf->setTranslate(keyframePos);
	//kf->setRotation(q2);

	//// Keyframe 4: movimiento
	//kf = track->createNodeKeyFrame(durPaso * 4);
	//keyframePos += Vector3::NEGATIVE_UNIT_Z * distance;
	//kf->setTranslate(keyframePos);
	//kf->setRotation(q2);

	//// Keyframe 5: rotacion
	//kf = track->createNodeKeyFrame(durPaso * 5);
	//Quaternion q3 = q2 * q1;
	//kf->setTranslate(keyframePos); // Quitar para movimiento diagonal
	//kf->setRotation(q3);

	//// Keyframe 6: movimiento
	//kf = track->createNodeKeyFrame(durPaso * 6);
	//keyframePos += Vector3::NEGATIVE_UNIT_X * distance;
	//kf->setTranslate(keyframePos);
	//kf->setRotation(q3);

	//// Keyframe 7: rotacion
	//kf = track->createNodeKeyFrame(durPaso * 7);
	//Quaternion q4 = q3 * q1;
	//kf->setTranslate(keyframePos);
	//kf->setRotation(q4);

	//// Keyframe 8: movimiento
	//kf = track->createNodeKeyFrame(durPaso * 8);
	//keyframePos += Vector3::UNIT_Z * distance;
	//kf->setTranslate(keyframePos);

	animationState = mSM->createAnimationState("animS");
	animationState->setEnabled(true);
	animationState->setLoop(true);

	addListener(this);
}

void Sinbad::frameRendered(const FrameEvent& evt) 
{
	runBase->addTime(evt.timeSinceLastFrame);
	runTop->addTime(evt.timeSinceLastFrame);
	dance->addTime(evt.timeSinceLastFrame);
	idleBase->addTime(evt.timeSinceLastFrame);
	idleTop->addTime(evt.timeSinceLastFrame);

	animationState->addTime(evt.timeSinceLastFrame);

	if (dead) {
		if (timeDead < 0) {
			sendEvent(msgBombaBoom, this);
			dead = false;
		}
		else timeDead -= evt.timeSinceLastFrame;
	}

	/*auto it3 = aux->getEnabledAnimationStates().begin();
	while (it3 != aux->getEnabledAnimationStates().end()) 
	{
		auto s = ent->getAnimationState();
		s->addTime(evt.timeSinceLastFrame);
		++it;
	}*/

	/*mNode->getParentSceneNode()->roll(Degree(-1));
	if (myTimer->getMilliseconds() > Math::RangeRandom(100, 200)) 
	{
		mNode->getParentSceneNode()->yaw(5 * Degree(2 * Math::RangeRandom(0, 2) - 1));
		myTimer->reset();
	}*/
}


void Sinbad::receiveEvent(MessageType msgType, EntidadIG* entidad) {
	switch (msgType)
	{
	case msgAvionBoom:
		die();
		break;
	default:
		break;
	}
}

// Añade una espada a la mano izquierda o derecha
void Sinbad::arma(bool hand) 
{
	if (hand && !leftSword) 
	{
		sword = mSM->createEntity("Sword.mesh");
		ent->attachObjectToBone("Handle.L", sword);
		leftSword = !leftSword;
	}
	else if (!hand && !rightSword) 
	{
		sword = mSM->createEntity("Sword.mesh");
		ent->attachObjectToBone("Handle.R", sword);
		rightSword = !rightSword;
	}
}

// Cambia de mano la espada
void Sinbad::cambiaArma() 
{
	if (!(leftSword && rightSword)) 
	{
		if (leftSword) 
		{
			ent->detachObjectFromBone(sword);
			leftSword = !leftSword;

			sword = mSM->createEntity("Sword.mesh");
			ent->attachObjectToBone("Handle.R", sword);
			rightSword = !rightSword;
		}
		else if (rightSword) 
		{
			ent->detachObjectFromBone(sword);
			rightSword = !rightSword;

			sword = mSM->createEntity("Sword.mesh");
			ent->attachObjectToBone("Handle.L", sword);
			leftSword = !leftSword;
		}
	}
}

// Añade una espada a las dos manos
void Sinbad::arma() 
{
	if (!leftSword) 
	{
		sword = mSM->createEntity("Sword.mesh");
		ent->attachObjectToBone("Handle.L", sword);
		leftSword = !leftSword;
	}
	if (!rightSword) 
	{
		sword = mSM->createEntity("Sword.mesh");
		ent->attachObjectToBone("Handle.R", sword);
		rightSword = !rightSword;
	}
}

// Cambia la animacion
void Sinbad::changeAnimation() 
{
	if (runBase->getEnabled() && runTop->getEnabled()) danceAnimation();
	else if (dance->getEnabled()) runAnimation();
}

// Animacion de correr
void Sinbad::runAnimation() 
{
	dance->setEnabled(false);

	runBase->setEnabled(true);
	runTop->setEnabled(true);
}

// Animacion de bailar
void Sinbad::danceAnimation() 
{
	runBase->setEnabled(false);
	runTop->setEnabled(false);

	dance->setEnabled(true);
}

void Sinbad::die() {
	danceAnimation();
	dance->setEnabled(false);
	animationState->setEnabled(false);
	mSinbadNode->pitch((Degree)-90);
	mSinbadNode->setPosition(mSinbadNode->getPosition() - Vector3(0, 5, 0));
	idleBase->setEnabled(true);
	idleTop->setEnabled(true);

	dead = true;
}
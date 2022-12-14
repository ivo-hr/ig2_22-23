#include "Muñeco.h"

Muñeco::Muñeco(SceneNode* node) : EntidadIG(node)
{
	//La constructora pasa el nodo asociado al objeto creado, como parámetro
	mNode = node;

	mSM = mNode->getCreator();

	mMuñecoNode = mNode->createChildSceneNode();

	mMuñecoHeadNode = mMuñecoNode->createChildSceneNode();
	head = mSM->createEntity("sphere.mesh");
	//head->setMaterialName("Practica1/head");
	head->setMaterialName("Practica1/amber");
	mMuñecoHeadNode->attachObject(head);
	mMuñecoHeadNode->translate(0, 150, 0);
	mMuñecoHeadNode->setScale(.6, .6, .6);

	mMuñecoBodyNode = mMuñecoNode->createChildSceneNode();
	body = mSM->createEntity("sphere.mesh");
	//body->setMaterialName("Practica1/body");
	body->setMaterialName("Practica1/amber");
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

	// Animacion desplazamiento
	Animation* animation = mSM->createAnimation("animM", duration);
	NodeAnimationTrack* track = animation->createNodeTrack(0);
	track->setAssociatedNode(mMuñecoNode);
	Vector3 keyframePos(0.0, 0.0, 0.0); // Posicion del keyframe
	Real durPaso = duration / 5.0; // 6 keyframes

	TransformKeyFrame* kf;

	// Keyframe 0: origen
	kf = track->createNodeKeyFrame(durPaso * 0);
	kf->setTranslate(keyframePos);

	// Keyframe 1: rotacion
	kf = track->createNodeKeyFrame(durPaso * 1);
	Quaternion q1 = Quaternion(Degree(90), Vector3(0.0, -1.0, 0.0));
	kf->setRotation(q1);

	// Keyframe 2: movimiento
	kf = track->createNodeKeyFrame(durPaso * 2);
	keyframePos += Vector3::UNIT_Z * distance;
	kf->setTranslate(keyframePos);
	kf->setRotation(q1);

	// Keyframe 3: rotacion
	kf = track->createNodeKeyFrame(durPaso * 3);
	Quaternion q2 = Quaternion(Degree(180), Vector3(0.0, 1.0, 0.0));
	Quaternion q3 = q2 * q1;
	kf->setTranslate(keyframePos);
	kf->setRotation(q3);

	// Keyframe 4: movimiento
	kf = track->createNodeKeyFrame(durPaso * 4);
	keyframePos += Vector3::NEGATIVE_UNIT_Z * distance;
	kf->setTranslate(keyframePos);
	kf->setRotation(q3);

	// Keyframe 5: rotacion
	kf = track->createNodeKeyFrame(durPaso * 5);
	Quaternion q4 = q3 * q1;
	kf->setRotation(q4);

	animationState = mSM->createAnimationState("animM");
	animationState->setEnabled(true);
	animationState->setLoop(true);
}

bool Muñeco::keyPressed(const OgreBites::KeyboardEvent& evt) 
{
	if (evt.keysym.sym == SDLK_UP) mMuñecoNode->translate(10, 0, 0, Node::TS_LOCAL);
	else if (evt.keysym.sym == SDLK_DOWN) mMuñecoNode->translate(-10, 0, 0, Node::TS_LOCAL);
	else if (evt.keysym.sym == SDLK_LEFT) mMuñecoNode->yaw(Degree(1));
	else if (evt.keysym.sym == SDLK_RIGHT) mMuñecoNode->yaw(Degree(-1));

	return true;
}

void Muñeco::frameRendered(const FrameEvent& evt) 
{
	/*if (isMoving) 
	{
		mMuñecoHeadNode->yaw(Degree(1));
		mMuñecoBodyNode->yaw(Degree(-1));
	}*/

	animationState->addTime(evt.timeSinceLastFrame);
}

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
		break;
	default:
		break;
	}
}
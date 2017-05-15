#pragma once
#include "cocos2d.h"
#include "TSubject.h"
#include "TMonster_H.h"
#include "TPlayer.h"
#include "Ptr.h"
#include "TObject.h"
#include "ObjectPtr.h"
#include "TBomb.h"
#include "TEnemy.h"
#include <vector>

class HelloWorld : public cocos2d::Layer
{
	SubjectPtr player;
	SubjectPtr enemyOne;
	SubjectPtr enemyTwo;
	SubjectPtr enemyThree;
	bool pressedKeyD = false;
	bool pressedKeyA = false;
	bool pressedKeyW = false;
	bool pressedKeyS = false;
	bool pressedKeyE = false;
	bool pressedKeyQ = false;
	std::vector <TObject> Block;
	ObjectPtr bomb;

public:
	friend void OnKeyReleased(cocos2d::EventKeyboard::KeyCode code, cocos2d::Event * event);
	friend void OnKeyPressed(cocos2d::EventKeyboard::KeyCode code, cocos2d::Event * event);

	~HelloWorld() = default;

	static cocos2d::Scene* createScene();

	virtual bool init();

	virtual void update(float);

	static HelloWorld * create();

	bool AbleToMoveR(const SubjectPtr&);

	bool AbleToMoveL(const SubjectPtr&);

	bool AbleToMoveF(const SubjectPtr&);

	bool AbleToMoveB(const SubjectPtr&);
};


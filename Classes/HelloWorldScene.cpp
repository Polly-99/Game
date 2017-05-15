#include "HelloWorldScene.h"

USING_NS_CC;

HelloWorld * GLOBAL_SCENE = nullptr;

HelloWorld * HelloWorld::create()
{
	HelloWorld *pRet = new(std::nothrow) HelloWorld();
	if (pRet && pRet->init())
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
}

cocos2d::Scene* HelloWorld::createScene()
{
	cocos2d::Scene * scene = cocos2d::Scene::create();
	HelloWorld * layer = HelloWorld::create();
	scene->addChild(layer);
	return scene;
}

void OnKeyReleased(cocos2d::EventKeyboard::KeyCode code, cocos2d::Event * event)
{
	if (GLOBAL_SCENE == nullptr)
		return;

	if (code == cocos2d::EventKeyboard::KeyCode::KEY_D)
		GLOBAL_SCENE->pressedKeyD = false;
	if (code == cocos2d::EventKeyboard::KeyCode::KEY_A)
		GLOBAL_SCENE->pressedKeyA = false;
	if (code == cocos2d::EventKeyboard::KeyCode::KEY_W)
		GLOBAL_SCENE->pressedKeyW = false;
	if (code == cocos2d::EventKeyboard::KeyCode::KEY_S)
		GLOBAL_SCENE->pressedKeyS = false;
	if (code == cocos2d::EventKeyboard::KeyCode::KEY_E)
		GLOBAL_SCENE->pressedKeyE = false;
	if (code == cocos2d::EventKeyboard::KeyCode::KEY_Q)
		GLOBAL_SCENE->pressedKeyQ = false;
}

void OnKeyPressed(cocos2d::EventKeyboard::KeyCode code, cocos2d::Event * event)
{
	if (GLOBAL_SCENE == nullptr)
		return;

	if (code == cocos2d::EventKeyboard::KeyCode::KEY_D)
		GLOBAL_SCENE->pressedKeyD = true;
	if (code == cocos2d::EventKeyboard::KeyCode::KEY_A)
		GLOBAL_SCENE->pressedKeyA = true;
	if (code == cocos2d::EventKeyboard::KeyCode::KEY_W)
		GLOBAL_SCENE->pressedKeyW = true;
	if (code == cocos2d::EventKeyboard::KeyCode::KEY_S)
		GLOBAL_SCENE->pressedKeyS = true;
	if (code == cocos2d::EventKeyboard::KeyCode::KEY_E)
		GLOBAL_SCENE->pressedKeyE = true;
	if (code == cocos2d::EventKeyboard::KeyCode::KEY_Q)
		GLOBAL_SCENE->pressedKeyQ = true;
}

bool HelloWorld::AbleToMoveR(const SubjectPtr & sub)
{
	for (int i = 0; i < Block.size(); i++)
	{
		if (abs((GLOBAL_SCENE->player.Get())->GetX() - GLOBAL_SCENE->Block[i].GetX()) < 46 &&
			(GLOBAL_SCENE->player.Get())->GetX() - GLOBAL_SCENE->Block[i].GetX() < 0 &&
			abs((GLOBAL_SCENE->player.Get())->GetY() - GLOBAL_SCENE->Block[i].GetY()) < 46)
			return false;
	}
	return true;
}

bool HelloWorld::AbleToMoveL(const SubjectPtr& sub)
{
	for (int i = 0; i < Block.size(); i++)
	{
		if (abs((GLOBAL_SCENE->player.Get())->GetX() - GLOBAL_SCENE->Block[i].GetX()) < 46 &&
			(GLOBAL_SCENE->player.Get())->GetX() - GLOBAL_SCENE->Block[i].GetX() > 0 &&
			abs((GLOBAL_SCENE->player.Get())->GetY() - GLOBAL_SCENE->Block[i].GetY()) < 46)
			return false;
	}
	return true;
}

bool HelloWorld::AbleToMoveF(const SubjectPtr& sub)
{
	for (int i = 0; i < Block.size(); i++)
	{
		if (abs((GLOBAL_SCENE->player.Get())->GetX() - GLOBAL_SCENE->Block[i].GetX()) < 44 &&
			(GLOBAL_SCENE->player.Get())->GetY() - GLOBAL_SCENE->Block[i].GetY() < 0 &&
			abs((GLOBAL_SCENE->player.Get())->GetY() - GLOBAL_SCENE->Block[i].GetY()) < 50)
			return false;
	}
	return true;
}

bool HelloWorld::AbleToMoveB(const SubjectPtr& sub)
{
	for (int i = 0; i < Block.size(); i++)
	{
		if (abs((GLOBAL_SCENE->player.Get())->GetX() - GLOBAL_SCENE->Block[i].GetX()) < 44 &&
			(GLOBAL_SCENE->player.Get())->GetY() - GLOBAL_SCENE->Block[i].GetY() > 0 &&
			abs((GLOBAL_SCENE->player.Get())->GetY() - GLOBAL_SCENE->Block[i].GetY()) < 50)
			return false;
	}
	return true;
}

bool HelloWorld::init()
{
	if (!cocos2d::Layer::init()){
		return false;
	}

	auto sprite = Sprite::create("Fon.png");
	sprite->setPosition(this->getBoundingBox().getMidX(), this->getBoundingBox().getMidY());
	this->addChild(sprite, 0);

	int n = 0;
	for (int i = 1; i < 8; i++)
	{
		for (int j = 1; j < 5; j++)
		{
			Block.push_back(TObject(120 * i, 120 * j, "block.png"));
			this->addChild(Block[n].GetSpritePtr(), 0);
			n++;
		}
	}

	player = new TPlayer(310, 310, 2.5, 0.f, "Hero-green.png");
	this->addChild(player->GetSpritePtr(), 0);

	enemyOne = new Monster_H(185, 185, 3.f, "monster1.png");
	this->addChild(enemyOne->GetSpritePtr(), 0);

	enemyTwo = new Monster_H(450, 430, 2.f, "monster-green.png");
	this->addChild(enemyTwo->GetSpritePtr(), 0);

	enemyThree = new Monster_V(650, 200, 4.f, "enemy.png");
	this->addChild(enemyThree->GetSpritePtr(), 0);

	cocos2d::EventListenerKeyboard * listener = cocos2d::EventListenerKeyboard::create();

	GLOBAL_SCENE = this;
	listener->onKeyReleased = OnKeyReleased;
	listener->onKeyPressed = OnKeyPressed;

	this->scheduleUpdate();
	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	return true;
}

void HelloWorld::update(float delta)
{
	//move enemyOne
	if (enemyOne)
	{
		if (static_cast<Monster_H*>(GLOBAL_SCENE->enemyOne.Get())->GetInd())
		{
			static_cast<Monster_H*>(GLOBAL_SCENE->enemyOne.Get())->MoveRight();
			if ((GLOBAL_SCENE->enemyOne.Get())->GetX() > this->getBoundingBox().getMaxX())
				static_cast<Monster_H*>(GLOBAL_SCENE->enemyOne.Get())->ChangeInd();
		}
		else
		{
			static_cast<Monster_H*>(GLOBAL_SCENE->enemyOne.Get())->MoveLeft();
			if ((GLOBAL_SCENE->enemyOne.Get())->GetX() < this->getBoundingBox().getMinX())
				static_cast<Monster_H*>(GLOBAL_SCENE->enemyOne.Get())->ChangeInd();
		}
	}

	//move enemyTwo
	if (enemyTwo)
	{
		if (static_cast<Monster_H*>(GLOBAL_SCENE->enemyTwo.Get())->GetInd())
		{
			static_cast<Monster_H*>(GLOBAL_SCENE->enemyTwo.Get())->MoveRight();
			if ((GLOBAL_SCENE->enemyTwo.Get())->GetX() > this->getBoundingBox().getMaxX())
				static_cast<Monster_H*>(GLOBAL_SCENE->enemyTwo.Get())->ChangeInd();
		}
		else
		{
			static_cast<Monster_H*>(GLOBAL_SCENE->enemyTwo.Get())->MoveLeft();
			if ((GLOBAL_SCENE->enemyTwo.Get())->GetX() < this->getBoundingBox().getMinX())
				static_cast<Monster_H*>(GLOBAL_SCENE->enemyTwo.Get())->ChangeInd();
		}
	}

	//move enemyThree
	if (enemyThree)
	{
		if (static_cast<Monster_V*>(GLOBAL_SCENE->enemyThree.Get())->GetInd())
		{
			static_cast<Monster_V*>(GLOBAL_SCENE->enemyThree.Get())->MoveFront();
			if ((GLOBAL_SCENE->enemyThree.Get())->GetY() > this->getBoundingBox().getMaxY())
				static_cast<Monster_V*>(GLOBAL_SCENE->enemyThree.Get())->ChangeInd();
		}
		else
		{
			static_cast<Monster_V*>(GLOBAL_SCENE->enemyThree.Get())->MoveBack();
			if ((GLOBAL_SCENE->enemyThree.Get())->GetY() < this->getBoundingBox().getMinY())
				static_cast<Monster_V*>(GLOBAL_SCENE->enemyThree.Get())->ChangeInd();
		}
	}

	if (player)
	{
		//move player
		if (pressedKeyD)
		{
			if ((GLOBAL_SCENE->player.Get())->GetX() < this->getBoundingBox().getMaxX() && AbleToMoveR(player))
				static_cast<TPlayer*>(GLOBAL_SCENE->player.Get())->MoveRight();
		}

		if (pressedKeyA)
		{
			if ((GLOBAL_SCENE->player.Get())->GetX() > this->getBoundingBox().getMinX() && AbleToMoveL(player))
				static_cast<TPlayer*>(GLOBAL_SCENE->player.Get())->MoveLeft();
		}

		if (pressedKeyW)
		{
			if ((GLOBAL_SCENE->player.Get())->GetY() < this->getBoundingBox().getMaxY() && AbleToMoveF(player))
				static_cast<TPlayer*>(GLOBAL_SCENE->player.Get())->MoveFront();
		}

		if (pressedKeyS)
		{
			if ((GLOBAL_SCENE->player.Get())->GetY() > this->getBoundingBox().getMinY() && AbleToMoveB(player))
				static_cast<TPlayer*>(GLOBAL_SCENE->player.Get())->MoveBack();
		}

		// bomb
		if (pressedKeyE)
		{
			if (!bomb)
			{
				bomb = new TBomb((GLOBAL_SCENE->player.Get())->GetX(), (GLOBAL_SCENE->player.Get())->GetY(), "bomb-green.png");
				this->addChild(bomb->GetSpritePtr(), 0);
			}

		}

		if (pressedKeyQ)
		{
			if (bomb)
			{
				if (enemyOne && (abs((GLOBAL_SCENE->enemyOne.Get())->GetX() - (GLOBAL_SCENE->bomb.Get())->GetX()) < 25 &&
					abs((GLOBAL_SCENE->enemyOne.Get())->GetY() - (GLOBAL_SCENE->bomb.Get())->GetY()) < 25))
				{
					this->removeChild(enemyOne->GetSpritePtr(), true);
					enemyOne = nullptr;
				}

				if (enemyTwo && (abs((GLOBAL_SCENE->enemyTwo.Get())->GetX() - (GLOBAL_SCENE->bomb.Get())->GetX()) < 25 &&
					abs((GLOBAL_SCENE->enemyTwo.Get())->GetY() - (GLOBAL_SCENE->bomb.Get())->GetY()) < 25))
				{
					this->removeChild(enemyTwo->GetSpritePtr(), true);
					enemyTwo = nullptr;
				}

				if (enemyThree && (abs((GLOBAL_SCENE->enemyThree.Get())->GetX() - (GLOBAL_SCENE->bomb.Get())->GetX()) < 25 &&
					abs((GLOBAL_SCENE->enemyThree.Get())->GetY() - (GLOBAL_SCENE->bomb.Get())->GetY()) < 25))
				{
					this->removeChild(enemyThree->GetSpritePtr(), true);
					enemyThree = nullptr;
				}
				auto sprite = cocos2d::Sprite::create("Vzryv-green.png");
				sprite->setPosition((GLOBAL_SCENE->bomb.Get())->GetX(), (GLOBAL_SCENE->bomb.Get())->GetY());
				this->addChild(sprite);
				auto action = cocos2d::FadeTo::create(2, 0);
				sprite->runAction(action);
				this->removeChild(bomb->GetSpritePtr(), true);
				bomb = nullptr;
				if (!enemyOne && !enemyTwo && !enemyThree)
				{
					auto label = Label::createWithSystemFont("YOU WIN!", "Arial", 96);
					label->setPosition(this->getBoundingBox().getMidX(), this->getBoundingBox().getMidY());
					this->addChild(label, 1);
				}
			}
		}

		//if player died
		if ((enemyOne && abs((GLOBAL_SCENE->enemyOne.Get())->GetX() - (GLOBAL_SCENE->player.Get())->GetX()) < 25 &&
			abs((GLOBAL_SCENE->enemyOne.Get())->GetY() - (GLOBAL_SCENE->player.Get())->GetY()) < 25) ||
			(enemyTwo && abs((GLOBAL_SCENE->enemyTwo.Get())->GetX() - (GLOBAL_SCENE->player.Get())->GetX()) < 25 &&
			abs((GLOBAL_SCENE->enemyTwo.Get())->GetY() - (GLOBAL_SCENE->player.Get())->GetY()) < 25) ||
			(enemyThree && (abs((GLOBAL_SCENE->enemyThree.Get())->GetX() - (GLOBAL_SCENE->player.Get())->GetX()) < 25 &&
			abs((GLOBAL_SCENE->enemyThree.Get())->GetY() - (GLOBAL_SCENE->player.Get())->GetY()) < 25)))
		{
			auto label = Label::createWithSystemFont("YOU LOSE!", "Arial", 96);
			label->setPosition(this->getBoundingBox().getMidX(), this->getBoundingBox().getMidY());
			this->addChild(label, 1);
			this->removeChild(player->GetSpritePtr(), true);
			player = nullptr;
		}
	}

	if (player)
		player->Update();
	if (enemyOne)
		enemyOne->Update();
	if (enemyTwo)
		enemyTwo->Update();
	if (enemyThree)
		enemyThree->Update();
}
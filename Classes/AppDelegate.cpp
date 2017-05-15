#include "AppDelegate.h"
#include "HelloWorldScene.h"

USING_NS_CC;

static cocos2d::Size designResolutionSize = cocos2d::Size(320 * 2, 480 * 2);
static cocos2d::Size smallResolutionSize = cocos2d::Size(480, 320);
static cocos2d::Size mediumResolutionSize = cocos2d::Size(1024, 768);
static cocos2d::Size largeResolutionSize = cocos2d::Size(2048, 1536);

AppDelegate::AppDelegate()
{}

AppDelegate::~AppDelegate()
{}

void AppDelegate::initGLContextAttrs()
{
	GLContextAttrs glContextAttrs = { 8, 8, 8, 8, 24, 8 };

	GLView::setGLContextAttrs(glContextAttrs);
}

static int register_all_packages()
{
	return 0;
}

bool AppDelegate::applicationDidFinishLaunching() {
	auto director = Director::getInstance();
	auto glview = director->getOpenGLView();
	if (!glview) {
		glview = GLViewImpl::create("DYNA");
		glview->setFrameSize(960, 640);
		director->setOpenGLView(glview);
	}

	auto scene = HelloWorld::createScene();
	director->runWithScene(scene);

	return true;
}

void AppDelegate::applicationDidEnterBackground() {
}

void AppDelegate::applicationWillEnterForeground() {
}
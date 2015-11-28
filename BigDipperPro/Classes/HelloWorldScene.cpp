#include "HelloWorldScene.h"
#include "NVDelaunayAlgorithm.h"
#include "NVVectorAlgorithm.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
	_geoLayer = cocos2d::Layer::create();
	addChild(_geoLayer);

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


	cocos2d::Point p(153.1f, 0);
	float d = CC_DEGREES_TO_RADIANS(90.0f);
	p.rotate(cocos2d::Point(0, 0), d);
	CCLOG("x=%f, y=%f", p.x, p.y);

    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

bool HelloWorld::onTouchBegan(Touch *touch, Event *unused_event)
{
	_oldP = touch->getLocation();
	return true;
}

void HelloWorld::onTouchMoved(Touch *touch, Event *unused_event)
{

}

#define  TOUCH_GAP			5.0f
void HelloWorld::onTouchEnded(Touch *touch, Event *unused_event)
{
	cocos2d::Point gap = touch->getLocation() - _oldP;
	float dx = abs(gap.x);
	float dy = abs(gap.y);
	if (dx <= TOUCH_GAP && dy <= TOUCH_GAP)
	{
		//
		CCLOG("click catch");
		if (!checkHit(touch->getLocation()))
		{
			addPoint(touch->getLocation());
			operationGeometryView();
		}
	}
}

void HelloWorld::onEnter()
{
	cocos2d::Layer::onEnter();

	_touchListener = cocos2d::EventListenerTouchOneByOne::create();
	_touchListener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	_touchListener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	_touchListener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);

	cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(_touchListener, 1);
}

void HelloWorld::onExit()
{
	if (_touchListener) cocos2d::Director::getInstance()->getEventDispatcher()->removeEventListener(_touchListener);
	_touchListener = nullptr;

	cocos2d::Layer::onExit();
}

HelloWorld::HelloWorld() :_touchListener(nullptr), _geoLayer(nullptr)
{

}

void HelloWorld::operationGeometryView()
{
	if (_geoLayer)
	{
		_geoLayer->removeAllChildren();

		if (_points.size() > 1)
		{
			cocos2d::DrawNode * rectV = cocos2d::DrawNode::create();
			cocos2d::Rect rect = nav::DelaunayAlgorithm::calculateRectByPoints(_points);
			rectV->drawRect(cocos2d::Point(rect.getMinX(), rect.getMinY()), cocos2d::Point(rect.getMaxX(), rect.getMaxY()), cocos2d::Color4F::RED);
			_geoLayer->addChild(rectV);

			nav::Circle circle = nav::DelaunayAlgorithm::calculateCircleByRect(rect);
			cocos2d::DrawNode * circleV = cocos2d::DrawNode::create();
			circleV->drawCircle(circle.getCenter(), circle.getR(), 0, 100, false, cocos2d::Color4F::GREEN);
			_geoLayer->addChild(circleV);

			nav::Triangle triangle = nav::DelaunayAlgorithm::calculateTriangleByCircle(circle);
			cocos2d::DrawNode * triangleVa = cocos2d::DrawNode::create();
			triangleVa->drawLine(triangle.getA(), triangle.getB(), cocos2d::Color4F::YELLOW);
			_geoLayer->addChild(triangleVa);
			cocos2d::DrawNode * triangleVb = cocos2d::DrawNode::create();
			triangleVb->drawLine(triangle.getB(), triangle.getC(), cocos2d::Color4F::YELLOW);
			_geoLayer->addChild(triangleVb);
			cocos2d::DrawNode * triangleVc = cocos2d::DrawNode::create();
			triangleVc->drawLine(triangle.getC(), triangle.getA(), cocos2d::Color4F::YELLOW);
			_geoLayer->addChild(triangleVc);
		}
	}
}

bool HelloWorld::checkHit(const cocos2d::Point& p)
{
	for (auto temp : _points)
	{
		if (temp.x == p.x && temp.y == p.y)
		{
			return true;
		}
	}
	return false;
}

void HelloWorld::addPoint(const cocos2d::Point& p)
{
	_points.push_back(p);
	cocos2d::DrawNode * dot = cocos2d::DrawNode::create();
	dot->drawDot(cocos2d::Point(0, 0), 2, cocos2d::Color4F::BLUE);
	dot->setPosition(p);
	addChild(dot);
}
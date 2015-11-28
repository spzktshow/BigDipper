#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event) override;
	void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event) override;
	void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event) override;

	void onEnter() override;
	void onExit() override;
protected:
	cocos2d::Point _oldP;

	cocos2d::EventListenerTouchOneByOne * _touchListener;

	HelloWorld();

	void operationGeometryView();
	std::vector<cocos2d::Point> _points;

	bool checkHit(const cocos2d::Point& p);
	void addPoint(const cocos2d::Point& p);

	cocos2d::Layer * _geoLayer;
};

#endif // __HELLOWORLD_SCENE_H__

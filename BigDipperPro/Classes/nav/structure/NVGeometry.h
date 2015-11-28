#ifndef __NV_GEOMETRY_H_
#define __NV_GEOMETRY_H_

#include "NavMacro.h"

NS_NV_BEGAN

class Line
{
public:
	Line(const cocos2d::Point&p1, const cocos2d::Point&p2);
	~Line();

	const cocos2d::Point& getP1() const;
	const cocos2d::Point& getP2() const;
protected:
	cocos2d::Point _p1;
	cocos2d::Point _p2;
};

class Circle
{
public:
	Circle(const cocos2d::Point& center, float r);
	~Circle();

	const cocos2d::Point& getCenter() const;
	float getR() const;
protected:
	cocos2d::Point _center;
	float _r;
};

/************三角形由abc三个点组成，abc3个点顺时针排列**********/
class Triangle
{
public:
	Triangle(const cocos2d::Point&a, const cocos2d::Point&b, const cocos2d::Point&c);
	~Triangle();

	const cocos2d::Point& getA() const;
	const cocos2d::Point& getB() const;
	const cocos2d::Point& getC() const;
protected:
	cocos2d::Point _a;
	cocos2d::Point _b;
	cocos2d::Point _c;
};

NS_NV_END;

#endif//__NV_GEOMETRY_H_
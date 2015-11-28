#include "NVGeometry.h"

US_NS_NV;

/**********Line************/
Line::Line(const cocos2d::Point&p1, const cocos2d::Point&p2)
{
	_p1 = p1;
	_p2 = p2;
}

Line::~Line()
{

}

const cocos2d::Point& Line::getP1() const
{
	return _p1;
}

const cocos2d::Point& Line::getP2() const
{
	return _p2;
}

/**************Circle**********/
Circle::Circle(const cocos2d::Point& center, float r)
{
	_center = center;
	_r = r;
}

Circle::~Circle()
{

}

const cocos2d::Point& Circle::getCenter() const
{
	return _center;
}

float Circle::getR() const
{
	return _r;
}

/**************Triangle**************/
Triangle::Triangle(const cocos2d::Point&a, const cocos2d::Point&b, const cocos2d::Point&c)
{
	_a = a;
	_b = b;
	_c = c;
}

Triangle::~Triangle()
{

}

const cocos2d::Point& Triangle::getA() const
{
	return _a;
}

const cocos2d::Point& Triangle::getB() const
{
	return _b;
}

const cocos2d::Point& Triangle::getC() const
{
	return _c;
}
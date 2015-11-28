#include "NVDelaunayAlgorithm.h"
US_NS_NV;

/*************DelaunayAlgorithm*****************/
cocos2d::Rect DelaunayAlgorithm::calculateRectByPoints(const std::vector<cocos2d::Point>&points)
{
	CCASSERT(points.size() > 1, "create rect must more than two points");
	float minX;
	bool mixt = false;
	float minY;
	bool miyt = false;
	float maxX;
	bool maxt = false;
	float maxY;
	bool mayt = false;
	for (auto p : points)
	{
		if (!mixt || p.x < minX)
		{
			minX = p.x;
			mixt = true;
		}
		if (!miyt || p.y < minY)
		{
			minY = p.y;
			miyt = true;
		}
		if (!maxt || p.x > maxX)
		{
			maxX = p.x;
			maxt = true;
		}
		if (!mayt || p.y > maxY)
		{
			maxY = p.y;
			mayt = true;
		}
	}
	if (!mixt || !miyt || !maxt || !mayt) return cocos2d::Rect(0, 0, 0, 0);
	cocos2d::Rect rect(cocos2d::Point(minX, minY), cocos2d::Size(maxX - minX, maxY - minY));
	return rect;
}

nav::Circle DelaunayAlgorithm::calculateCircleByRect(const cocos2d::Rect&rect)
{
	CCASSERT(rect.size.width > 0 && rect.size.height > 0, "create circle must rect");
	cocos2d::Point center(rect.getMidX(), rect.getMidY());
	cocos2d::Point topright(rect.getMaxX(), rect.getMaxY());
	float distance = center.getDistance(topright);
	nav::Circle circle(center, distance);
	return circle;
}

nav::Triangle DelaunayAlgorithm::calculateTriangleByCircle(const nav::Circle&circle)
{
	CCASSERT(circle.getR() > 0, "create traingle that circle's r must > 0");
	float length = circle.getR() * 2.0f;
	float d = 90.0f;
	float r = CC_DEGREES_TO_RADIANS(d);
	cocos2d::Point a(length, 0);
	a.rotate(cocos2d::Point(0, 0), r);
	a = a + circle.getCenter();
	d = 90.0f + 120.0f;
	r = CC_DEGREES_TO_RADIANS(d);
	cocos2d::Point b(length, 0);
	b.rotate(cocos2d::Point(0, 0), r);
	b = b + circle.getCenter();
	d = 90.0f + 240.f;
	r = CC_DEGREES_TO_RADIANS(d);
	cocos2d::Point c(length, 0);
	c.rotate(cocos2d::Point(0, 0), r);
	c = c + circle.getCenter();
	nav::Triangle triangle(a, b, c);
	return triangle;
}
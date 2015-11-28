#include "NVDelaunayAlgorithm.h"

US_NS_NV;

/*************DelaunayAlgorithm*****************/
cocos2d::Rect DelaunayAlgorithm::calculateRectByPoints(const cocos2d::Vector<cocos2d::Point>&points)
{
	cocos2d::Point * min = nullptr;
	cocos2d::Point * max = nullptr;
	for (auto p : points)
	{
		if (min == nullptr || min != nullptr && p.x <= min->x && p.y <= min->y) min = &p;
		if (max == nullptr || max != nullptr && p.x >= max->x && p.y <= max->y) max = &p;
	}
	if (min == nullptr || max == nullptr) return cocos2d::Rect(0, 0, 0, 0);
	cocos2d::Rect rect(*min, cocos2d::Size(max->x - min->x, max->y - min->y));
	return rect;
}

nav::Circle DelaunayAlgorithm::calculateCircleByRect(const cocos2d::Rect&rect)
{
	cocos2d::Point center(rect.getMidX(), rect.getMidY());
	cocos2d::Point topright(rect.getMaxX(), rect.getMaxY());
	float distance = center.getDistance(topright);
	nav::Circle circle(center, distance);
	return circle;
}

nav::Triangle DelaunayAlgorithm::calculateTriangleByCircle(const nav::Triangle&triangle)
{

}
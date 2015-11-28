#ifndef __NAV_DELAUNAY_ALGORITHM_H_
#define __NAV_DELAUNAY_ALGORITHM_H_

#include "NavMacro.h"
#include "NVGeometry.h"

NS_NV_BEGAN

class DelaunayAlgorithm
{
public:
	/*********根据点集创建矩形*********/
	static cocos2d::Rect calculateRectByPoints(const cocos2d::Vector<cocos2d::Point>&points);

	static nav::Circle calculateCircleByRect(const cocos2d::Rect&rect);

	static nav::Triangle calculateTriangleByCircle(const nav::Triangle&triangle);
};

NS_NV_END;

#endif // !__NAV_DELAUNAY_ALGORITHM_H_

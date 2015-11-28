#ifndef __NAV_DELAUNAY_ALGORITHM_H_
#define __NAV_DELAUNAY_ALGORITHM_H_

#include "NavMacro.h"
#include "NVGeometry.h"

NS_NV_BEGAN

class DelaunayAlgorithm
{
public:
	/*********根据点集创建矩形*********/
	static cocos2d::Rect calculateRectByPoints(const std::vector<cocos2d::Point>&points);

	static nav::Circle calculateCircleByRect(const cocos2d::Rect&rect);
	/******通过一个圆获得一个外接于圆的正等边三角形，所有内角都为60度******/
	static nav::Triangle calculateTriangleByCircle(const nav::Circle&circle);
	/****************检测点是否在三角形内***************/
	static bool checkPointInTriangle(const cocos2d::Point&p, const nav::Triangle& triangle);
	/**************检测点是否在三角形列表内****************/
	static std::vector<Triangle> checkPointInTriangles(const cocos2d::Point&p, const std::vector<Triangle>& triangles);
};

NS_NV_END;

#endif // !__NAV_DELAUNAY_ALGORITHM_H_

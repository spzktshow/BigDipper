#include "NVVectorAlgorithm.h"

US_NS_NV;
/**********VectorAlgorithm************/
float VectorAlgorithm::crossProduct(const cocos2d::Point&P, const cocos2d::Point&Q)
{
	return P.x * Q.y - Q.x * P.y;
}

float VectorAlgorithm::inflectionPoint(const cocos2d::Point&p0, const cocos2d::Point&p1, const cocos2d::Point&p2)
{
	cocos2d::Point r1 = p2 - p0;
	cocos2d::Point r2 = p1 - p0;
	return crossProduct(r1, r2);
}

bool VectorAlgorithm::fastExclusion(const nav::Line&p, const nav::Line&q)
{
	const cocos2d::Rect&pR = getRectByLine(p);
	const cocos2d::Rect&qR = getRectByLine(q);
	return (pR.intersectsRect(qR));
}

cocos2d::Rect VectorAlgorithm::getRectByLine(const nav::Line&p)
{
	float minX = std::min(p.getP1().x, p.getP2().x);
	float minY = std::min(p.getP1().y, p.getP2().y);
	float maxX = std::max(p.getP1().x, p.getP2().x);
	float maxY = std::max(p.getP1().y, p.getP2().y);
	cocos2d::Point minP(minX, minY);
	cocos2d::Rect rect(minP, cocos2d::Size(maxX - minX, maxY - minY));
	return rect;
}

bool VectorAlgorithm::cross(const nav::Line&p, const nav::Line&q)
{
	cocos2d::Point p1subq1(p.getP1() - q.getP1());
	cocos2d::Point p2subq1(p.getP2() - q.getP1());
	cocos2d::Point q2subq1(q.getP2() - q.getP1());
	float a = crossProduct(p1subq1, q2subq1);
	float b = crossProduct(p2subq1, q2subq1);
	return a * b;
}

bool VectorAlgorithm::eachCross(const nav::Line&P, const nav::Line&Q)
{
	return (cross(P, Q) && cross(Q, P));
}
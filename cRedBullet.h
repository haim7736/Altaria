#pragma once
#include "cBullet.h"
class cRedBullet :
public cBullet
{
public:
	float RenderSize;
	float m_speed;
	cRedBullet(Vec2 pos, Vec2 dir, float damage, float size = 10, float speed = 300);
	virtual ~cRedBullet();

	float radian;
	float rot;
	float degree;
	virtual void Update() override;
	virtual void Render() override;
};
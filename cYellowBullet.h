#pragma once
#include "cBullet.h"
class cYellowBullet :
	public cBullet
{
public:
	float RenderSize;
	float m_speed;
	cYellowBullet(Vec2 pos, Vec2 dir, float damage, float size = 10, float speed = 300);
	virtual ~cYellowBullet();

	virtual void Update() override;
	virtual void Render() override;
};
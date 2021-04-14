#pragma once
#include "cBullet.h"
class cBlueBullet :
	public cBullet
{
public:
	float RenderSize;
	float m_speed;
	cBlueBullet(Vec2 pos, Vec2 dir, float damage, float size = 10, float speed = 300);
	virtual ~cBlueBullet();

	virtual void Update() override;
	virtual void Render() override;
};


#pragma once
#include "cBullet.h"
class cPurPle :
	public cBullet
{
public:
	float RenderSize;
	float m_speed;
	cPurPle(Vec2 pos, Vec2 dir, float damage, float size = 10, float speed =300);
	virtual ~cPurPle();

	virtual void Update() override;
	virtual void Render() override;
};
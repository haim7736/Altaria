#pragma once
#include "cBullet.h"
class cPlayerBullet :
	public cBullet
{
public:
	cPlayerBullet(Vec2 pos, Vec2 dir = Vec2(0, 1));
	virtual ~cPlayerBullet();

	virtual void Update() override;
	virtual void Render() override;
};


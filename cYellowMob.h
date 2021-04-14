#pragma once
#include "cMob.h"
#include "cBullet.h"
#include "cPlayer.h"
class cYellowMob : public cMob
{
public:
	cYellowMob(Vec2 pos, cPlayer* player, vector<cBullet*>& bullet);
	virtual ~cYellowMob();
	bool b_once;

	bool b_Attack = true;
	cTimer* AS = nullptr;
	vector<cBullet*>& m_bullet;

	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
};


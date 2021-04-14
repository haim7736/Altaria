#pragma once
#include "cMob.h"
#include "cBullet.h"
#include "cPlayer.h"
class cBlueMob : public cMob
{
public:
	cBlueMob(Vec2 pos, cPlayer* player, vector<cBullet*>& bullet);
	virtual ~cBlueMob();
	bool b_once;

	vector<cTexture*> m_blueani;

	bool b_Attack = true;
	cTimer* AS = nullptr;
	cTimer* m_ani = nullptr;
	int m_frame = 0;
	int m_framebu = 0;
	bool m_bOnce;

	vector<cBullet*>& m_bullet;

	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	void Animation();
};


#pragma once
#include "cMob.h"
#include "cBullet.h"
#include "cPlayer.h"
class cRedMob : public cMob
{
public:
	cRedMob(Vec2 pos, cPlayer* player, vector<cBullet*>& bullet);
	virtual ~cRedMob();
	bool b_once;

	bool b_Attack = true;
	cTimer* AS = nullptr;
	float radian;
	vector<cBullet*>& m_bullet;


	vector<cTexture*> m_redani;

	cTimer* m_ani = nullptr;
	int m_frame = 0;
	int m_framebu = 0;
	bool m_bOnce;

	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	void Animation();
};


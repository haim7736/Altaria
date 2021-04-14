#pragma once
#include "cMob.h"
#include "cBullet.h"
#include "cPlayer.h"
class cPurpleMob : public cMob
{
public:
	cPurpleMob(Vec2 pos, cPlayer* player, vector<cBullet*>& bullet);
	virtual ~cPurpleMob();
	bool b_once;


	vector<cTexture*> m_purple;


	Vec2 pos1;
	Vec2 pos2;
	bool b_Attack = true;
	cTimer* AS = nullptr;
	bool l_Attack = true;
	cTimer* LS = nullptr;
	bool R_Attack = true;
	cTimer* RS = nullptr;
	vector<cBullet*>& m_bullet;

	cTimer* m_ani = nullptr;
	int m_frame = 0;
	int m_framebu1 = 0;
	int m_framebu2 = 0;
	int m_framebu3 = 0;
	bool m_bOnce;

	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	void Animation();
};


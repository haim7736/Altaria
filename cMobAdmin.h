#pragma once
#include "cPlayer.h"
#include "cMob.h"
#include "cBullet.h"

class cMobAdmin
{
public:
	cMobAdmin(cPlayer* player, vector<cBullet*>& bullet);
	~cMobAdmin();


	vector<cMob*> mobs;
	vector<cBullet*>& m_bullet;
	cPlayer* m_player;

	bool boss1 = false;


	bool boss1S = true;


	bool BossDead = false;

	bool mobSpawn = true;

	cTimer* NMS = nullptr;
	cTimer* BMSB = nullptr;
	cTimer* BMSY = nullptr;
	cTimer* BMSR = nullptr;
	cTimer* BMSP = nullptr;

	bool NM = true;
	bool BMB = true;
	bool BMY = true;
	bool BMR = true;
	bool BMP = true;
	bool boss2 = true;



	void Update();
	void Render();
	void UIRender();
	void CreateMob();
	void IsOut();
	void IsDestroy();
};


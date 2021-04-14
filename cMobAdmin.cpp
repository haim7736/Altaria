#include "DXUT.h"
#include "cMobAdmin.h"
#include "cBlueMob.h"
#include "cOrangeMob.h"
#include "cRedMob.h"
#include "cYellowMob.h"
#include "cPurpleMob.h"
#include "cMoonMob.h"

cMobAdmin::cMobAdmin(cPlayer* player, vector<cBullet*>& bullet)
	:m_player(player), m_bullet(bullet)
{
}

cMobAdmin::~cMobAdmin()
{
	for (auto iter : mobs) SAFE_DELETE(iter);
	mobs.clear();
	SAFE_DELETE(NMS);
	SAFE_DELETE(BMSB);
	SAFE_DELETE(BMSR);
	SAFE_DELETE(BMSY);
	SAFE_DELETE(BMSP);
}

void cMobAdmin::Update()
{
	for (auto iter : mobs) iter->Update();
	IsOut();
	IsDestroy();
	CreateMob();
}

void cMobAdmin::Render()
{
	for (auto iter : mobs) iter->Render();
}

void cMobAdmin::UIRender()
{
	for (auto iter : mobs) iter->UIRender();	
}

void cMobAdmin::CreateMob()
{
	

	if (NMS != nullptr) NMS->Update();
	if (BMSB != nullptr) BMSB->Update();
	if (BMSR != nullptr) BMSR->Update();
	if (BMSY != nullptr) BMSY->Update();
	if (BMSP != nullptr) BMSP->Update();

	if (m_player->Score >= limit && boss1S && m_player->Score <= 1100000) { boss1 = true; mobSpawn = false; }
	if (mobSpawn)
	{
		if (NM && m_player->Score <= 10000000)
		{
			NMS = new cTimer(2.5, [&]()->void {NM = true; NMS = nullptr; });
			NM = false;
			mobs.push_back(new cOrangeMob(Vec2(-10, rand() % 300), m_player));
			mobs.push_back(new cOrangeMob(Vec2(WINSIZEX + 10, rand() % 300), m_player));

		}
		if (BMB && m_player->Score <= 10000000)
		{
			BMSB = new cTimer(1.5, [&]()->void {BMB = true; BMSB = nullptr; });
			BMB = false;
			mobs.push_back(new cBlueMob(Vec2(rand() % 1320 + 300, -10), m_player, m_bullet));
		}
		if (BMR && m_player->Score <= 10000000)
		{
			BMSR = new cTimer(12, [&]()->void {BMR = true; BMSR = nullptr; });
			BMR = false;
			mobs.push_back(new cRedMob(Vec2(0, rand() % (833 + 1 - 562) + 562), m_player, m_bullet));
		}
		if (BMY && m_player->Score <= 10000000)
		{
			BMSY = new cTimer(5
				, [&]()->void {BMY = true; BMSY = nullptr; });
			BMY = false;
			mobs.push_back(new cYellowMob(Vec2(rand() % 1320 + 300, -10), m_player, m_bullet));
			
		}
		if (BMP && m_player->Score <= 10000000 )
		{
			BMSP = new cTimer(3.5, [&]()->void {BMP = true; BMSP = nullptr; });
			BMP = false;
			mobs.push_back(new cPurpleMob(Vec2(1600, rand() % WINSIZEX), m_player, m_bullet));

		}
	}
	if ( boss1 &&  boss2|| INPUT->KeyDown(VK_F1))
	{
		boss2 = false;
		mobs.push_back(new cMoonMob(Vec2(WINSIZEX / 2, 200), m_player, m_bullet));
		
	}
}

void cMobAdmin::IsOut()
{
	size_t size = mobs.size();
	for (size_t i = 0; i < size; i++)
	{
		auto& iter = mobs[i];
		if (iter->IsOutMap() && iter->mobType != "Boss")
		{
			SAFE_DELETE(iter);
			mobs.erase(mobs.begin() + i);
			i--; size--;
		}
	}
}

void cMobAdmin::IsDestroy()
{
	size_t size = mobs.size();
	for (size_t i = 0; i < size; i++)
	{
		auto& iter = mobs[i];
		if (iter->isDestroy)
		{
			if (iter->mobName == "Moon")
			{
				boss1 = false;
				mobSpawn = true;
			}
			if (iter->mobType != "Boss")
			SAFE_DELETE(iter);
			mobs.erase(mobs.begin() + i);
			i--; size--;
		}
	}
}

#include "DXUT.h"
#include "cYellowMob.h"
#include "cPlayer.h"
#include "cYellowBullet.h"

cYellowMob::cYellowMob(Vec2 pos, cPlayer* player, vector<cBullet*>& bullet)
	:cMob(pos, player), m_bullet(bullet)
{
	m_Hp = 60;
	m_Damage = 10;
	m_size = 20;
	mobName = "Yellow";
	mobType = "none";
}

cYellowMob::~cYellowMob()
{
	SAFE_DELETE(AS);
}

void cYellowMob::Update()
{
	m_pos.y += 30 * DXUTGetElapsedTime();
	if (AS != nullptr) AS->Update();
	if (b_Attack)
	{
		AS = new cTimer(5, [&]()->void {b_Attack = true; AS = nullptr; });
		b_Attack = false;
		m_bullet.push_back(new cYellowBullet(m_pos, Vec2(0, 1), m_Damage));
	}
}

void cYellowMob::Render()
{
	if(m_Hp > 30)
	{
		RENDER->CenterRender(IMAGE->FindImage("Yellowshield"), m_pos, 0, 1.5);
	}else
	if (m_Hp <= 30)
	{
		RENDER->CenterRender(IMAGE->FindImage("Yellow"), m_pos, 0, 1.5);
	}
	
}

void cYellowMob::UIRender()
{
}

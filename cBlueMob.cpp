#include "DXUT.h"
#include "cBlueMob.h"
#include "cPlayer.h"
#include "cBlueBullet.h"


cBlueMob::cBlueMob(Vec2 pos, cPlayer* player, vector<cBullet*>& bullet)
	:cMob(pos,player),  m_bullet(bullet)
{
	m_Hp = 20;
	m_Damage = 10;
	m_size = 10;
	mobName = "Blue";
	mobType = "none";
	m_blueani = IMAGE->MakeVecImg("Blueani");
}

cBlueMob::~cBlueMob()
{
	SAFE_DELETE(AS);
	SAFE_DELETE(m_ani);
}

void cBlueMob::Update()
{
	//if (m_pos.x < rand() % 200 + 300 && b_once) { m_pos.x += 6; m_angle = 0; }
	 //if (m_pos.x > WINSIZEX - (rand() % 200 + 300) && b_once) { m_pos.x -= 6; m_angle = D3DXToRadian(180); }
	/*
	
		b_once = false;
		m_angle = atan2(m_player->m_pos.y - 500, m_player->m_pos.x  - m_pos.x);
		m_pos += Vec2(cos(m_angle), sin(m_angle)) * 3;
	
	*/
	Animation();
	m_pos.y += 100 * DXUTGetElapsedTime();
	if (AS != nullptr) AS->Update();
	/*
	if (b_Attack)
	{
		AS = new cTimer(1.5, [&]()->void {b_Attack = true; AS = nullptr; });
		b_Attack = false;
		m_bullet.push_back(new cBlueBullet(m_pos, Vec2(0,1), m_Damage));
	}
	*/
	if (b_Attack)
	{
		AS = new cTimer(0.06, [&]()->void {m_framebu++;
		if (m_framebu == m_blueani.size())
		{
			b_Attack = true;
			m_framebu = 0;
			AS = nullptr;
			m_bullet.push_back(new cBlueBullet(Vec2(m_pos.x,m_pos.y+30), Vec2(0, 1), m_Damage));
		} }, 1);
		b_Attack = false;
	}
}

void cBlueMob::Render()
{
	//RENDER->CenterRender(IMAGE->FindImage("Blue"), m_pos, -m_angle+90);
	RENDER->CenterRender(m_blueani[m_frame], Vec2(m_pos.x, m_pos.y ), 0, 1.5);
}

void cBlueMob::UIRender()
{
}

void cBlueMob::Animation()
{
	if (m_ani != nullptr) m_ani->Update();
	if (m_bOnce)
	{
		m_ani = new cTimer(0.06, [&]()->void {m_frame++; if (m_frame == m_blueani.size()) m_frame = 0; }, 1);
		m_bOnce = false;
	}

}
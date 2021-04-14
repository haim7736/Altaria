#include "DXUT.h"
#include "cPurpleMob.h"
#include "cPlayer.h"
#include "cPurPle.h"

cPurpleMob::cPurpleMob(Vec2 pos, cPlayer* player, vector<cBullet*>& bullet)
	:cMob(pos, player), m_bullet(bullet)
{
	m_Hp = 30;
	m_Damage = 10;
	m_size = 20;
	mobName = "Purple";
	mobType = "none";

	m_purple = IMAGE->MakeVecImg("PurpleAni");
}

cPurpleMob::~cPurpleMob()
{
	SAFE_DELETE(AS);
	SAFE_DELETE(LS);
	SAFE_DELETE(RS);
	SAFE_DELETE(m_ani);
}

void cPurpleMob::Update()
{
	m_pos.x -= 100 * DXUTGetElapsedTime();
	pos1 = Vec2(m_pos.x + 30, m_pos.y+50);
	pos2 = Vec2(m_pos.x - 30, m_pos.y+50);
	if (AS != nullptr) AS->Update();
	if (RS != nullptr) RS->Update();
	if (LS != nullptr) LS->Update();

	Animation();

	if (b_Attack)
	{
		AS = new cTimer(0.06, [&]()->void {m_framebu1++;
		if (m_framebu1 == m_purple.size())
		{
			b_Attack = true;
			m_framebu1 = 0;
			AS = nullptr;
		m_bullet.push_back(new cPurPle(pos1, Vec2(0, 1), m_Damage));
		} }, 1);
		b_Attack = false;
	}
	if (R_Attack)
	{
		RS = new cTimer(0.06, [&]()->void {m_framebu2++;
		if (m_framebu2 == m_purple.size())
		{
			R_Attack = true;
			m_framebu2 = 0;
			RS = nullptr;
		m_bullet.push_back(new cPurPle(Vec2(m_pos.x,m_pos.y +50)
			, Vec2(0, 1), m_Damage));
		} }, 1);
		R_Attack = false;
	}
	if (l_Attack)
	{
		LS = new cTimer(0.06, [&]()->void {m_framebu3++;
		if (m_framebu3 == m_purple.size())
		{
			l_Attack = true;
			m_framebu3 = 0;
			LS = nullptr;
			m_bullet.push_back(new cPurPle(pos2, Vec2(0, 1), m_Damage));
		} }, 1);
		l_Attack = false;
	}
}

void cPurpleMob::Render()
{
	//RENDER->CenterRender(IMAGE->FindImage("Purple"), m_pos,0,1.5);
	RENDER->CenterRender(m_purple[m_frame], Vec2(m_pos.x, m_pos.y-75), 0, 1.5);
}

void cPurpleMob::UIRender()
{
}


void cPurpleMob::Animation()
{
	if (m_ani != nullptr) m_ani->Update();
	if (m_bOnce)
	{
		m_ani = new cTimer(0.06, [&]()->void {m_frame++; if (m_frame == m_purple.size()) m_frame = 0; }, 1);
		m_bOnce = false;
	}

}
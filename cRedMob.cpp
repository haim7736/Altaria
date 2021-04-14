#include "DXUT.h"
#include "cRedMob.h"
#include "cPlayer.h"
#include "cRedBullet.h"

cRedMob::cRedMob(Vec2 pos, cPlayer* player, vector<cBullet*>& bullet)
	:cMob(pos, player), m_bullet(bullet)
{
	m_Hp = 10;
	m_Damage = 10;
	m_size = 10;
	mobName = "Red";
	mobType = "none";
	m_redani = IMAGE->MakeVecImg("RedAni");
}

cRedMob::~cRedMob()
{
	SAFE_DELETE(AS);
	SAFE_DELETE(m_ani);
}

void cRedMob::Update()
{

	Animation();


	m_pos.x += 100 * DXUTGetElapsedTime();
	if (AS != nullptr) AS->Update();
	if (b_Attack)
	{
		AS = new cTimer(0.06, [&]()->void {m_framebu++;
		if (m_framebu == m_redani.size())
		{
			b_Attack = true;
			m_framebu = 0;
			AS = nullptr;
			m_bullet.push_back(new cRedBullet(Vec2(m_pos.x+25,m_pos.y), Vec2(0, 1), m_Damage));
		} }, 1);
		b_Attack = false;
	}
	radian = ((180) * (D3DX_PI / 180.0f));
}

void cRedMob::Render()
{
	//RENDER->CenterRender(IMAGE->FindImage("Red"), m_pos, radian,1.5);
	RENDER->CenterRender(m_redani[m_frame], Vec2(m_pos.x, m_pos.y), 0, 1.5);
}

void cRedMob::UIRender()
{
}

void cRedMob::Animation()
{
	if (m_ani != nullptr) m_ani->Update();
	if (m_bOnce)
	{
		m_ani = new cTimer(0.06, [&]()->void {m_frame++; if (m_frame == m_redani.size()) m_frame = 0; }, 1);
		m_bOnce = false;
	}

}
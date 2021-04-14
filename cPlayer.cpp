#include "DXUT.h"
#include "cPlayer.h"
#include "cPlayerBullet.h"
#include "cMeteor.h"
#include "cMob.h"


cPlayer::cPlayer(vector<cBullet*>& bullet)
	:m_pos(WINSIZEX / 2, 700), m_bullet(bullet), m_size(15)
{
	m_Hp = SCENE->m_Hp;
	m_MaxHp = SCENE->m_MaxHp;
	m_AS_b = SCENE->m_AS_b;
	m_AS_s = SCENE->m_AS_s;
	m_damage = SCENE->m_damage;
	m_Exp = SCENE->m_Exp;
	m_MaxExp = SCENE->m_MaxExp;
	Score = SCENE->Score;
	livecheck = true;
	m_playmv = IMAGE->MakeVecImg("playermv");
	m_playbu = IMAGE->MakeVecImg("playerbu");
}

cPlayer::~cPlayer()
{
	TimerDelete();
	SCENE->m_Hp = m_Hp;
	SCENE->m_MaxHp = m_MaxHp;
	SCENE->m_AS_b = m_AS_b;
	SCENE->m_AS_s = m_AS_s;
	SCENE->m_damage = m_damage;
	SCENE->m_Exp = m_Exp;
	SCENE->m_MaxExp = m_MaxExp;
	SCENE->Score = Score;
	SAFE_DELETE(m_ani);
	SAFE_DELETE(m_plbu);
	
}

void cPlayer::Update()
{

	if (m_Hp <= 0)
	{
		m_Hp = 0;
		b_invincible = true;
		livecheck = false;
		SCENE->ChangeScene("cOverScene");
	}

	Move();
	FireBullet();
	TimerUpdate();
	OutMap();
	SkillUpdate();
	ItemUpdate();
	ScoreUpdate();
	Cheat();
	Animation();
}

void cPlayer::Render()
{
	
	RENDER->CenterRender(m_playmv[m_frame], Vec2(m_pos.x,m_pos.y+30),0,1.5);
	
	RENDER->CenterRender(m_playbu[m_framebu], Vec2(m_pos.x,m_pos.y-110));
		
}

void cPlayer::UIRender()
{
	RECT hprc = {
			0,
			0,
			((float)IMAGE->FindImage("plhpgauge")->info.Width / m_MaxHp) * m_Hp,
			IMAGE->FindImage("plhpgauge")->info.Height
	};
	UI->CenterRender(IMAGE->FindImage("plhp_frame"), Vec2(150, 850));
	UI->CropRender(IMAGE->FindImage("plhpgauge"), Vec2(150, 850), hprc);

}

void cPlayer::FireBullet()
{
	if (m_plbu != nullptr) m_plbu->Update();

		if (INPUT->KeyPress(90) && attacksp)
		{
			attacksp = false;
			
			if (m_bOncebu)
			{
				m_plbu = new cTimer(0.04, [&]()->void {m_framebu++;
				if (m_framebu == m_playbu.size())
				{
					m_bOncebu = true;
					ch = false;
					m_framebu = 0;
					m_plbu = nullptr;
					attacksp = true;
					m_bullet.push_back(new cPlayerBullet(m_pos - Vec2(0, 50)));
				} }, 1);
				m_bOncebu = false;
			}
			ch = true;
			
		}

		
}


void cPlayer::Move()
{
	if (INPUT->KeyPress(VK_UP)) m_pos.y -= 450 * DXUTGetElapsedTime();
	if (INPUT->KeyPress(VK_DOWN)) m_pos.y += 450 * DXUTGetElapsedTime();
	if (INPUT->KeyPress(VK_LEFT)) m_pos.x -= 450 * DXUTGetElapsedTime();
	if (INPUT->KeyPress(VK_RIGHT)) m_pos.x += 450 * DXUTGetElapsedTime();

	
}

void cPlayer::OutMap()
{
	if (Score <= limit)
	{
		if (m_pos.x < 490) m_pos.x += 450 * DXUTGetElapsedTime();
		if (m_pos.x > 1110) m_pos.x -= 450 * DXUTGetElapsedTime();
		if (m_pos.y < 600) m_pos.y += 450 * DXUTGetElapsedTime();
		if (m_pos.y > 850) m_pos.y -= 450 * DXUTGetElapsedTime();
	}
	else
	{
		if (m_pos.x < 300) m_pos.x += 450 * DXUTGetElapsedTime();
		if (m_pos.x > 1300) m_pos.x -= 450 * DXUTGetElapsedTime();
		if (m_pos.y < 645) m_pos.y += 450 * DXUTGetElapsedTime();
		if (m_pos.y > 860) m_pos.y -= 450 * DXUTGetElapsedTime();
	}
}

void cPlayer::TimerUpdate()
{
}

void cPlayer::TimerDelete()
{
}

void cPlayer::SkillUpdate()
{
}

void cPlayer::SkillRender()
{
}

void cPlayer::ItemUpdate()
{
}


void cPlayer::ScoreUpdate()
{
	if (MobTag == "Normal")
	{
		Score += 10000;
		MobTag = "none";
	}
}

void cPlayer::Cheat()
{
}

void cPlayer::Animation()
{
	if (m_ani != nullptr) m_ani->Update();
	if (m_bOnce)
	{
		m_ani = new cTimer(0.08, [&]()->void {m_frame++; if (m_frame == m_playmv.size()) m_frame = 0; }, 1);
		m_bOnce = false;
	}

}

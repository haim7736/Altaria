#include "DXUT.h"
#include "cMoonMob.h"
#include "cPlayer.h"
#include "cMoonBullet1.h"
#include "cMoonBullet2.h"
#include "cMeteor.h"
cMoonMob::cMoonMob(Vec2 pos, cPlayer* player, vector<cBullet*>& bullet)
	:cMob(pos, player), m_bullet(bullet)
{
	m_Hp = 500;
	m_Damage = 15;
	m_angle = 0;
	m_size = 200;
	mobName = "Moon";
	mobType = "Boss";
	RenderSize = 1;
	m_moonani = IMAGE->MakeVecImg("MoonAni");
	m_warning = IMAGE->MakeVecImg("warning");
	
}

cMoonMob::~cMoonMob()
{
	SAFE_DELETE(Bm);
	SAFE_DELETE(Pm);
	SAFE_DELETE(AS);
	SAFE_DELETE(LS);
	SAFE_DELETE(Mm);
	SAFE_DELETE(m_ani);
}

void cMoonMob::Update()
{
	if (alpha == 255)
	{
		is = false;
	}
	if (alpha != 255 && is)
	{
		alpha++;
	}
	if (alpha <= 1)
	{
		iis = false;
	}
	if (alpha !=0 && !is && iis)
	{
		alpha-=2;
	}

	if (m_pos.x >= 1000)
	{
		check = false;
	}
	else if (m_pos.x <= 550)
	{
		check = true;
	}
	if (check)
	{
		m_pos.x += 0.2 * 5+ Delta ;
	}
	if (!check)
	{
		m_pos.x -= 0.2 * 5+ Delta;
	}
	if (m_Hp < 0)
	{
		m_pos.x += 200 * DXUTGetElapsedTime();
		m_pos.y -= 200 * DXUTGetElapsedTime();	
		if (m_pos.y <= -100 )SCENE->ChangeScene("cEndScene");
	}
	if (AS != nullptr) AS->Update();
	Animation();
	Ready();
	switch (pattern)
	{
	case 0:
		break;
	case 1:
		Pattern1();
		break;
	case 2:
		Pattern2();
		break;
	case 3:
		Pattern3();
		break;
	default:
		break;
	}
	
}

void cMoonMob::Render()
{

	RENDER->CenterRender(m_moonani[m_frame], Vec2(m_pos.x, m_pos.y + 30), 0, 1.2);
	if (pattern3)
	{
		RENDER->CenterRender(IMAGE->FindImage("meteorline"), Vec2(m_meteor.x, m_pos.y), 0, 1);
		RENDER->CenterRender(m_warning[p3_frame], Vec2(m_meteor.x, m_pos.y + 212), 0, 1.5);
	}
	/*
	if (m_Hp >= 0)
	{
		RENDER->CenterRender(IMAGE->FindImage("moon"), m_pos, 0, 1);
	}
	else
	{
		RENDER->CenterRender(IMAGE->FindImage("MoonHurt"), m_pos, 0, 1);
	}*/
}

void cMoonMob::UIRender()
{
	RECT hprc = {
		0,
		0,
		((float)IMAGE->FindImage("hpgauge")->info.Width / 500) * m_Hp,
		IMAGE->FindImage("hpgauge")->info.Height
	};
	UI->CropRender(IMAGE->FindImage("hpgauge"), Vec2(WINSIZEX/2, 50), hprc);
	UI->CenterRender(IMAGE->FindImage("hp_frame"), Vec2(WINSIZEX / 2, 50));
	UI->CenterRender(IMAGE->FindImage("themoon"), Vec2(WINSIZEX / 2, WINSIZEY/2),1,0, D3DCOLOR_RGBA(255, 255, 255, alpha));
}

void cMoonMob::Pattern1()
{
	if (pattern1)
	{
		Vec2 temp;
		D3DXVec2Normalize(&temp, &(m_player->m_pos - m_pos));
		if (Bm != nullptr) Bm->Update();
		if (BM)
		{
			Bm = new cTimer(0.2, [&]()->void {p1_frame++;
			m_bullet.push_back(new cMoonBullet1(m_pos, temp, m_Damage));
			if (p1_frame == 20) {
				Bm = nullptr; ready = true; p1_frame = 0; pattern1 = false; BM = true;
			}}, 1);
			BM = false;

		}
	}
}

void cMoonMob::Pattern2()
{
	if (pattern2)
	{
		Vec2 temp;
		D3DXVec2Normalize(&temp, &(m_player->m_pos - m_pos));
		if (Pm != nullptr) Pm->Update();
		if (PP)
		{
			Pm = new cTimer(0.1, [&]()->void {p2_frame++;
			m_bullet.push_back(new cMoonBullet1(Vec2(rand() % 1320 + 300, -10), temp - Vec2(0.0625, 0), m_Damage));
			m_bullet.push_back(new cMoonBullet2(Vec2(rand() % 1320 + 300, -10), temp + Vec2(0.0625, 0), m_Damage));
			if (p2_frame == 100) {
				Pm = nullptr; ready = true; p2_frame = 0; pattern2 = false; PP = true;
			}}, 1);
			PP = false;
		}
	}

}

void cMoonMob::Pattern3()
{
	if (pattern3)
	{
		if (Mm != nullptr) Mm->Update();
		if (MP)
		{
			m_meteor = Vec2(rand() % 1320 + 300, -50);
			Mm = new cTimer(0.09, [&]()->void {p3_frame++;
			if (p3_frame == m_warning.size()) {
				ready = true; 
				p3_frame = 0; 
				m_bullet.push_back(new cMeteor(m_meteor, Vec2(0, 1), m_Damage));
				MP = true;
				pattern3 = false; 
				Mm = nullptr; 
			}},1);
			MP = false;
		}
	}
}



void cMoonMob::Ready()
{
	if (ready)
	{
		ready = false;
		pattern = 0;
		AS = new cTimer(2, [&]()->void {
			pattern = (rand() % 3) + 1;
			if (pattern == 1) pattern1 = true;
			if (pattern == 2) pattern2 = true;
			if (pattern == 3) pattern3 = true;
			AS = nullptr;
			});
	}
}

void cMoonMob::Animation()
{
	if (m_ani != nullptr) m_ani->Update();
	if (m_bOnce)
	{
		m_ani = new cTimer(0.08, [&]()->void {m_frame++; if (m_frame == m_moonani.size()) m_frame = 0; }, 1);
		m_bOnce = false;
	}

}
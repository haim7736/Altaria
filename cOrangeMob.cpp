#include "DXUT.h"
#include "cOrangeMob.h"
#include "cPlayer.h"
cOrangeMob::cOrangeMob(Vec2 pos, cPlayer* player)
	:cMob(pos, player)
{
	m_Hp = 10;
	m_Damage = 10;
	m_size = 10;
	mobName = "Orange";
	mobType = "none";
}

cOrangeMob::~cOrangeMob()
{
}

void cOrangeMob::Update()
{

	b_once = false;
	m_angle = atan2(m_player->m_pos.y - 500, m_player->m_pos.x - m_pos.x);
	m_pos += Vec2(cos(m_angle), sin(m_angle)) * 3;
}

void cOrangeMob::Render()
{
	RENDER->CenterRender(IMAGE->FindImage("Orange"), m_pos, -m_angle + 90,1.5);
}

void cOrangeMob::UIRender()
{
}

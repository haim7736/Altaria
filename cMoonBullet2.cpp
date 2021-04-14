#include "DXUT.h"
#include "cMoonBullet2.h"

cMoonBullet2::cMoonBullet2(Vec2 pos, Vec2 dir, float damage, float size, float speed)
	:cBullet(pos, dir, size), m_speed(speed)
{
	m_Damage = damage;
	RenderSize = m_size / 10;
	bulletType = "mob";
	m_size;
}

cMoonBullet2::~cMoonBullet2()
{
}

void cMoonBullet2::Update()
{
	m_pos += m_Dir * 800 * Delta;
}

void cMoonBullet2::Render()
{
	RENDER->CenterRender(IMAGE->FindImage("Moonbullet2"), m_pos, m_angle, RenderSize);
}

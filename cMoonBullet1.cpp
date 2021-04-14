
#include "DXUT.h"
#include "cMoonBullet1.h"

cMoonBullet1::cMoonBullet1(Vec2 pos, Vec2 dir, float damage, float size, float speed)
	:cBullet(pos, dir, size), m_speed(speed)
{
	m_Damage = damage;
	RenderSize = m_size / 10;
	bulletType = "mob";
	m_size = 20;
}

cMoonBullet1::~cMoonBullet1()
{
}

void cMoonBullet1::Update()
{
	m_pos += m_Dir * 700 * Delta;
}

void cMoonBullet1::Render()
{
	RENDER->CenterRender(IMAGE->FindImage("Moonbullet1"), m_pos, m_angle, RenderSize);
}

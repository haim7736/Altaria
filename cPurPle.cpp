#include "DXUT.h"
#include "cPurPle.h"

cPurPle::cPurPle(Vec2 pos, Vec2 dir, float damage, float size, float speed)
	:cBullet(pos, dir, size), m_speed(speed)
{
	m_Damage = damage;
	RenderSize = m_size / 10;
	bulletType = "mob";
}

cPurPle::~cPurPle()
{
}

void cPurPle::Update()
{
	m_pos += m_Dir * m_speed * Delta;
}

void cPurPle::Render()
{
	RENDER->CenterRender(IMAGE->FindImage("purplebullet"), m_pos, 0, 1.5);
}

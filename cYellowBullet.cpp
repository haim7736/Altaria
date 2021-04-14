#include "DXUT.h"
#include "cYellowBullet.h"

cYellowBullet::cYellowBullet(Vec2 pos, Vec2 dir, float damage, float size, float speed)
	:cBullet(pos, dir, size), m_speed(speed)
{
	m_Damage = damage;
	RenderSize = m_size / 10;
	bulletType = "mob";
}

cYellowBullet::~cYellowBullet()
{
}

void cYellowBullet::Update()
{
	m_pos += m_Dir * m_speed * Delta;
}

void cYellowBullet::Render()
{
	RENDER->CenterRender(IMAGE->FindImage("yellowbullet"), m_pos, 0, 1.5);
}

#include "DXUT.h"
#include "cBlueBullet.h"

cBlueBullet::cBlueBullet(Vec2 pos, Vec2 dir, float damage, float size, float speed)
	:cBullet(pos, dir, size), m_speed(speed)
{
	m_Damage = damage;
	RenderSize = m_size / 10;
	bulletType = "mob";
	
}

cBlueBullet::~cBlueBullet()
{
}

void cBlueBullet::Update()
{
	m_pos += m_Dir * m_speed * Delta;
}

void cBlueBullet::Render()
{
	RENDER->CenterRender(IMAGE->FindImage("bluebullet"), m_pos, m_angle ,1.5);
}

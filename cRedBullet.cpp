#include "DXUT.h"
#include "cRedBullet.h"

cRedBullet::cRedBullet(Vec2 pos, Vec2 dir, float damage, float size, float speed)
	:cBullet(pos, dir, size), m_speed(speed)
{
	m_Damage = damage;
	RenderSize = m_size / 10;
	bulletType = "mob";
}

cRedBullet::~cRedBullet()
{
}

void cRedBullet::Update()
{
	m_pos.x +=  m_speed * Delta;

}

void cRedBullet::Render()
{
	RENDER->CenterRender(IMAGE->FindImage("redbullet"), m_pos, 0 , 1.5);
}

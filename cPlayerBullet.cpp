#include "DXUT.h"
#include "cPlayerBullet.h"

cPlayerBullet::cPlayerBullet(Vec2 pos, Vec2 dir)
	:cBullet(pos, dir, 10)
{
	bulletType = "player";
}

cPlayerBullet::~cPlayerBullet()
{
	PART->AddParticle(m_pos, 1, 0.01);
}

void cPlayerBullet::Update()
{
	m_pos -= m_Dir * 700 * Delta;
}

void cPlayerBullet::Render()
{
	RENDER->CenterRender(IMAGE->FindImage("playerbullet"), m_pos,0,1.5);
}

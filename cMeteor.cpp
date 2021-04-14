#include "DXUT.h"
#include "cMeteor.h"

cMeteor::cMeteor(Vec2 pos, Vec2 dir, float damage, float size, float speed)
	:cBullet(pos, dir, size), m_speed(speed)
{
	m_Damage = damage;
	RenderSize = m_size / 10;
	bulletType = "mob";
	m_size = 120;
	m_meteor = IMAGE->MakeVecImg("meteor");

}

cMeteor::~cMeteor()
{
}

void cMeteor::Update()
{
	m_pos += m_Dir * m_speed * Delta;
	radian = ((360) * (D3DX_PI / 180.0f));
	Animation();
}

void cMeteor::Render()
{
	//RENDER->CenterRender(IMAGE->FindImage("Moonbullet1"), m_pos, m_angle, RenderSize);
	RENDER->CenterRender(m_meteor[m_frame],Vec2(m_pos.x,m_pos.y-240), radian, 4);
}

void cMeteor::Animation()
{
	if (m_ani != nullptr) m_ani->Update();
	if (m_bOnce)
	{
		m_ani = new cTimer(0.08, [&]()->void {m_frame++; if (m_frame == m_meteor.size()) m_frame = 0; }, 1);
		m_bOnce = false;
	}

}

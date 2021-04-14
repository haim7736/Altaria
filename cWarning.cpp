#include "DXUT.h"
#include "cWarning.h"

cWarning::cWarning(vector<cBullet*>& bullet)
{
	m_meteor = IMAGE->MakeVecImg("warning");
}

cWarning::~cWarning()
{
}

void cWarning::Update()
{
	Animation();
}

void cWarning::Render()
{
	RENDER->CenterRender(m_meteor[m_frame], Vec2(m_pos.x, m_pos.y + 30), 0, 1.5);
}

void cWarning::UIRender()
{
}

void cWarning::Animation()
{
	if (m_ani != nullptr) m_ani->Update();
	if (m_bOnce)
	{
		m_ani = new cTimer(0.08, [&]()->void {m_frame++; if (m_frame == m_meteor.size()) m_frame = 0; }, 1);
		m_bOnce = false;
	}
}

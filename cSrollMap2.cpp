#include "DXUT.h"
#include "cSrollMap2.h"

cSrollMap2::cSrollMap2(cTexture* img)
	:m_scroll(0), m_img(img)
{
}

cSrollMap2::~cSrollMap2()
{
}

void cSrollMap2::Update(float speed)
{
	m_scroll += speed * Delta;
}

void cSrollMap2::Render()
{
	float renderPos = (int)m_scroll % m_img->info.Height;
	RENDER->CenterRender(m_img, Vec2(WINSIZEX / 2, WINSIZEY / 2 + renderPos - m_img->info.Height));
	RENDER->CenterRender(m_img, Vec2(WINSIZEX / 2, WINSIZEY / 2 + renderPos));
}

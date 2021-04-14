#include "DXUT.h"
#include "cSrollMap1.h"

cSrollMap1::cSrollMap1(cTexture* img)
	:m_scroll(0), m_img(img)
{
}

cSrollMap1::~cSrollMap1()
{
}

void cSrollMap1::Update(float speed)
{
	m_scroll += speed * Delta;
}

void cSrollMap1::Render()
{
	float renderPos = (int)m_scroll % m_img->info.Height;
	RENDER->CenterRender(m_img, Vec2(WINSIZEX / 2, WINSIZEY / 2 + renderPos - m_img->info.Height));
	RENDER->CenterRender(m_img, Vec2(WINSIZEX / 2, WINSIZEY / 2 + renderPos));
}

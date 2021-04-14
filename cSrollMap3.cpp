#include "DXUT.h"
#include "cSrollMap3.h"

cSrollMap3::cSrollMap3(cTexture* img)
	:m_scroll(0), m_img(img)
{
}

cSrollMap3::~cSrollMap3()
{
}

void cSrollMap3::Update(float speed)
{
	m_scroll += speed * Delta;
}

void cSrollMap3::Render()
{
	float renderPos = (int)m_scroll % m_img->info.Height;
	RENDER->CenterRender(m_img, Vec2(WINSIZEX / 2, WINSIZEY / 2 + renderPos - m_img->info.Height));
	RENDER->CenterRender(m_img, Vec2(WINSIZEX / 2, WINSIZEY / 2 + renderPos));
}

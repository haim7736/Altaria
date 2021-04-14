#include "DXUT.h"
#include "cPlayerAni.h"

cPlayerAni::cPlayerAni(Vec2 pos, float size, float speed)
	:cParticle(pos, size), anispeed(speed)
{
	m_images = IMAGE->MakeVecImg("playerbu");
	isDestroy = false;
}

cPlayerAni::~cPlayerAni()
{
	SAFE_DELETE(m_ani);
}

void cPlayerAni::Update()
{
	
}

void cPlayerAni::Render()
{
	RENDER->CenterRender(m_images[m_frame], m_pos, 0, RenderSize);
}

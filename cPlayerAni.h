#pragma once
#include "cParticle.h"

class cPlayerAni:
	public cParticle
{
public:
    cPlayerAni(Vec2 pos, float size, float speed);
    virtual ~cPlayerAni();

    vector<cTexture*> m_images;
    cTimer* m_ani = nullptr;
    float anispeed;
    int m_frame = 0;
    bool m_bOnce = true;

    virtual void Update() override;
    virtual void Render() override;
};
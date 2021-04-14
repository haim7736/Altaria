#pragma once
#include "cBullet.h"

class cMeteor : public cBullet
{
public:
    float RenderSize;
    float m_speed;

    vector<cTexture*> m_meteor;
    cTimer* m_ani = nullptr;
    int m_frame = 0;
    float radian;
    bool m_bOnce;

    cMeteor(Vec2 pos, Vec2 dir, float damage, float size = 10, float speed = 1500);
    virtual ~cMeteor();

    // cBullet을(를) 통해 상속됨
    virtual void Update() override;
    virtual void Render() override;
    void Animation();
};





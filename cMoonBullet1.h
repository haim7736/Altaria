#pragma once
#include "cBullet.h"

class cMoonBullet1 : public cBullet
{
public:   
    float RenderSize;
    float m_speed;
    cMoonBullet1(Vec2 pos, Vec2 dir, float damage, float size = 10, float speed = 900);
    virtual ~cMoonBullet1();

    // cBullet��(��) ���� ��ӵ�
    virtual void Update() override;
    virtual void Render() override;
};


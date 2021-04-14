#pragma once
#include "cMob.h"
class cOrangeMob : public cMob
{
public:
    cOrangeMob(Vec2 pos, cPlayer* player);
    virtual ~cOrangeMob();
    bool b_once;

    virtual void Update() override;
    virtual void Render() override;
    virtual void UIRender() override;
};


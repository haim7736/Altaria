#pragma once
#include "cScene.h"
#include "cPlayer.h"
#include "cBulletAdmin.h"
#include "cSrollMap.h"
#include "cMobAdmin.h"
#include "cItemAdmin.h"
#include "cCollision.h"

class cStage2Scene :
    public cScene
{
    cPlayer* player = nullptr;
    cBulletAdmin* bullet = nullptr;
    cSrollMap* map = nullptr;
    cMobAdmin* mob = nullptr;
    cItemAdmin* item = nullptr;
    cCollision* coll = nullptr;
public:
    cStage2Scene();
    virtual ~cStage2Scene();
    // cScene��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void UIRender() override;
    virtual void Release() override;
};


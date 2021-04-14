#pragma once
#include "cScene.h"
#include "cPlayer.h"
#include "cBulletAdmin.h"
#include "cSrollMap.h"
#include "cSrollMap1.h"
#include "cSrollMap2.h"
#include "cSrollMap3.h"
#include "cMobAdmin.h"
#include "cItemAdmin.h"
#include "cCollision.h"

class cStage1Scene :
    public cScene
{
    cPlayer* player = nullptr;
    cBulletAdmin* bullet = nullptr;
    cSrollMap* map = nullptr;
    cSrollMap1* map1 = nullptr;
    cSrollMap2* map2 = nullptr;
    cSrollMap3* map3 = nullptr;
    cMobAdmin* mob = nullptr;
    cItemAdmin* item = nullptr;
    cCollision* coll = nullptr;
	int alpha = 255;
public:
    cStage1Scene();
    virtual ~cStage1Scene();
    // cScene을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void UIRender() override;
    virtual void Release() override;
};


#pragma once
#include "cScene.h"
class cOverScene : 
    public cScene
{

public:
    cOverScene();
    virtual ~cOverScene();
    // cScene��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void UIRender() override;
    virtual void Release() override;
};


#pragma once
#include "cScene.h"
class cEndScene :
	public cScene
{
   
public:
    cEndScene();
    virtual ~cEndScene();
    // cScene��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void UIRender() override;
    virtual void Release() override;
};


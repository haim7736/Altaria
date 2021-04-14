#pragma once
#include "cScene.h"
class cTitleScene :
	public cScene
{
public:
	int select = 1;
	bool option = false;
	bool button = true;
	bool Credits = false;
	Vec2 m_pos;
	Vec2 titlename;
	cTexture* img;
	bool check = true;
	cTitleScene();
	virtual ~cTitleScene();
	
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	virtual void Release() override;
};


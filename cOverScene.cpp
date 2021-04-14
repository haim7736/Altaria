#include "DXUT.h"
#include "cOverScene.h"

cOverScene::cOverScene()
{
}

cOverScene::~cOverScene()
{
}

void cOverScene::Init()
{
}

void cOverScene::Update()
{
	if (INPUT->KeyDown(90) || INPUT->KeyDown(VK_RETURN))
	{
		SCENE->ChangeScene("cTitleScene");
	}
}

void cOverScene::Render()
{
	RENDER->CenterRender(IMAGE->FindImage("gameover"), Vec2(WINSIZEX / 2, WINSIZEY / 2));
}

void cOverScene::UIRender()
{
}

void cOverScene::Release()
{
}

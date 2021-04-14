#include "DXUT.h"
#include "cEndScene.h"

cEndScene::cEndScene()
{
}

cEndScene::~cEndScene()
{
}

void cEndScene::Init()
{
}

void cEndScene::Update()
{
	if (INPUT->KeyDown(90) || INPUT->KeyDown(VK_RETURN))
	{
		SCENE->ChangeScene("cTitleScene");
	}
}

void cEndScene::Render()
{
	
	RENDER->CenterRender(IMAGE->FindImage("gameclear"), Vec2(WINSIZEX / 2, WINSIZEY / 2));

}

void cEndScene::UIRender()
{
}

void cEndScene::Release()
{
}

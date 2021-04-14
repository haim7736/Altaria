#include "DXUT.h"
#include "cTitleScene.h"

cTitleScene::cTitleScene()
{
	img = IMAGE->FindImage("title");
	m_pos = Vec2(400, 500);
	titlename = Vec2(WINSIZEX/2, 120);
}

cTitleScene::~cTitleScene()
{
}

void cTitleScene::Init()
{
	SCENE->PlayerInit();
}

void cTitleScene::Update()
{
	if (m_pos.y >= 500)
	{
		check = false;
	}
	else if (m_pos.y <= 470)
	{
		check = true;
	}
	if (check)
	{
		m_pos.y += 0.2 * DXUTGetElapsedTime() + 0.8 ;
	}
	if (!check)
	{
		m_pos.y -= 0.2 * DXUTGetElapsedTime() + 0.8;
	}

	if (INPUT->KeyDown(VK_DOWN) && select < 4)
	{
		select++;
		option = false;
		Credits = false;
		button = true;
	}
	if (INPUT->KeyDown(VK_UP) && select > 1)
	{
		select--;
		option = false;
		Credits = false;
		button = true;
	}

	switch (select)
	{
	case 1:
		if (INPUT->KeyDown(90)|| INPUT->KeyDown(VK_RETURN))
			SCENE->ChangeScene("cStage1Scene");
		break;
	case 2:
		if (INPUT->KeyDown(90) || INPUT->KeyDown(VK_RETURN))
			Credits = true;
		break;

	case 3:
		if (INPUT->KeyDown(90) || INPUT->KeyDown(VK_RETURN) )
			option = true;
		break;
	case 4:
		if (INPUT->KeyDown(90) || INPUT->KeyDown(VK_RETURN))
			exit(0);
		break;
	default:
		break;
	}
}

void cTitleScene::Render()
{
	RENDER->CenterRender(img, Vec2(WINSIZEX / 2, WINSIZEY / 2));
	RENDER->CenterRender(IMAGE->FindImage("green"), m_pos);
	RENDER->CenterRender(IMAGE->FindImage("titlename1"), titlename);
	RENDER->CenterRender(IMAGE->FindImage("line"), Vec2(1000,680));
	
}

void cTitleScene::UIRender()
{
	
	if (button)
	{
		if (select == 1)
			UI->CenterRender(IMAGE->FindImage("startoff"), Vec2(1205, 525));
		else
			UI->CenterRender(IMAGE->FindImage("starton"), Vec2(1205, 525));
		if (select == 2)
			UI->CenterRender(IMAGE->FindImage("creditoff"), Vec2(1215, 615));
		else
			UI->CenterRender(IMAGE->FindImage("crediton"), Vec2(1215, 615));
		if (select == 3)
			UI->CenterRender(IMAGE->FindImage("optionoff"), Vec2(1170, 705));
		else
			UI->CenterRender(IMAGE->FindImage("optionon"), Vec2(1170, 705));
		if (select == 4)
			UI->CenterRender(IMAGE->FindImage("exitoff"), Vec2(1145, 795));
		else
			UI->CenterRender(IMAGE->FindImage("exiton"), Vec2(1145, 795));
	}
	if (Credits)
	{
		button = false;
		UI->CenterRender(IMAGE->FindImage("Creditimg"), Vec2(WINSIZEX / 2, WINSIZEY / 2));
	}
	if (option)
	{
		button = false;
		UI->CenterRender(IMAGE->FindImage("option"), Vec2(WINSIZEX / 2, WINSIZEY / 2));

	}
}

void cTitleScene::Release()
{
}

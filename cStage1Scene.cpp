#include "DXUT.h"
#include "cStage1Scene.h"

cStage1Scene::cStage1Scene()
{
}

cStage1Scene::~cStage1Scene()
{
	Release();
}

void cStage1Scene::Init()
{
	srand(time(NULL));
	bullet = new cBulletAdmin();
	player = new cPlayer(bullet->b);
	mob = new cMobAdmin(player, bullet->b);
	map = new cSrollMap(IMAGE->FindImage("background"));
	map1 = new cSrollMap1(IMAGE->FindImage("background1"));
	map2 = new cSrollMap2(IMAGE->FindImage("background2"));
	map3 = new cSrollMap3(IMAGE->FindImage("background3"));
	item = new cItemAdmin(player);
	coll = new cCollision(mob->mobs, bullet->b, item, player);
}

void cStage1Scene::Update()
{
	player->Update();
	bullet->Update();
	mob->Update();
	map->Update(100);
	map1->Update(120);
	map2->Update(80);
	map3->Update(50);
	coll->Update();
	if (alpha != 0)
	{
		alpha--;
	}
}

void cStage1Scene::Render()
{
	RENDER->CenterRender(IMAGE->FindImage("back1"), Vec2(WINSIZEX / 2, WINSIZEY / 2));
	map->Render();
	map1->Render();
	map2->Render();
	map3->Render();
	if (player->Score <= limit)
	{
		RENDER->CenterRender(IMAGE->FindImage("limit1"), Vec2(WINSIZEX / 2, 720));
	}
	else
	{
		RENDER->CenterRender(IMAGE->FindImage("limit2"), Vec2(WINSIZEX / 2, 750),0,1.5);
	}
	bullet->Render();
	mob->Render();
	player->Render();
}

void cStage1Scene::UIRender()
{
	player->UIRender();
	mob->UIRender();
	UI->PrintText("Stage1", Vec2(WINSIZEX/2, WINSIZEY/2), 100, 1, D3DCOLOR_RGBA(255,255,255, alpha));
}

void cStage1Scene::Release()
{
	SAFE_DELETE(player);
	SAFE_DELETE(bullet);
	SAFE_DELETE(mob);
	SAFE_DELETE(map);
	SAFE_DELETE(map1);
	SAFE_DELETE(map2);
	SAFE_DELETE(map3);
	SAFE_DELETE(item);
	SAFE_DELETE(coll);
}

#include "DXUT.h"
#include "cStage2Scene.h"

cStage2Scene::cStage2Scene()
{
}

cStage2Scene ::~cStage2Scene()
{
	Release();
}

void cStage2Scene::Init()
{
	srand(time(NULL));
	bullet = new cBulletAdmin();
	map = new cSrollMap(IMAGE->FindImage("background2"));
	player = new cPlayer(bullet->b);
	mob = new cMobAdmin(player, bullet->b);
	map = new cSrollMap(IMAGE->FindImage("background"));
	item = new cItemAdmin(player);
	coll = new cCollision(mob->mobs, bullet->b, item, player);
}

void cStage2Scene::Update()
{
	player->Update();
	bullet->Update();
	mob->Update();
	map->Update(100);
	coll->Update();
}

void cStage2Scene::Render()
{
	RENDER->CenterRender(IMAGE->FindImage("back2"), Vec2(WINSIZEX / 2, WINSIZEY / 2));
	map->Render();
	bullet->Render();
	mob->Render();
	player->Render();
}

void cStage2Scene::UIRender()
{
	player->UIRender();
}

void cStage2Scene::Release()
{
	SAFE_DELETE(player);
	SAFE_DELETE(bullet);
	SAFE_DELETE(mob);
	SAFE_DELETE(map);
	SAFE_DELETE(item);
	SAFE_DELETE(coll);
}

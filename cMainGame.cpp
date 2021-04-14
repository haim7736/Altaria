#include "DXUT.h"
#include "cMainGame.h"
#include "cTitleScene.h"
#include "cStage1Scene.h"
#include "cStage2Scene.h"
#include "cEndScene.h"
#include "cOverScene.h"
cMainGame::cMainGame()
{
}

cMainGame::~cMainGame()
{
}

void cMainGame::Init()
{
	AddResource();
	SCENE->AddScene("cTitleScene", new cTitleScene);
	SCENE->AddScene("cStage1Scene", new cStage1Scene);
	SCENE->AddScene("cStage2Scene", new cStage2Scene);
	SCENE->AddScene("cEndScene", new cEndScene);
	SCENE->AddScene("cOverScene", new cOverScene);

	SCENE->ChangeScene("cTitleScene");
}

void cMainGame::Update()
{
	INPUT->Update();
	SCENE->Update();
	PART->Update();
}

void cMainGame::Render()
{
	SCENE->Render();
	PART->Render();
	UI->Begin();
	SCENE->UIRender();
	UI->End();
}


void cMainGame::Release()
{
	cImageManager::ReleaseInstance();
	cInputManager::ReleaseInstance();
	cRenderManager::ReleaseInstance();
	cParticleManager::ReleaseInstance();
	cSceneManager::ReleaseInstance();
	cUIManager::ReleaseInstance();
}

void cMainGame::LostDevice()
{
	UI->LostDevice();
}

void cMainGame::ResetDevice()
{
	UI->ResetDevice();
}

void cMainGame::AddResource()
{
	//Title
	IMAGE->AddImage("title","Title/title");
	IMAGE->AddImage("exiton", "Title/Quiton");
	IMAGE->AddImage("exitoff", "Title/Quit");
	IMAGE->AddImage("optionon", "Title/Settingon");
	IMAGE->AddImage("optionoff", "Title/Setting");
	IMAGE->AddImage("starton", "Title/starton");
	IMAGE->AddImage("startoff", "Title/start");
	IMAGE->AddImage("crediton", "Title/Crediton");
	IMAGE->AddImage("creditoff", "Title/Credit");
	IMAGE->AddImage("green", "Title/green");
	IMAGE->AddImage("titlename1", "Title/titlename1");
	IMAGE->AddImage("line", "Title/line");
	IMAGE->AddImage("Creditimg", "Title/Creditimg");
	IMAGE->AddImage("option", "Title/option");
	//Map
	IMAGE->AddImage("back1", "Map/back1");
	IMAGE->AddImage("back2", "Map/back2");
	IMAGE->AddImage("background", "Map/mapBackGround");
	IMAGE->AddImage("background1", "Map/mapBackGround1");
	IMAGE->AddImage("background2", "Map/mapBackGround2");
	IMAGE->AddImage("background3", "Map/mapBackGround3");
	IMAGE->AddImage("limit1", "Map/limit1");
	IMAGE->AddImage("limit2", "Map/limit2");
	IMAGE->AddImage("gameover", "Map/GameOver");
	IMAGE->AddImage("gameclear", "Map/GameClear");
	IMAGE->AddImage("themoon", "Map/TheMoon");
	//Player
	IMAGE->AddImage("player", "Player/player");
	IMAGE->AddImage("player", "Player/player");
	//Bullet
	IMAGE->AddImage("playerbullet", "Bullet/playerbullet");
	IMAGE->AddImage("bluebullet", "Bullet/enemyBullet");
	IMAGE->AddImage("redbullet", "Bullet/RedBullet");
	IMAGE->AddImage("purplebullet", "Bullet/PurpleBullet");
	IMAGE->AddImage("yellowbullet", "Bullet/YellowBullet");
	IMAGE->AddImage("Moonbullet1", "Bullet/MoonBullet1");
	IMAGE->AddImage("Moonbullet2", "Bullet/MoonBullet2");
	//Enemy
	IMAGE->AddImage("Blue", "Enemy/Blue");
	IMAGE->AddImage("Red", "Enemy/Red/Red");
	IMAGE->AddImage("Yellow", "Enemy/Yellow/Yellow");
	IMAGE->AddImage("Yellowshield", "Enemy/Yellow/Yellowshield");
	IMAGE->AddImage("Purple", "Enemy/Purple/Purple");
	IMAGE->AddImage("Orange", "Enemy/Orange/Orange");
	IMAGE->AddImage("moon", "Enemy/boss");
	IMAGE->AddImage("MoonHurt", "Enemy/MoonHurt");
	IMAGE->AddImage("MoonAni", "Enemy/MoonAni",5);
	IMAGE->AddImage("Blueani", "Enemy/Blue/BlueAni", 21);
	IMAGE->AddImage("RedAni", "Enemy/Red/RedAni", 47);
	IMAGE->AddImage("PurpleAni", "Enemy/Purple/PurpleAni", 47);
	//Effect
	IMAGE->AddImage("expl", "Effect/expl", 7);
	IMAGE->AddImage("playerbu", "Effect/playerbu", 11);
	IMAGE->AddImage("playermv", "Effect/playermv",3);
	IMAGE->AddImage("meteor", "Meteor/Meteor", 11);
	IMAGE->AddImage("warning", "Meteor/Warning", 9);
	IMAGE->AddImage("meteorline", "Meteor/Line");
	//Hp
	IMAGE->AddImage("hp_frame", "Hp/hp_frame");
	IMAGE->AddImage("hpgauge", "Hp/hpgauge");
	IMAGE->AddImage("plhp_frame", "Hp/plhp_frame");
	IMAGE->AddImage("plhpgauge", "Hp/plhpgauge");

}

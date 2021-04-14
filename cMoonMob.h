#pragma once
#include "cMob.h"
#include "cPlayer.h"
#include "cBullet.h"
class cMoonMob :
	public cMob
{
private:
	cTimer* LS = nullptr;
	int alpha = 100;
	bool is = true;
	bool iis = true;
	bool b_Attack = true;
	bool check;
	cTimer* m_ani = nullptr;
	bool m_bOnce;
	int p1_frame = 0;
	int p2_frame = 0;
	int p3_frame = 0;
	int m_frame = 0;
	vector<cTexture*> m_moon;
	int pattern = 0;
	int i = 0;
	cTimer* Bm = nullptr;
	bool BM = true;

	cTimer* Pm = nullptr;
	bool PP = true;

	cTimer* Mm = nullptr;
	bool MP = true;

	cTimer* AS = nullptr;
	bool pattern1 = false;
	bool pattern2 = false;
	bool pattern3 = false;
	bool ready = true;

public:
    cMoonMob(Vec2 pos, cPlayer* player, vector<cBullet*>& bullet);
    virtual ~cMoonMob();

    Vec2 m_meteor;
	vector<cTexture*> m_moonani;
	vector<cTexture*> m_warning;




    virtual void Update() override;
    virtual void Render() override;
    virtual void UIRender() override;
    void Pattern1();
    void Pattern2();
    void Pattern3();
    void Ready();

    float RenderSize;

    vector<cBullet*>& m_bullet;
	void Animation();
};


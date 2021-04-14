#pragma once
#include "cBullet.h"

class cPlayer
{
public:
	cPlayer(vector<cBullet*>& bullet);
	~cPlayer();
	vector<cBullet*>& m_bullet;
	Vec2 m_pos;

	vector<cTexture*> m_playmv;
	vector<cTexture*> m_playbu;
	string itemTag;
	string MobTag;

	cTimer* m_ani = nullptr;
	cTimer* m_plbu = nullptr;
	bool ch ;
	bool attacksp = true;
	int m_frame = 0;
	int m_framebu = 0;
	bool m_bOnce;
	bool m_bOncebu;
	bool shot = true;
	bool b_spread = false;
	bool b_invincible = false;
	bool livecheck;

	float m_Hp;
	float m_MaxHp;
	float m_AS_b;
	float m_AS_s;
	float m_damage;
	float m_size;
	int	m_Exp;
	int m_MaxExp;

	int Score;
	void Update();
	void Render();
	void UIRender();

	void FireBullet();
	void Move();
	void OutMap();
	void TimerUpdate();
	void TimerDelete();
	void SkillUpdate();
	void SkillRender();
	void ItemUpdate();
	void ScoreUpdate();
	void Cheat();
	void Animation();
};


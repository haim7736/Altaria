#pragma once
#include "cBullet.h"
class cWarning
{
public:
	Vec2 m_pos;
	float m_angle;
	float m_size;


	vector<cTexture*> m_meteor;

	cTimer* m_ani = nullptr;
	int m_frame = 0;
	bool m_bOnce;

	cWarning(vector<cBullet*>& bullet);
	virtual ~cWarning();

	void Update();
	void Render();
	void UIRender();
	void Animation();
};


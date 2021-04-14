#pragma once
class cSrollMap2
{
public:
	cSrollMap2(cTexture* img);
	~cSrollMap2();

	cTexture* m_img;
	float m_scroll;

	void Update(float speed);
	void Render();
};


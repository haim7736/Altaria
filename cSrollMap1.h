#pragma once
class cSrollMap1
{
public:
	cSrollMap1(cTexture* img);
	~cSrollMap1();

	cTexture* m_img;
	float m_scroll;

	void Update(float speed);
	void Render();
};


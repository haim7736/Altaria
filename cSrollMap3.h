#pragma once
class cSrollMap3
{
public:
	cSrollMap3(cTexture* img);
	~cSrollMap3();

	cTexture* m_img;
	float m_scroll;

	void Update(float speed);
	void Render();
};


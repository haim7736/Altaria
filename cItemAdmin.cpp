#include "DXUT.h"
#include "cItemAdmin.h"

cItemAdmin::cItemAdmin(cPlayer* player)
	:m_player(player)
{

}

cItemAdmin::~cItemAdmin()
{
	for (auto iter : m_items) SAFE_DELETE(iter);
	m_items.clear();
}

void cItemAdmin::Update()
{
	for (auto iter : m_items) iter->Update();
	IsOut();
	IsDestroy();
	CreateItem();
	Cheat();
}

void cItemAdmin::Render()
{
	for (auto iter : m_items) iter->Render();
}

void cItemAdmin::IsOut()
{
	size_t size = m_items.size();
	for (size_t i = 0; i < size; i++)
	{
		auto& iter = m_items[i];
		if (iter->IsOutMap())
		{
			SAFE_DELETE(iter);
			m_items.erase(m_items.begin() + i);
			i--; size--;
		}
	}
}

void cItemAdmin::IsDestroy()
{
	size_t size = m_items.size();
	for (size_t i = 0; i < size; i++)
	{
		auto& iter = m_items[i];
		if (iter->isDestroy)
		{
			SAFE_DELETE(iter);
			m_items.erase(m_items.begin() + i);
			i--; size--;
		}
	}
}

void cItemAdmin::CreateItem()
{

}

void cItemAdmin::Cheat()
{
}

#include "pch.h"
#include "World.h"

std::vector<Layer*> World::m_persistanceLayers = {};

World::~World()
{
	for (Layer* layer : m_layers)
	{
		SAFE_DELETE(layer);
	}
}

void World::FixedUpdate()
{
	for (Layer* layer : m_layers)
	{
		if (layer->GetState() == GameState::Active)
			layer->FixedUpdate();
	}
}

void World::PreUpdate()
{
	CreateUpdate();
	Sorting();
	for (Layer* layer : m_layers)
	{
		if (layer->GetState() == GameState::Active)
			layer->PreUpdate();
	}
}

void World::Update()
{
	for (Layer* layer : m_layers)
	{
		if (layer->GetState() == GameState::Active)
			layer->Update();
	}
}

void World::LateUpdate()
{
	for (Layer* layer : m_layers)
	{
		if (layer->GetState() == GameState::Active)
			layer->LateUpdate();
	}
}

void World::Render()
{
	for (auto iter = m_layers.begin(); iter != m_layers.end();)
	{
		if ((*iter)->GetState() == GameState::Destroy)
		{
			m_watingDestructions.push_back(*iter);
			iter = m_layers.erase(iter);
		}
		else
		{
			if ((*iter)->GetState() == GameState::Active)
				(*iter)->Render();
			++iter;
		}
	}
	DestroyUpdate();
}

Layer* World::CreateLayer(std::wstring_view _name, std::wstring_view _tag, int _layerLevel)
{
	Layer* layer = Create<Layer>(_name, _tag, _layerLevel);
	m_layers.push_back(layer);
	return layer;
}

Layer* World::operator[](std::wstring_view _key)
{
	for (Layer* layer : m_layers)
	{
		if (layer->GetName() == _key)
			return layer;
	}
	return nullptr;
}

// 비교 함수 정의
bool CompareLayer(const Layer* layer1, const Layer* layer2)
{
	return layer1->layerLevel < layer2->layerLevel;
}

void World::Sorting()
{
	std::sort(m_layers.begin(), m_layers.end(), CompareLayer);
}

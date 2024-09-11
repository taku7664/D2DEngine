#include "pch.h"
#include "Layer.h"

Layer::Layer(std::wstring_view _name, std::wstring_view _tag, int _layerDepths)
	: Engine::Entity(_name, _tag), layerLevel(_layerDepths)
{
}

Layer::~Layer()
{
}

void Layer::FixedUpdate()
{
}

void Layer::PreUpdate()
{
}

void Layer::Update()
{
}

void Layer::LateUpdate()
{
}

void Layer::Render()
{
}

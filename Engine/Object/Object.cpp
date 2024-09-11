#include "pch.h"
#include "Object.h"

Object::Object(std::wstring_view _key, std::wstring_view _tag, Layer* _ownerLayer)
	: Engine::Entity(_key, _tag)
	, m_ownerLayer(_ownerLayer)
{
}

Object::~Object()
{
	for (auto components : m_components)
	{
		for (auto component : components)
		{
			delete component;
		}
	}
}

void Object::FixedUpdate()
{
}

void Object::PreUpdate()
{
}

void Object::Update()
{
}

void Object::LateUpdate()
{
}

void Object::Render()
{
}

_CALLBACK Object::OnEnable()
{

}

_CALLBACK Object::OnDisable()
{

}

_CALLBACK Object::OnDestroy()
{

}

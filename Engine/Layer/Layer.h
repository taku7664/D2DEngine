#pragma once
#include "Object/Object.h"

class Layer final
	: public Engine::Entity
	, public Engine::ILifeCycle
	, public Engine::Factory
{
public:
	Layer(std::wstring_view _name, std::wstring_view _tag, int _layerDepths = 0);
	virtual ~Layer();

	virtual void FixedUpdate() override;
	virtual void PreUpdate() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;

	int layerLevel; // 레이어 순서
private:
	// list를 쓸지 vector를 쓸지 매우개큰고민중
	std::list<Object*> m_objects;
	//============Layer메소드============
public:
	template <class T>
	T* CreateObject(std::wstring_view _name, std::wstring_view _tag);

	void TakeObjectToThis(Object* _dest) {}
};

template <class T>
T* Layer::CreateObject(std::wstring_view _name, std::wstring_view _tag)
{
	T* object = Create<T>(_name, _tag, this);
	m_objects.push_back(object);
	return object;
}
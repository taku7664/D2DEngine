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

	int layerLevel; // ���̾� ����
private:
	// list�� ���� vector�� ���� �ſ찳ū�����
	std::list<Object*> m_objects;
	//============Layer�޼ҵ�============
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
#pragma once
#include "Layer/Layer.h"

_ABSTRACT World
	: public Engine::Entity
	, public Engine::ILifeCycle
	, public Engine::Factory
{
public:
	World() = default;
	virtual ~World();

	virtual void WorldLoad() = 0;
	virtual void WorldDestroy() = 0;
	virtual void WorldEnter() = 0;
	virtual void WorldExit() = 0;

	virtual void FixedUpdate() override;
	virtual void PreUpdate() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;

	Layer* CreateLayer(std::wstring_view _name, std::wstring_view _tag, int _layerLevel = 0);
	// ���忡�� []�����ڸ� ���� ���̾ �������� ���ҵ�?
	Layer* operator[](std::wstring_view _key);
private:
	// layer�� depth���� �������� ������ �� �ֵ��� ������
	// layer�� ���� ����δ� �ָ� �������ҵ�?
	// ��ũ�帮��Ʈó�� ���� layer�� next,prev�� �˰��ְ� �����? ������ū���
	// https://unluckyjung.github.io/cpp/2020/05/07/Sort_map_by_value/
	std::vector<Layer*> m_layers;
	static std::vector<Layer*> m_persistanceLayers;

	void Sorting();
};
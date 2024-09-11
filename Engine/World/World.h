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
	// 월드에서 []연산자를 통해 레이어를 가져오면 편할듯?
	Layer* operator[](std::wstring_view _key);
private:
	// layer의 depth값을 기준으로 정렬할 수 있도록 만들자
	// layer를 따로 묶어두는 애를 만들어야할듯?
	// 링크드리스트처럼 노드로 layer의 next,prev를 알고있게 만들까? ㅁㄹ개큰고민
	// https://unluckyjung.github.io/cpp/2020/05/07/Sort_map_by_value/
	std::vector<Layer*> m_layers;
	static std::vector<Layer*> m_persistanceLayers;

	void Sorting();
};
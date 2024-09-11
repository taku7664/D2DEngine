#pragma once
#include "World/World.h"

class WorldManager
{
public:
	World* GetCurrentWorld() { return m_curWorld; }
	template <class T>
	T* CreateWorld(const std::wstring& _key, const std::wstring& _tag);
	template <class T>
	T* FindWorld(const std::wstring& _key);
	World* FindWorld(const std::wstring& _key);
	void         DestroyWorld(const std::wstring& _key);
	void         ChangeWorld(const std::wstring& _key);
	void         ChangeWorld(World* _world);
protected:
	World* m_curWorld;
	World* m_nextWorld;
	std::unordered_map<std::wstring, World*> m_worlds;
	std::vector<World*> m_watingDestructionWorlds;
};

template <class T>
T* WorldManager::CreateWorld(const std::wstring& _key, const std::wstring& _tag)
{
	T* world = new T();
	world->SetName(_key);
	world->SetTag(_tag);
	m_worlds[_key] = world;
	return world;
}

template <class T>
T* WorldManager::FindWorld(const std::wstring& _key)
{
	World* baseWorld = FindWorld(_key);
	if (!baseWorld) return nullptr;
	T* world = dynamic_cast<T*>(baseWorld);
	return world;
}

namespace Engine
{
	class WorldCore final
		: public WorldManager
		, public ILifeCycle
	{
	public:
		void Release();
		virtual void FixedUpdate() override;
		virtual void PreUpdate() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;
	private:
	};
}
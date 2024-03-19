#pragma once

#include "entt.hpp"
#include "Violet/Core/Timestep.h"

namespace Violet {
	class Entity;
	class Scene {
	public:
		Scene();
		~Scene();

		Entity CreateEntity(const std::string& name = std::string());
		void DestroyEntity(Entity entity);
		inline entt::registry& Reg() { return m_Registry; }

		void OnUpdate(Timestep timestep);
		void OnViewportResize(uint32_t m_Width, uint32_t m_Height);
	private:
		template<typename T>
		void OnComponentAdded(Entity entity, T& component);
		// void OnComponentAdded(Entity entity, CameraComponent& component);
	private:
		entt::registry m_Registry;
		uint32_t m_ViewportWidth = 0, m_ViewportHeight = 0;

		friend class Entity;
		friend class SceneSerializer;
		friend class SceneHierarchyPanel;
	};
}
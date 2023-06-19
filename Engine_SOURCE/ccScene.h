#pragma once
#include "ccEntity.h"
#include "ccLayer.h"

namespace cc
{
	class Scene : public Entity
	{
	public:
		Scene();
		virtual ~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

		void AddGameObject(eLayerType type, GameObject* gameObj);

	private:
		//std::vector<Layer*> mLayers;
		std::vector<Layer> mLayers;
	};
}
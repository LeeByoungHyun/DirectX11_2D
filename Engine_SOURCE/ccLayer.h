#pragma once
#include "ccGameObject.h"

namespace cc
{
	class Layer
	{
	public:
		Layer();
		~Layer();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
		virtual void Destory();
		virtual void Subjoin();

		void AddGameObject(GameObject* gameObj);
		const std::vector<GameObject*> GetGameObjects() { return mGameObjects; }
		void ClearGameObject();

	private:
		std::vector<GameObject*> mGameObjects;
		std::set<GameObject*> addGameObj;
	};
}
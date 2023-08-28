#pragma once
#include "ccScene.h"

namespace cc
{
	class SceneManager
	{
	public:
		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render();
		static void Destroy();
		static void Subjoin();
		static void Release();

		template <typename T>
		static bool CreateScene(std::wstring name)
		{
			T* scene = new T();

			std::map<std::wstring, Scene*>::iterator iter
				= mScenes.find(name);

			if (iter != mScenes.end())
				return false;

			mScenes.insert(std::make_pair(name, scene));
			mActiveScene = scene;
			scene->Initialize();
			return true;
		}

		static Scene* LoadScene(std::wstring name);
		static Scene* ChangeScene();
		static Scene* GetNextScene() { return nextScene; }
		static Scene* GetActiveScene() { return mActiveScene; }
		static void SetActiveScene(Scene* scene) { mActiveScene = scene; }

	private:
		static Scene* mActiveScene;
		static Scene* nextScene;
		static std::map<std::wstring, Scene*> mScenes;
	};
}
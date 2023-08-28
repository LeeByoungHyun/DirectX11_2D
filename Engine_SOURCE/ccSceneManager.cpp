#include "ccSceneManager.h"
#include "ccInput.h"

namespace cc
{
	Scene* SceneManager::mActiveScene = nullptr;
	Scene* SceneManager::nextScene = nullptr;
	std::map<std::wstring, Scene*> SceneManager::mScenes;

	void SceneManager::Initialize()
	{
		
	}

	void SceneManager::Update()
	{
		mActiveScene->Update();
	}

	void SceneManager::LateUpdate()
	{
		mActiveScene->LateUpdate();
	}

	void SceneManager::Render()
	{
		mActiveScene->Render();
	}

	void SceneManager::Destroy()
	{
		mActiveScene->Destroy();
	}

	void SceneManager::Subjoin()
	{
		mActiveScene->Subjoin();
	}

	void SceneManager::Release()
	{
		for (auto& iter : mScenes)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}

	Scene* SceneManager::LoadScene(std::wstring name)
	{
		std::map<std::wstring, Scene*>::iterator iter
			= mScenes.find(name);
		
		if (iter == mScenes.end())
			return nullptr;
		
		//mActiveScene->OnExit();
		//mActiveScene = iter->second;
		//mActiveScene->OnEnter();

		nextScene = iter->second;
		
		return iter->second;
	}

	Scene* SceneManager::ChangeScene()
	{
		mActiveScene->OnExit();
		mActiveScene = nextScene;
		mActiveScene->OnEnter();

		nextScene = nullptr;

		return mActiveScene;
	}
}
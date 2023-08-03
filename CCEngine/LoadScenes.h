#pragma once
#include "..\Engine_SOURCE\ccSceneManager.h"

#include "ccTestScene.h"
#include "SurfaceScene.h"
#include "TitleScene.h"
#include "MenuScene.h"
#include "PlayScene.h"

#ifdef _DEBUG
#pragma comment(lib, "..\\x64\\Debug\\CCEngine.lib")
#else
#pragma comment(lib, "..\\x64\\Release\\CCEngine.lib")
#endif


namespace cc
{
	void InitializeScenes()
	{
		SceneManager::CreateScene<TestScene>(L"TestScene");

		SceneManager::CreateScene<SurfaceScene>(L"SurfaceScene");
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<MenuScene>(L"MenuScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");

		//SceneManager::LoadScene(L"SurfaceScene");
		SceneManager::LoadScene(L"TestScene");
	}
}
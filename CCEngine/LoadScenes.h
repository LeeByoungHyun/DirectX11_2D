#pragma once
#include "..\Engine_SOURCE\ccSceneManager.h"

#include "SurfaceScene.h"
#include "TitleScene.h"
#include "MenuScene.h"

#ifdef _DEBUG
#pragma comment(lib, "..\\x64\\Debug\\CCEngine.lib")
#else
#pragma comment(lib, "..\\x64\\Release\\CCEngine.lib")
#endif


namespace cc
{
	void InitializeScenes()
	{
		SceneManager::CreateScene<SurfaceScene>(L"SurfaceScene");
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<MenuScene>(L"MenuScene");

		SceneManager::LoadScene(L"SurfaceScene");
	}
}
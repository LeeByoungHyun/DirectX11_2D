#pragma once
#include "..\Engine_SOURCE\ccSceneManager.h"
#include "ccTitleScene.h"
#include "ccTutorialScene.h"

#ifdef _DEBUG
#pragma comment(lib, "..\\x64\\Debug\\CCEngine.lib")
#else
#pragma comment(lib, "..\\x64\\Release\\CCEngine.lib")
#endif


namespace cc
{
	void InitializeScenes()
	{
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<TutorialScene>(L"TutorialScene");

		SceneManager::LoadScene(L"TitleScene");
	}
}
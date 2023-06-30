#pragma once
#include "..\Engine_SOURCE\ccSceneManager.h"
#include "ccTitleScene.h"

#ifdef _DEBUG
#pragma comment(lib, "..\\x64\\Debug\\CCEngine.lib")
#else
#pragma comment(lib, "..\\x64\\Release\\CCEngine.lib")
#endif



namespace cc
{
	void InitializeScenes()
	{
		//PlayScene* playScene = new PlayScene();
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
	}
}
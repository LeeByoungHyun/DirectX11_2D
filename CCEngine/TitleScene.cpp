#include "TitleScene.h"
#include "ccTransform.h"
#include "ccMeshRenderer.h"
#include "ccResourceManager.h"
#include "ccMesh.h"
#include "ccCameraScript.h"
#include "ccCamera.h"
#include "ccInput.h"
#include "ccSceneManager.h"
#include "ccObject.h"
#include "ccRenderer.h"

#include "MenuTitle.h"
#include "MenuTitleGal.h"

namespace cc
{
	TitleScene::TitleScene()
	{

	}

	TitleScene::~TitleScene()
	{

	}

	void TitleScene::Initialize()
	{
		Scene* mActiveScene = SceneManager::GetActiveScene();

		{
			MenuTitle* title = object::Instantiate<MenuTitle>(eLayerType::BG);
			title->SetName(L"menutitle");
		}

		{
			MenuTitleGal* titlegal = object::Instantiate<MenuTitleGal>(eLayerType::BG);
			titlegal->SetName(L"menuTitleGal");
			Transform* tr = titlegal->GetComponent<Transform>();
			tr->AddPosition(Vector3(-55.0f, -5.0f, 0.0f));
		}

		// Main Camera
		Camera* cameraComp = nullptr;
		{
			GameObject* camera = new GameObject();
			AddGameObject(eLayerType::UI, camera);
			camera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
			cameraComp = camera->AddComponent<Camera>();
			cameraComp->TurnLayerMask(eLayerType::UI, false);
			renderer::cameras.push_back(cameraComp);
			renderer::mainCamera = cameraComp;
			//camera->AddComponent<CameraScript>();
		}

		// UI Camera
		{
			GameObject* camera = new GameObject();
			AddGameObject(eLayerType::UI, camera);
			camera->GetComponent<Transform>()->SetPosition(Vector3(100000.0f, 100000.0f, -10.0f));
			Camera* cameraComp = camera->AddComponent<Camera>();
			cameraComp->TurnLayerMask(eLayerType::Player, false);
			//camera->AddComponent<CameraScript>();
		}
	}

	void TitleScene::Update()
	{
		Scene::Update();

		if (Input::GetKeyDown(eKeyCode::P))
		{
			SceneManager::LoadScene(L"MenuScene");
		}
	}

	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void TitleScene::Render()
	{
		Scene::Render();
	}
}
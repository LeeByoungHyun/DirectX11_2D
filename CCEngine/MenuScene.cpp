#include "MenuScene.h"
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

#include "BaseSkyNight.h"
#include "MainDoorBack.h"
#include "MainDirt.h"
#include "MainDoorFrame.h"
#include "MainFore2.h"
#include "MainFore1.h"
#include "MainFore11.h"
#include "MainFore21.h"
#include "MainFore22.h"
#include "MainFore12.h"

namespace cc
{
	MenuScene::MenuScene()
	{

	}

	MenuScene::~MenuScene()
	{

	}

	void MenuScene::Initialize()
	{
		Scene* mActiveScene = SceneManager::GetActiveScene();

		{
			BaseSkyNight* bg = object::Instantiate<BaseSkyNight>(eLayerType::BG);
			bg->SetName(L"BaseSkyNight");
		} 

		{
			MainDoorBack* doorback = object::Instantiate<MainDoorBack>(eLayerType::BG);
			doorback->SetName(L"menuTitleGal");
			Transform* tr = doorback->GetComponent<Transform>();
			//tr->AddPosition(Vector3(-55.0f, -5.0f, 0.0f));
		}

		{
			MainDirt* dirt = object::Instantiate<MainDirt>(eLayerType::BG);
			dirt->SetName(L"dirt");
			Transform* tr = dirt->GetComponent<Transform>();
			tr->AddPosition(Vector3(0.0f, -40.0f, 0.0f));
		}

		{
			MainDoorFrame* doorframe = object::Instantiate<MainDoorFrame>(eLayerType::BG);
			doorframe->SetName(L"doorframe");
			Transform* tr = doorframe->GetComponent<Transform>();
			//tr->AddPosition(Vector3(0.0f, -40.0f, 0.0f));
		}

		{
			MainFore21* mainfore21 = object::Instantiate<MainFore21>(eLayerType::BG);
			mainfore21->SetName(L"mainfore21");
			Transform* tr = mainfore21->GetComponent<Transform>();
			tr->AddPosition(Vector3(-70.0f, 0.0f, 0.0f));
		}

		{
			MainFore22* mainfore22 = object::Instantiate<MainFore22>(eLayerType::BG);
			mainfore22->SetName(L"mainfore22");
			Transform* tr = mainfore22->GetComponent<Transform>();
			tr->AddPosition(Vector3(70.0f, 0.0f, 0.0f));
		}

		{
			MainFore11* mainfore11 = object::Instantiate<MainFore11>(eLayerType::BG);
			mainfore11->SetName(L"mainfore11");
			Transform* tr = mainfore11->GetComponent<Transform>();
			tr->AddPosition(Vector3(-80.0f, 0.0f, 0.0f));
		}

		{
			MainFore12* mainfore12 = object::Instantiate<MainFore12>(eLayerType::BG);
			mainfore12->SetName(L"mainfore12");
			Transform* tr = mainfore12->GetComponent<Transform>();
			tr->AddPosition(Vector3(80.0f, 0.0f, 0.0f));
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

	void MenuScene::Update()
	{
		Scene::Update();

		if (Input::GetKeyDown(eKeyCode::P))
		{
			SceneManager::LoadScene(L"PlayScene");
		}
	}

	void MenuScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void MenuScene::Render()
	{
		Scene::Render();
	}
}
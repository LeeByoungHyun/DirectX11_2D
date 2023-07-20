#include "SurfaceScene.h"
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
#include "BaseSurface01.h"
#include "BaseSurface2_01.h"
#include "BaseSurface02.h"
#include "BaseSurface03.h"
#include "BaseSurface2_02.h"
#include "BaseSurface04.h"

namespace cc
{
	SurfaceScene::SurfaceScene()
	{

	}

	SurfaceScene::~SurfaceScene()
	{

	}

	void SurfaceScene::Initialize()
	{
		Scene* mActiveScene = SceneManager::GetActiveScene();

		// BG
		BaseSkyNight* bg = object::Instantiate<BaseSkyNight>(eLayerType::BG);
		bg->SetName(L"BaseSkyNight");

		BaseSurface2_01* bg2 = object::Instantiate<BaseSurface2_01>(eLayerType::BG);
		bg2->SetName(L"TitleBG2");

		{
			{
				BaseSurface02* surface02 = object::Instantiate<BaseSurface02>(eLayerType::BG);
				surface02->SetName(L"Surface02_0");
				Transform* tr = surface02->GetComponent<Transform>();
				tr->AddPosition(Vector3(-60.0f, -10.0f, 0.0f));
			}

			{
				BaseSurface02* surface02 = object::Instantiate<BaseSurface02>(eLayerType::BG);
				surface02->SetName(L"Surface02_1");
				Transform* tr = surface02->GetComponent<Transform>();
				tr->AddPosition(Vector3(93.5f, -10.0f, 0.0f));
			}
		}

		{
			{
				BaseSurface03* surface03 = object::Instantiate<BaseSurface03>(eLayerType::BG);
				surface03->SetName(L"Surface03_0");
				Transform* tr = surface03->GetComponent<Transform>();
				tr->AddPosition(Vector3(-60.0f, -20.0f, 0.0f));
			}

			{
				BaseSurface03* surface03 = object::Instantiate<BaseSurface03>(eLayerType::BG);
				surface03->SetName(L"Surface03_1");
				Transform* tr = surface03->GetComponent<Transform>();
				tr->AddPosition(Vector3(93.5f, -20.0f, 0.0f));
			}
		}

		{
			BaseSurface2_02* bgStatue = object::Instantiate<BaseSurface2_02>(eLayerType::BG);
			bgStatue->SetName(L"bgStatue");
			Transform* tr = bgStatue->GetComponent<Transform>();
			tr->AddPosition(Vector3(20.0f, -10.0f, 0.0f));
		}

		{
			{
				BaseSurface04* surface04 = object::Instantiate<BaseSurface04>(eLayerType::BG);
				surface04->SetName(L"Surface04_0");
				Transform* tr = surface04->GetComponent<Transform>();
				tr->AddPosition(Vector3(-60.0f, -35.0f, 0.0f));
			}

			{
				BaseSurface04* surface04 = object::Instantiate<BaseSurface04>(eLayerType::BG);
				surface04->SetName(L"Surface04_1");
				Transform* tr = surface04->GetComponent<Transform>();
				tr->AddPosition(Vector3(93.5f, -35.0f, 0.0f));
			}
		}

		//{
		//	BaseSurface01* surface01 = object::Instantiate<BaseSurface01>(eLayerType::FrontObject);
		//	surface01->SetName(L"Surface04_0");
		//	Transform* tr = surface01->GetComponent<Transform>();
		//	tr->AddPosition(Vector3(0.0f, -30.0f, 0.0f));
		//}



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

	void SurfaceScene::Update()
	{
		Scene::Update();

		if (Input::GetKeyDown(eKeyCode::P))
		{
			SceneManager::LoadScene(L"TitleScene");
		}
	}

	void SurfaceScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void SurfaceScene::Render()
	{
		Scene::Render();
	}
}
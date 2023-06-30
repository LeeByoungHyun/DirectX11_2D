#include "ccTestScene.h"
#include "ccTransform.h"
#include "ccMeshRenderer.h"
#include "ccResourceManager.h"
#include "ccMesh.h"
#include "ccCameraScript.h"
#include "ccCamera.h"

namespace cc
{
	TestScene::TestScene()
	{

	}

	TestScene::~TestScene()
	{

	}

	void TestScene::Initialize()
	{
		{
			GameObject* player = new GameObject();
			player->SetName(L"Zelda");
			AddGameObject(eLayerType::Player, player);
			MeshRenderer* mr = player->AddComponent<MeshRenderer>();
			mr->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(ResourceManager::Find<Material>(L"TitleWords"));
			player->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 2.0f, 0.0f));
			player->GetComponent<Transform>()->SetScale(Vector3(8.72f, 2.78f, 0.0f));
			//player->AddComponent<CameraScript>();
		}

		{
			GameObject* player = new GameObject();
			player->SetName(L"Smile");
			AddGameObject(eLayerType::UI, player);
			MeshRenderer* mr = player->AddComponent<MeshRenderer>();
			mr->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(ResourceManager::Find<Material>(L"TitleBG"));
			player->GetComponent<Transform>()->SetPosition(Vector3(0.0f, -1.0f, 0.0f));
			player->GetComponent<Transform>()->SetScale(Vector3(11.5 * 2.0f, 7.1f * 2.0f, 0.0f));
			//player->AddComponent<CameraScript>();
		}

		// Main Camera
		{
			GameObject* camera = new GameObject();
			AddGameObject(eLayerType::Player, camera);
			camera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
			Camera* cameraComp = camera->AddComponent<Camera>();
			cameraComp->TurnLayerMask(eLayerType::UI, false);
			camera->AddComponent<CameraScript>();
		}

		// UI Camera
		{
			GameObject* camera = new GameObject();
			AddGameObject(eLayerType::Player, camera);
			camera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
			Camera* cameraComp = camera->AddComponent<Camera>();
			cameraComp->TurnLayerMask(eLayerType::Player, false);
			//camera->AddComponent<CameraScript>();
		}
	}

	void TestScene::Update()
	{
		Scene::Update();
	}

	void TestScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void TestScene::Render()
	{
		Scene::Render();
	}
}

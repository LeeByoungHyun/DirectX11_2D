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
			AddGameObject(eLayerType::Player, player);
			MeshRenderer* mr = player->AddComponent<MeshRenderer>();
			mr->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(ResourceManager::Find<Material>(L"SpriteMaterial"));
			player->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
			//player->AddComponent<CameraScript>();
		}

		{
			GameObject* player = new GameObject();
			AddGameObject(eLayerType::Player, player);
			MeshRenderer* mr = player->AddComponent<MeshRenderer>();
			mr->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(ResourceManager::Find<Material>(L"SpriteMaterial02"));
			player->GetComponent<Transform>()->SetPosition(Vector3(2.0f, 0.0f, 0.0f));
			//player->AddComponent<CameraScript>();
		}

		//Main Camera
		GameObject* camera = new GameObject();
		AddGameObject(eLayerType::Player, camera);
		camera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		camera->AddComponent<CameraScript>();
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

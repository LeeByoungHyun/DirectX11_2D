#include "ccTitleScene.h"
#include "ccTransform.h"
#include "ccMeshRenderer.h"
#include "ccResourceManager.h"
#include "ccMesh.h"
#include "ccCameraScript.h"
#include "ccCamera.h"

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
		{
			GameObject* object = new GameObject();
			AddGameObject(eLayerType::Player, object);
			MeshRenderer* mr = object->AddComponent<MeshRenderer>();
			mr->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(ResourceManager::Find<Material>(L"TitleWords"));
			object->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 2.0f, 0.0f));
			object->GetComponent<Transform>()->SetScale(Vector3(8.72f, 2.78f, 0.0f));
		}

		{
			GameObject* object = new GameObject();
			AddGameObject(eLayerType::Player, object);
			MeshRenderer* mr = object->AddComponent<MeshRenderer>();
			mr->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(ResourceManager::Find<Material>(L"TitleBG"));
			object->GetComponent<Transform>()->SetPosition(Vector3(0.0f, -1.0f, 0.0f));
			object->GetComponent<Transform>()->SetScale(Vector3(11.5 * 1.9f, 7.1f * 1.9f, 0.0f));

		}

		//Main Camera
		GameObject* camera = new GameObject();
		AddGameObject(eLayerType::UI, camera);
		camera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		camera->AddComponent<CameraScript>();
	}

	void TitleScene::Update()
	{
		Scene::Update();
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

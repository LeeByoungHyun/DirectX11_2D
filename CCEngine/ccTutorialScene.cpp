#include "ccTutorialScene.h"
#include "ccTransform.h"
#include "ccMeshRenderer.h"
#include "ccResourceManager.h"
#include "ccMesh.h"
#include "ccCameraScript.h"
#include "ccCamera.h"

namespace cc
{
	TutorialScene::TutorialScene()
	{

	}

	TutorialScene::~TutorialScene()
	{

	}

	void TutorialScene::Initialize()
	{
		{
			GameObject* object = new GameObject();
			AddGameObject(eLayerType::Player, object);
			MeshRenderer* mr = object->AddComponent<MeshRenderer>();
			mr->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(ResourceManager::Find<Material>(L"marine"));
			object->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
			object->GetComponent<Transform>()->SetScale(Vector3(0.24f * 3.0f, 0.27f * 3.0f, 0.0f));
		}

		//Main Camera
		GameObject* camera = new GameObject();
		AddGameObject(eLayerType::UI, camera);
		camera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		camera->AddComponent<CameraScript>();
	}

	void TutorialScene::Update()
	{
		Scene::Update();
	}

	void TutorialScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void TutorialScene::Render()
	{
		Scene::Render();
	}
}

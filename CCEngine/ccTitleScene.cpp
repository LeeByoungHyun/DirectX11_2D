/*
#include "ccTitleScene.h"
#include "ccTransform.h"
#include "ccMeshRenderer.h"
#include "ccResourceManager.h"
#include "ccMesh.h"
#include "ccCameraScript.h"
#include "ccCamera.h"
#include "ccInput.h"
#include "ccSceneManager.h"

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
			object->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 1.0f, 0.0f));
			object->GetComponent<Transform>()->SetScale(Vector3(0.872f * 3.0f, 0.278f * 3.0f, 0.0f));
		}

		{
			GameObject* object = new GameObject();
			AddGameObject(eLayerType::Player, object);
			MeshRenderer* mr = object->AddComponent<MeshRenderer>();
			mr->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(ResourceManager::Find<Material>(L"TitleBG"));
			object->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 100.0f));
			object->GetComponent<Transform>()->SetScale(Vector3(11.5 * 0.7f, 7.1f * 0.7f, 0.0f));

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

		if (Input::GetKeyDown(eKeyCode::P))
		{
			SceneManager::LoadScene(L"TutorialScene");
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
*/
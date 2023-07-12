#include "ccTutorialScene.h"
#include "ccTransform.h"
#include "ccMeshRenderer.h"
#include "ccResourceManager.h"
#include "ccMesh.h"
#include "ccCameraScript.h"
#include "ccCamera.h"
#include "ccMouseScript.h"
#include "ccPlayerMoveScript.h"
#include "ccInput.h"
#include "ccObject.h"
#include "ccSceneManager.h"
#include "ccRenderer.h"

#include "Marine.h"
#include "AimCursor.h"

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
		Scene::Initialize();
		Scene* scene = SceneManager::GetActiveScene();

		// Map
		mapTest = object::Instantiate<GameObject>(eLayerType::Map);
		mapTest->AddComponent<MeshRenderer>();
		mapTest->GetComponent<MeshRenderer>()->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		mapTest->GetComponent<MeshRenderer>()->SetMaterial(ResourceManager::Find<Material>(L"mapTest"));
		mapTest->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 100.0f));
		mapTest->GetComponent<Transform>()->SetScale(Vector3(5.76f, 4.32f, 0.0f));

		// player
		//marine = object::Instantiate<Marine>(eLayerType::Player);
		marine = Marine::GetInstance();
		marine->SetName(L"Marine");
		object::Instantiate(marine, eLayerType::Player);
		
		// mouse cursor
		mouse = object::Instantiate<AimCursor>(eLayerType::UI);
		mouse->SetName(L"Mouse");
		
		//Main Camera
		camera = new GameObject();
		AddGameObject(eLayerType::UI, camera);
		camera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		camera->AddComponent<CameraScript>();
		renderer::cameras.push_back(cameraComp);

		/*
		// 부모자식 테스트
		GameObject* player2 = new GameObject();
		player2->SetName(L"MarineChild");
		AddGameObject(eLayerType::Player, player2);
		MeshRenderer* mr2 = player2->AddComponent<MeshRenderer>();
		mr2->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		mr2->SetMaterial(ResourceManager::Find<Material>(L"marine"));
		player2->GetComponent<Transform>()->SetPosition(Vector3(1.0f, 0.0f, 1.0001f));

		player2->GetComponent<Transform>()->SetParent(marine->GetComponent<Transform>());
		//player->AddComponent<CameraScript>();

		float radian = math::DegreeToRadian(0);
		marine->GetComponent<Transform>()->SetRotation(Vector3(0.0f, 0.0f, radian));
		*/
	}

	void TutorialScene::Update()
	{
		Scene::Update();
	}

	void TutorialScene::LateUpdate()
	{
		Scene::LateUpdate();

		// 카메라 위치 플레이어 위치로
		// 나중에 카메라 스크립트로 이동 임시
		Vector3 pos = marine->GetComponent<Transform>()->GetPosition();
		camera->GetComponent<Transform>()->SetPosition(Vector3(pos.x, pos.y, -10.0f));
	}

	void TutorialScene::Render()
	{
		Scene::Render();
	}
}

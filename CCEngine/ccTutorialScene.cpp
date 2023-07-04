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
		// Map
		mapTest = new GameObject();
		mapTest->SetName(L"MapTest");
		AddGameObject(eLayerType::Map, mapTest);
		mapTest->AddComponent<MeshRenderer>();
		mapTest->GetComponent<MeshRenderer>()->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		mapTest->GetComponent<MeshRenderer>()->SetMaterial(ResourceManager::Find<Material>(L"mapTest"));
		mapTest->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 100.0f));
		mapTest->GetComponent<Transform>()->SetScale(Vector3(5.76f, 4.32f, 0.0f));
		
		// player
		marine = new GameObject();
		marine->SetName(L"Marine");
		AddGameObject(eLayerType::Player, marine);
		marine->AddComponent<MeshRenderer>();
		marine->GetComponent<MeshRenderer>()->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		marine->GetComponent<MeshRenderer>()->SetMaterial(ResourceManager::Find<Material>(L"marine"));
		marine->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
		marine->GetComponent<Transform>()->SetScale(Vector3(0.24f, 0.27f, 0.0f));
		marine->AddComponent<PlayerMoveScript>();

		// mouse cursur
		mouse = new GameObject();
		mouse->SetName(L"Mouse");
		AddGameObject(eLayerType::UI, mouse);
		mouse->AddComponent<MeshRenderer>();
		mouse->GetComponent<MeshRenderer>()->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		mouse->GetComponent<MeshRenderer>()->SetMaterial(ResourceManager::Find<Material>(L"Aim"));
		Vector2 mousePos = Input::GetMousePos();
		mouse->GetComponent<Transform>()->SetPosition(Vector3(mousePos.x, mousePos.y, -100.0f));
		//mouse->GetComponent<Transform>()->SetPosition(Vector3(1.0f, 1.0f, -100.0f));
		mouse->GetComponent<Transform>()->SetScale(Vector3(0.2f, 0.2f, 0.0f));
		mouse->AddComponent<MouseScript>();

		//Main Camera
		camera = new GameObject();
		AddGameObject(eLayerType::UI, camera);
		camera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		camera->AddComponent<CameraScript>();

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

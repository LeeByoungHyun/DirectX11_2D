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
#include "ccCollisionManager.h"

#include "Marine.h"
#include "AimCursor.h"
#include "TestGun.h"
#include "Heart.h"
#include "Blank.h"

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
		//mouse = object::Instantiate<AimCursor>(eLayerType::UI);
		mouse = AimCursor::GetInstance();
		mouse->SetName(L"Mouse");
		object::Instantiate(mouse, eLayerType::Player);
	
		// Test Gun
		testGun = object::Instantiate<TestGun>(eLayerType::Player);
		testGun->SetName(L"TestGun");
		testGun->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));


		// UI
		// �Ŵ��� ���� ���� �����ؾ� �� ������ �ӽ�
		Heart* heart1 = object::Instantiate<Heart>(eLayerType::UI);
		heart1->GetComponent<Transform>()->SetPosition(Vector3(100000.0f - 3.8f, 100000.0f + 2.0f, 100.0f));
		heart1->GetComponent<Transform>()->SetScale(Vector3(0.13f, 0.11f, 0.0f));

		Heart* heart2 = object::Instantiate<Heart>(eLayerType::UI);
		heart2->GetComponent<Transform>()->SetPosition(Vector3(100000.0f - 3.65f, 100000.0f + 2.0f, 100.0f));
		heart2->GetComponent<Transform>()->SetScale(Vector3(0.13f, 0.11f, 0.0f));

		Heart* heart3 = object::Instantiate<Heart>(eLayerType::UI);
		heart3->GetComponent<Transform>()->SetPosition(Vector3(100000.0f - 3.50f, 100000.0f + 2.0f, 100.0f));
		heart3->GetComponent<Transform>()->SetScale(Vector3(0.13f, 0.11f, 0.0f));

		Blank* blank1 = object::Instantiate<Blank>(eLayerType::UI);
		blank1->GetComponent<Transform>()->SetPosition(Vector3(100000.0f - 3.8f, 100000.0f + 1.85f, 100.0f));
		blank1->GetComponent<Transform>()->SetScale(Vector3(0.12f, 0.12f, 0.0f));
		
		// Main Camera
		//camera = new GameObject();
		//AddGameObject(eLayerType::UI, camera);
		//camera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
		//Camera* cameraComp = camera->AddComponent<Camera>();
		//camera->AddComponent<CameraScript>();
		//renderer::cameras.push_back(cameraComp);

		// Main Camera
		Camera* cameraComp = nullptr;
		{
			GameObject* camera = new GameObject();
			AddGameObject(eLayerType::UI, camera);
			camera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
			cameraComp = camera->AddComponent<Camera>();
			cameraComp->TurnLayerMask(eLayerType::UI, false);
			camera->AddComponent<CameraScript>();
			renderer::cameras.push_back(cameraComp);
			renderer::mainCamera = cameraComp;
		}

		// UI Camera
		{
			GameObject* camera = new GameObject();
			AddGameObject(eLayerType::Player, camera);
			camera->GetComponent<Transform>()->SetPosition(Vector3(100000.0f, 100000.0f, -10.0f));
			Camera* cameraComp = camera->AddComponent<Camera>();
			cameraComp->TurnLayerMask(eLayerType::Player, false);
			//camera->AddComponent<CameraScript>();
		}

		/*
		// �θ��ڽ� �׽�Ʈ
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
	}

	void TutorialScene::Render()
	{
		Scene::Render();
	}

	void TutorialScene::OnEnter()
	{
		// CollisionManager
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::UI, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Player, true);
		CollisionManager::SetLayer(eLayerType::UI, eLayerType::Player, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Player, true);
	}

	void TutorialScene::OnExit()
	{

	}
}

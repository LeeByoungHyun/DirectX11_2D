#include "ccTestScene.h"
#include "ccTransform.h"
#include "ccMeshRenderer.h"
#include "ccResourceManager.h"
#include "ccMesh.h"
#include "ccCameraScript.h"
#include "ccCamera.h"
#include "ccCollider2D.h"
#include "ccRenderer.h"
#include "ccSceneManager.h"
#include "ccInput.h"
#include "ccObject.h"

#include "Player.h"
#include "Whip.h"
#include "CaveBG.h"

namespace cc
{
	TestScene::TestScene()
	{
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"rink.png", L"..\\Resources\\Texture\\Old\\link.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Transparent);
			ResourceManager::Insert(L"rink", spriteMateiral);
		}
	}

	TestScene::~TestScene()
	{

	}

	void TestScene::Initialize()
	{
		//{
		//	GameObject* player = new GameObject();
		//	player->SetName(L"Zelda");
		//	AddGameObject(eLayerType::Player, player);
		//	MeshRenderer* mr = player->AddComponent<MeshRenderer>();
		//	mr->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		//	mr->SetMaterial(ResourceManager::Find<Material>(L"rink"));
		//	player->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
		//	player->GetComponent<Transform>()->SetScale(Vector3(2.0f, 2.0f, 0.0f));
		//	Collider2D* cd = player->AddComponent<Collider2D>();
		//	cd->SetSize(Vector2(2.0f, 2.0f));
		//	//player->AddComponent<CameraScript>();
		//}

		Whip* sdf = object::Instantiate<Whip>(eLayerType::Weapon);
		sdf->GetComponent<Transform>()->SetPosition(0.0f, 0.0f, 0.0f);

		//Player* asdas = Player::GetInstance();
		//object::Instantiate(asdas, eLayerType::Player);
		//asdas->GetComponent<Transform>()->SetPosition(0.0f, 0.0f, 0.0f);
		//asdas->GetComponent<Transform>()->SetScale(1.0f, 1.0f, 1.0f);

		//CaveBG* bg = object::Instantiate<CaveBG>(eLayerType::BG);
		//bg->SetName(L"caveBG");

		// Main Camera
		{
			GameObject* camera = new GameObject();
			AddGameObject(eLayerType::Player, camera);
			camera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
			Camera* cameraComp = camera->AddComponent<Camera>();
			cameraComp->TurnLayerMask(eLayerType::UI, false);
			//camera->AddComponent<CameraScript>();
			renderer::cameras.push_back(cameraComp);
			renderer::mainCamera = cameraComp;
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

		if (Input::GetKeyDown(eKeyCode::P))
		{
			SceneManager::LoadScene(L"PlayScene");
		}
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

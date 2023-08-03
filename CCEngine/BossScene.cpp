#include "BossScene.h"
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

//#include "PxPhysicsAPI.h"

#include "Player.h"
#include "Whip.h"
#include "CaveBG.h"
#include "CaveDirt.h"
#include "BorderTile.h"

namespace cc
{
	extern const float TILESIZE;
	extern const float BGSIZE;
	extern const float BGDEPTH;
	extern const float TILEDEPTH;
	extern const float PLAYERDEPTH;
	extern const float MASKINGDIST;
	extern const int MAPCOLUMN;
	extern const int MAPROW;

	BossScene::BossScene()
	{
		// ∏  ∫§≈Õ √ ±‚»≠
		map.resize(MAPCOLUMN);
		for (UINT i = 0; i < map.size(); i++)
			map[i].resize(MAPROW);

		mapTile.resize(MAPCOLUMN);
		for (UINT i = 0; i < mapTile.size(); i++)
			mapTile[i].resize(MAPROW);

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

	BossScene::~BossScene()
	{

	}

	void BossScene::Initialize()
	{
		Scene::Initialize();

		//CreateMap();

		{
			GameObject* player = new GameObject();
			player->SetName(L"rink");
			AddGameObject(eLayerType::Monster, player);
			MeshRenderer* mr = player->AddComponent<MeshRenderer>();
			mr->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(ResourceManager::Find<Material>(L"rink"));
			player->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 1.0f));
			Collider2D* cd = player->AddComponent<Collider2D>();
			//cd->SetSize(Vector2(1.2f, 1.2f));
			//player->AddComponent<PlayerScript>();
		}

		// Main Camera
		Camera* cameraComp = nullptr;
		{
			GameObject* camera = new GameObject();
			AddGameObject(eLayerType::UI, camera);
			camera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -100.0f));
			cameraComp = camera->AddComponent<Camera>();
			cameraComp->TurnLayerMask(eLayerType::UI, false);
			renderer::cameras.push_back(cameraComp);
			renderer::mainCamera = cameraComp;
			camera->AddComponent<CameraScript>();
		}

		// UI Camera
		{
			GameObject* camera = new GameObject();
			AddGameObject(eLayerType::UI, camera);
			camera->GetComponent<Transform>()->SetPosition(Vector3(100000.0f, 100000.0f, -10.0f));
			Camera* cameraComp = camera->AddComponent<Camera>();
			cameraComp->TurnLayerMask(eLayerType::Player, false);
		}
	}

	void BossScene::Update()
	{
		Scene::Update();

		if (Input::GetKeyDown(eKeyCode::P))
		{
			SceneManager::LoadScene(L"PlayScene");
		}
	}

	void BossScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void BossScene::Render()
	{
		Scene::Render();
	}

	void BossScene::CreateMap()
	{
		
	}

	void BossScene::MaskingTile()
	{

	}

}
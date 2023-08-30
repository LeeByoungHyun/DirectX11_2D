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
#include "ccCollisionManager.h"

#include "Player.h"
#include "CaveBG.h"
#include "CaveDirt.h"
#include "Wood.h"
#include "BorderTile.h"
#include "Whip.h"
#include "CaveMan.h"
#include "OlmecSeal.h"
#include "Olmec.h"
#include "ScreenCollider.h"
#include "MainCamera.h"
#include "UICamera.h"
#include "PlayerCheckGroundCollider.h"
#include "PlayerCheckOnPlatformCollider.h"
#include "CaveEntrance.h"
#include "CaveExit.h"
#include "Platform.h"

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

	TestScene::TestScene()
	{
		mainCamera = nullptr;
		TileDestroyedFlag = false;

		entrancePos = Vector2::Zero;
	}

	TestScene::~TestScene()
	{

	}

	void TestScene::Initialize()
	{
		Scene::Initialize();

		// 맵 생성
		CreateLevel();
	}

	void TestScene::Update()
	{
		Scene::Update();

		// 이전 프레임에서 타일이 파괴되었으면 타일 마스킹
		if (TileDestroyedFlag == true)
		{
			TileDestroyedFlag = false; 
			MaskingTile();
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

	void TestScene::OnEnter()
	{
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Tile, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Platform, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Monster, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Entrance, true);
		CollisionManager::SetLayer(eLayerType::Monster, eLayerType::Tile, true);
		CollisionManager::SetLayer(eLayerType::Weapon, eLayerType::Monster, true);
		CollisionManager::SetLayer(eLayerType::Tile, eLayerType::PlayerCheck, true);
		CollisionManager::SetLayer(eLayerType::PlayerCheck, eLayerType::Tile, true);
		CollisionManager::SetLayer(eLayerType::PlayerCheck, eLayerType::Platform, true);

		// 시작 위치로 플레이어 위치 설정
		Player::GetInstance()->GetComponent<Transform>()->SetPosition(Vector3(entrancePos.x, entrancePos.y - TILESIZE / 2, PLAYERDEPTH));
		mainCamera->GetComponent<Transform>()->SetPosition(Vector3(entrancePos.x, entrancePos.y - TILESIZE / 2, -10.0f));
	}

	void TestScene::OnExit()
	{
		ResetMap();
		CreateLevel();
	}

	void TestScene::CreatePath()
	{
		// 경로 생성 알고리즘 


	}

	void TestScene::CreateLevel()
	{
		Vector3 bgStartPos = Vector3(-BGSIZE * 10, BGSIZE, 0.0f);	// BG LeftTop
		Vector3 tileStartPos = Vector3(-TILESIZE * 10, TILESIZE, 0.0f);	// Tile LeftTop

		// BG
		for (UINT i = 0; i < 20; i++)
		{
			for (UINT j = 0; j < 20; j++)
			{
				CaveBG* bg = object::Instantiate<CaveBG>(eLayerType::BG);
				bg->SetName(L"caveBG");
				Transform* tr = bg->GetComponent<Transform>();
				tr->AddPosition(Vector3(bgStartPos.x + (BGSIZE * j), bgStartPos.y - (BGSIZE * i), 0.0f));
			}
		}

		// 맵은 (10 * 8)사이즈의 방 이 (4 * 4)로 배치되어 있는 형태
		// 배열을 사용하여 블럭 배치

		// 0 = 빈칸
		// 1 = 흙
		// 2 = 나무
		// 3 = 사다리
		// 4 = 플랫폼
		// 5 = 떨어지는 박스
		// 6 = caveman
		// 9 = border
		// 98 = entrence
		// 99 = exit

		// test

		// 맵 벡터 초기화
		map.resize(MAPCOLUMN);
		for (UINT i = 0; i < map.size(); i++)
			map[i].resize(MAPROW);

		mapTile.resize(MAPCOLUMN);
		for (UINT i = 0; i < mapTile.size(); i++)
			mapTile[i].resize(MAPROW);

		std::vector<std::vector<int>> test =
		{
			{ 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9 },
			{ 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9 },
			{ 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9 },
			{ 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9 },
			{ 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9 },
			{ 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9 },
			{ 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9 },
			{ 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9 },
			{ 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9 },
			{ 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9 },
			{ 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9 },
			{ 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9 },
			{ 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9 },
			{ 9, 9, 0, 0, 98, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9 },
			{ 9, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9, 9 },
			{ 9, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9, 9 },
			{ 9, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9, 9 },
			{ 9, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9, 9 },
			{ 9, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9, 9 },
			{ 9, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9, 9 },
			{ 9, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9, 9 },
			{ 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9 },
			{ 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9 },
			{ 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9 },
			{ 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9 },
			{ 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9 },
			{ 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9 },
			{ 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9 },
			{ 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9 },
			{ 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9 },
			{ 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99, 0, 0, 9, 9 },
			{ 9, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9, 9 },
			{ 9, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9, 9 },
			{ 9, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9, 9 },
			{ 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9 },
			{ 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9 },
		};

		copy(test.begin(), test.end(), map.begin());

		//std::memcpy(map, test, sizeof(test));


		/*
		int map[8][10] =
		{
			{ 1, 1, 1, 1, 0, 0, 1, 1, 1, 1},
			{ 1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
			{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
		};
		*/

		// 배열에 저장된 값에 따라 맵 생성
		for (UINT col = 0; col < MAPCOLUMN; col++)
		{
			for (UINT row = 0; row < MAPROW; row++)
			{
				if (map[col][row] != 0)
				{
					if (map[col][row] == 9)	// border
					{
						BorderTile* border = object::Instantiate<BorderTile>(eLayerType::Tile);
						mapTile[col][row] = border;
						border->SetColPos(col);
						border->SetRowPos(row);
						border->SetName(L"border");
						Transform* tr = border->GetComponent<Transform>();
						tr->SetPosition(Vector3(tileStartPos.x + (TILESIZE * row), tileStartPos.y - (TILESIZE * col), TILEDEPTH));
					}

					else if (map[col][row] == 1)	// dirt
					{
						CaveDirt* dirt = object::Instantiate<CaveDirt>(eLayerType::Tile);
						dirt->SetName(L"dirt");
						mapTile[col][row] = dirt;
						dirt->SetColPos(col);
						dirt->SetRowPos(row);
						Transform* tr = dirt->GetComponent<Transform>();
						tr->SetPosition(Vector3(tileStartPos.x + (TILESIZE * row), tileStartPos.y - (TILESIZE * col), TILEDEPTH));
					}

					else if (map[col][row] == 3)	// wood
					{
						Wood* wood = object::Instantiate<Wood>(eLayerType::Tile);
						wood->SetName(L"wood");
						wood->SetColPos(col);
						wood->SetRowPos(row);
						Transform* tr = wood->GetComponent<Transform>();
						tr->SetPosition(Vector3(tileStartPos.x + (TILESIZE * row), tileStartPos.y - (TILESIZE * col), TILEDEPTH));
					}

					else if (map[col][row] == 6)	// caveman
					{
						CaveMan* caveman = object::Instantiate<CaveMan>(eLayerType::Monster);
						caveman->SetName(L"caveman");
						Transform* tr = caveman->GetComponent<Transform>();
						tr->SetPosition(Vector3(tileStartPos.x + (TILESIZE * row), tileStartPos.y - (TILESIZE * col), PLAYERDEPTH));
					}

					else if (map[col][row] == 98)	// entrence
					{
						CaveEntrance* entrance = object::Instantiate<CaveEntrance>(eLayerType::Entrance);
						entrance->SetName(L"entrance");
						Transform* tr = entrance->GetComponent<Transform>();
						tr->SetPosition(Vector3(tileStartPos.x + (TILESIZE * row), tileStartPos.y - (TILESIZE * col) + (TILESIZE / 2), 0.0f));

						// 플랫폼 생성
						//Platform* platform = object::Instantiate<Platform>(eLayerType::Platform);
						//tr = platform->GetComponent<Transform>();
						//tr->SetPosition(Vector3(tileStartPos.x + (TILESIZE * row), tileStartPos.y - (TILESIZE * col) + (TILESIZE / 2), -0.01f));

						// 시작위치 저장
						entrancePos.x = tr->GetPosition().x;
						entrancePos.y = tr->GetPosition().y;
					}

					else if (map[col][row] == 99)	// exit
					{
						CaveExit* exit = object::Instantiate<CaveExit>(eLayerType::Entrance);
						exit->SetName(L"entrance");
						Transform* tr = exit->GetComponent<Transform>();
						tr->SetPosition(Vector3(tileStartPos.x + (TILESIZE * row), tileStartPos.y - (TILESIZE * col) + (TILESIZE / 2), 0.0f));
					}
				}
			}
		}

		MaskingTile();

		// test
		Player* player = Player::GetInstance();
		player->SetName(L"Player");
		object::Instantiate(player, eLayerType::Player);
		player->GetComponent<Transform>()->AddPosition(Vector3(TILESIZE * 5, -TILESIZE * 12, 0.0f));
		object::Instantiate<PlayerCheckPosition>(eLayerType::PlayerCheck);
		object::Instantiate<PlayerCheckOnPlatformCollider>(eLayerType::PlayerCheck);

		Olmec* olmec = object::Instantiate<Olmec>(eLayerType::Monster);
		olmec->GetComponent<Transform>()->SetPosition(Vector3(TILESIZE * 15, -TILESIZE * 10, 0.0f));
		olmec->GetComponent<Transform>()->AddPosition(Vector3(0.0f, -TILESIZE / 2.0f, 0.0f));

		// Camera
		mainCamera = object::Instantiate<MainCamera>(eLayerType::UI);
		mainCamera->AddComponent<CameraScript>();
		object::Instantiate<UICamera>(eLayerType::Player);
	}

	void TestScene::ResetMap()
	{
		// 현재 씬에 존재하는 모든 오브젝트 제거
		// 다시 CreateMap 호출하여 새로운 Level 생성

		GameObject* test;
		std::vector<Layer>& layers = GetLayers();
		// 오브젝트 제거
		for (Layer& layer : layers)
		{
			//auto gameObjs = layer.GetGameObjects();
			//for (GameObject* obj : gameObjs)
			//{
			//	test = obj;
			//	object::Destroy(obj);
			//}

			layer.ClearGameObject();
		}

		// 새로운 Level 생성
		int a = 0;
	}

	void TestScene::MaskingTile()
	{
		// masking check
		for (UINT col = 0; col < MAPCOLUMN; col++)
		{
			for (UINT row = 0; row < MAPROW; row++)
			{
				if (map[col][row] != 0)
				{
					if (map[col][row] == 9)	// border
					{
						// 타일의 4방향을 조사하여 같은 종류의 타일이 없으면 마스킹
						int checkCol;
						int checkRow;

						// top
						checkCol = col - 1;
						checkRow = row;
						if (checkCol < 0)
							mapTile[col][row]->SetMask(0, true);
						else if (map[checkCol][checkRow] != 9)
							mapTile[col][row]->SetMask(0, true);

						// right
						checkCol = col;
						checkRow = row + 1;
						if (checkRow >= MAPROW)
							mapTile[col][row]->SetMask(1, true);
						else if (map[checkCol][checkRow] != 9)
							mapTile[col][row]->SetMask(1, true);

						// bottom
						checkCol = col + 1;
						checkRow = row;
						if (checkCol >= MAPCOLUMN)
							mapTile[col][row]->SetMask(2, true);
						else if (map[checkCol][checkRow] != 9)
							mapTile[col][row]->SetMask(2, true);

						// left
						checkCol = col;
						checkRow = row - 1;
						if (checkRow < 0)
							mapTile[col][row]->SetMask(3, true);
						else if (map[checkCol][checkRow] != 9)
							mapTile[col][row]->SetMask(3, true);
					}

					if (map[col][row] == 1)	// dirt
					{
						// 타일의 4방향을 조사하여 같은 종류의 타일이 없으면 마스킹
						int checkCol;
						int checkRow;

						// top
						checkCol = col - 1;
						checkRow = row;
						if (map[checkCol][checkRow] != 1 && map[checkCol][checkRow] != 9 && checkCol >= 0)
							mapTile[col][row]->SetMask(0, true);

						// right
						checkCol = col;
						checkRow = row + 1;
						if (map[checkCol][checkRow] != 1 && map[checkCol][checkRow] != 9 && checkRow < MAPROW)
							mapTile[col][row]->SetMask(1, true);

						// bottom
						checkCol = col + 1;
						checkRow = row;
						if (map[checkCol][checkRow] != 1 && map[checkCol][checkRow] != 9 && checkCol < MAPCOLUMN)
							mapTile[col][row]->SetMask(2, true);

						// left
						checkCol = col;
						checkRow = row - 1;
						if (map[checkCol][checkRow] != 1 && map[checkCol][checkRow] != 9 && checkRow >= 0)
							mapTile[col][row]->SetMask(3, true);

						int a = 0;
					}
				}
			}
		}

		// masking
		for (UINT col = 0; col < MAPCOLUMN; col++)
		{
			for (UINT row = 0; row < MAPROW; row++)
			{
				if (mapTile[col][row] == 0)
					continue;

				for (UINT dir = 0; dir < 4; dir++)
				{
					if (mapTile[col][row]->GetMask(dir) == true)
					{
						mapTile[col][row]->Masking(dir);
					}
				}
			}
		}
	}
}

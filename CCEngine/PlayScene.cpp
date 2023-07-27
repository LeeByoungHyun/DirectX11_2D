#include "PlayScene.h"
#include "ccTransform.h"
#include "ccMeshRenderer.h"
#include "ccResourceManager.h"
#include "ccMesh.h"
#include "ccCameraScript.h"
#include "ccCamera.h"
#include "ccInput.h"
#include "ccSceneManager.h"
#include "ccObject.h"
#include "ccRenderer.h"

#include "Player.h"
#include "CaveBG.h"
#include "CaveDirt.h"
#include "Wood.h"
#include "BorderTile.h"

namespace cc
{
	//const float TILESIZE = 15.36f;
	//const float BGSIZE = 61.44f;
	const float TILESIZE = 128.0f;
	const float BGSIZE = 512.0f;

	const float BGDEPTH = 100.0f;
	const float TILEDEPTH = 90.0f;

	PlayScene::PlayScene()
	{

	}

	PlayScene::~PlayScene()
	{

	}

	void PlayScene::Initialize()
	{
		Scene* mActiveScene = SceneManager::GetActiveScene();

		// 맵 생성
		CreateMap();


		Player* player = Player::GetInstance();
		player->SetName(L"Player");
		object::Instantiate(player, eLayerType::Player);
		player->GetComponent<Transform>()->AddPosition(Vector3(TILESIZE * 20, -TILESIZE * 32, 0.0f));

		// Main Camera
		Camera* cameraComp = nullptr;
		{
			GameObject* camera = new GameObject();
			AddGameObject(eLayerType::UI, camera);
			camera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -1100.0f));
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
			//camera->AddComponent<CameraScript>();
		}
	}
	
	void PlayScene::Update()
	{
		Scene::Update();

		if (Input::GetKeyDown(eKeyCode::P))
		{
			//SceneManager::LoadScene(L"TutorialScene");
		}
	}

	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void PlayScene::Render()
	{
		Scene::Render();
	}

	void PlayScene::CreatePath()
	{
		// 맵 배치 배열 4*4로 초기화
		mapPath.resize(4);
		for (UINT i = 0; i < mapPath.size(); i++)
			mapPath[i].resize(4);

		// 0 = 보조 방
		// 1 = 좌우가 열린 방
		// 2 = 좌우, 하단이 열린 방
		// 3 = 좌우, 상단이 열린 방
		// 4 = 시작 방
		// 5 = 출구 방

		// 4 * 4개의 방이 하나의 맵을 구성
		// 입구방은 반드시 최상단에 존재하며 출구방은 반드시 최하단에 존재
		// 입구에서 출구로 이어지는 경로가 반드시 존재해야 함
		
		
		// 시작 지점 결정
		std::random_device rd;
		std::mt19937 rng(rd());
		std::uniform_int_distribution<int> genEnter(0, 3);
		int enter = genEnter(rng);
		mapPath[0][enter] = 4;

		// 층별로 방 배치
		// 입구방 우선 배치 후 입구방에서 시작하는 경로 생성
		// 각 층에는 반드시 아래로 내려갈 수 있는 방이 1개 존재
		// 
		



		// 1층이 생성되었으면 2
	}

	void PlayScene::CreateMap()
	{
		Vector3 bgStartPos = Vector3(-BGSIZE * 5, BGSIZE, 0.0f);	// BG LeftTop
		Vector3 tileStartPos = Vector3(-TILESIZE * 5, TILESIZE, 0.0f);	// Tile LeftTop

		// BG
		for (UINT i = 0; i < 30; i++)
		{
			for (UINT j = 0; j < 30; j++)
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
		// 3 = 나무
		// 3 = 사다리
		// 4 = 플랫폼
		// 5 = 떨어지는 박스
		// 6 = 
		// 9 = border

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
			{ 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9 },
			{ 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9 },
			{ 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9 },
			{ 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9 },
			{ 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9 },
			{ 9, 9, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9 },
			{ 9, 9, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9 },
			{ 9, 9, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9 },
			{ 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9 },
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
						BorderTile* border = object::Instantiate<BorderTile>(eLayerType::BackObject);
						mapTile[col][row] = border;
						border->SetName(L"border");
						Transform* tr = border->GetComponent<Transform>();
						tr->SetPosition(Vector3(tileStartPos.x + (TILESIZE * row), tileStartPos.y - (TILESIZE * col), TILEDEPTH));
					}

					else if (map[col][row] == 1)	// dirt
					{
						CaveDirt* dirt = object::Instantiate<CaveDirt>(eLayerType::BackObject);
						dirt->SetName(L"dirt");
						mapTile[col][row] = dirt;
						Transform* tr = dirt->GetComponent<Transform>();
						tr->SetPosition(Vector3(tileStartPos.x + (TILESIZE * row), tileStartPos.y - (TILESIZE * col), TILEDEPTH));
					}

					else if (map[col][row] == 3)	// wood
					{
						Wood* wood = object::Instantiate<Wood>(eLayerType::BackObject);
						wood->SetName(L"wood");
						Transform* tr = wood->GetComponent<Transform>();
						tr->SetPosition(Vector3(tileStartPos.x + (TILESIZE * row), tileStartPos.y - (TILESIZE * col), TILEDEPTH));
					}
					
				}
			}
		}

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

	void PlayScene::MaskingTile()
	{
		for (UINT i = 0; i < 32; i++)
		{
			for (UINT j = 0; j < 40; j++)
			{
				// 흙 타일
				// 위에 흙 타일이 존재하지 않는 타일
				
				// 왼쪽에 흙 타일이 존재하지 않는 타일

				// 오른쪽에 흙 타일이 존재하지 않는 타일

				// 아래쪽에 흙 타일이 존재하지 않는 타일

				// border
				
			}
		}
	}
}
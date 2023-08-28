#include "NextLevelScene.h"
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
#include "CaveEntrance.h"
#include "CaveExit.h"


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

    NextLevelScene::NextLevelScene()
    {
        map.resize(12);
        for (UINT i = 0; i < map.size(); i++)
            map[i].resize(22);

        mapTile.resize(12);
        for (UINT i = 0; i < mapTile.size(); i++)
            mapTile[i].resize(22);
    }

    NextLevelScene::~NextLevelScene()
    {

    }

    void NextLevelScene::Initialize()
    {
        Scene::Initialize();
        
        CreateLevel();

        // Camera
        MainCamera* mainCamera = object::Instantiate<MainCamera>(eLayerType::UI);
        mainCamera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, -5.0f, -10.0f));
        object::Instantiate<UICamera>(eLayerType::Player);
    }

    void NextLevelScene::Update()
    {
        Scene::Update();
    }

    void NextLevelScene::LateUpdate()
    {
        Scene::LateUpdate();
    }

    void NextLevelScene::Render()
    {
        Scene::Render();
    }

    void NextLevelScene::OnEnter()
    {
        Scene::OnEnter();

        Player::GetInstance()->GetComponent<Transform>()->SetPosition(Vector3(TILESIZE * -8, -TILESIZE * 8, 0.0f));
    }

    void NextLevelScene::OnExit()
    {
        Scene::OnExit();
    }

    void NextLevelScene::CreateLevel()
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

        std::vector<std::vector<int>> test =
        {
            { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
            { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
            { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
            { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
            { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
            { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
            { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
            { 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1 },
            { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
            { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
            { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
            { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
          };

        copy(test.begin(), test.end(), map.begin());

        //std::memcpy(map, test, sizeof(test));

        // 배열에 저장된 값에 따라 맵 생성
        for (UINT col = 0; col < 12; col++)
        {
            for (UINT row = 0; row < 22; row++)
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

                }
            }
        }

        MaskingTile();

        // test
        Player* player = Player::GetInstance();
        player->SetName(L"Player");
        object::Instantiate(player, eLayerType::Player);
        //player->GetComponent<Transform>()->AddPosition(Vector3(TILESIZE * 5, -TILESIZE * 8, 0.0f));
        PlayerCheckPosition* pcgc = object::Instantiate<PlayerCheckPosition>(eLayerType::PlayerCheck);

        CaveEntrance* testEntrance = object::Instantiate<CaveEntrance>(eLayerType::Entrance);
        testEntrance->GetComponent<Transform>()->SetPosition(Vector3(TILESIZE * -8, -TILESIZE * 8 + (TILESIZE / 2), 0.0f));

        CaveExit* testExit = object::Instantiate<CaveExit>(eLayerType::Entrance);
        testExit->GetComponent<Transform>()->SetPosition(Vector3(TILESIZE * 9, -TILESIZE * 8 + (TILESIZE / 2), 0.0f));
    }

    void NextLevelScene::MaskingTile()
    {
        // masking check
        for (UINT col = 0; col < 12; col++)
        {
            for (UINT row = 0; row < 22; row++)
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
                        if (checkRow >= 22)
                            mapTile[col][row]->SetMask(1, true);
                        else if (map[checkCol][checkRow] != 9)
                            mapTile[col][row]->SetMask(1, true);

                        // bottom
                        checkCol = col + 1;
                        checkRow = row;
                        if (checkCol >= 12)
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
                        if (checkCol < 0)
                            mapTile[col][row]->SetMask(0, true);
                        else if (map[checkCol][checkRow] != 1 && map[checkCol][checkRow] != 9 && checkCol >= 0)
                            mapTile[col][row]->SetMask(0, true);

                        // right
                        checkCol = col;
                        checkRow = row + 1;
                        if (checkRow >= 22)
                            mapTile[col][row]->SetMask(1, true);
                        else if (map[checkCol][checkRow] != 1 && map[checkCol][checkRow] != 9 && checkRow < 22)
                            mapTile[col][row]->SetMask(1, true);

                        // bottom
                        checkCol = col + 1;
                        checkRow = row;
                        if (checkCol >= 12)
                            mapTile[col][row]->SetMask(2, true);
                        else if (map[checkCol][checkRow] != 1 && map[checkCol][checkRow] != 9 && checkCol < 12)
                            mapTile[col][row]->SetMask(2, true);

                        // left
                        checkCol = col;
                        checkRow = row - 1;
                        if (checkRow < 0)
                            mapTile[col][row]->SetMask(3, true);
                        else if (map[checkCol][checkRow] != 1 && map[checkCol][checkRow] != 9 && checkRow >= 0)
                            mapTile[col][row]->SetMask(3, true);

                        int a = 0;
                    }
                }
            }
        }

        // masking
        for (UINT col = 0; col < 12; col++)
        {
            for (UINT row = 0; row < 22; row++)
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
#include "ccTestScene.h"
#include "ccTransform.h"
#include "ccMeshRenderer.h"

namespace cc
{
	TestScene::TestScene()
	{

	}

	TestScene::~TestScene()
	{

	}

	void TestScene::Initialize()
	{
		GameObject* player = new GameObject();
		AddGameObject(eLayerType::Player, player);
		player->AddComponent<MeshRenderer>();

		//GameObject* player2 = new GameObject();
		//AddGameObject(eLayerType::Player, player2);
		//player2->AddComponent<MeshRenderer>();

		//Transform* tr = player->GetComponent<Transform>();
		//tr->SetPosition(Vector3(0.5f, 0.5f, 0.0f));
	}

	void TestScene::Update()
	{
		Scene::Update();
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

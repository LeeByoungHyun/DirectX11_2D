#include "MainDirt.h"
#include "ccResourceManager.h"

namespace cc
{
	MainDirt::MainDirt()
	{

	}

	MainDirt::~MainDirt()
	{

	}

	void MainDirt::Initialize()
	{
		GameObject::Initialize();

		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"main_dirt.png", L"..\\Resources\\Texture\\menu\\main_dirt.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"MainDirt", spriteMateiral);
		}

		mMeshRenderer = AddComponent<MeshRenderer>();
		mMeshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"MainDirt"));

		mTransform = GetComponent<Transform>();
		mTransform->SetPosition(Vector3(0.0f, 0.0f, 99.0f));
		mTransform->SetScale(Vector3(1024.0f, 256.0f, 0.0f) * 0.12f);

		// script
	}

	void MainDirt::Update()
	{
		GameObject::Update();
	}

	void MainDirt::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void MainDirt::Render()
	{
		GameObject::Render();
	}
}
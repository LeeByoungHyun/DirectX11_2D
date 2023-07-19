#include "MainFore1.h"
#include "ccResourceManager.h"

namespace cc
{
	MainFore1::MainFore1()
	{

	}

	MainFore1::~MainFore1()
	{

	}

	void MainFore1::Initialize()
	{
		GameObject::Initialize();

		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"main_fore1.png", L"..\\Resources\\Texture\\menu\\main_fore1.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"MainFore1", spriteMateiral);
		}

		mMeshRenderer = AddComponent<MeshRenderer>();
		mMeshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"MainFore1"));

		mTransform = GetComponent<Transform>();
		mTransform->SetPosition(Vector3(0.0f, 0.0f, 95.0f));
		mTransform->SetScale(Vector3(1024.0f, 1080.0f, 0.0f) * 0.12f);

		// script
	}

	void MainFore1::Update()
	{
		GameObject::Update();
	}

	void MainFore1::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void MainFore1::Render()
	{
		GameObject::Render();
	}
}
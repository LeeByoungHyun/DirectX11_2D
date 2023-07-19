#include "MainFore12.h"
#include "ccResourceManager.h"

namespace cc
{
	MainFore12::MainFore12()
	{

	}

	MainFore12::~MainFore12()
	{

	}

	void MainFore12::Initialize()
	{
		GameObject::Initialize();

		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"main_fore1_2.png", L"..\\Resources\\Texture\\menu\\main_fore1_2.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"MainFore12", spriteMateiral);
		}

		mMeshRenderer = AddComponent<MeshRenderer>();
		mMeshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"MainFore12"));

		mTransform = GetComponent<Transform>();
		mTransform->SetPosition(Vector3(0.0f, 0.0f, 95.0f));
		mTransform->SetScale(Vector3(512.0f, 1080.0f, 0.0f) * 0.12f);

		// script
	}

	void MainFore12::Update()
	{
		GameObject::Update();
	}

	void MainFore12::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void MainFore12::Render()
	{
		GameObject::Render();
	}
}
#include "MainFore2.h"
#include "ccResourceManager.h"

namespace cc
{
	MainFore2::MainFore2()
	{

	}

	MainFore2::~MainFore2()
	{

	}

	void MainFore2::Initialize()
	{
		GameObject::Initialize();

		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"main_fore2.png", L"..\\Resources\\Texture\\menu\\main_fore2.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"MainFore2", spriteMateiral);
		}

		mMeshRenderer = AddComponent<MeshRenderer>();
		mMeshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"MainFore2"));

		mTransform = GetComponent<Transform>();
		mTransform->SetPosition(Vector3(0.0f, 0.0f, 96.0f));
		mTransform->SetScale(Vector3(1536.0f, 1080.0f, 0.0f) * 0.12f);

		// script
	}

	void MainFore2::Update()
	{
		GameObject::Update();
	}

	void MainFore2::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void MainFore2::Render()
	{
		GameObject::Render();
	}
}
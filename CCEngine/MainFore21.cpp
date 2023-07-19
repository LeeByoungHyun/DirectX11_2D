#include "MainFore21.h"
#include "ccResourceManager.h"

namespace cc
{
	MainFore21::MainFore21()
	{

	}

	MainFore21::~MainFore21()
	{

	}

	void MainFore21::Initialize()
	{
		GameObject::Initialize();

		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"main_fore21.png", L"..\\Resources\\Texture\\menu\\main_fore21.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"MainFore21", spriteMateiral);
		}

		mMeshRenderer = AddComponent<MeshRenderer>();
		mMeshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"MainFore21"));

		mTransform = GetComponent<Transform>();
		mTransform->SetPosition(Vector3(0.0f, 0.0f, 96.0f));
		mTransform->SetScale(Vector3(768.0f, 1080.0f, 0.0f) * 0.12f);

		// script
	}

	void MainFore21::Update()
	{
		GameObject::Update();
	}

	void MainFore21::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void MainFore21::Render()
	{
		GameObject::Render();
	}
}
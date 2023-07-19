#include "MainFore22.h"
#include "ccResourceManager.h"

namespace cc
{
	MainFore22::MainFore22()
	{

	}

	MainFore22::~MainFore22()
	{

	}

	void MainFore22::Initialize()
	{
		GameObject::Initialize();

		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"main_fore22.png", L"..\\Resources\\Texture\\menu\\main_fore22.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"MainFore22", spriteMateiral);
		}

		mMeshRenderer = AddComponent<MeshRenderer>();
		mMeshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"MainFore22"));

		mTransform = GetComponent<Transform>();
		mTransform->SetPosition(Vector3(0.0f, 0.0f, 96.0f));
		mTransform->SetScale(Vector3(768.0f, 1080.0f, 0.0f) * 0.12f);

		// script
	}

	void MainFore22::Update()
	{
		GameObject::Update();
	}

	void MainFore22::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void MainFore22::Render()
	{
		GameObject::Render();
	}
}
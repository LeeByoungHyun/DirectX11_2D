#include "MainFore11.h"
#include "ccResourceManager.h"

namespace cc
{
	MainFore11::MainFore11()
	{

	}

	MainFore11::~MainFore11()
	{

	}

	void MainFore11::Initialize()
	{
		GameObject::Initialize();

		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"main_fore1_1.png", L"..\\Resources\\Texture\\menu\\main_fore1_1.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"MainFore11", spriteMateiral);
		}

		mMeshRenderer = AddComponent<MeshRenderer>();
		mMeshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"MainFore11"));

		mTransform = GetComponent<Transform>();
		mTransform->SetPosition(Vector3(0.0f, 0.0f, 95.0f));
		mTransform->SetScale(Vector3(512.0f, 1080.0f, 0.0f) * 0.12f);

		// script
	}

	void MainFore11::Update()
	{
		GameObject::Update();
	}

	void MainFore11::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void MainFore11::Render()
	{
		GameObject::Render();
	}
}
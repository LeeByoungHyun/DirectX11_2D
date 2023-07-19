#include "MainDoorBack.h"
#include "ccResourceManager.h"

namespace cc
{
	MainDoorBack::MainDoorBack()
	{

	}

	MainDoorBack::~MainDoorBack()
	{

	}

	void MainDoorBack::Initialize()
	{
		GameObject::Initialize();

		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"main_doorback.png", L"..\\Resources\\Texture\\menu\\main_doorback.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"MainDoorBack", spriteMateiral);
		}

		mMeshRenderer = AddComponent<MeshRenderer>();
		mMeshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"MainDoorBack"));

		mTransform = GetComponent<Transform>();
		mTransform->SetPosition(Vector3(0.0f, 0.0f, 98.0f));
		mTransform->SetScale(Vector3(1024.0f, 1024.0f, 0.0f) * 0.12f);

		// script
	}

	void MainDoorBack::Update()
	{
		GameObject::Update();
	}

	void MainDoorBack::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void MainDoorBack::Render()
	{
		GameObject::Render();
	}
}
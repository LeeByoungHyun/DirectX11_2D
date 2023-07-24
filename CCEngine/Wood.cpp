#include "Wood.h"
#include "ccResourceManager.h"

namespace cc
{
	Wood::Wood()
	{

	}

	Wood::~Wood()
	{

	}

	void Wood::Initialize()
	{
		GameObject::Initialize();

		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"wood_33.png", L"..\\Resources\\Texture\\wood\\tile\\wood_33.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"Wood", spriteMateiral);
		}

		mMeshRenderer = AddComponent<MeshRenderer>();
		mMeshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"Wood"));

		mTransform = GetComponent<Transform>();
		mTransform->SetPosition(Vector3(0.0f, 0.0f, 98.0f));
		mTransform->SetScale(Vector3(128.0f, 128.0f, 0.0f) * 0.12f);

		// script
	}

	void Wood::Update()
	{
		GameObject::Update();
	}

	void Wood::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void Wood::Render()
	{
		GameObject::Render();
	}
	void Wood::Masking(int dir)
	{
	}
}
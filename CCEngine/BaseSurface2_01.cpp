#include "BaseSurface2_01.h"
#include "ccResourceManager.h"

namespace cc
{
	BaseSurface2_01::BaseSurface2_01()
	{

	}

	BaseSurface2_01::~BaseSurface2_01()
	{

	}

	void BaseSurface2_01::Initialize()
	{
		GameObject::Initialize();

		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"base_surface2_0.png", L"..\\Resources\\Texture\\base\\base_surface2_0.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"BaseSurface2_01", spriteMateiral);
		}

		mMeshRenderer = AddComponent<MeshRenderer>();
		mMeshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"BaseSurface2_01"));

		mTransform = GetComponent<Transform>();
		mTransform->SetPosition(Vector3(0.0f, 0.0f, 99.0f));
		mTransform->SetScale(Vector3(1024.0f, 512.0f, 0.0f));

		// script
	}

	void BaseSurface2_01::Update()
	{
		GameObject::Update();
	}

	void BaseSurface2_01::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void BaseSurface2_01::Render()
	{
		GameObject::Render();
	}
}
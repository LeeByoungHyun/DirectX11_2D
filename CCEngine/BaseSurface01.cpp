#include "BaseSurface01.h"
#include "ccResourceManager.h"

namespace cc
{
	BaseSurface01::BaseSurface01()
	{

	}

	BaseSurface01::~BaseSurface01()
	{

	}

	void BaseSurface01::Initialize()
	{
		GameObject::Initialize();

		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"base_surface_0.png", L"..\\Resources\\Texture\\base\\base_surface_0.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"BaseSurface01", spriteMateiral);
		}

		mMeshRenderer = AddComponent<MeshRenderer>();
		mMeshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"BaseSurface01"));

		mTransform = GetComponent<Transform>();
		mTransform->SetPosition(Vector3(0.0f, 0.0f, 91.0f));
		mTransform->SetScale(Vector3(1024.0f, 256.0f, 0.0f));

		// script
	}

	void BaseSurface01::Update()
	{
		GameObject::Update();
	}

	void BaseSurface01::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void BaseSurface01::Render()
	{
		GameObject::Render();
	}
}
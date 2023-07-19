#include "BaseSurface02.h"
#include "ccResourceManager.h"

namespace cc
{
	BaseSurface02::BaseSurface02()
	{

	}

	BaseSurface02::~BaseSurface02()
	{

	}

	void BaseSurface02::Initialize()
	{
		GameObject::Initialize();

		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"base_surface_1.png", L"..\\Resources\\Texture\\base\\base_surface_1.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"BaseSurface02", spriteMateiral);
		}

		mMeshRenderer = AddComponent<MeshRenderer>();
		mMeshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"BaseSurface02"));

		mTransform = GetComponent<Transform>();
		mTransform->SetPosition(Vector3(0.0f, 0.0f, 97.0f));
		mTransform->SetScale(Vector3(1024.0f, 256.0f, 0.0f) * 0.15f);

		// script
	}

	void BaseSurface02::Update()
	{
		GameObject::Update();
	}

	void BaseSurface02::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void BaseSurface02::Render()
	{
		GameObject::Render();
	}
}
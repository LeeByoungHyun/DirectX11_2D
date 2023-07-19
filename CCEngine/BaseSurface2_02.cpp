#include "BaseSurface2_02.h"
#include "ccResourceManager.h"

namespace cc
{
	BaseSurface2_02::BaseSurface2_02()
	{

	}

	BaseSurface2_02::~BaseSurface2_02()
	{

	}

	void BaseSurface2_02::Initialize()
	{
		GameObject::Initialize();

		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"base_surface2_1.png", L"..\\Resources\\Texture\\base\\base_surface2_1.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"BaseSurface2_02", spriteMateiral);
		}

		mMeshRenderer = AddComponent<MeshRenderer>();
		mMeshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"BaseSurface2_02"));

		mTransform = GetComponent<Transform>();
		mTransform->SetPosition(Vector3(0.0f, 0.0f, 95.0f));
		mTransform->SetScale(Vector3(1024.0f, 505.0f, 0.0f) * 0.10f);

		// script
	}

	void BaseSurface2_02::Update()
	{
		GameObject::Update();
	}

	void BaseSurface2_02::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void BaseSurface2_02::Render()
	{
		GameObject::Render();
	}
}
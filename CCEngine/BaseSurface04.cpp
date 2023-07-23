#include "BaseSurface04.h"
#include "ccResourceManager.h"

namespace cc
{
	BaseSurface04::BaseSurface04()
	{

	}

	BaseSurface04::~BaseSurface04()
	{

	}

	void BaseSurface04::Initialize()
	{
		GameObject::Initialize();

		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"base_surface_3.png", L"..\\Resources\\Texture\\base\\base_surface_3.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"BaseSurface04", spriteMateiral);
		}

		mMeshRenderer = AddComponent<MeshRenderer>();
		mMeshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"BaseSurface04"));

		mTransform = GetComponent<Transform>();
		mTransform->SetPosition(Vector3(0.0f, 0.0f, 94.0f));
		mTransform->SetScale(Vector3(1024.0f, 256.0f, 0.0f));

		// script
	}

	void BaseSurface04::Update()
	{
		GameObject::Update();
	}

	void BaseSurface04::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void BaseSurface04::Render()
	{
		GameObject::Render();
	}
}
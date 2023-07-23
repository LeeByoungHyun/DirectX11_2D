#include "BaseSurface03.h"
#include "ccResourceManager.h"

namespace cc
{
	BaseSurface03::BaseSurface03()
	{

	}

	BaseSurface03::~BaseSurface03()
	{

	}

	void BaseSurface03::Initialize()
	{
		GameObject::Initialize();

		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"base_surface_2.png", L"..\\Resources\\Texture\\base\\base_surface_2.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"BaseSurface03", spriteMateiral);
		}

		mMeshRenderer = AddComponent<MeshRenderer>();
		mMeshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"BaseSurface03"));

		mTransform = GetComponent<Transform>();
		mTransform->SetPosition(Vector3(0.0f, 0.0f, 96.0f));
		mTransform->SetScale(Vector3(1024.0f, 256.0f, 0.0f));

		// script
	}

	void BaseSurface03::Update()
	{
		GameObject::Update();
	}

	void BaseSurface03::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void BaseSurface03::Render()
	{
		GameObject::Render();
	}
}
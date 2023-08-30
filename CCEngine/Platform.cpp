#include "Platform.h"
#include "ccTransform.h"
#include "ccCollider2D.h"
#include "ccMeshRenderer.h"
#include "ccResourceManager.h"

#include "PlatformColliderScript.h"

namespace cc
{
	extern const float TILESIZE;

	Platform::Platform()
	{
		mTransform = GetComponent<Transform>();
		mCollider = AddComponent<Collider2D>();
		mMeshRenderer = AddComponent<MeshRenderer>();


	}

	Platform::~Platform()
	{

	}

	void Platform::Initialize()
	{
		GameObject::Initialize();

		// Sprite
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"platform_01.png", L"..\\Resources\\Texture\\cave\\tile\\platform_01.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Transparent);
			ResourceManager::Insert(L"platform_01", spriteMateiral);
		}

		mMeshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"platform_01"));

		mCollider->SetSize(Vector2(1.0f, 0.1f));
		mCollider->SetCenter(Vector2(0.0f, TILESIZE / 2));

		AddComponent<PlatformColliderScript>();
	}

	void Platform::Update()
	{
		GameObject::Update();
	}

	void Platform::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void Platform::Render()
	{
		GameObject::Render();
	}
}
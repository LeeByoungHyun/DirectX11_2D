#include "Heart.h"
#include "ccResourceManager.h"
#include "ccMouseScript.h"

namespace cc
{
	Heart::Heart()
	{

	}

	Heart::~Heart()
	{

	}

	void Heart::Initialize()
	{
		GameObject::Initialize();

		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"heart_big_idle_005", L"..\\Resources\\Texture\\Heart\\heart_big_idle_004.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"heart_big_idle", spriteMateiral);
		}

		mMeshRenderer = AddComponent<MeshRenderer>();
		mMeshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"heart_big_idle"));

		// script
	}

	void Heart::Update()
	{
		GameObject::Update();
	}

	void Heart::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void Heart::Render()
	{
		GameObject::Render();
	}
}
#include "BaseSkyNight.h"
#include "ccResourceManager.h"

namespace cc
{
	BaseSkyNight::BaseSkyNight()
	{

	}

	BaseSkyNight::~BaseSkyNight()
	{

	}

	void BaseSkyNight::Initialize()
	{
		GameObject::Initialize();

		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"base_skynight.png", L"..\\Resources\\Texture\\base\\base_skynight.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"BaseSkyNight", spriteMateiral);
		}

		mMeshRenderer = AddComponent<MeshRenderer>();
		mMeshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"BaseSkyNight"));

		mTransform = GetComponent<Transform>();
		mTransform->SetPosition(Vector3(0.0f, 0.0f, 100.0f));
		mTransform->SetScale(Vector3(1600.0f, 900.0f, 0.0f));

		// script
	}

	void BaseSkyNight::Update()
	{
		GameObject::Update();
	}

	void BaseSkyNight::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void BaseSkyNight::Render()
	{
		GameObject::Render();
	}
}
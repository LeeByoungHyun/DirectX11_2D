#include "CaveDirt.h"
#include "ccResourceManager.h"

namespace cc
{
	CaveDirt::CaveDirt()
	{

	}

	CaveDirt::~CaveDirt()
	{

	}

	void CaveDirt::Initialize()
	{
		GameObject::Initialize();

		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"cave_00.png", L"..\\Resources\\Texture\\cave\\tile\\cave_00.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"CaveDirt", spriteMateiral);
		}

		mMeshRenderer = AddComponent<MeshRenderer>();
		mMeshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"CaveDirt"));

		mTransform = GetComponent<Transform>();
		mTransform->SetPosition(Vector3(0.0f, 0.0f, 98.0f));
		mTransform->SetScale(Vector3(128.0f, 128.0f, 0.0f) * 0.12f);

		// script
	}

	void CaveDirt::Update()
	{
		GameObject::Update();
	}

	void CaveDirt::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void CaveDirt::Render()
	{
		GameObject::Render();
	}

	void CaveDirt::Masking(int dir)
	{

	}
}
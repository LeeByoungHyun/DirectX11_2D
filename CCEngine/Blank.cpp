#include "Blank.h"
#include "ccResourceManager.h"
#include "ccMouseScript.h"

namespace cc
{
	Blank::Blank()
	{

	}

	Blank::~Blank()
	{

	}

	void Blank::Initialize()
	{
		GameObject::Initialize();

		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"ui_blank.png", L"..\\Resources\\Texture\\UI\\ui_blank.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"ui_blank", spriteMateiral);
		}

		mMeshRenderer = AddComponent<MeshRenderer>();
		mMeshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"ui_blank"));

		// script
	}

	void Blank::Update()
	{
		GameObject::Update();
	}

	void Blank::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void Blank::Render()
	{
		GameObject::Render();
	}
}
#include "MenuTitle.h"
#include "ccResourceManager.h"

namespace cc
{
	MenuTitle::MenuTitle()
	{

	}

	MenuTitle::~MenuTitle()
	{

	}

	void MenuTitle::Initialize()
	{
		GameObject::Initialize();

		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"menu_title.png", L"..\\Resources\\Texture\\menu\\menu_title.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"MenuTitle", spriteMateiral);
		}

		mMeshRenderer = AddComponent<MeshRenderer>();
		mMeshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"MenuTitle"));

		mTransform = GetComponent<Transform>();
		mTransform->SetPosition(Vector3(0.0f, 0.0f, 100.0f));
		mTransform->SetScale(Vector3(1920.0f, 1080.0f, 0.0f) * 0.12f);

		// script
	}

	void MenuTitle::Update()
	{
		GameObject::Update();
	}

	void MenuTitle::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void MenuTitle::Render()
	{
		GameObject::Render();
	}
}
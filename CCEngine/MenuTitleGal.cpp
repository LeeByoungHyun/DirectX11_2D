#include "MenuTitleGal.h"
#include "ccResourceManager.h"

namespace cc
{
	MenuTitleGal::MenuTitleGal()
	{

	}

	MenuTitleGal::~MenuTitleGal()
	{

	}

	void MenuTitleGal::Initialize()
	{
		GameObject::Initialize();

		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"menu_titlegal.png", L"..\\Resources\\Texture\\menu\\menu_titlegal.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"MenuTitleGal", spriteMateiral);
		}

		mMeshRenderer = AddComponent<MeshRenderer>();
		mMeshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"MenuTitleGal"));

		mTransform = GetComponent<Transform>();
		mTransform->SetPosition(Vector3(0.0f, 0.0f, 99.0f));
		mTransform->SetScale(Vector3(1024.0f, 1024.0f, 0.0f) * 0.12f);

		// script
	}

	void MenuTitleGal::Update()
	{
		GameObject::Update();
	}

	void MenuTitleGal::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void MenuTitleGal::Render()
	{
		GameObject::Render();
	}
}
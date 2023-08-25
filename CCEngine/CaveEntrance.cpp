#include "CaveEntrance.h"
#include "ccResourceManager.h"


namespace cc
{
	CaveEntrance::CaveEntrance()
	{
		mTransform = GetComponent<Transform>();
		mMeshRenderer = AddComponent<MeshRenderer>();
	}

	CaveEntrance::~CaveEntrance()
	{

	}

	void CaveEntrance::Initialize()
	{
		GameObject::Initialize();

		// transform
		mTransform->SetScale(Vector3(3.0f, 3.0f, 1.0f));

		// meshRenderer
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"cave_entrance.png", L"..\\Resources\\Texture\\cave\\tile\\cave_entrance.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Transparent);
			ResourceManager::Insert(L"cave_entrance", spriteMateiral);
		}
		mMeshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"cave_entrance"));
	}

	void CaveEntrance::Update()
	{
		GameObject::Update();
	}

	void CaveEntrance::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void CaveEntrance::Render()
	{
		GameObject::Render();
	}
}
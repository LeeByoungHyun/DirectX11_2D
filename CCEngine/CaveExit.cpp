#include "CaveExit.h"
#include "ccResourceManager.h"


namespace cc
{
	CaveExit::CaveExit()
	{
		mTransform = GetComponent<Transform>();
		mMeshRenderer = AddComponent<MeshRenderer>();
		mCollider = AddComponent<Collider2D>();
	}

	CaveExit::~CaveExit()
	{

	}

	void CaveExit::Initialize()
	{
		GameObject::Initialize();

		// transform
		mTransform->SetScale(Vector3(3.0f, 3.0f, 1.0f));

		// meshRenderer
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"cave_exit.png", L"..\\Resources\\Texture\\cave\\tile\\cave_exit.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Transparent);
			ResourceManager::Insert(L"cave_exit", spriteMateiral);
		}
		mMeshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"cave_exit"));

		// collider
		mCollider->SetSize(Vector2(0.2f, 0.66f));
	}

	void CaveExit::Update()
	{
		GameObject::Update();
	}

	void CaveExit::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void CaveExit::Render()
	{
		GameObject::Render();
	}
}
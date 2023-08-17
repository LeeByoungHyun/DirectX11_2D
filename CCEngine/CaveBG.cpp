#include "CaveBG.h"
#include "ccResourceManager.h"

namespace cc
{
	extern const float BGDEPTH;
	extern Vector3 cameraPos;
	extern Vector2 screenSize;

	CaveBG::CaveBG()
	{

	}

	CaveBG::~CaveBG()
	{

	}

	void CaveBG::Initialize()
	{
		GameObject::Initialize();

		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"bg_cave.png", L"..\\Resources\\Texture\\cave\\bg_cave.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"CaveBG", spriteMateiral);
		}

		mMeshRenderer = AddComponent<MeshRenderer>();
		mMeshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"CaveBG"));

		mTransform = GetComponent<Transform>();
		mTransform->SetPosition(Vector3(0.0f, 0.0f, BGDEPTH));
		mTransform->SetScale(Vector3(4.0f, 4.0f, 0.0f));
		//mTransform->SetScale(Vector3(512.0f, 512.0f, 0.0f));

		// script
	}

	void CaveBG::Update()
	{
		GameObject::Update();
	}

	void CaveBG::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void CaveBG::Render()
	{
		// 설정한 범위에 포함될 경우에만 render
		Vector3 mPos = mTransform->GetPosition();
		if (cameraPos.x - screenSize.x <= mPos.x && mPos.x <= cameraPos.x + screenSize.x
			&& cameraPos.y - screenSize.y <= mPos.y && mPos.y <= cameraPos.y + screenSize.y)
		{
			GameObject::Render();
		}
	}
}
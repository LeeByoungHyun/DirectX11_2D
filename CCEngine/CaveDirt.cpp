#include "CaveDirt.h"
#include "ccResourceManager.h"
#include "ccObject.h"
#include "ccCollider2D.h"

#include "DirtMasking.h"

namespace cc
{
	extern const float TILESIZE;
	extern const float TILEDEPTH;
	extern const float MASKINGDIST;

	CaveDirt::CaveDirt()
	{

	}

	CaveDirt::~CaveDirt()
	{

	}

	void CaveDirt::Initialize()
	{
		GameObject::Initialize();

		// Sprite
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"cave_00.png", L"..\\Resources\\Texture\\cave\\tile\\cave_00.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"cave_00", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"cave_01.png", L"..\\Resources\\Texture\\cave\\tile\\cave_01.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"cave_01", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"cave_02.png", L"..\\Resources\\Texture\\cave\\tile\\cave_02.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"cave_02", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"cave_03.png", L"..\\Resources\\Texture\\cave\\tile\\cave_03.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"cave_03", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"cave_04.png", L"..\\Resources\\Texture\\cave\\tile\\cave_04.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"cave_04", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"cave_05.png", L"..\\Resources\\Texture\\cave\\tile\\cave_05.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"cave_05", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"cave_06.png", L"..\\Resources\\Texture\\cave\\tile\\cave_06.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"cave_06", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"cave_07.png", L"..\\Resources\\Texture\\cave\\tile\\cave_07.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"cave_07", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"cave_08.png", L"..\\Resources\\Texture\\cave\\tile\\cave_08.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"cave_08", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"cave_09.png", L"..\\Resources\\Texture\\cave\\tile\\cave_09.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"cave_09", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"cave_10.png", L"..\\Resources\\Texture\\cave\\tile\\cave_10.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"cave_10", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"cave_11.png", L"..\\Resources\\Texture\\cave\\tile\\cave_11.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"cave_11", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"cave_12.png", L"..\\Resources\\Texture\\cave\\tile\\cave_12.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"cave_12", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"cave_13.png", L"..\\Resources\\Texture\\cave\\tile\\cave_13.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"cave_13", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"cave_14.png", L"..\\Resources\\Texture\\cave\\tile\\cave_14.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"cave_14", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"cave_15.png", L"..\\Resources\\Texture\\cave\\tile\\cave_15.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"cave_15", spriteMateiral);

		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"cave_16.png", L"..\\Resources\\Texture\\cave\\tile\\cave_16.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"cave_16", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"cave_17.png", L"..\\Resources\\Texture\\cave\\tile\\cave_17.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"cave_17", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"cave_18.png", L"..\\Resources\\Texture\\cave\\tile\\cave_18.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"cave_18", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"cave_19.png", L"..\\Resources\\Texture\\cave\\tile\\cave_19.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"cave_19", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"cave_20.png", L"..\\Resources\\Texture\\cave\\tile\\cave_20.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"cave_20", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"cave_21.png", L"..\\Resources\\Texture\\cave\\tile\\cave_21.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"cave_21", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"cave_22.png", L"..\\Resources\\Texture\\cave\\tile\\cave_22.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"cave_22", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"cave_23.png", L"..\\Resources\\Texture\\cave\\tile\\cave_23.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"cave_23", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"cave_24.png", L"..\\Resources\\Texture\\cave\\tile\\cave_24.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"cave_24", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"cave_25.png", L"..\\Resources\\Texture\\cave\\tile\\cave_25.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"cave_25", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"cave_26.png", L"..\\Resources\\Texture\\cave\\tile\\cave_26.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"cave_26", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"cave_27.png", L"..\\Resources\\Texture\\cave\\tile\\cave_27.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"cave_27", spriteMateiral);
		}

		// 패턴 랜덤생성
		std::random_device rd;
		std::mt19937 rng(rd());
		std::uniform_int_distribution<int> uniform_int_dist(0, 9);
		int randomInt = uniform_int_dist(rng);

		mMeshRenderer = AddComponent<MeshRenderer>();
		mMeshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		if (randomInt == 0)
			mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"cave_00"));
		else if (randomInt == 1)
			mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"cave_01"));
		else if (randomInt == 2)
			mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"cave_04"));
		else if (randomInt == 3)
			mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"cave_05"));
		else if (randomInt == 4)
			mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"cave_08"));
		else if (randomInt == 5)
			mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"cave_09"));
		else if (randomInt == 6)
			mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"cave_12"));
		else if (randomInt == 7)
			mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"cave_13"));
		else if (randomInt == 8)
			mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"cave_16"));
		else if (randomInt == 9)
			mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"cave_17"));

		mTransform = GetComponent<Transform>();
		mTransform->SetPosition(Vector3(0.0f, 0.0f, TILEDEPTH));
		mTransform->SetScale(Vector3(TILESIZE, TILESIZE, 0.0f));

		mCollider = AddComponent<Collider2D>();
		//mCollider->SetSize(Vector2(2.0f, 2.0f));

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
		// 0 = top
		// 1 = right
		// 2 = bottom
		// 3 = left

		if (masking[dir] == false)	// 마스킹 할 필요가 없으면 return
			return;

		if (masked[dir] == true)	// 이미 마스킹 되어있으면 return
			return;

		DirtMasking* dirtMask = new DirtMasking();
		dirtMask->SetName(L"dirtMask");
		dirtMask->SetDirection(dir);
		object::Instantiate(dirtMask, eLayerType::FrontObject);

		//borderMask->Instantiate(dir);

		if (dir == 0)
			dirtMask->GetComponent<Transform>()->SetPosition(mTransform->GetPosition().x, mTransform->GetPosition().y + (TILESIZE / 2.0f + MASKINGDIST), TILEDEPTH - 0.01f);
		else if (dir == 1)
			dirtMask->GetComponent<Transform>()->SetPosition(mTransform->GetPosition().x + (TILESIZE / 2.0f + MASKINGDIST), mTransform->GetPosition().y, TILEDEPTH - 0.01f);
		else if (dir == 2)
			dirtMask->GetComponent<Transform>()->SetPosition(mTransform->GetPosition().x, mTransform->GetPosition().y - (TILESIZE / 2.0f + MASKINGDIST), TILEDEPTH - 0.01f);
		else if (dir == 3)
			dirtMask->GetComponent<Transform>()->SetPosition(mTransform->GetPosition().x - (TILESIZE / 2.0f + MASKINGDIST), mTransform->GetPosition().y, TILEDEPTH - 0.01f);

		maskPos[dir] = dirtMask;
		masked[dir] = true;
	}
}
#include "BorderTile.h"
#include "ccResourceManager.h"
#include "BorderMasking.h"
#include "ccObject.h"
#include "ccGameObject.h"

namespace cc
{
	extern const float TILESIZE;
	extern const float TILEDEPTH;

	BorderTile::BorderTile()
	{

	}

	BorderTile::~BorderTile()
	{

	}

	void BorderTile::Initialize()
	{
		GameObject::Initialize();

#pragma region SpriteMaterial
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"border_00.png", L"..\\Resources\\Texture\\border\\tile\\border_00.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"border_00", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"border_01.png", L"..\\Resources\\Texture\\border\\tile\\border_01.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"border_01", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"border_02.png", L"..\\Resources\\Texture\\border\\tile\\border_02.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"border_02", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"border_03.png", L"..\\Resources\\Texture\\border\\tile\\border_03.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"border_03", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"border_04.png", L"..\\Resources\\Texture\\border\\tile\\border_04.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"border_04", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"border_05.png", L"..\\Resources\\Texture\\border\\tile\\border_05.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"border_05", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"border_06.png", L"..\\Resources\\Texture\\border\\tile\\border_06.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"border_06", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"border_07.png", L"..\\Resources\\Texture\\border\\tile\\border_07.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"border_07", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"border_08.png", L"..\\Resources\\Texture\\border\\tile\\border_08.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"border_08", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"border_09.png", L"..\\Resources\\Texture\\border\\tile\\border_09.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"border_09", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"border_10.png", L"..\\Resources\\Texture\\border\\tile\\border_10.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"border_10", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"border_11.png", L"..\\Resources\\Texture\\border\\tile\\border_11.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"border_11", spriteMateiral);
		}
#pragma endregion

		// 패턴 랜덤생성
		std::random_device rd;
		std::mt19937 rng(rd());
		std::uniform_int_distribution<int> uniform_int_dist(0, 11);
		int randomInt = uniform_int_dist(rng);

#pragma region MeshRenderer
		// 생성된 랜덤변수에 따라 패턴 결정
		mMeshRenderer = AddComponent<MeshRenderer>();
		mMeshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		if (randomInt == 0)
			mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"border_00"));
		else if (randomInt == 1)
			mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"border_01"));
		else if (randomInt == 2)
			mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"border_02"));
		else if (randomInt == 3)
			mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"border_03"));
		else if (randomInt == 4)
			mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"border_04"));
		else if (randomInt == 5)
			mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"border_05"));
		else if (randomInt == 6)
			mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"border_06"));
		else if (randomInt == 7)
			mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"border_07"));
		else if (randomInt == 8)
			mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"border_08"));
		else if (randomInt == 9)
			mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"border_09"));
		else if (randomInt == 10)
			mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"border_10"));
		else if (randomInt == 11)
			mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"border_11"));
#pragma endregion

		mTransform = GetComponent<Transform>();
		mTransform->SetPosition(Vector3(0.0f, 0.0f, TILEDEPTH));
		mTransform->SetScale(Vector3(TILESIZE, TILESIZE, 0.0f));

		// script
	}

	void BorderTile::Update()
	{
		GameObject::Update();
	}

	void BorderTile::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void BorderTile::Render()
	{
		GameObject::Render();
	}

	void BorderTile::Masking(int dir)
	{
		// 0 = top
		// 1 = right
		// 2 = bottom
		// 3 = left

		if (masking[dir] == false)	// 마스킹 할 필요가 없으면 return
			return;

		if (masked[dir] == true)	// 이미 마스킹 되어있으면 return
			return;

		BorderMasking* borderMask = new BorderMasking();
		borderMask->SetName(L"borderMask");
		borderMask->SetDirection(dir);
		object::Instantiate(borderMask, eLayerType::FrontObject);

		//borderMask->Instantiate(dir);

		if (dir == 0)
			borderMask->GetComponent<Transform>()->SetPosition(mTransform->GetPosition().x, mTransform->GetPosition().y + (TILESIZE / 2.0f + 5.0f), TILEDEPTH - 0.01f);
		else if (dir == 1)
			borderMask->GetComponent<Transform>()->SetPosition(mTransform->GetPosition().x + (TILESIZE / 2.0f + 5.0f), mTransform->GetPosition().y, TILEDEPTH - 0.01f);
		else if (dir == 2)
			borderMask->GetComponent<Transform>()->SetPosition(mTransform->GetPosition().x, mTransform->GetPosition().y - (TILESIZE / 2.0f + 5.0f), TILEDEPTH - 0.01f);
		else if (dir == 3)
			borderMask->GetComponent<Transform>()->SetPosition(mTransform->GetPosition().x - (TILESIZE / 2.0f + 5.0f), mTransform->GetPosition().y, TILEDEPTH - 0.01f);

		maskPos[dir] = borderMask;
		masked[dir] = true;
	}
}
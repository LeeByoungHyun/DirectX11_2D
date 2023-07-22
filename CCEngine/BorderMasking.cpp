#include "BorderMasking.h"
#include "ccResourceManager.h"
#include "ccObject.h"

namespace cc
{
	BorderMasking::BorderMasking()
	{
		mMeshRenderer = AddComponent<MeshRenderer>();
		mMeshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"border_masking_top_00")); // test

		mTransform = GetComponent<Transform>();
		mTransform->SetPosition(Vector3(0.0f, 0.0f, 10.0f));
		mTransform->SetScale(Vector3(128.0f, 128.0f, 0.0f) * 0.12f);
	}

	BorderMasking::~BorderMasking()
	{

	}

	void BorderMasking::Initialize()
	{
		GameObject::Initialize();

		// top
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"border_masking_top_00.png", L"..\\Resources\\Texture\\border\\tile\\border_masking_top_00.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"border_masking_top_00", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"border_masking_top_01.png", L"..\\Resources\\Texture\\border\\tile\\border_masking_top_01.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"border_masking_top_01", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"border_masking_top_02.png", L"..\\Resources\\Texture\\border\\tile\\border_masking_top_02.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"border_masking_top_02", spriteMateiral);
		}

		// right
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"border_masking_right_00.png", L"..\\Resources\\Texture\\border\\tile\\border_masking_right_00.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"border_masking_right_00", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"border_masking_right_01.png", L"..\\Resources\\Texture\\border\\tile\\border_masking_right_01.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"border_masking_right_01", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"border_masking_right_02.png", L"..\\Resources\\Texture\\border\\tile\\border_masking_right_02.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"border_masking_right_02", spriteMateiral);
		}

		// bottom
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"border_masking_bottom_00.png", L"..\\Resources\\Texture\\border\\tile\\border_masking_bottom_00.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"border_masking_bottom_00", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"border_masking_bottom_01.png", L"..\\Resources\\Texture\\border\\tile\\border_masking_bottom_01.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"border_masking_bottom_01", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"border_masking_bottom_02.png", L"..\\Resources\\Texture\\border\\tile\\border_masking_bottom_02.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"border_masking_bottom_02", spriteMateiral);
		}

		// left
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"border_masking_left_00.png", L"..\\Resources\\Texture\\border\\tile\\border_masking_left_00.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"border_masking_left_00", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"border_masking_left_01.png", L"..\\Resources\\Texture\\border\\tile\\border_masking_left_01.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"border_masking_left_01", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"border_masking_left_02.png", L"..\\Resources\\Texture\\border\\tile\\border_masking_left_02.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"border_masking_left_02", spriteMateiral);
		}

		

		

		// script
	}

	void BorderMasking::Update()
	{
		GameObject::Update();
	}

	void BorderMasking::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void BorderMasking::Render()
	{
		GameObject::Render();
	}

	BorderMasking* BorderMasking::Instantiate(int direct)
	{
		// 마스킹 패턴 랜덤하게 생성
		std::random_device rd;
		std::mt19937 rng(rd());
		std::uniform_int_distribution<int> uniform_int_dist(0, 2);
		int randomInt = uniform_int_dist(rng);

		// top
		if (direct == 0)
		{
			if (randomInt == 0)
				mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"border_masking_top_00"));
			else if (randomInt == 1)
				mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"border_masking_top_01"));
			else if (randomInt == 2)
				mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"border_masking_top_02"));
		}

		// right
		else if(direct == 1)
		{
			if (randomInt == 0)
				mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"border_masking_right_00"));
			else if (randomInt == 1)
				mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"border_masking_right_01"));
			else if (randomInt == 2)
				mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"border_masking_right_02"));
		}

		// bottom
		else if (direct == 2)
		{
			if (randomInt == 0)
				mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"border_masking_bottom_00"));
			else if (randomInt == 1)														
				mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"border_masking_bottom_01"));
			else if (randomInt == 2)														
				mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"border_masking_bottom_02"));
		}

		// left
		else if (direct == 2)
		{
			if (randomInt == 0)
				mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"border_masking_left_00"));
			else if (randomInt == 1)														
				mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"border_masking_left_01"));
			else if (randomInt == 2)														
				mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"border_masking_left_02"));
		}

		return object::Instantiate<BorderMasking>(eLayerType::FrontObject);
	}
}
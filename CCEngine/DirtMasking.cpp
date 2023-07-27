#include "DirtMasking.h"
#include "ccResourceManager.h"
#include "ccObject.h"

namespace cc
{
	extern const float TILEDEPTH;

	DirtMasking::DirtMasking()
	{

	}

	DirtMasking::~DirtMasking()
	{

	}

	void DirtMasking::Initialize()
	{
		GameObject::Initialize();

		// script
	}

	void DirtMasking::Update()
	{
		GameObject::Update();
	}

	void DirtMasking::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void DirtMasking::Render()
	{
		GameObject::Render();
	}

	void DirtMasking::SetDirection(int dir)
	{
#pragma region Material
		// top
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"dirt_masking_top_00.png", L"..\\Resources\\Texture\\cave\\tile\\dirt_masking_top_00.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Transparent);
			ResourceManager::Insert(L"dirt_masking_top_00", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"dirt_masking_top_01.png", L"..\\Resources\\Texture\\cave\\tile\\dirt_masking_top_01.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Transparent);
			ResourceManager::Insert(L"dirt_masking_top_01", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"dirt_masking_top_02.png", L"..\\Resources\\Texture\\cave\\tile\\dirt_masking_top_02.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Transparent);
			ResourceManager::Insert(L"dirt_masking_top_02", spriteMateiral);
		}

		// right
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"dirt_masking_right_00.png", L"..\\Resources\\Texture\\cave\\tile\\dirt_masking_right_00.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Transparent);
			ResourceManager::Insert(L"dirt_masking_right_00", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"dirt_masking_right_01.png", L"..\\Resources\\Texture\\cave\\tile\\dirt_masking_right_01.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Transparent);
			ResourceManager::Insert(L"dirt_masking_right_01", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"dirt_masking_right_02.png", L"..\\Resources\\Texture\\cave\\tile\\dirt_masking_right_02.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Transparent);
			ResourceManager::Insert(L"dirt_masking_right_02", spriteMateiral);
		}

		// bottom
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"dirt_masking_bottom_00.png", L"..\\Resources\\Texture\\cave\\tile\\dirt_masking_bottom_00.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Transparent);
			ResourceManager::Insert(L"dirt_masking_bottom_00", spriteMateiral);
		}

		// left
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"dirt_masking_left_00.png", L"..\\Resources\\Texture\\cave\\tile\\dirt_masking_left_00.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Transparent);
			ResourceManager::Insert(L"dirt_masking_left_00", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"dirt_masking_left_01.png", L"..\\Resources\\Texture\\cave\\tile\\dirt_masking_left_01.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Transparent);
			ResourceManager::Insert(L"dirt_masking_left_01", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"dirt_masking_left_02.png", L"..\\Resources\\Texture\\cave\\tile\\dirt_masking_left_02.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Transparent);
			ResourceManager::Insert(L"dirt_masking_left_02", spriteMateiral);
		}
#pragma endregion

		mMeshRenderer = AddComponent<MeshRenderer>();
		mMeshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));

		mTransform = GetComponent<Transform>();
		mTransform->SetPosition(Vector3(0.0f, 0.0f, TILEDEPTH - 0.01f));
		mTransform->SetScale(Vector3(128.0f, 128.0f, 0.0f));

		std::random_device rd;
		std::mt19937 rng(rd());
		std::uniform_int_distribution<int> uniform_int_dist(0, 2);
		int randomInt = uniform_int_dist(rng);

		// top
		if (dir == 0)
		{
			if (randomInt == 0)
				mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"dirt_masking_top_00"));
			else if (randomInt == 1)
				mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"dirt_masking_top_01"));
			else if (randomInt == 2)									
				mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"dirt_masking_top_02"));
		}

		// right
		else if (dir == 1)
		{
			if (randomInt == 0)
				mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"dirt_masking_right_00"));
			else if (randomInt == 1)										
				mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"dirt_masking_right_01"));
			else if (randomInt == 2)										
				mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"dirt_masking_right_02"));
		}

		// bottom
		else if (dir == 2)
		{
			mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"dirt_masking_bottom_00"));
		}

		// left
		else if (dir == 3)
		{
			if (randomInt == 0)
				mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"dirt_masking_left_00"));
			else if (randomInt == 1)										
				mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"dirt_masking_left_01"));
			else if (randomInt == 2)										 
				mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"dirt_masking_left_02"));
		}
	}
}
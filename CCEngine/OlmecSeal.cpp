#include "OlmecSeal.h"
#include "ccGameObject.h"
#include "ccTransform.h"
#include "ccAnimator.h"
#include "ccMeshRenderer.h"
#include "ccResourceManager.h"
#include "ccTime.h"
#include "ccObject.h"

namespace cc
{
	OlmecSeal::OlmecSeal()
	{
		mMeshRenderer = AddComponent<MeshRenderer>();
		mTransform = GetComponent<Transform>();

		mState = eOlmecSealState::Idle;
		double mTime = 0.0f;

	}

	OlmecSeal::~OlmecSeal()
	{

	}

	void OlmecSeal::Initialize()
	{
		GameObject::Initialize();

		// transform
		//mTransform->SetScale(Vector3(4.0f, 4.0f, 0.0f));

		// texture
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"olmec_awake_00.png", L"..\\Resources\\Texture\\Monster\\olmec_awake_00.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Transparent);
			ResourceManager::Insert(L"olmec_awake_00", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"olmec_awake_01.png", L"..\\Resources\\Texture\\Monster\\olmec_awake_01.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Transparent);
			ResourceManager::Insert(L"olmec_awake_01", spriteMateiral);
		}
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"olmec_awake_02.png", L"..\\Resources\\Texture\\Monster\\olmec_awake_02.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Transparent);
			ResourceManager::Insert(L"olmec_awake_02", spriteMateiral);
		}

		// meshrenderer
		mMeshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"olmec_awake_00"));

	}

	void OlmecSeal::Update()
	{
		GameObject::Update();

		switch (mState)
		{
		case eOlmecSealState::Idle:
			idle();
			break;

		case eOlmecSealState::Awake01:
			awake01();
			break;

		case eOlmecSealState::Awake02:
			awake02();
			break;

		case eOlmecSealState::Death:
			death();
			break;
		}
	}

	void OlmecSeal::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void OlmecSeal::Render()
	{
		GameObject::Render();
	}

	void OlmecSeal::idle()
	{
		mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"olmec_awake_00"));

		mTime += Time::DeltaTime();
		if (mTime >= 2.0f)
		{
			mState = eOlmecSealState::Awake01;
			mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"olmec_awake_01"));
			mTime = 0.0f;
		}
	}

	void OlmecSeal::awake01()
	{
		mTime += Time::DeltaTime();
		if (mTime >= 2.0f)
		{
			mState = eOlmecSealState::Awake02;
			mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"olmec_awake_02"));
			mTime = 0.0f;
		}
	}

	void OlmecSeal::awake02()
	{
		mTime += Time::DeltaTime();
		if (mTime >= 2.0f)
		{
			mState = eOlmecSealState::Death;
			mTime = 0.0f;
		}
	}

	void OlmecSeal::death()
	{
		object::Destroy(this);
	}
}
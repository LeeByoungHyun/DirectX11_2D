#include "Olmec.h"
#include "ccMeshRenderer.h"
#include "ccResourceManager.h"
#include "ccTransform.h"
#include "ccCollider2D.h"
#include "ccAnimator.h"
#include "ccObject.h"
#include "ccScene.h"
#include "ccTime.h"
#include "ccRigidbody.h"

#include "OlmecSeal.h"
#include "Player.h"
#include "OlmecCollisionScript.h"

namespace cc
{
	Olmec::Olmec()
	{
		//mHp = 1;
		mTime = 0.0f;
		animationFlag = false;
		mDirection = eDirection::Left;
		mState = eOlmecState::Awake; 
		awakeFlag = false;
		jumpFlag = false;
		seal = nullptr;
		checkTime = NULL;

		mTransform = GetComponent<Transform>();
		mMeshRenderer = AddComponent<MeshRenderer>();
		mRigidbody = AddComponent<Rigidbody>();
		mCollider = AddComponent<Collider2D>();
	}

	Olmec::~Olmec()
	{

	}

	void Olmec::Initialize()
	{
		GameObject::Initialize();

		mMeshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"SpriteAnimationMaterial"));

		mTransform->SetScale(Vector3(4.0f, 4.0f, 0.0f));

		mCollider->SetSize(Vector2(0.95f, 0.95f));

		mRigidbody->SetGround(true);
		mRigidbody->SetMass(2.0f);
		mRigidbody->SetGravity(Vector2(0.0f, 15.0f));

		// texture
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"olmec_idle.png", L"..\\Resources\\Texture\\Monster\\olmec_idle.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Transparent);
			ResourceManager::Insert(L"olmec_idle", spriteMateiral);
		}

		// meshrenderer
		mMeshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"olmec_idle"));

		// script
		AddComponent<OlmecCollisionScript>();
	}

	void Olmec::Update()
	{
		GameObject::Update();

		switch (mState)
		{
		case eOlmecState::Idle:
			idle();
			break;

		case eOlmecState::Awake:
			awake();
			break;

		case eOlmecState::Jump:
			jump();
			break;
			
		case eOlmecState::Crash:
			crash();
			break;

		case eOlmecState::Death:
			death();
			break;
		}
	}

	void Olmec::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void Olmec::Render()
	{
		GameObject::Render();
	}

	void Olmec::idle()
	{
		mTime += Time::DeltaTime();
		if (mTime >= 1.5f)
		{
			mState = eOlmecState::Jump; 
			mTime = 0.0f;
			InitializeState();
		}
	}

	void Olmec::awake()
	{
		if (awakeFlag == false)
		{
			seal = object::Instantiate<OlmecSeal>(eLayerType::FrontObject);
			seal->GetComponent<Transform>()->SetParent(mTransform);
			awakeFlag = true;
		}
		
		if (seal->GetOlmecSealState() == OlmecSeal::eOlmecSealState::Death)
		{
			mState = eOlmecState::Idle;
		}
	}

	void Olmec::jump()
	{
		if (jumpFlag == false)
		{
			jumpFlag = true;

			// 플레이어 방향
			Transform* playerTr = Player::GetInstance()->GetComponent<Transform>();
			if (playerTr->GetPosition().x < mTransform->GetPosition().x)
				mDirection = eDirection::Left;
			else
				mDirection = eDirection::Right;

			mRigidbody->AddForce(Vector2(0.0f, -1000.0f));
			mRigidbody->SetGround(false);

			checkTime = false;
		}
		
		mTime += Time::DeltaTime();
		if (mTime >= 0.3f && checkTime == false)
		{
			checkTime = true;
		}

		// 점프 도중 플레이어가 하단에 위치할 경우
		if ((mTransform->GetPosition().x - mTransform->GetScale().x / 2.0f) <= Player::GetInstance()->GetComponent<Transform>()->GetPosition().x
			&& (mTransform->GetPosition().x + mTransform->GetScale().x / 2.0f) >= Player::GetInstance()->GetComponent<Transform>()->GetPosition().x
			&& mTransform->GetPosition().y > Player::GetInstance()->GetComponent<Transform>()->GetPosition().y
			&& checkTime == true)
		{
			mState = eOlmecState::Crash;
			mRigidbody->SetGround(true); 
			mRigidbody->SetVelocity(Vector2(0.0f, 0.0f));
			mTime = 0.0f;
			jumpFlag = false;
			checkTime = false;
		}

		if (checkTime != NULL && checkTime == true)
		{
			Vector2 mVelocity = mRigidbody->GetVelocity();

			if (mDirection == eDirection::Left)
			{
				mRigidbody->SetVelocity(Vector2(-5.0f, mVelocity.y));
			}
			else
			{
				mRigidbody->SetVelocity(Vector2(5.0f, mVelocity.y));
			}
		}

	}

	void Olmec::crash()
	{
		mTime += Time::DeltaTime();
		if (mTime >= 1.0f)
		{
			mRigidbody->SetGround(false);
			mRigidbody->SetVelocity(Vector2(0.0f, 15.0f));
		}
	}

	void Olmec::death()
	{

	}

	void Olmec::InitializeState()
	{
		mTime = 0.0f;
		mRigidbody->SetVelocity(Vector2::Zero);

		jumpFlag = false;
	}
}
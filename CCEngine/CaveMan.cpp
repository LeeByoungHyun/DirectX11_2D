#include "CaveMan.h"
#include "ccMeshRenderer.h"
#include "ccResourceManager.h"
#include "ccTransform.h"
#include "ccCollider2D.h"
#include "ccAnimator.h"
#include "ccObject.h"
#include "ccScene.h"
#include "ccTime.h"

#include "Player.h"
#include "CaveManColliderScript.h"

namespace cc
{
	extern const float PLAYERDEPTH;

	CaveMan::CaveMan()
	{
		mHp = 1;
		mTime = 0.0f;
		animationFlag = false;
		mDirection = eDirection::Left;
		mState = eCaveManState::Idle;

		mTransform = GetComponent<Transform>();
		mMeshRenderer = AddComponent<MeshRenderer>();
		mAnimator = AddComponent<Animator>();
		mRigidbody = AddComponent<Rigidbody>();
		mCollider = AddComponent<Collider2D>();

	}

	CaveMan::~CaveMan()
	{

	}

	void CaveMan::Initialize()
	{
		GameObject::Initialize();
		
		mMeshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"SpriteAnimationMaterial"));

		mTransform->SetScale(Vector3(2.0f, 2.0f, 0.0f));

		mCollider->SetSize(Vector2(0.45f, 0.45f));

		// amimator
		{
			std::shared_ptr<Texture> atlas
				= ResourceManager::Load<Texture>(L"caveMan.png", L"..\\Resources\\Texture\\Monster\\caveMan.png");
		
			
			mAnimator->Create(L"Idle_r", atlas, Vector2(128.0f * 0, 128.0f * 0), Vector2(128.0f, 128.0f), 1, Vector2::Zero, 0.1f);
			mAnimator->Create(L"Idle_l", atlas, Vector2(128.0f * 0, 128.0f * 1), Vector2(128.0f, 128.0f), 1, Vector2::Zero, 0.1f);
			mAnimator->Create(L"Move_r", atlas, Vector2(128.0f * 0, 128.0f * 2), Vector2(128.0f, 128.0f), 8, Vector2::Zero, 0.1f);
			mAnimator->Create(L"Move_l", atlas, Vector2(128.0f * 0, 128.0f * 3), Vector2(128.0f, 128.0f), 8, Vector2::Zero, 0.1f);
			mAnimator->Create(L"Death_r", atlas, Vector2(128.0f * 0, 128.0f * 4), Vector2(128.0f, 128.0f), 1, Vector2::Zero, 0.1f);
			mAnimator->Create(L"Death_l", atlas, Vector2(128.0f * 0, 128.0f * 5), Vector2(128.0f, 128.0f), 1, Vector2::Zero, 0.1f);
			mAnimator->Create(L"Chase_r", atlas, Vector2(128.0f * 0, 128.0f * 6), Vector2(128.0f, 128.0f), 8, Vector2::Zero, 0.1f);
			mAnimator->Create(L"Chase_l", atlas, Vector2(128.0f * 0, 128.0f * 7), Vector2(128.0f, 128.0f), 8, Vector2::Zero, 0.1f);
		}
		
		mAnimator->PlayAnimation(L"Idle_l", true);
		
		// script
		AddComponent<CaveManColliderScript>();
	}

	void CaveMan::Update()
	{
		GameObject::Update();

		switch (mState)
		{
		case eCaveManState::Idle:
			idle();
			break;

		case eCaveManState::Move:
			move();
			break;

		case eCaveManState::Chase:
			chase();
			break;

		case eCaveManState::Death:
			death();
			break;
		}
	}

	void CaveMan::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void CaveMan::Render()
	{
		GameObject::Render();
	}

	void CaveMan::idle()
	{
		if (animationFlag == false)
		{
			if (mDirection == eDirection::Left)
				mAnimator->PlayAnimation(L"Idle_l", true);
			else if (mDirection == eDirection::Right)
				mAnimator->PlayAnimation(L"Idle_r", true);

			animationFlag = true;
		}

		mTime += Time::DeltaTime();
		if (mTime >= 1.0f)
		{
			std::random_device rd;
			std::mt19937 rng(rd());
			std::uniform_int_distribution<int> uniform_int_dist(0, 1);
			int randomInt = uniform_int_dist(rng);

			if (randomInt == 0)	// left
				mDirection = eDirection::Left;
			else
				mDirection = eDirection::Right;

			mTime = 0.0f;
			mState = eCaveManState::Move;
			animationFlag = false;
		}
	}

	void CaveMan::move()
	{
		if (animationFlag == false)
		{
			if (mDirection == eDirection::Left)
				mAnimator->PlayAnimation(L"Move_l", true);
			else if (mDirection == eDirection::Right)
				mAnimator->PlayAnimation(L"Move_r", true);

			animationFlag = true;
		}

		// 0.5초간 랜덤한 방향으로 걸어감
		if (mDirection == eDirection::Left)
			mTransform->AddPosition(Vector3(-3.0f * Time::DeltaTime(), 0.0f, 0.0f));
		else if (mDirection == eDirection::Right)
			mTransform->AddPosition(Vector3(3.0f * Time::DeltaTime(), 0.0f, 0.0f));

		// 
		mTime += Time::DeltaTime();
		if (mTime >= 1.0f)
		{
			mTime = 0.0f;
			mState = eCaveManState::Idle;
			animationFlag = false;
		}
	}

	void CaveMan::chase()
	{

	}

	void CaveMan::death()
	{
		if (animationFlag == false)
		{
			if (mDirection == eDirection::Left)
				mAnimator->PlayAnimation(L"Death_l", true);
			else if (mDirection == eDirection::Right)
				mAnimator->PlayAnimation(L"Death_r", true);

			animationFlag = true;
		}
	}
}
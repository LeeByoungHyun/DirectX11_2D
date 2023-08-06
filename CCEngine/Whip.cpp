#include "Whip.h"
#include "ccMeshRenderer.h"
#include "ccResourceManager.h"
#include "ccTransform.h"
#include "ccCollider2D.h"
#include "ccAnimator.h"
#include "ccObject.h"
#include "ccScene.h"

#include "Player.h"
#include "WhipColliderScript.h"

namespace cc
{
	extern const float PLAYERDEPTH;

	Whip::Whip()
	{
		animationFlag = false;
	}

	Whip::~Whip()
	{

	}

	void Whip::Initialize()
	{
		GameObject::Initialize();

		mMeshRenderer = AddComponent<MeshRenderer>();
		mMeshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"SpriteAnimationMaterial"));

		mTransform = GetComponent<Transform>();
		mTransform->SetScale(Vector3(2.0f, 2.0f, 0.0f));
		//mTransform->SetParent(Player::GetInstance()->GetComponent<Transform>());

		mCollider = AddComponent<Collider2D>();
		mCollider->SetSize(Vector2(0.5f, 0.5f));

		mDirection = Player::GetInstance()->GetPlayerDirection();

		// amimator
		{
			std::shared_ptr<Texture> atlas
				= ResourceManager::Load<Texture>(L"whip.png", L"..\\Resources\\Texture\\Player\\whip.png");

			mAnimator = AddComponent<Animator>();
			mAnimator->Create(L"WhipWieldStart_r", atlas, Vector2(128.0f * 0, 128.0f * 0), Vector2(128.0f, 128.0f), 3, Vector2::Zero, 0.05f);
			mAnimator->Create(L"WhipWieldStart_l", atlas, Vector2(128.0f * 0, 128.0f * 1), Vector2(128.0f, 128.0f), 3, Vector2::Zero, 0.05f);
			mAnimator->Create(L"WhipWield_r", atlas, Vector2(128.0f * 3, 128.0f * 0), Vector2(128.0f, 128.0f), 3, Vector2::Zero, 0.05f);
			mAnimator->Create(L"WhipWield_l", atlas, Vector2(128.0f * 3, 128.0f * 1), Vector2(128.0f, 128.0f), 3, Vector2::Zero, 0.05f);

			mAnimator->CompleteEvent(L"WhipWieldStart_r") = std::bind(&Whip::wieldStartEnd, this);
			mAnimator->CompleteEvent(L"WhipWieldStart_l") = std::bind(&Whip::wieldStartEnd, this);
			mAnimator->CompleteEvent(L"WhipWield_r") = std::bind(&Whip::wieldEnd, this);
			mAnimator->CompleteEvent(L"WhipWield_l") = std::bind(&Whip::wieldEnd, this);
		}
		
		mState = eWhipState::WieldStart;
		mAnimator->PlayAnimation(L"WhipWieldStart_r", true);

		// script
		AddComponent<WhipColliderScript>();
	}

	void Whip::Update()
	{
		GameObject::Update();

		mTransform->SetPosition(Player::GetInstance()->GetComponent<Transform>()->GetPosition());
		mTransform->AddPosition(Vector3(0.0f, 0.0f, 0.01f));

		switch (mState)
		{
		case cc::Whip::eWhipState::WieldStart:
			wieldStart();
			break;

		case cc::Whip::eWhipState::Wield:
			wield();
			break;
		}
	}

	void Whip::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void Whip::Render()
	{
		GameObject::Render();
	}

	void Whip::wieldStart()
	{
		if (animationFlag == false)
		{
			if (mDirection == eDirection::Left)
				mAnimator->PlayAnimation(L"WhipWieldStart_l", true);
			else if (mDirection == eDirection::Right)
				mAnimator->PlayAnimation(L"WhipWieldStart_r", true);

			animationFlag = true;
		}

		Vector3 pos = mTransform->GetPosition();
		if (mDirection == eDirection::Left)
			mTransform->SetPosition(pos + Vector3(0.5f, 0.15f, 0.0f));
		else if (mDirection == eDirection::Right)
			mTransform->SetPosition(pos + Vector3(-0.5f, 0.15f, 0.0f));
	}

	void Whip::wield()
	{
		if (animationFlag == false)
		{
			if (mDirection == eDirection::Left)
				mAnimator->PlayAnimation(L"WhipWield_l", true);
			else if (mDirection == eDirection::Right)
				mAnimator->PlayAnimation(L"WhipWield_r", true);

			animationFlag = true;
		}

		Vector3 pos = mTransform->GetPosition();
		if (mDirection == eDirection::Left)
			mTransform->SetPosition(pos + Vector3(-0.5f, -0.3f, 0.0f));
		else if (mDirection == eDirection::Right)
			mTransform->SetPosition(pos + Vector3(0.5f, -0.3f, 0.0f));
	}

	void Whip::wieldStartEnd()
	{
		animationFlag = false;
		mState = eWhipState::Wield;
	}

	void Whip::wieldEnd()
	{
		object::Destroy(this);
	}
}
#include "PlayerCheckOnPlatformCollider.h"
#include "ccCollider2D.h"
#include "ccTransform.h"
#include "Player.h"
#include "PlayerCheckOnPlatformScript.h"

namespace cc
{
	PlayerCheckOnPlatformCollider::PlayerCheckOnPlatformCollider()
	{
		mTransform = GetComponent<Transform>();
		mCollider = AddComponent<Collider2D>();
	}

	PlayerCheckOnPlatformCollider::~PlayerCheckOnPlatformCollider()
	{

	}

	void PlayerCheckOnPlatformCollider::Initialize()
	{
		GameObject::Initialize();

		mCollider->SetSize(Vector2(0.9f, 1.1f));
		mCollider->SetCenter(Vector2(0.0f, 0.0f));

		// Script
		AddComponent<PlayerCheckOnPlatformScript>();
	}

	void PlayerCheckOnPlatformCollider::Update()
	{
		GameObject::Update();

		if (Player::GetInstance() != nullptr)
			mTransform->SetPosition(Player::GetInstance()->GetComponent<Transform>()->GetPosition());
		else
			mTransform->SetPosition(Vector3::Zero);
	}

	void PlayerCheckOnPlatformCollider::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void PlayerCheckOnPlatformCollider::Render()
	{
		GameObject::Render();
	}
}
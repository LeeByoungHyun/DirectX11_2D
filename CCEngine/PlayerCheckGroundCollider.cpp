#include "PlayerCheckGroundCollider.h"
#include "ccCollider2D.h"
#include "ccTransform.h"
#include "Player.h"
#include "PlayerCheckGroundScript.h"

namespace cc
{
	PlayerCheckPosition::PlayerCheckPosition()
	{
		mTransform = GetComponent<Transform>();
		mCollider = AddComponent<Collider2D>();
	}

	PlayerCheckPosition::~PlayerCheckPosition()
	{

	}

	void PlayerCheckPosition::Initialize()
	{
		GameObject::Initialize();

		mCollider->SetSize(Vector2(0.9f, 1.0f));
		mCollider->SetCenter(Vector2(0.0f, 0.0f));

		// Script
		AddComponent<PlayerCheckGroundScript>();
	}

	void PlayerCheckPosition::Update()
	{
		GameObject::Update();

		if (Player::GetInstance() != nullptr)
			mTransform->SetPosition(Player::GetInstance()->GetComponent<Transform>()->GetPosition());
		else
			mTransform->SetPosition(Vector3::Zero);
	}

	void PlayerCheckPosition::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void PlayerCheckPosition::Render()
	{
		GameObject::Render();
	}
}
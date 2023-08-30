#include "PlayerCheckOnPlatformScript.h"
#include "ccGameObject.h"
#include "ccRigidbody.h"
#include "Player.h"

namespace cc
{
	PlayerCheckOnPlatformScript::PlayerCheckOnPlatformScript()
	{
		onPlatform = false;
	}

	PlayerCheckOnPlatformScript::~PlayerCheckOnPlatformScript()
	{

	}

	void PlayerCheckOnPlatformScript::Initialize()
	{
		Script::Initialize();
	}

	void PlayerCheckOnPlatformScript::Update()
	{
		Script::Update();

		onPlatform = false;
	}

	void PlayerCheckOnPlatformScript::LateUpdate()
	{
		Script::LateUpdate();

		if (onPlatform != true)
		{
			Player::GetInstance()->SetIsFalling(true);
			Player::GetInstance()->SetIsOnPlatform(false);
		}
		else
		{
			Player::GetInstance()->SetIsFalling(false);
			Player::GetInstance()->SetIsOnPlatform(true);
		}
	}

	void PlayerCheckOnPlatformScript::Render()
	{
		Script::Render();
	}

	void PlayerCheckOnPlatformScript::OnCollisionEnter(Collider2D* other)
	{
		Script::OnCollisionEnter(other);

		if (other->GetOwner()->GetType() == eLayerType::Platform)
		{
			//other->GetOwner()->GetComponent<Transform>()->Update();
			//other->GetOwner()->GetComponent<Collider2D>()->Update();

			onPlatform = true; 
			Player::GetInstance()->SetIsFalling(false);
		}
	}

	void PlayerCheckOnPlatformScript::OnCollisionStay(Collider2D* other)
	{
		Script::OnCollisionStay(other);

		if (other->GetOwner()->GetType() == eLayerType::Platform)
		{
			//other->GetOwner()->GetComponent<Transform>()->Update();
			//other->GetOwner()->GetComponent<Collider2D>()->Update();

			onPlatform = true;
			Player::GetInstance()->SetIsFalling(false);
		}
	}

	void PlayerCheckOnPlatformScript::OnCollisionExit(Collider2D* other)
	{
		Script::OnCollisionExit(other);
	}
}
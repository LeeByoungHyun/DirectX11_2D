#include "PlayerCheckGroundScript.h"
#include "ccGameObject.h"
#include "ccRigidbody.h"
#include "Player.h"

namespace cc
{
	PlayerCheckGroundScript::PlayerCheckGroundScript()
	{
		onGround = false;
	}

	PlayerCheckGroundScript::~PlayerCheckGroundScript()
	{

	}

	void PlayerCheckGroundScript::Initialize()
	{
		Script::Initialize();
	}

	void PlayerCheckGroundScript::Update()
	{
		Script::Update();

		onGround = false;
	}

	void PlayerCheckGroundScript::LateUpdate()
	{
		Script::LateUpdate();

		if (onGround != true)
		{
			//Player::GetInstance()->GetComponent<Rigidbody>()->SetGround(false);
			Player::GetInstance()->SetIsFalling(true);
		}
	}

	void PlayerCheckGroundScript::Render()
	{
		Script::Render();
	}

	void PlayerCheckGroundScript::OnCollisionEnter(Collider2D* other)
	{
		Script::OnCollisionEnter(other);

		Player::GetInstance()->SetIsFalling(false);

		onGround = true;
	}

	void PlayerCheckGroundScript::OnCollisionStay(Collider2D* other)
	{
		Script::OnCollisionStay(other);

		Player::GetInstance()->SetIsFalling(false);

		onGround = true;
	}

	void PlayerCheckGroundScript::OnCollisionExit(Collider2D* other)
	{
		Script::OnCollisionExit(other);
	}

	bool PlayerCheckGroundScript::IsFalling()
	{
		return false;
	}

	bool PlayerCheckGroundScript::IsOnGround()
	{
		return false;
	}
}
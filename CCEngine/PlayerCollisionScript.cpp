#include "PlayerCollisionScript.h"
#include "ccGameObject.h"
#include "ccRigidbody.h"
#include "Player.h"

namespace cc
{
	PlayerCollisionScript::PlayerCollisionScript()
	{
		onTile = false;
	}

	PlayerCollisionScript::~PlayerCollisionScript()
	{

	}

	void PlayerCollisionScript::Initialize()
	{
		Script::Initialize();
	}

	void PlayerCollisionScript::Update()
	{
		Script::Update();
	}

	void PlayerCollisionScript::LateUpdate()
	{
		Script::LateUpdate();
	}

	void PlayerCollisionScript::Render()
	{
		Script::Render();
	}

	void PlayerCollisionScript::OnCollisionEnter(Collider2D* other)
	{
		Script::OnCollisionEnter(other);

		eLayerType otherType = other->GetOwner()->GetType();
		switch (otherType)
		{
		case eLayerType::Tile:
			//if (onTile == false)
			//{
			//	onTile = true;
			//
			//	this->GetOwner()->GetComponent<Rigidbody>()->SetGround(true);
			//	Player::GetInstance()->SetPlayerState(Player::ePlayerState::Idle);
			//}

			if (!this->GetOwner()->GetComponent<Rigidbody>()->GetGround())
			{
				this->GetOwner()->GetComponent<Rigidbody>()->SetGround(true);
				Player::GetInstance()->SetPlayerState(Player::ePlayerState::Idle);
			}
			

			break;
		}
	}

	void PlayerCollisionScript::OnCollisionStay(Collider2D* other)
	{
		Script::OnCollisionStay(other);
	}

	void PlayerCollisionScript::OnCollisionExit(Collider2D* other)
	{
		Script::OnCollisionExit(other);

		eLayerType otherType = other->GetOwner()->GetType();
		switch (otherType)
		{
		case eLayerType::Tile:
			this->GetOwner()->GetComponent<Rigidbody>()->SetGround(false);
			onTile = false;

			break;

		}
	}
}
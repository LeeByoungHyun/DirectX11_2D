#include "PlayerCollisionScript.h"
#include "ccGameObject.h"
#include "ccRigidbody.h"
#include "Player.h"

namespace cc
{
	PlayerCollisionScript::PlayerCollisionScript()
	{
		player = Player::GetInstance();
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

		Player* player = dynamic_cast<Player*>(this->GetOwner());
	}

	void PlayerCollisionScript::LateUpdate()
	{
		Script::LateUpdate();

		if (onTile == false)
		{
			this->GetOwner()->GetComponent<Rigidbody>()->SetGround(false);
		}
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

		// Ÿ��
		case eLayerType::Tile:
			if (player->GetPlayerState() == Player::ePlayerState::Ghost)
				return;

			onTile = true;

			collisionCheck(other);

			break;
		}
	}

	void PlayerCollisionScript::OnCollisionStay(Collider2D* other)
	{
		Script::OnCollisionStay(other);

		eLayerType otherType = other->GetOwner()->GetType();
		switch (otherType)
		{
		case eLayerType::Tile:
			//this->GetOwner()->GetComponent<Rigidbody>()->SetGround(false);
			//onTile = true;

			collisionCheck(other);

			break;

		}
	}

	void PlayerCollisionScript::OnCollisionExit(Collider2D* other)
	{
		Script::OnCollisionExit(other);

		eLayerType otherType = other->GetOwner()->GetType();
		switch (otherType)
		{
		case eLayerType::Tile:

			break;

		}
	}

	void PlayerCollisionScript::collisionCheck(Collider2D* other)
	{
		Collider2D* playerCol = this->GetOwner()->GetComponent<Collider2D>();
		Collider2D* otherCol = other->GetOwner()->GetComponent<Collider2D>();

		Vector3 playerColPos = playerCol->GetPosition();
		Vector3 otherColPos = otherCol->GetPosition();

		float lenX = 0.0f;
		float lenY = 0.0f;

		// �浹ü�� ��ģ �κ��� x���� ���
		if (playerColPos.x <= otherColPos.x)
			lenX = (playerColPos.x + (playerCol->GetScale().x / 2)) - (otherColPos.x - (otherCol->GetScale().x / 2)) + 0.00f;
		else
			lenX = (playerColPos.x - (playerCol->GetScale().x / 2)) - (otherColPos.x + (otherCol->GetScale().x / 2)) - 0.00f;

		// �浹ü�� ��ģ �κ��� y���� ���																				  
		if (playerColPos.y <= otherColPos.y)
			lenY = (playerColPos.y + (playerCol->GetScale().y / 2)) - (otherColPos.y - (otherCol->GetScale().y / 2)) + 0.00f;
		else
			lenY = (playerColPos.y - (playerCol->GetScale().y / 2)) - (otherColPos.y + (otherCol->GetScale().y / 2)) - 0.00f;

		// ��ü�� �����¿� ��� �浹�ߴ��� ���
		// �浹�� ��ü�� �����¿쿡 ������ ������ ���� ��
		// other�� ���� ���� ������ �浹�� ������ �浹 ����
		float checkX[4] = { 0.0f };
		float checkY[4] = { 0.0f };
		float checkArea[4] = { 0.0f };

		Vector3 checkColPos[4] =
		{
			playerColPos + Vector3(0.0f, playerCol->GetScale().y, 0.0f),	// ��
			playerColPos - Vector3(0.0f, playerCol->GetScale().y, 0.0f),	// ��
			playerColPos - Vector3(playerCol->GetScale().x, 0.0f, 0.0f),	// ��
			playerColPos + Vector3(playerCol->GetScale().x, 0.0f, 0.0f),	// ��
		};
		checkX[0] = 0.0f;
		checkY[0] = 0.0f;
		for (UINT i = 0; i < 4; i++)
		{
			if (checkColPos[i].x <= otherColPos.x)
				checkX[i] = (checkColPos[i].x + (playerCol->GetScale().x / 2)) - (otherColPos.x - (otherCol->GetScale().x / 2));
			else
				checkX[i] = (checkColPos[i].x - (playerCol->GetScale().x / 2)) - (otherColPos.x + (otherCol->GetScale().x / 2));

			if (checkColPos[i].y <= otherColPos.y)
				checkY[i] = (checkColPos[i].y + (playerCol->GetScale().y / 2)) - (otherColPos.y - (otherCol->GetScale().y / 2));
			else
				checkY[i] = (checkColPos[i].y - (playerCol->GetScale().y / 2)) - (otherColPos.y + (otherCol->GetScale().y / 2));
			checkArea[i] = abs(checkX[i]) * abs(checkY[i]);
		}

		int dir = 0;
		float largest = 0.0f;
		for (UINT i = 0; i < 4; i++)
		{
			if (largest < checkArea[i])
			{
				largest = checkArea[i];
				dir = i;
			}
		}

		if (dir == (UINT)eDirection::Up)	// ��
		{
			//Vector2 vel = Player::GetInstance()->GetComponent<Rigidbody>()->GetVelocity();
			//Player::GetInstance()->GetComponent<Rigidbody>()->SetVelocity(vel);
		}
		else if (dir == (UINT)eDirection::Down)	// ��
		{
			// 
			if (Player::GetInstance()->GetComponent<Rigidbody>()->GetGround() == false)
			{
				Player::GetInstance()->GetComponent<Rigidbody>()->SetGround(true);

				// tile�� �������� �� Ư�� state�� �ƴ϶�� idle
				if (Player::GetInstance()->GetPlayerState() != Player::ePlayerState::Attack)
				{
					Player::GetInstance()->SetPlayerState(Player::ePlayerState::Idle);
				}
			}

			//Player::GetInstance()->GetComponent<Rigidbody>()->SetGround(true);
			//Player::GetInstance()->SetPlayerState(Player::ePlayerState::Idle);
		}
		else if (dir == (UINT)eDirection::Left)	// ��
		{
			Vector2 vel = Player::GetInstance()->GetComponent<Rigidbody>()->GetVelocity();
		}
		else if (dir == (UINT)eDirection::Right)	// ��
		{
			Vector2 vel = Player::GetInstance()->GetComponent<Rigidbody>()->GetVelocity();
		}
	}
}
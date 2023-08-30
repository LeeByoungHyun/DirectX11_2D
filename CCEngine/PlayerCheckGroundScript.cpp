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
			Player::GetInstance()->SetIsFalling(true);
			Player::GetInstance()->SetIsOnGround(false);
		}
		else
		{
			Player::GetInstance()->SetIsFalling(false);
			Player::GetInstance()->SetIsOnGround(true);
		}
	}

	void PlayerCheckGroundScript::Render()
	{
		Script::Render();
	}

	void PlayerCheckGroundScript::OnCollisionEnter(Collider2D* other)
	{
		Script::OnCollisionEnter(other);

		collisionCheck(other);
	}

	void PlayerCheckGroundScript::OnCollisionStay(Collider2D* other)
	{
		Script::OnCollisionStay(other);

		collisionCheck(other);
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

	void PlayerCheckGroundScript::collisionCheck(Collider2D* other)
	{
		// tile �̿��� object�� �浹�� return
		if (other->GetOwner()->GetType() != eLayerType::Tile)
			return;

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
			if (Player::GetInstance()->GetComponent<Rigidbody>()->GetVelocity().y >= 0.0f)
			{
				Player::GetInstance()->SetIsFalling(false);
				onGround = true;
			}
		}
		else if (dir == (UINT)eDirection::Down)	// ��
		{
			
		}
		else if (dir == (UINT)eDirection::Left)	// ��
		{

		}
		else if (dir == (UINT)eDirection::Right)	// ��
		{

		}
	}
}
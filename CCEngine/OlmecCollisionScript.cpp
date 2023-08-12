#include "OlmecCollisionScript.h"
#include "ccGameObject.h"
#include "ccRigidbody.h"
#include "ccTime.h"

#include "Olmec.h"
#include "Tile.h"

namespace cc
{
	OlmecCollisionScript::OlmecCollisionScript()
	{
		mTime = 0.0f;
		crashFlag = false;
	}

	OlmecCollisionScript::~OlmecCollisionScript()
	{

	}

	void OlmecCollisionScript::Initialize()
	{

	}

	void OlmecCollisionScript::Update()
	{
		if (crashFlag == true)
		{
			mTime += Time::DeltaTime();
			if (mTime >= 0.05f)
			{
				Olmec* olmec = dynamic_cast<Olmec*>(this->GetOwner());
				olmec->SetOlmecState(Olmec::eOlmecState::Idle);
				olmec->InitializeState();
				crashFlag = false;
			}
		}
	}

	void OlmecCollisionScript::LateUpdate()
	{

	}

	void OlmecCollisionScript::Render()
	{

	}

	void OlmecCollisionScript::OnCollisionEnter(Collider2D* other)
	{
		Olmec* olmec = dynamic_cast<Olmec*>(this->GetOwner());

		// 충돌체가 밀려나야 하는 물체인 경우
		if (other->GetOwner()->GetType() == eLayerType::Player)
		{
			PushObject(other);
		}

		// 
		if (other->GetOwner()->GetType() == eLayerType::Tile)
		{
			// 특정 state에서 tile과 충돌시 return
			if (olmec->GetOlmecState() == Olmec::eOlmecState::Awake)
				return;

			// 충돌한 tile이 파괴 가능한 tile일 경우 파괴
			//if (olmec->GetOlmecState() == Olmec::eOlmecState::Crash)
			//{
			//	Tile* tile = dynamic_cast<Tile*>(other->GetOwner());
			//	tile->DestroyTile();
			//	crashFlag = true;
			//}
			else
			{
				collisionCheck(other);
				//olmec->SetOlmecState(Olmec::eOlmecState::Idle);
				//olmec->GetComponent<Rigidbody>()->SetGround(true);
			}	
		}
	}

	void OlmecCollisionScript::OnCollisionStay(Collider2D* other)
	{
		Olmec* olmec = dynamic_cast<Olmec*>(this->GetOwner());

		// 충돌체가 플레이어일 경우 밀어냄
		if (other->GetOwner()->GetType() == eLayerType::Player)
		{
			PushObject(other);
		}

		if (other->GetOwner()->GetType() == eLayerType::Tile)
		{
			// 특정 state에서 tile과 충돌시 return
			if (olmec->GetOlmecState() == Olmec::eOlmecState::Awake)
				return;

		}
	}

	void OlmecCollisionScript::OnCollisionExit(Collider2D* other)
	{

	}

	void OlmecCollisionScript::PushObject(Collider2D* other)
	{
		Collider2D* olmecCol = this->GetOwner()->GetComponent<Collider2D>();
		Collider2D* otherCol = other->GetOwner()->GetComponent<Collider2D>();

		Vector3 olmecColPos = olmecCol->GetPosition();
		Vector3 otherColPos = otherCol->GetPosition();

		float lenX = 0.0f;
		float lenY = 0.0f;

		// 충돌체가 겹친 부분의 x길이 계산
		if (olmecColPos.x <= otherColPos.x)
			lenX = (olmecColPos.x + (olmecCol->GetScale().x / 2)) - (otherColPos.x - (otherCol->GetScale().x / 2)) + 0.00f;
		else
			lenX = (olmecColPos.x - (olmecCol->GetScale().x / 2)) - (otherColPos.x + (otherCol->GetScale().x / 2)) - 0.00f;

		// 충돌체가 겹친 부분의 y길이 계산																				  
		if (olmecColPos.y <= otherColPos.y)
			lenY = (olmecColPos.y + (olmecCol->GetScale().y / 2)) - (otherColPos.y - (otherCol->GetScale().y / 2)) + 0.00f;
		else
			lenY = (olmecColPos.y - (olmecCol->GetScale().y / 2)) - (otherColPos.y + (otherCol->GetScale().y / 2)) - 0.00f;

		// 물체가 상하좌우 어디서 충돌했는지 계산
		// 충돌시 물체의 상하좌우에 가상의 공간을 만든 후
		// other와 가장 넓은 범위로 충돌한 공간이 충돌 방향
		float checkX[4] = { 0.0f };
		float checkY[4] = { 0.0f };
		float checkArea[4] = { 0.0f };

		Vector3 checkColPos[4] =
		{
			olmecColPos + Vector3(0.0f, olmecCol->GetScale().y, 0.0f),
			olmecColPos - Vector3(0.0f, olmecCol->GetScale().y, 0.0f),
			olmecColPos - Vector3(olmecCol->GetScale().x, 0.0f, 0.0f),
			olmecColPos + Vector3(olmecCol->GetScale().x, 0.0f, 0.0f),
		};
		checkX[0] = 0.0f;
		checkY[0] = 0.0f;
		for (UINT i = 0; i < 4; i++)
		{
			if (checkColPos[i].x <= otherColPos.x)
				checkX[i] = (checkColPos[i].x + (olmecCol->GetScale().x / 2)) - (otherColPos.x - (otherCol->GetScale().x / 2));
			else
				checkX[i] = (checkColPos[i].x - (olmecCol->GetScale().x / 2)) - (otherColPos.x + (otherCol->GetScale().x / 2));

			if (checkColPos[i].y <= otherColPos.y)
				checkY[i] = (checkColPos[i].y + (olmecCol->GetScale().y / 2)) - (otherColPos.y - (otherCol->GetScale().y / 2));
			else
				checkY[i] = (checkColPos[i].y - (olmecCol->GetScale().y / 2)) - (otherColPos.y + (otherCol->GetScale().y / 2));
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

		if (dir == 0)	// 상
		{
			other->GetOwner()->GetComponent<Transform>()->AddPosition(Vector3(0.0f, lenY, 0.0f));
			other->GetOwner()->GetComponent<Rigidbody>()->SetGround(true);
		}
		else if (dir == 1)	// 하
		{
			other->GetOwner()->GetComponent<Transform>()->AddPosition(Vector3(0.0f, lenY, 0.0f));
		}
		else if (dir == 2 || dir == 3)	// 좌우
		{
			other->GetOwner()->GetComponent<Transform>()->AddPosition(Vector3(lenX, 0.0f, 0.0f));
		}
	}

	void OlmecCollisionScript::PushOlmec(Collider2D* other)
	{
		Collider2D* olmecCol = this->GetOwner()->GetComponent<Collider2D>();
		Collider2D* otherCol = other->GetOwner()->GetComponent<Collider2D>();

		Vector3 olmecColPos = olmecCol->GetPosition();
		Vector3 otherColPos = otherCol->GetPosition();

		float lenX = 0.0f;
		float lenY = 0.0f;

		// 충돌체가 겹친 부분의 x길이 계산
		if (olmecColPos.x <= otherColPos.x)
			lenX = (olmecColPos.x + (olmecCol->GetScale().x / 2)) - (otherColPos.x - (otherCol->GetScale().x / 2)) + 0.00f;
		else
			lenX = (olmecColPos.x - (olmecCol->GetScale().x / 2)) - (otherColPos.x + (otherCol->GetScale().x / 2)) - 0.00f;

		// 충돌체가 겹친 부분의 y길이 계산																				  
		if (olmecColPos.y <= otherColPos.y)
			lenY = (olmecColPos.y + (olmecCol->GetScale().y / 2)) - (otherColPos.y - (otherCol->GetScale().y / 2)) + 0.00f;
		else
			lenY = (olmecColPos.y - (olmecCol->GetScale().y / 2)) - (otherColPos.y + (otherCol->GetScale().y / 2)) - 0.00f;

		// 물체가 상하좌우 어디서 충돌했는지 계산
		// 충돌시 물체의 상하좌우에 가상의 공간을 만든 후
		// other와 가장 넓은 범위로 충돌한 공간이 충돌 방향
		float checkX[4] = { 0.0f };
		float checkY[4] = { 0.0f };
		float checkArea[4] = { 0.0f };

		Vector3 checkColPos[4] =
		{
			olmecColPos + Vector3(0.0f, olmecCol->GetScale().y, 0.0f),
			olmecColPos - Vector3(0.0f, olmecCol->GetScale().y, 0.0f),
			olmecColPos - Vector3(olmecCol->GetScale().x, 0.0f, 0.0f),
			olmecColPos + Vector3(olmecCol->GetScale().x, 0.0f, 0.0f),
		};
		checkX[0] = 0.0f;
		checkY[0] = 0.0f;
		for (UINT i = 0; i < 4; i++)
		{
			if (checkColPos[i].x <= otherColPos.x)
				checkX[i] = (checkColPos[i].x + (olmecCol->GetScale().x / 2)) - (otherColPos.x - (otherCol->GetScale().x / 2));
			else
				checkX[i] = (checkColPos[i].x - (olmecCol->GetScale().x / 2)) - (otherColPos.x + (otherCol->GetScale().x / 2));

			if (checkColPos[i].y <= otherColPos.y)
				checkY[i] = (checkColPos[i].y + (olmecCol->GetScale().y / 2)) - (otherColPos.y - (otherCol->GetScale().y / 2));
			else
				checkY[i] = (checkColPos[i].y - (olmecCol->GetScale().y / 2)) - (otherColPos.y + (otherCol->GetScale().y / 2));
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

		if (dir == 0)	// 상
		{
			this->GetOwner()->GetComponent<Transform>()->AddPosition(Vector3(0.0f, lenY, 0.0f));
			this->GetOwner()->GetComponent<Rigidbody>()->SetGround(true);

		}
		else if (dir == 1)	// 하
		{
			this->GetOwner()->GetComponent<Transform>()->AddPosition(Vector3(0.0f, lenY, 0.0f));
		}
		else if (dir == 2 || dir == 3)	// 좌우
		{
			this->GetOwner()->GetComponent<Transform>()->AddPosition(Vector3(lenX, 0.0f, 0.0f));
		}
	}

	void OlmecCollisionScript::collisionCheck(Collider2D* other)
	{
		Olmec* olmec = dynamic_cast<Olmec*>(this->GetOwner());

		Collider2D* playerCol = this->GetOwner()->GetComponent<Collider2D>();
		Collider2D* olmecCol = other->GetOwner()->GetComponent<Collider2D>();

		Vector3 playerColPos = playerCol->GetPosition();
		Vector3 olmecColPos = olmecCol->GetPosition();

		float lenX = 0.0f;
		float lenY = 0.0f;

		// 충돌체가 겹친 부분의 x길이 계산
		if (playerColPos.x <= olmecColPos.x)
			lenX = (playerColPos.x + (playerCol->GetScale().x / 2)) - (olmecColPos.x - (olmecCol->GetScale().x / 2)) + 0.00f;
		else
			lenX = (playerColPos.x - (playerCol->GetScale().x / 2)) - (olmecColPos.x + (olmecCol->GetScale().x / 2)) - 0.00f;

		// 충돌체가 겹친 부분의 y길이 계산																				  
		if (playerColPos.y <= olmecColPos.y)
			lenY = (playerColPos.y + (playerCol->GetScale().y / 2)) - (olmecColPos.y - (olmecCol->GetScale().y / 2)) + 0.00f;
		else
			lenY = (playerColPos.y - (playerCol->GetScale().y / 2)) - (olmecColPos.y + (olmecCol->GetScale().y / 2)) - 0.00f;

		// 물체가 상하좌우 어디서 충돌했는지 계산
		// 충돌시 물체의 상하좌우에 가상의 공간을 만든 후
		// other와 가장 넓은 범위로 충돌한 공간이 충돌 방향
		float checkX[4] = { 0.0f };
		float checkY[4] = { 0.0f };
		float checkArea[4] = { 0.0f };

		Vector3 checkColPos[4] =
		{
			playerColPos - Vector3(0.0f, playerCol->GetScale().y, 0.0f),	// 상
			playerColPos + Vector3(0.0f, playerCol->GetScale().y, 0.0f),	// 하
			playerColPos - Vector3(playerCol->GetScale().x, 0.0f, 0.0f),	// 좌
			playerColPos + Vector3(playerCol->GetScale().x, 0.0f, 0.0f),	// 우
		};
		checkX[0] = 0.0f;
		checkY[0] = 0.0f;
		for (UINT i = 0; i < 4; i++)
		{
			if (checkColPos[i].x <= olmecColPos.x)
				checkX[i] = (checkColPos[i].x + (playerCol->GetScale().x / 2)) - (olmecColPos.x - (olmecCol->GetScale().x / 2));
			else
				checkX[i] = (checkColPos[i].x - (playerCol->GetScale().x / 2)) - (olmecColPos.x + (olmecCol->GetScale().x / 2));

			if (checkColPos[i].y <= olmecColPos.y)
				checkY[i] = (checkColPos[i].y + (playerCol->GetScale().y / 2)) - (olmecColPos.y - (olmecCol->GetScale().y / 2));
			else
				checkY[i] = (checkColPos[i].y - (playerCol->GetScale().y / 2)) - (olmecColPos.y + (olmecCol->GetScale().y / 2));
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

		if (dir == (UINT)eDirection::Up)	// 상
		{
			
		}
		else if (dir == (UINT)eDirection::Down)	// 하
		{
			// 충돌한 tile이 파괴 가능한 tile일 경우 파괴
			if (olmec->GetOlmecState() == Olmec::eOlmecState::Crash)
			{
				Tile* tile = dynamic_cast<Tile*>(other->GetOwner());
				tile->DestroyTile();
				crashFlag = true;
			}
			else
			{
				olmec->SetOlmecState(Olmec::eOlmecState::Idle);
				olmec->GetComponent<Rigidbody>()->SetGround(true);
				olmec->InitializeState();
			}
			
		}
		else if (dir == (UINT)eDirection::Left)	// 좌
		{

		}
		else if (dir == (UINT)eDirection::Right)	// 우
		{

		}
	}
}
#include "TileColliderScript.h"
#include "ccTransform.h"
#include "ccGameObject.h"
#include "ccCollider2D.h"
#include "ccRigidbody.h"
#include "Olmec.h"

namespace cc
{
	TileColliderScript::TileColliderScript()
	{

	}

	TileColliderScript::~TileColliderScript()
	{

	}

	void TileColliderScript::Initialize()
	{

	}

	void TileColliderScript::Update()
	{

	}

	void TileColliderScript::LateUpdate()
	{

	}

	void TileColliderScript::Render()
	{

	}

	void TileColliderScript::OnCollisionEnter(Collider2D* other)
	{
		Olmec* olmec = dynamic_cast<Olmec*>(other->GetOwner());
		if (olmec != nullptr)
			return;

		if (other->GetOwner()->GetType() != eLayerType::PlayerCheck)
		{
			Push(other);
		}
		
	}

	void TileColliderScript::OnCollisionStay(Collider2D* other)
	{
		Olmec* olmec = dynamic_cast<Olmec*>(other->GetOwner());

		if (olmec != nullptr)
		{
			if (olmec->GetOlmecState() == Olmec::eOlmecState::Crash)
				return;
		}

		if (other->GetOwner()->GetType() != eLayerType::PlayerCheck)
		{
			Push(other);
		}
	}

	void TileColliderScript::OnCollisionExit(Collider2D* other)
	{
		other->GetOwner()->SetCollisionFlag(false);
		if (other->GetOwner()->GetComponent<Rigidbody>())
		{
			//other->GetOwner()->GetComponent<Rigidbody>()->SetGround(false);

			//other->GetOwner()->GetComponent<Rigidbody>()->SetDirLock(eDirection::Up, false);
			//other->GetOwner()->GetComponent<Rigidbody>()->SetDirLock(eDirection::Right, false);
			//other->GetOwner()->GetComponent<Rigidbody>()->SetDirLock(eDirection::Down, false);
			//other->GetOwner()->GetComponent<Rigidbody>()->SetDirLock(eDirection::Left, false);
		}
	}

	void TileColliderScript::Push(Collider2D* other)
	{
		Collider2D* tileCol = this->GetOwner()->GetComponent<Collider2D>();
		Collider2D* otherCol = other->GetOwner()->GetComponent<Collider2D>();

		Vector3 tileColPos = tileCol->GetPosition();
		Vector3 otherColPos = otherCol->GetPosition();

		float lenX = 0.0f;
		float lenY = 0.0f;

		// 충돌체가 겹친 부분의 x길이 계산
		if (tileColPos.x <= otherColPos.x)
			lenX = (tileColPos.x + (tileCol->GetScale().x / 2)) - (otherColPos.x - (otherCol->GetScale().x / 2)) + 0.00f;
		else
			lenX = (tileColPos.x - (tileCol->GetScale().x / 2)) - (otherColPos.x + (otherCol->GetScale().x / 2)) - 0.00f;

		// 충돌체가 겹친 부분의 y길이 계산																				  
		if (tileColPos.y <= otherColPos.y)
			lenY = (tileColPos.y + (tileCol->GetScale().y / 2)) - (otherColPos.y - (otherCol->GetScale().y / 2)) + 0.00f;
		else
			lenY = (tileColPos.y - (tileCol->GetScale().y / 2)) - (otherColPos.y + (otherCol->GetScale().y / 2)) - 0.00f;

		// 물체가 상하좌우 어디서 충돌했는지 계산
		// 충돌시 물체의 상하좌우에 가상의 공간을 만든 후
		// other와 가장 넓은 범위로 충돌한 공간이 충돌 방향
		float checkX[4] = { 0.0f };
		float checkY[4] = { 0.0f };
		float checkArea[4] = { 0.0f };

		Vector3 checkColPos[4] =
		{
			tileColPos - Vector3(0.0f, tileCol->GetScale().y, 0.0f),	// 상
			tileColPos + Vector3(0.0f, tileCol->GetScale().y, 0.0f),	// 하
			tileColPos - Vector3(tileCol->GetScale().x, 0.0f, 0.0f),	// 좌
			tileColPos + Vector3(tileCol->GetScale().x, 0.0f, 0.0f),	// 우
		};
		checkX[0] = 0.0f;
		checkY[0] = 0.0f;
		for (UINT i = 0; i < 4; i++)
		{
			if (checkColPos[i].x <= otherColPos.x)
				checkX[i] = (checkColPos[i].x + (tileCol->GetScale().x / 2)) - (otherColPos.x - (otherCol->GetScale().x / 2));
			else
				checkX[i] = (checkColPos[i].x - (tileCol->GetScale().x / 2)) - (otherColPos.x + (otherCol->GetScale().x / 2));

			if (checkColPos[i].y <= otherColPos.y)
				checkY[i] = (checkColPos[i].y + (tileCol->GetScale().y / 2)) - (otherColPos.y - (otherCol->GetScale().y / 2));
			else
				checkY[i] = (checkColPos[i].y - (tileCol->GetScale().y / 2)) - (otherColPos.y + (otherCol->GetScale().y / 2));
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
			other->GetOwner()->GetComponent<Transform>()->AddPosition(Vector3(0.0f, lenY, 0.0f));
			//other->GetOwner()->GetComponent<Rigidbody>()->SetGround(true);
			//other->GetOwner()->GetComponent<Rigidbody>()->SetDirLock(eDirection::Up, true);
		}
		else if (dir == (UINT)eDirection::Down)	// 하
		{
			other->GetOwner()->GetComponent<Transform>()->AddPosition(Vector3(0.0f, lenY, 0.0f));
			//other->GetOwner()->GetComponent<Rigidbody>()->SetDirLock(eDirection::Down, true);
		}
		else if (dir == (UINT)eDirection::Left)	// 좌
		{
			other->GetOwner()->GetComponent<Transform>()->AddPosition(Vector3(lenX, 0.0f, 0.0f));
			//other->GetOwner()->GetComponent<Rigidbody>()->SetDirLock(eDirection::Left , true);
		}
		else if (dir == (UINT)eDirection::Right)	// 우
		{
			other->GetOwner()->GetComponent<Transform>()->AddPosition(Vector3(lenX, 0.0f, 0.0f));
			//other->GetOwner()->GetComponent<Rigidbody>()->SetDirLock(eDirection::Right, true);
		}
	}
}
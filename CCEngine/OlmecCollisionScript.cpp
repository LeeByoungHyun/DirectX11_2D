#include "OlmecCollisionScript.h"
#include "ccGameObject.h"
#include "ccRigidbody.h"
#include "Olmec.h"
#include "Tile.h"

namespace cc
{
	OlmecCollisionScript::OlmecCollisionScript()
	{

	}

	OlmecCollisionScript::~OlmecCollisionScript()
	{

	}

	void OlmecCollisionScript::Initialize()
	{

	}

	void OlmecCollisionScript::Update()
	{

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

		if (other->GetOwner()->GetType() == eLayerType::Tile)
		{
			// 충돌한 tile이 파괴 가능한 tile일 경우 파괴
			if (olmec->GetOlmecState() == Olmec::eOlmecState::Crash)
			{
				Tile* tile = dynamic_cast<Tile*>(other->GetOwner());
				tile->DestroyTile();

			}

			// 특정 state에서 tile과 충돌시 return
			if (olmec->GetOlmecState() == Olmec::eOlmecState::Awake
				|| olmec->GetOlmecState() == Olmec::eOlmecState::Idle)
				return;

			olmec->SetOlmecState(Olmec::eOlmecState::Idle);
			olmec->GetComponent<Rigidbody>()->SetGround(true);
			olmec->InitializeState();
		}
	}

	void OlmecCollisionScript::OnCollisionStay(Collider2D* other)
	{
		if (other->GetOwner()->GetType() == eLayerType::Player)
		{
			Collider2D* olmecCol = this->GetOwner()->GetComponent<Collider2D>();
			Collider2D* otherCol = other->GetOwner()->GetComponent<Collider2D>();

			Vector3 tileColPos = olmecCol->GetPosition();
			Vector3 otherColPos = otherCol->GetPosition();

			float lenX = 0.0f;
			float lenY = 0.0f;

			// 충돌체가 겹친 부분의 x길이 계산
			if (tileColPos.x <= otherColPos.x)
				lenX = (tileColPos.x + (olmecCol->GetScale().x / 2)) - (otherColPos.x - (otherCol->GetScale().x / 2)) + 0.00f;
			else
				lenX = (tileColPos.x - (olmecCol->GetScale().x / 2)) - (otherColPos.x + (otherCol->GetScale().x / 2)) - 0.00f;

			// 충돌체가 겹친 부분의 y길이 계산																				  
			if (tileColPos.y <= otherColPos.y)
				lenY = (tileColPos.y + (olmecCol->GetScale().y / 2)) - (otherColPos.y - (otherCol->GetScale().y / 2)) + 0.00f;
			else
				lenY = (tileColPos.y - (olmecCol->GetScale().y / 2)) - (otherColPos.y + (otherCol->GetScale().y / 2)) - 0.00f;

			// 겹친 부분만큼 밀어냄
			if (abs(lenX) > abs(lenY))
				other->GetOwner()->GetComponent<Transform>()->AddPosition(Vector3(0.0f, lenY, 0.0f));
			else
				other->GetOwner()->GetComponent<Transform>()->AddPosition(Vector3(lenX, 0.0f, 0.0f));
		}
	}

	void OlmecCollisionScript::OnCollisionExit(Collider2D* other)
	{

	}
}
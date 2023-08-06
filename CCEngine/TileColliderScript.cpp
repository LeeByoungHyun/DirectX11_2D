#include "TileColliderScript.h"
#include "ccTransform.h"
#include "ccGameObject.h"
#include "ccCollider2D.h"
#include "ccRigidbody.h"

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
		
	}

	void TileColliderScript::OnCollisionStay(Collider2D* other)
	{
		if (other->GetOwner()->GetCollisionFlag() == false)
		{
			Collider2D* tileCol = this->GetOwner()->GetComponent<Collider2D>();
			Collider2D* otherCol = other->GetOwner()->GetComponent<Collider2D>();

			Vector3 tileColPos = tileCol->GetPosition();
			Vector3 otherColPos = otherCol->GetPosition();

			float lenX = 0.0f;
			float lenY = 0.0f;

			// 충돌체가 겹친 부분의 x길이 계산
			if (tileColPos.x <= otherColPos.x)
				lenX = (tileColPos.x + (tileCol->GetScale().x / 2)) - (otherColPos.x - (otherCol->GetScale().x / 2)) + 0.01f;
			else																										  
				lenX = (tileColPos.x - (tileCol->GetScale().x / 2)) - (otherColPos.x + (otherCol->GetScale().x / 2)) - 0.01f;
																														  
			// 충돌체가 겹친 부분의 y길이 계산																				  
			if (tileColPos.y <= otherColPos.y)																			  
				lenY = (tileColPos.y + (tileCol->GetScale().y / 2)) - (otherColPos.y - (otherCol->GetScale().y / 2)) + 0.01f;
			else																										  
				lenY = (tileColPos.y - (tileCol->GetScale().y / 2)) - (otherColPos.y + (otherCol->GetScale().y / 2)) - 0.01f;

			//
			//if (abs(lenX) > tileCol->GetScale().x * 0.5f)
			//	lenX = 0.0f;
			//else
			//	int a = 0;
			//
			//if (abs(lenY) > tileCol->GetScale().y * 0.5f)
			//	lenY = 0.0f;
			//else
			//	other->GetOwner()->GetComponent<Rigidbody>()->SetGround(true);

			// 겹친 부분만큼 밀어냄
			if (abs(lenX) > abs(lenY))
			{
				other->GetOwner()->GetComponent<Transform>()->AddPosition(Vector3(0.0f, lenY, 0.0f));
				other->GetOwner()->GetComponent<Rigidbody>()->SetGround(true);
			}

			else
				other->GetOwner()->GetComponent<Transform>()->AddPosition(Vector3(lenX, 0.0f, 0.0f));

		
			//other->GetOwner()->GetComponent<Transform>()->AddPosition(Vector3(lenX, lenY, 0.0f));
			//other->GetOwner()->SetCollisionFlag(true);
		}
	}

	void TileColliderScript::OnCollisionExit(Collider2D* other)
	{
		other->GetOwner()->SetCollisionFlag(false);
	}
}
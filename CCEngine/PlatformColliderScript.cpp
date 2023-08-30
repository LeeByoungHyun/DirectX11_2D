#include "PlatformColliderScript.h"
#include "ccTransform.h"
#include "ccGameObject.h"
#include "ccCollider2D.h"
#include "ccRigidbody.h"

namespace cc
{
	PlatformColliderScript::PlatformColliderScript()
	{

	}

	PlatformColliderScript::~PlatformColliderScript()
	{

	}

	void PlatformColliderScript::Initialize()
	{
		Script::Initialize();
	}

	void PlatformColliderScript::Update()
	{
		Script::Update();
	}

	void PlatformColliderScript::LateUpdate()
	{
		Script::LateUpdate();
	}

	void PlatformColliderScript::Render()
	{
		Script::Render();
	}

	void PlatformColliderScript::OnCollisionEnter(Collider2D* other)
	{
		Script::OnCollisionEnter(other);

		Push(other);
	}

	void PlatformColliderScript::OnCollisionStay(Collider2D* other)
	{
		Script::OnCollisionStay(other);

		Push(other);
	}

	void PlatformColliderScript::OnCollisionExit(Collider2D* other)
	{
		Script::OnCollisionExit(other);

	}

	void PlatformColliderScript::Push(Collider2D* other)
	{
		if (other->GetOwner()->GetComponent<Rigidbody>() == nullptr)
			return;

		other->GetOwner()->GetComponent<Transform>()->Update();
		other->GetOwner()->GetComponent<Collider2D>()->Update();

		Collider2D* tileCol = this->GetOwner()->GetComponent<Collider2D>();
		Collider2D* otherCol = other->GetOwner()->GetComponent<Collider2D>();

		Vector3 tileColPos = tileCol->GetPosition();
		Vector3 otherColPos = otherCol->GetPosition();

		Vector2 pos = Vector2(tileColPos.x, tileColPos.y + (otherCol->GetScale().y / 2.0f));
		//Vector2 pos = Vector2(tileColPos.x, tileColPos.y + (tileCol->GetScale().y / 2.0f));
		Vector3 otherPos = other->GetOwner()->GetComponent<Transform>()->GetPosition();
		other->GetOwner()->GetComponent<Transform>()->SetPosition(Vector3(otherPos.x, pos.y, otherPos.z));
		other->GetOwner()->GetComponent<Rigidbody>()->SetGround(true);

		other->GetOwner()->GetComponent<Transform>()->Update();
		other->GetOwner()->GetComponent<Collider2D>()->Update();
	}
}
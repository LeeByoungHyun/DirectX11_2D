#include "CaveManColliderScript.h"
#include "CaveMan.h"

namespace cc
{
	CaveManColliderScript::CaveManColliderScript()
	{

	}

	CaveManColliderScript::~CaveManColliderScript()
	{

	}

	void CaveManColliderScript::Initialize()
	{

	}

	void CaveManColliderScript::Update()
	{

	}

	void CaveManColliderScript::LateUpdate()
	{

	}

	void CaveManColliderScript::Render()
	{

	}

	void CaveManColliderScript::OnCollisionEnter(Collider2D* other)
	{
		if (other->GetOwner()->GetType() == eLayerType::Weapon)
		{
			CaveMan* caveman = dynamic_cast<CaveMan*>(this->GetOwner());
			if (caveman == nullptr)
				return;

			caveman->SetHp(caveman->GetHp() - 1);
			if (caveman->GetHp() <= 0)
			{
				caveman->SetCaveManState(CaveMan::eCaveManState::Death);
				caveman->SetAnimationFlag(false);
			}
		}
	}

	void CaveManColliderScript::OnCollisionStay(Collider2D* other)
	{

	}

	void CaveManColliderScript::OnCollisionExit(Collider2D* other)
	{

	}
}
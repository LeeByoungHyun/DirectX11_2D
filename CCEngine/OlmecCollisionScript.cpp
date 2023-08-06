#include "OlmecCollisionScript.h"
#include "ccGameObject.h"
#include "ccRigidbody.h"
#include "Olmec.h"

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
			// �浹�� tile�� �ı� ������ ��� �ı�
			if (olmec->GetOlmecState() == Olmec::eOlmecState::Crash)
			{
				//other
			}

			// olmec ���� ��ȯ
			if (olmec->GetOlmecState() == Olmec::eOlmecState::Awake)
				return;

			olmec->SetOlmecState(Olmec::eOlmecState::Idle);
			olmec->InitializeState();


			
		}
	}

	void OlmecCollisionScript::OnCollisionStay(Collider2D* other)
	{

	}

	void OlmecCollisionScript::OnCollisionExit(Collider2D* other)
	{

	}
}
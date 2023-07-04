#include "ccPlayerMoveScript.h"
#include "ccTransform.h"
#include "ccGameObject.h"
#include "ccTime.h"
#include "ccinput.h"

namespace cc
{
	const float SPEED = 1.0f;

	void PlayerMoveScript::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		if (Input::GetKey(eKeyCode::W))
		{
			pos.y += SPEED * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		if (Input::GetKey(eKeyCode::A))
		{
			pos.x -= SPEED * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		if (Input::GetKey(eKeyCode::S))
		{
			pos.y -= SPEED * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		if (Input::GetKey(eKeyCode::D))
		{
			pos.x += SPEED * Time::DeltaTime();
			tr->SetPosition(pos);
		}
	}
}
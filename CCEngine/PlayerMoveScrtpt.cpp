#include "PlayerMoveScrtpt.h"
#include "ccTransform.h"
#include "ccGameObject.h"
#include "ccTime.h"
#include "ccinput.h"
#include "Player.h"
#include "PlayerCollisionScript.h"

namespace cc
{
	//const float PLAYERWALKSPEED = 500.0f;

	void PlayerMoveScrtpt::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		/*
		if (Input::GetKey(eKeyCode::W))
		{
			pos.y += PLAYERWALKSPEED * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		if (Input::GetKey(eKeyCode::A))
		{
			pos.x -= PLAYERWALKSPEED * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		if (Input::GetKey(eKeyCode::S))
		{
			pos.y -= PLAYERWALKSPEED * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		if (Input::GetKey(eKeyCode::D))
		{
			pos.x += PLAYERWALKSPEED * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		*/
	}
}
#include "ccCameraScript.h"
#include "ccTransform.h"
#include "ccGameObject.h"
#include "ccTime.h"
#include "ccinput.h"
#include "Player.h"

namespace cc
{
	void CameraScript::Update()
	{
		//Vector3 playerPos = Player::GetInstance()->GetComponent<Transform>()->GetPosition();
		//Transform* tr = GetOwner()->GetComponent<Transform>();
		//Vector3 pos = tr->GetPosition();
		//pos.x = playerPos.x;
		//pos.y = playerPos.y;
		//tr->SetPosition(pos);

		/*
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();
		//tr->SetPosition(pos);

		if (Input::GetKey(eKeyCode::W))
		{
			pos.z += 500.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::S))
		{
			pos.z -= 500.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::A))
		{
			pos.x -= 500.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::D))
		{
			pos.x += 500.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::Q))
		{
			pos.y -= 500.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::E))
		{
			pos.y += 500.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		*/
	}
	void CameraScript::LateUpdate()
	{
		Vector3 playerPos = Player::GetInstance()->GetComponent<Transform>()->GetPosition();
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();
		pos.x = playerPos.x;
		pos.y = playerPos.y;
		tr->SetPosition(pos);
	}
}
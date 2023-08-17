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
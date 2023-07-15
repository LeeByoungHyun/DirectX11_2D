#include "TestGunScript.h"
#include "ccTransform.h"
#include "ccGameObject.h"
#include "ccTime.h"
#include "ccinput.h"
#include "Marine.h"
#include "AimCursor.h"

namespace cc
{
	void TestGunScript::Update()
	{
		
	}

	void TestGunScript::LateUpdate()
	{
		Vector3 pos = Marine::GetInstance()->GetPos();
		pos.x += 0.1f;
		pos.y += -0.05f;
		pos.z -= 0.1f;

		Transform* tr = GetOwner()->GetComponent<Transform>();
		tr->SetPosition(pos);

		Vector3 marinePos = Marine::GetInstance()->GetComponent<Transform>()->GetPosition();
		Vector3 cursorPos = AimCursor::GetInstance()->GetPos();
		float radian = atan2(cursorPos.y - marinePos.y, cursorPos.x - marinePos.x);
		//float degree = math::RadianToDegree(radian);

		tr->SetRotation(0.0f, 0.0f, radian);
	}
}
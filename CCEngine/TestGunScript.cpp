#include "TestGunScript.h"
#include "ccTransform.h"
#include "ccGameObject.h"
#include "ccTime.h"
#include "ccinput.h"
#include "Marine.h"

namespace cc
{
	void TestGunScript::Update()
	{
		Vector3 pos = Marine::GetInstance()->GetPos();
		pos.x += 0.1f;
		pos.y += -0.05f;
		pos.z -= 0.1f;

		Transform* tr = GetOwner()->GetComponent<Transform>();
		tr->SetPosition(pos);


	}
}
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
		pos.z -= 0.01f;

		Transform* tr = GetOwner()->GetComponent<Transform>();
		tr->SetPosition(pos);
	}
}
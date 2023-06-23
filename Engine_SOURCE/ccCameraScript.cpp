#include "ccCameraScript.h"
#include "ccTransform.h"
#include "ccGameObject.h"
#include "ccTime.h"

namespace cc
{
	void CameraScript::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		tr->SetPosition(pos);
	}
}
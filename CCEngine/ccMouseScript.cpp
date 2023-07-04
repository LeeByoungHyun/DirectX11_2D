#include "ccMouseScript.h"
#include "ccTransform.h"
#include "ccGameObject.h"
#include "ccTime.h"
#include "ccinput.h"
#include "ccApplication.h"

extern cc::Application application;

namespace cc
{
	void MouseScript::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		Vector2 mousePos = Input::GetMousePos();
		float pointX = 2.0f * mousePos.x / application.GetWidth() - 1.0f;
		float pointY = -2.0f * mousePos.y / application.GetHeight() - 1.0f;

		pos.x = pointX;
		pos.y = pointY;

		tr->SetPosition(pos); 
	}
}
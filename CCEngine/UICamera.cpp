#include "UICamera.h"
#include "ccRenderer.h"
#include "ccCamera.h"
#include "ccCameraScript.h"
#include "ccScene.h"

namespace cc
{
	UICamera::UICamera()
	{
		mTransform = this->GetComponent<Transform>();
		mCamera = AddComponent<Camera>();
	}

	UICamera::~UICamera()
	{

	}

	void UICamera::Initialize()
	{
		GameObject::Initialize();

		mTransform->SetPosition(Vector3(10000.0f, 10000.0f, -10.0f));
		mCamera->TurnLayerMask(eLayerType::Player, false);
		renderer::cameras.push_back(mCamera);
	}

	void UICamera::Update()
	{
		GameObject::Update();
	}

	void UICamera::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void UICamera::Render()
	{
		GameObject::Render();
	}
}
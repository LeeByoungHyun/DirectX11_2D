#include "MainCamera.h"
#include "ccRenderer.h"
#include "ccCamera.h"
#include "ccCameraScript.h"
#include "ccScene.h"

namespace cc
{
	Vector3 cameraPos = Vector3::Zero;
	Vector2 screenSize = Vector2(16.0f, 9.0f);

	MainCamera::MainCamera()
	{
		mTransform = this->GetComponent<Transform>();
		mCamera = AddComponent<Camera>();

		//cameraPos = Vector3::Zero;
		//screenSize = Vector2(16.0f, 9.0f);
	}

	MainCamera::~MainCamera()
	{

	}

	void MainCamera::Initialize()
	{
		GameObject::Initialize();

		mCamera->TurnLayerMask(eLayerType::UI, false);
		mTransform->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
		renderer::cameras.push_back(mCamera);
		renderer::mainCamera = mCamera;
		//AddComponent<CameraScript>();
	}

	void MainCamera::Update()
	{
		GameObject::Update();

		cameraPos = mTransform->GetPosition();
	}

	void MainCamera::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void MainCamera::Render()
	{
		GameObject::Render();
	}
}
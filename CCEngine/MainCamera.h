#pragma once
#include "ccGameObject.h"

namespace cc
{
	class MainCamera : public GameObject
	{
	public:
		MainCamera();
		~MainCamera();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		//Vector3 GatCameraPos() { return cameraPos; }
		//Vector3 GatScreenSize() { return screenSize; }

	private:
		class Transform* mTransform;
		class Camera* mCamera;

		//static Vector3 cameraPos;
		//static Vector2 screenSize;
	};
}


#pragma once
#include "ccGameObject.h"

namespace cc
{
	class UICamera : public GameObject
	{
	public:
		UICamera();
		~UICamera();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:
		class Transform* mTransform;
		class Camera* mCamera;
	};
}


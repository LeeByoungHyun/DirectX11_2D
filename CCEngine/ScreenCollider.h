#pragma once
#include "ccGameObject.h"

namespace cc
{
	class ScreenCollider : public GameObject
	{
	public:

		ScreenCollider();
		~ScreenCollider();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:
		class Transform* mTransform;
		class Collider2D* mCollider;
	};
}



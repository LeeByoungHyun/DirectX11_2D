#pragma once
#include "ccGameObject.h"

namespace cc
{
	class PlayerCheckOnPlatformCollider : public GameObject
	{
	public:

		PlayerCheckOnPlatformCollider();
		~PlayerCheckOnPlatformCollider();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:
		class Transform* mTransform;
		class Collider2D* mCollider;
	};
}



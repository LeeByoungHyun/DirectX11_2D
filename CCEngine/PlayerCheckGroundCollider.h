#pragma once
#include "ccGameObject.h"

namespace cc
{
	class PlayerCheckPosition : public GameObject
	{
	public:

		PlayerCheckPosition();
		~PlayerCheckPosition();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:
		class Transform* mTransform;
		class Collider2D* mCollider;
	};
}



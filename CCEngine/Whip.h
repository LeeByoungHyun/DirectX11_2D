#pragma once
#include "ccGameObject.h"

namespace cc
{
	class Whip : public GameObject
	{
	public:
		enum class eWhipState
		{
			WieldStart,
			Wield
		};
		Whip();
		~Whip();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:
		eWhipState mState;
		eDirection mDirection;

		void wieldStart();
		void wield();

		void wieldStartEnd();
		void wieldEnd();

		class MeshRenderer* mMeshRenderer;
		class Collider2D* mCollider;
		class Animator* mAnimator;
		class Transform* mTransform;

		bool animationFlag;
	};

}


#pragma once
#include "ccGameObject.h"

namespace cc
{
	class CaveMan : public GameObject
	{
	public:
		enum class eCaveManState
		{
			Idle,
			Move,
			Chase, 
			Death
		};

		CaveMan();
		~CaveMan();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void SetCaveManState(eCaveManState state) { mState = state; }
		void SetAnimationFlag(bool flag) { animationFlag = flag; }
		eDirection GetPlayerDirection() { return mDirection; }
		void SetHp(int hp) { mHp = hp; }
		int GetHp() { return mHp; }

	private:
		// FSM
		void idle();
		void move();
		void chase();
		void death();

		// Events

		// 
		void InitializeFlag();

	private:
		eCaveManState mState;
		eDirection mDirection;
		double mTime;

		int mHp;

		class MeshRenderer* mMeshRenderer;
		class Transform* mTransform;
		class Animator* mAnimator;
		class Collider2D* mCollider;
		class Rigidbody* mRigidbody;

		// flag
		bool animationFlag;
	};
}

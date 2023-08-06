#pragma once
#include "ccGameObject.h"

namespace cc
{
	class Olmec : public GameObject
	{
	public:
		enum class eOlmecState
		{
			Idle,
			Awake,
			Jump,
			Crash,
			Find,
			Death
		};

		Olmec();
		~Olmec();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void SetOlmecState(eOlmecState state) { mState = state; }
		eOlmecState GetOlmecState() { return mState; }
		void SetAnimationFlag(bool flag) { animationFlag = flag; }
		void InitializeState();

	private:
		// FSM
		void idle();
		void awake();
		void jump();
		void crash();
		void death();

		// Events

		// 
		

	private:
		eOlmecState mState;
		eDirection mDirection;
		double mTime;
		class OlmecSeal* seal;

		class MeshRenderer* mMeshRenderer;
		class Transform* mTransform;
		class Collider2D* mCollider;
		class Rigidbody* mRigidbody;

		// flag
		bool animationFlag;
		bool awakeFlag;
		bool jumpFlag;
		bool checkTime;
	};
}

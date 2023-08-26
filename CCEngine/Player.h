#pragma once
#include "ccGameObject.h"
#include "ccMeshRenderer.h"
#include "ccTransform.h"
#include "ccAnimator.h"
#include "ccRigidbody.h"

namespace cc
{
	class Rigidbody;
	class Animator;
	class Player : public GameObject
	{
	public:
		enum class ePlayerState
		{
			Idle,
			Move,
			Jump,
			Fall,
			FallLong,
			Attack,
			Kneel,
			Crawl,
			OnEdge,
			Enter,
			Ghost
		};

		Player();
		~Player();

		static Player* GetInstance()
		{
			if (instance == nullptr)
				instance = new Player();

			return instance;
		}

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void SetPlayerState(ePlayerState state) { mState = state; }
		ePlayerState GetPlayerState() { return mState; }
		void SetAnimationFlag(bool flag) { animationFlag = flag; }
		eDirection GetPlayerDirection() { return mDirection; }

		void SetIsFalling(bool state) { isFalling = state; }
		void SetIsOnGround(bool state) { isOnGround = state; }
		bool GetIsFalling() { return isFalling; }

		void SetExitPos(Vector2 pos) { exitPos = pos; }

	private:
		// FSM
		void idle();
		void walk();
		void jump();
		void fall();
		void attack();
		void kneel();
		void crawl();
		void enter();
		void ghost();

		//
		void move();

		// Events
		void AnimationComplete();
		void WhipComplete();
		void KneelDownEnd();
		void KneelUpComplete();

		void InitializeFlag();

	private:
		static Player* instance;
		ePlayerState mState;
		eDirection mDirection;

		MeshRenderer* mMeshRenderer;
		Transform* mTransform;
		class Animator* mAnimator;
		class Collider2D* mCollider;
		class Rigidbody* mRigidbody;

		// flag
		bool animationFlag;

		// stateFlag
		bool idleFlag;
		bool moveFlag;
		bool jumpFlag;
		bool fallFlag;
		bool falllongFlag;
		bool attackFlag;
		bool kneelUpFlag;
		bool kneelDownEndFlag;
		bool crawlFlag;
		bool exitFlag;

		bool isFalling;
		bool isOnGround;

		Vector2 startPos;
		Vector2 exitPos;
		float mTime;
	};
}

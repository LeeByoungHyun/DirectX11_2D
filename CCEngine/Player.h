#pragma once
#include "ccGameObject.h"
#include "ccMeshRenderer.h"
#include "ccTransform.h"
#include "ccAnimator.h"

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
			Ghost
		};

		enum class eDirection
		{
			Left,
			Right
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

	private:
		// FSM
		void idle();
		void move();
		void jump();
		void fall();
		void attack();
		void kneel();
		void crawl();
		void ghost();

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

		// flag
		bool animationFlag;
		bool kneelUpFlag;
		bool kneelDownEndFlag;
		bool crawlFlag;
	};
}
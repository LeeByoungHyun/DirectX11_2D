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
		void idle();
		void move();

	private:
		static Player* instance;
		ePlayerState mState;

		MeshRenderer* mMeshRenderer;
		Transform* mTransform;
		class Animator* mAnimator;
	};
}

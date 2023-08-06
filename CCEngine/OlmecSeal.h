#pragma once
class OlmecSeal
{
};

#pragma once
#include "ccGameObject.h"

namespace cc
{
	class OlmecSeal : public GameObject
	{
	public:
		enum class eOlmecSealState
		{
			Idle,
			Awake01,
			Awake02,
			Death
		};

		OlmecSeal();
		~OlmecSeal();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void SetOlmecSealState(eOlmecSealState state) { mState = state; }
		eOlmecSealState GetOlmecSealState() { return mState; }
		void SetAnimationFlag(bool flag) { animationFlag = flag; }

	private:
		// FSM
		void idle();
		void awake01();
		void awake02();
		void death();

		// Events

		// 
		void InitializeFlag();

	private:
		eOlmecSealState mState;
		double mTime;

		class MeshRenderer* mMeshRenderer;
		class Transform* mTransform;

		// flag
		bool animationFlag;
	};
}
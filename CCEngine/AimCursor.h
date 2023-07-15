#pragma once
#include "ccGameObject.h"
#include "ccMeshRenderer.h"
#include "ccTransform.h"

namespace cc
{
	class AimCursor : public GameObject
	{
	public:
		AimCursor();
		virtual ~AimCursor();

		static AimCursor* GetInstance()
		{
			if (instance == nullptr)
				instance = new AimCursor();

			return instance;
		}

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		Vector3 GetPos() { return mTransform->GetPosition(); }

	private:
		static AimCursor* instance;

		MeshRenderer* mMeshRenderer;
		Transform* mTransform;
	};
}


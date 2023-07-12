#pragma once
#include "ccGameObject.h"
#include "ccMeshRenderer.h"
#include "ccTransform.h"

namespace cc
{
	class Marine : public GameObject
	{
	public:
		Marine();
		virtual ~Marine();

		static Marine* GetInstance()
		{
			if (instance == nullptr)
				instance = new Marine();

			return instance;
		}

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:
		static Marine* instance;

		MeshRenderer* mMeshRenderer;
		Transform* mTransform;
	};
}


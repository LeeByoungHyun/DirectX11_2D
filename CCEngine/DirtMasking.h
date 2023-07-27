#pragma once
#include "ccGameObject.h"
#include "ccMeshRenderer.h"
#include "ccTransform.h"

namespace cc
{
	class DirtMasking : public GameObject
	{
	public:
		DirtMasking();
		virtual ~DirtMasking();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void SetDirection(int dir);

	private:
		MeshRenderer* mMeshRenderer;
		Transform* mTransform;
	};
}
#pragma once
#include "ccGameObject.h"
#include "ccMeshRenderer.h"
#include "ccTransform.h"

namespace cc
{
	class BorderMasking : public GameObject
	{
	public:
		BorderMasking();
		virtual ~BorderMasking();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		BorderMasking* Instantiate(int direct);

	private:
		MeshRenderer* mMeshRenderer;
		Transform* mTransform;
	};
}
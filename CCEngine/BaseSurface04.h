#pragma once
#include "ccGameObject.h"
#include "ccMeshRenderer.h"
#include "ccTransform.h"

namespace cc
{
	class BaseSurface04 : public GameObject
	{
	public:
		BaseSurface04();
		virtual ~BaseSurface04();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:
		MeshRenderer* mMeshRenderer;
		Transform* mTransform;
	};
}
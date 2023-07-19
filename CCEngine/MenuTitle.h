#pragma once
#include "ccGameObject.h"
#include "ccMeshRenderer.h"
#include "ccTransform.h"

namespace cc
{
	class MenuTitle : public GameObject
	{
	public:
		MenuTitle();
		virtual ~MenuTitle();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:
		MeshRenderer* mMeshRenderer;
		Transform* mTransform;
	};
}
#pragma once
#include "ccGameObject.h"
#include "ccMeshRenderer.h"
#include "ccTransform.h"

namespace cc
{
	class MenuTitleGal : public GameObject
	{
	public:
		MenuTitleGal();
		virtual ~MenuTitleGal();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:
		MeshRenderer* mMeshRenderer;
		Transform* mTransform;
	};
}
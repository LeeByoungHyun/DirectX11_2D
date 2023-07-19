#pragma once
#include "ccGameObject.h"
#include "ccMeshRenderer.h"
#include "ccTransform.h"

namespace cc
{
	class BaseSkyNight : public GameObject
	{
	public:
		BaseSkyNight();
		virtual ~BaseSkyNight();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:
		MeshRenderer* mMeshRenderer;
		Transform* mTransform;
	};
}
#pragma once
#include "ccGameObject.h"
#include "ccMeshRenderer.h"
#include "ccTransform.h"
#include "ccCollider2D.h"
namespace cc
{
	class CaveEntrance : public GameObject
	{
	public:
		CaveEntrance();
		virtual ~CaveEntrance();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:
		Transform* mTransform;
		MeshRenderer* mMeshRenderer;
	};
}
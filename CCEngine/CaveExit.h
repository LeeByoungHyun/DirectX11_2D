#pragma once
#include "ccGameObject.h"
#include "ccMeshRenderer.h"
#include "ccTransform.h"
#include "ccCollider2D.h"
namespace cc
{
	class CaveExit : public GameObject
	{
	public:
		CaveExit();
		virtual ~CaveExit();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:
		Transform* mTransform;
		MeshRenderer* mMeshRenderer;
		Collider2D* mCollider;
	};
}
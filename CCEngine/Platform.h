#pragma once
#include "Tile.h"

namespace cc
{
	class Platform : public GameObject
	{
	public:
		Platform();
		virtual ~Platform();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:
		class MeshRenderer* mMeshRenderer;
		class Transform* mTransform;
		class Collider2D* mCollider;
	};
}
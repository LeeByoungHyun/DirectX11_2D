#pragma once
#include "Tile.h"
#include "ccMeshRenderer.h"
#include "ccTransform.h"

namespace cc
{
	class Wood : public Tile
	{
	public:
		Wood();
		virtual ~Wood();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		virtual void Masking(int dir) override;

	private:
		MeshRenderer* mMeshRenderer;
		Transform* mTransform;
	};
}
#pragma once
#include "Tile.h"
#include "ccMeshRenderer.h"
#include "ccTransform.h"

namespace cc
{
	class CaveDirt : public Tile
	{
	public:
		CaveDirt();
		virtual ~CaveDirt();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		virtual void Masking() override;

	private:
		MeshRenderer* mMeshRenderer;
		Transform* mTransform;
	};
}
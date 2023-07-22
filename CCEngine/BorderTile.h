#pragma once
#include "Tile.h"
#include "ccMeshRenderer.h"
#include "ccTransform.h"

namespace cc
{
	class BorderTile : public Tile
	{
	public:
		BorderTile();
		virtual ~BorderTile();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		virtual void Masking() override;
		

	private:
		//MeshRenderer* mMeshRenderer;
		//Transform* mTransform;

		class BorderMasking* maskPos[4];
	};
}
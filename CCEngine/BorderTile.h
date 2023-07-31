#pragma once
#include "Tile.h"

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

		virtual void Masking(int dir) override;

	private:
		class Collider2D* mCollider;

		class BorderMasking* maskPos[4];
	};
}
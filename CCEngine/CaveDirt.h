#pragma once
#include "Tile.h"

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

		virtual void Masking(int dir) override;

	private:
		class Collider2D* mCollider;

		class DirtMasking* maskPos[4];
	};
}
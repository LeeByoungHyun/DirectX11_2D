#include "Tile.h"

namespace cc
{
	Tile::Tile()
	{
		std::fill_n(masking, 4, false);
		std::fill_n(masked, 4, false);
		destructible = false;
	}

	Tile::~Tile()
	{

	}

	void Tile::Initialize()
	{

	}

	void Tile::Update()
	{

	}

	void Tile::LateUpdate()
	{

	}

	void Tile::Render()
	{

	}

	void Tile::Masking(int dir)
	{

	}

	void Tile::DestroyTile()
	{
		if (destructible == false)
			return;


	}
}

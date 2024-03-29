#pragma once

namespace cc::enums
{
	enum class eComponentType
	{
		None,
		Transform,
		Mesh,
		Collider2D,
		Rigidbody,
		Particle,
		MeshRenderer,
		Animator,
		Script,
		Camera,
		End,
	};

	enum class eLayerType
	{
		Grid,
		Map,
		BG,
		BackObject,
		Entrance,
		Platform,
		Tile,
		Monster,
		Player,
		PlayerCheck,
		Weapon,
		FrontObject,
		UI,
		End = 16,
	};

	enum class eResourceType
	{
		Texture,
		Shader,
		Material,
		Mesh,
		Animation,
		End,
	};

	enum class eColliderType
	{
		Rect,
		Circle,
		Sphere,
		Cube,
		End,
	};

	enum class eDirection
	{
		Up,
		Down,
		Left,
		Right,
	};
}
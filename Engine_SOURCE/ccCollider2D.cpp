#include "ccCollider2D.h"
#include "ccGameObject.h"
#include "ccRenderer.h"

namespace cc
{
	Collider2D::Collider2D()
		: Component(eComponentType::Collider2D)
		, mTransform(nullptr)
		, mSize(Vector2::One)
		, mCenter(Vector2::Zero)
	{

	}

	Collider2D::~Collider2D()
	{

	}

	void Collider2D::Initialize()
	{
		mTransform = GetOwner()->GetComponent<Transform>();
	}

	void Collider2D::Update()
	{

	}

	void Collider2D::LateUpdate()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();

		graphics::DebugMesh mesh = {};
		mesh.position = tr->GetPosition();
		mesh.scale = tr->GetScale();
		mesh.rotation = tr->GetRotation();
		mesh.type = eColliderType::Rect;

		renderer::PushDebugMeshAttribute(mesh);
	}

	void Collider2D::Render()
	{

	}
}
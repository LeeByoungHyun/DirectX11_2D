#include "ScreenCollider.h"
#include "ccCollider2D.h"
#include "ccTransform.h"
#include "Player.h"

namespace cc
{
	ScreenCollider::ScreenCollider()
	{
		mTransform = GetComponent<Transform>();
		mCollider = AddComponent<Collider2D>();
	}

	ScreenCollider::~ScreenCollider()
	{

	}

	void ScreenCollider::Initialize()
	{
		GameObject::Initialize();

		mCollider->SetSize(Vector2(16.0f, 9.0f) * 1.5f);
	}

	void ScreenCollider::Update()
	{
		GameObject::Update();

		if (Player::GetInstance() != nullptr)
			mTransform->SetPosition(Player::GetInstance()->GetComponent<Transform>()->GetPosition());
		else
			mTransform->SetPosition(Vector3::Zero);
	}

	void ScreenCollider::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void ScreenCollider::Render()
	{
		GameObject::Render();
	}
}
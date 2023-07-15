#include "AimCursor.h"
#include "ccResourceManager.h"
#include "ccMouseScript.h"

namespace cc
{
	AimCursor::AimCursor()
	{

	}

	AimCursor::~AimCursor()
	{

	}

	void AimCursor::Initialize()
	{
		GameObject::Initialize();

		mMeshRenderer = AddComponent<MeshRenderer>();
		mMeshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"Aim"));

		mTransform = GetComponent<Transform>();
		mTransform->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
		mTransform->SetScale(Vector3(0.2f, 0.2f, 0.0f));

		Collider2D* cd = AddComponent<Collider2D>();
		cd->SetType(eColliderType::Circle);

		// script
		AddComponent<MouseScript>();
	}

	void AimCursor::Update()
	{
		GameObject::Update();
	}

	void AimCursor::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void AimCursor::Render()
	{
		GameObject::Render();
	}
}
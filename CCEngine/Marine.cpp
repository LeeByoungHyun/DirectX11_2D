#include "Marine.h"
#include "ccResourceManager.h"
#include "ccPlayerMoveScript.h"
#include "ccCollider2D.h"

namespace cc
{
	Marine* Marine::instance = nullptr;

	Marine::Marine()
	{

	}

	Marine::~Marine()
	{

	}

	void Marine::Initialize()
	{
		GameObject::Initialize();

		mMeshRenderer = AddComponent<MeshRenderer>();
		mMeshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"marine"));

		mTransform = GetComponent<Transform>();
		mTransform->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
		mTransform->SetScale(Vector3(0.24f, 0.27f, 0.0f)); 
		
		Collider2D* cd = AddComponent<Collider2D>();
		cd->SetType(eColliderType::Circle);
		//cd->SetSize(Vector2(0.24f, 0.27f));

		// Script
		AddComponent<PlayerMoveScript>();

	}

	void Marine::Update()
	{
		GameObject::Update();
	}

	void Marine::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void Marine::Render()
	{
		GameObject::Render();
	}
}
#include "TestGun.h"
#include "ccResourceManager.h"
#include "TestGunScript.h"

namespace cc
{
	TestGun::TestGun()
	{

	}

	TestGun::~TestGun()
	{

	}

	void TestGun::Initialize()
	{
		GameObject::Initialize();

		mMeshRenderer = AddComponent<MeshRenderer>();
		mMeshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"TestGun"));

		mTransform = GetComponent<Transform>(); 
		
		mTransform->SetScale(Vector3(0.23f * 0.7f, 0.14f * 0.7f, 0.0f));

		// script
		AddComponent<TestGunScript>();
	}

	void TestGun::Update()
	{
		GameObject::Update();
	}

	void TestGun::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void TestGun::Render()
	{
		GameObject::Render();
	}
}
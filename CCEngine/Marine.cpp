#include "Marine.h"
#include "ccResourceManager.h"
#include "ccPlayerMoveScript.h"

namespace cc
{
	Marine::Marine()
	{

	}

	Marine::~Marine()
	{

	}

	void Marine::Initialize()
	{
		GameObject::Initialize();

		//mMeshRenderer = AddComponent<MeshRenderer>();
		//mMeshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		//mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"marine"));

		//mTransform = GetComponent<Transform>();
		//mTransform->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
		//mTransform->SetScale(Vector3(0.24f, 0.27f, 0.0f));

		mMeshRenderer = AddComponent<MeshRenderer>();
		mMeshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"marine"));

		mTransform = GetComponent<Transform>();
		mTransform->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
		mTransform->SetScale(Vector3(0.24f, 0.27f, 0.0f)); 
		
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
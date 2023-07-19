#include "MainDoorFrame.h"
#include "ccResourceManager.h"

namespace cc
{
	MainDoorFrame::MainDoorFrame()
	{

	}

	MainDoorFrame::~MainDoorFrame()
	{

	}

	void MainDoorFrame::Initialize()
	{
		GameObject::Initialize();

		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"main_doorframe.png", L"..\\Resources\\Texture\\menu\\main_doorframe.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"MainDoorFrame", spriteMateiral);
		}

		mMeshRenderer = AddComponent<MeshRenderer>();
		mMeshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"MainDoorFrame"));

		mTransform = GetComponent<Transform>();
		mTransform->SetPosition(Vector3(0.0f, 0.0f, 97.0f));
		mTransform->SetScale(Vector3(1280.0f, 1080.0f, 0.0f) * 0.12f);

		// script
	}

	void MainDoorFrame::Update()
	{
		GameObject::Update();
	}

	void MainDoorFrame::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void MainDoorFrame::Render()
	{
		GameObject::Render();
	}
}
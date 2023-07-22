#include "BorderTile.h"
#include "ccResourceManager.h"
#include "BorderMasking.h"
#include "ccObject.h"
#include "ccGameObject.h"

namespace cc
{
	//extern float TILESIZE;

	BorderTile::BorderTile()
	{

	}

	BorderTile::~BorderTile()
	{

	}

	void BorderTile::Initialize()
	{
		GameObject::Initialize();

		//
		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"border_00.png", L"..\\Resources\\Texture\\border\\tile\\border_00.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"border_00", spriteMateiral);
		}
		
		mMeshRenderer = AddComponent<MeshRenderer>();
		mMeshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"border_00"));

		mTransform = GetComponent<Transform>();
		mTransform->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
		mTransform->SetScale(Vector3(128.0f, 128.0f, 0.0f) * 0.12f);

		// 배열 초기화
		std::fill_n(masking, 4, false);
		std::fill_n(masked, 4, false);

		// script
	}

	void BorderTile::Update()
	{
		GameObject::Update();
	}

	void BorderTile::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void BorderTile::Render()
	{
		GameObject::Render();
	}

	void BorderTile::Masking()
	{
		for (UINT i = 0; i < 4; i++)
		{
			// 0 = top
			// 1 = right
			// 2 = bottom
			// 3 = left

			if (masking[i] == true)
			{
				if (masked[i] == true)	// 이미 마스킹 되어있으면 continue
					continue;

				BorderMasking* borderMask = new BorderMasking();
				borderMask->SetName(L"borderMask");
				borderMask->Instantiate(i);

				if (i == 0)
					borderMask->GetComponent<Transform>()->SetPosition(mTransform->GetPosition().x, mTransform->GetPosition().y + (15.36f / 2.0f), 0.0f);
				else if (i == 1)
					borderMask->GetComponent<Transform>()->SetPosition(mTransform->GetPosition().x + (15.36f / 2.0f), mTransform->GetPosition().y, 0.0f);
				else if (i == 2)
					borderMask->GetComponent<Transform>()->SetPosition(mTransform->GetPosition().x, mTransform->GetPosition().y - (15.36f / 2.0f), 0.0f);
				else if (i == 3)
					borderMask->GetComponent<Transform>()->SetPosition(mTransform->GetPosition().x - (15.36f / 2.0f), mTransform->GetPosition().y, 0.0f);

				maskPos[i] = borderMask;
				masked[i] = true;
			}
		}
	}
}
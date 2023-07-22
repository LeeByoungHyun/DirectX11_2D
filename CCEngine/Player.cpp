#include "Player.h"
#include "ccResourceManager.h"
#include "ccCollider2D.h"

namespace cc
{
	Player* Player::instance = nullptr;

	extern const float TILEDEPTH;

	Player::Player()
	{

	}

	Player::~Player()
	{

	}

	void Player::Initialize()
	{
		GameObject::Initialize();

		{
			std::shared_ptr<Shader> spriteShader
				= ResourceManager::Find<Shader>(L"SpriteShader");
			std::shared_ptr<Texture> texture
				= ResourceManager::Load<Texture>(L"char_orange.png", L"..\\Resources\\Texture\\player\\char_orange.png");
			std::shared_ptr<Material> spriteMateiral = std::make_shared<Material>();
			spriteMateiral->SetShader(spriteShader);
			spriteMateiral->SetTexture(texture);
			spriteMateiral->SetRenderingMode(eRenderingMode::Opaque);
			ResourceManager::Insert(L"char_orange", spriteMateiral);
		}

		mMeshRenderer = AddComponent<MeshRenderer>();
		mMeshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"SpriteAnimationMaterial"));

		mTransform = GetComponent<Transform>();
		mTransform->SetPosition(Vector3(0.0f, 0.0f, TILEDEPTH));
		mTransform->SetScale(Vector3(128.0f, 128.0f, 0.0f) * 0.12f);

		// amimator
		{
			std::shared_ptr<Texture> atlas
				= ResourceManager::Load<Texture>(L"char_orange.png", L"..\\Resources\\Texture\\player\\char_orange.png");

			mAnimator = AddComponent<Animator>();
			mAnimator->Create(L"Idle", atlas, Vector2(0.0f, 0.0f), Vector2(128.0f, 128.0f), 1);
		}
		
		mAnimator->PlayAnimation(L"Idle", true);
	}

	void Player::Update()
	{
		GameObject::Update();

		switch (mState)
		{
		case cc::Player::ePlayerState::Idle:
			idle();
			break;

		case cc::Player::ePlayerState::Move:
			move();
			break;

		default:
			break;
		}
	}

	void Player::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void Player::Render()
	{
		GameObject::Render();
	}

	void Player::idle()
	{

	}

	void Player::move()
	{

	}
}
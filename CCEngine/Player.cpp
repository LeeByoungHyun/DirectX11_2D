#include "Player.h"
#include "ccResourceManager.h"
#include "ccCollider2D.h"
#include "ccInput.h"
#include "ccTime.h"
#include "ccRigidbody.h"
#include "ccObject.h"

#include "PlayerCollisionScript.h"
#include "Whip.h"
#include "NextLevelScene.h"
#include "ccTestScene.h"

namespace cc
{
	Player* Player::instance = nullptr;

	extern const float TILEDEPTH;
	extern const float PLAYERDEPTH;
	const float PLAYERWALKSPEED = 8.0f;
	const float PLAYERRUNSPEED = 12.0f;
	const float PLAYERCRAWLSPEED = 4.0f;

	Player::Player()
	{
		mCollider = AddComponent<Collider2D>();
		mMeshRenderer = AddComponent<MeshRenderer>();
		mTransform = GetComponent<Transform>();
		mRigidbody = AddComponent<Rigidbody>();
		mAnimator = AddComponent<Animator>();
		mDirection = eDirection::Right;
		mState = ePlayerState::Idle;

		animationFlag = false;
		idleFlag = false;
		moveFlag = false;
		jumpFlag = false;
		fallFlag = false;
		falllongFlag = false;
		attackFlag = false;
		kneelUpFlag = false;
		kneelDownEndFlag = false;
		crawlFlag = false;
		exitFlag = false;

		isFalling = false;
		isOnGround = false;
		isOnPlatform = false;

		nextFlag = false;

		startPos = Vector2::Zero;
		exitPos = Vector2::Zero;
		mTime = 0.0f;
	}

	Player::~Player()
	{

	}

	void Player::Initialize()
	{
		GameObject::Initialize();

		mMeshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectMesh"));
		mMeshRenderer->SetMaterial(ResourceManager::Find<Material>(L"SpriteAnimationMaterial"));

		mTransform->SetPosition(Vector3(0.0f, 0.0f, PLAYERDEPTH));
		mTransform->SetScale(Vector3(2.0f, 2.0f, 0.0f));

		mCollider->SetSize(Vector2(0.45f, 0.45f));

		mRigidbody->SetGravity(Vector2(0.0f, 40.0f));
		mRigidbody->SetGround(true);

		// amimator
		{
			std::shared_ptr<Texture> atlas
				= ResourceManager::Load<Texture>(L"player.png", L"..\\Resources\\Texture\\Player\\player.png");
		
			mAnimator->Create(L"Idle_r", atlas, Vector2(128.0f * 0, 128.0f * 0), Vector2(128.0f, 128.0f), 1);
			mAnimator->Create(L"Idle_l", atlas, Vector2(128.0f * 0, 128.0f * 1), Vector2(128.0f, 128.0f), 1);
			mAnimator->Create(L"Wark_r", atlas, Vector2(128.0f * 0, 128.0f * 2), Vector2(128.0f, 128.0f), 8);
			mAnimator->Create(L"Wark_l", atlas, Vector2(128.0f * 0, 128.0f * 3), Vector2(128.0f, 128.0f), 8);
			mAnimator->Create(L"Stun/Death_r", atlas, Vector2(128.0f * 0, 128.0f * 4), Vector2(128.0f, 128.0f), 1);
			mAnimator->Create(L"Stun/Death_l", atlas, Vector2(128.0f * 0, 128.0f * 5), Vector2(128.0f, 128.0f), 1);
			mAnimator->Create(L"KneelDown_r", atlas, Vector2(128.0f * 0, 128.0f * 6), Vector2(128.0f, 128.0f), 3);
			mAnimator->Create(L"KneelDown_l", atlas, Vector2(128.0f * 0, 128.0f * 7), Vector2(128.0f, 128.0f), 3);
			mAnimator->Create(L"KneelUp_r", atlas, Vector2(128.0f * 0, 128.0f * 8), Vector2(128.0f, 128.0f), 2);
			mAnimator->Create(L"KneelUp_l", atlas, Vector2(128.0f * 0, 128.0f * 9), Vector2(128.0f, 128.0f), 2);
			mAnimator->Create(L"Crawl_r", atlas, Vector2(128.0f * 0, 128.0f * 10), Vector2(128.0f, 128.0f), 7);
			mAnimator->Create(L"Crawl_l", atlas, Vector2(128.0f * 0, 128.0f * 11), Vector2(128.0f, 128.0f), 7);
			mAnimator->Create(L"Stun/Hit_r", atlas, Vector2(128.0f * 0, 128.0f * 12), Vector2(128.0f, 128.0f), 4);
			mAnimator->Create(L"Stun/Hit_l", atlas, Vector2(128.0f * 0, 128.0f * 13), Vector2(128.0f, 128.0f), 4);
			mAnimator->Create(L"Idle/Holding_r", atlas, Vector2(128.0f * 0, 128.0f * 14), Vector2(128.0f, 128.0f), 1);
			mAnimator->Create(L"Idle/Holding_l", atlas, Vector2(128.0f * 0, 128.0f * 15), Vector2(128.0f, 128.0f), 1);
			mAnimator->Create(L"OnEdge_r", atlas, Vector2(128.0f * 0, 128.0f * 16), Vector2(128.0f, 128.0f), 8);
			mAnimator->Create(L"OnEdge_l", atlas, Vector2(128.0f * 0, 128.0f * 17), Vector2(128.0f, 128.0f), 8);
			mAnimator->Create(L"HangingCorner_r", atlas, Vector2(128.0f * 0, 128.0f * 18), Vector2(128.0f, 128.0f), 3);
			mAnimator->Create(L"HangingCorner_l", atlas, Vector2(128.0f * 0, 128.0f * 19), Vector2(128.0f, 128.0f), 3);
			mAnimator->Create(L"Idle_Hanging_r", atlas, Vector2(128.0f * 0, 128.0f * 20), Vector2(128.0f, 128.0f), 1);
			mAnimator->Create(L"Idle_Hanging_l", atlas, Vector2(128.0f * 0, 128.0f * 21), Vector2(128.0f, 128.0f), 1);
			mAnimator->Create(L"Idle_Hanging_r", atlas, Vector2(128.0f * 0, 128.0f * 20), Vector2(128.0f, 128.0f), 1);
			mAnimator->Create(L"Idle_Hanging_l", atlas, Vector2(128.0f * 0, 128.0f * 21), Vector2(128.0f, 128.0f), 1);
			mAnimator->Create(L"PlayerWhip_r", atlas, Vector2(128.0f * 0, 128.0f * 22), Vector2(128.0f, 128.0f), 6, Vector2::Zero, 0.05f);
			mAnimator->Create(L"PlayerWhip_l", atlas, Vector2(128.0f * 0, 128.0f * 23), Vector2(128.0f, 128.0f), 6, Vector2::Zero, 0.05f);
			mAnimator->Create(L"Throw_r", atlas, Vector2(128.0f * 0, 128.0f * 24), Vector2(128.0f, 128.0f), 5);
			mAnimator->Create(L"Throw_l", atlas, Vector2(128.0f * 0, 128.0f * 25), Vector2(128.0f, 128.0f), 5);
			mAnimator->Create(L"Enter", atlas, Vector2(128.0f * 0, 128.0f * 26), Vector2(128.0f, 128.0f), 6);
			mAnimator->Create(L"Exit", atlas, Vector2(128.0f * 0, 128.0f * 27), Vector2(128.0f, 128.0f), 6);
			mAnimator->Create(L"Idle/Ladder", atlas, Vector2(128.0f * 0, 128.0f * 28), Vector2(128.0f, 128.0f), 1);
			mAnimator->Create(L"Ladder", atlas, Vector2(128.0f * 0, 128.0f * 29), Vector2(128.0f, 128.0f), 5);
			mAnimator->Create(L"Push_r", atlas, Vector2(128.0f * 0, 128.0f * 30), Vector2(128.0f, 128.0f), 6);
			mAnimator->Create(L"Push_l", atlas, Vector2(128.0f * 0, 128.0f * 31), Vector2(128.0f, 128.0f), 6);
			mAnimator->Create(L"Idle/Rope", atlas, Vector2(128.0f * 0, 128.0f * 32), Vector2(128.0f, 128.0f), 1);
			mAnimator->Create(L"Rope", atlas, Vector2(128.0f * 0, 128.0f * 33), Vector2(128.0f, 128.0f), 9);
			mAnimator->Create(L"LookUp_r", atlas, Vector2(128.0f * 0, 128.0f * 34), Vector2(128.0f, 128.0f), 4);
			mAnimator->Create(L"LookUp_l", atlas, Vector2(128.0f * 0, 128.0f * 35), Vector2(128.0f, 128.0f), 4);
			mAnimator->Create(L"LookDown_r", atlas, Vector2(128.0f * 0, 128.0f * 36), Vector2(128.0f, 128.0f), 3);
			mAnimator->Create(L"LookDown_l", atlas, Vector2(128.0f * 0, 128.0f * 37), Vector2(128.0f, 128.0f), 3);
			mAnimator->Create(L"Jump_r", atlas, Vector2(128.0f * 0, 128.0f * 38), Vector2(128.0f, 128.0f), 8, Vector2::Zero, 0.05f);
			mAnimator->Create(L"Jump_l", atlas, Vector2(128.0f * 0, 128.0f * 39), Vector2(128.0f, 128.0f), 8, Vector2::Zero, 0.05f);
			mAnimator->Create(L"Fall_r", atlas, Vector2(128.0f * 0, 128.0f * 40), Vector2(128.0f, 128.0f), 4, Vector2::Zero, 0.05f);
			mAnimator->Create(L"Fall_l", atlas, Vector2(128.0f * 0, 128.0f * 41), Vector2(128.0f, 128.0f), 4, Vector2::Zero, 0.05f);
			mAnimator->Create(L"Idle/Ghost_r", atlas, Vector2(128.0f * 0, 128.0f * 42), Vector2(128.0f, 128.0f), 4);
			mAnimator->Create(L"Idle/Ghost_l", atlas, Vector2(128.0f * 0, 128.0f * 43), Vector2(128.0f, 128.0f), 4);
			mAnimator->Create(L"Ghost/Charging_r", atlas, Vector2(128.0f * 0, 128.0f * 44), Vector2(128.0f, 128.0f), 6);
			mAnimator->Create(L"Ghost/Charging_l", atlas, Vector2(128.0f * 0, 128.0f * 45), Vector2(128.0f, 128.0f), 6);
			mAnimator->Create(L"Ghost/Shoot_r", atlas, Vector2(128.0f * 0, 128.0f * 46), Vector2(128.0f, 128.0f), 6);
			mAnimator->Create(L"Ghost/Shoot_l", atlas, Vector2(128.0f * 0, 128.0f * 47), Vector2(128.0f, 128.0f), 6);
			mAnimator->Create(L"Fall/Long_r", atlas, Vector2(128.0f * 0, 128.0f * 48), Vector2(128.0f, 128.0f), 6);
			mAnimator->Create(L"Fall/Long_l", atlas, Vector2(128.0f * 0, 128.0f * 49), Vector2(128.0f, 128.0f), 6);
		
			// events
			mAnimator->CompleteEvent(L"PlayerWhip_r") = std::bind(&Player::WhipComplete, this);
			mAnimator->CompleteEvent(L"PlayerWhip_l") = std::bind(&Player::WhipComplete, this);
			mAnimator->CompleteEvent(L"KneelUp_r") = std::bind(&Player::KneelUpComplete, this);
			mAnimator->CompleteEvent(L"KneelUp_l") = std::bind(&Player::KneelUpComplete, this);
			mAnimator->EndEvent(L"KneelDown_r") = std::bind(&Player::KneelDownEnd, this);
			mAnimator->EndEvent(L"KneelDown_l") = std::bind(&Player::KneelDownEnd, this);
		}
		
		

		InitializeFlag();

		// script
		AddComponent<PlayerCollisionScript>();
	}

	void Player::Update()
	{
		GameObject::Update();

		if (Input::GetKey(eKeyCode::LEFT))
			mDirection = eDirection::Left;
		if (Input::GetKey(eKeyCode::RIGHT))
			mDirection = eDirection::Right;

		switch (mState)
		{
		case cc::Player::ePlayerState::Idle:
			idle();
			break;

		case cc::Player::ePlayerState::Move:
			walk();
			break;

		case cc::Player::ePlayerState::Jump:
			jump();
			break;

		case cc::Player::ePlayerState::Fall:
			fall();
			break;

		case cc::Player::ePlayerState::Attack:
			attack();
			break;

		case cc::Player::ePlayerState::Kneel:
			kneel();
			break;

		case cc::Player::ePlayerState::Crawl:
			crawl();
			break;

		case cc::Player::ePlayerState::Enter:
			enter();
			break;

		case cc::Player::ePlayerState::Ghost:
			ghost();
			break;
			
		default:
			break;
		}
	}

	void Player::LateUpdate()
	{
		GameObject::LateUpdate();

		// Player가 현재 공중에 있는지 체크
		if (isFalling == true)
		{
			mRigidbody->SetGround(false);

			// 특정 state가 아닐 때 낙하 state로 변경
			if (mState != ePlayerState::Attack 
				&& mState != ePlayerState::Fall
				&& mState != ePlayerState::FallLong
				&& mState != ePlayerState::Jump
				&& mState != ePlayerState::Ghost)
			{
  				mState = ePlayerState::Fall;

				InitializeFlag();
			}
		}
		if (isOnGround == true
			&& mRigidbody->GetVelocity().y > 0.0f)
		{
			mRigidbody->SetGround(true);

			if (mState != ePlayerState::Idle
				&& mState != ePlayerState::Move
				&& mState != ePlayerState::Attack
				&& mState != ePlayerState::Ghost
				&& mState != ePlayerState::Enter)
			{
				mState = ePlayerState::Idle;
			}
		}
		if (isOnPlatform == true
			&& mRigidbody->GetVelocity().y > 0.0f)
		{
			mRigidbody->SetGround(true);

			if (mState != ePlayerState::Idle
				&& mState != ePlayerState::Move
				&& mState != ePlayerState::Attack
				&& mState != ePlayerState::Ghost
				&& mState != ePlayerState::Enter)
			{
				mState = ePlayerState::Idle;
			}
		}
	}

	void Player::Render()
	{
		GameObject::Render();
	}

	void Player::idle()
	{
		InitializeFlag();

		if (idleFlag == false)
		{
			if (mDirection == eDirection::Left)
				mAnimator->PlayAnimation(L"Idle_l", true);
			else if (mDirection == eDirection::Right)
				mAnimator->PlayAnimation(L"Idle_r", true);

			idleFlag = true;
		}

		if (Input::GetKey(eKeyCode::LEFT) || Input::GetKey(eKeyCode::RIGHT))
		{
			mState = ePlayerState::Move;

			idleFlag = false;
		}

		if (Input::GetKey(eKeyCode::DOWN))
		{
			mState = ePlayerState::Kneel;

			idleFlag = false;
		}

		if (Input::GetKeyDown(eKeyCode::Q))
		{
			mState = ePlayerState::Attack;

			idleFlag = false;
		}

		if (Input::GetKey(eKeyCode::O))
		{
			mState = ePlayerState::Ghost;

			idleFlag = false;
		}

		if (Input::GetKeyDown(eKeyCode::SPACE))
		{
			mState = ePlayerState::Jump;

			idleFlag = false;
		}
	}

	void Player::walk()
	{
		if (moveFlag == false)
		{
			if (mDirection == eDirection::Left)
				mAnimator->PlayAnimation(L"Wark_l", true);
			else if (mDirection == eDirection::Right)
				mAnimator->PlayAnimation(L"Wark_r", true);

			moveFlag = true;
		}

		move();

		if (Input::GetKeyUp(eKeyCode::LEFT) || Input::GetKeyUp(eKeyCode::RIGHT))
		{
			mState = ePlayerState::Idle;

			moveFlag = false;
		}

		if (Input::GetKeyDown(eKeyCode::Q))
		{
			mState = ePlayerState::Attack;

			moveFlag = false;
		}

		if (Input::GetKeyDown(eKeyCode::SPACE))
		{
			mState = ePlayerState::Jump;

			moveFlag = false;
		}
	}

	void Player::jump()
	{
		if (jumpFlag == false)
		{
			if (mDirection == eDirection::Left)
				mAnimator->PlayAnimation(L"Jump_l", false);
			else if (mDirection == eDirection::Right)
				mAnimator->PlayAnimation(L"Jump_r", false);

			jumpFlag = true;

			mRigidbody->SetGround(false);
			//mRigidbody->AddForce(Vector2(0.0f, -200.0f));
			mRigidbody->SetVelocity(Vector2(0.0f, -15.0f));
		}

		if (Input::GetKeyDown(eKeyCode::Q))
		{
			mState = ePlayerState::Attack;

			jumpFlag = false;
		}

		move();
	}

	void Player::fall()
	{
		if (fallFlag == false)
		{
			if (mDirection == eDirection::Left)
				mAnimator->PlayAnimation(L"Fall_l", false);
			else if (mDirection == eDirection::Right)
				mAnimator->PlayAnimation(L"Fall_r", false);

			fallFlag = true;

			mRigidbody->SetGround(false);
		}

		if (Input::GetKeyDown(eKeyCode::Q))
		{
			mState = ePlayerState::Attack;

			jumpFlag = false;
		}

		move();
	}

	void Player::attack()
	{
		Vector3 pos = mTransform->GetPosition();

		if (attackFlag == false)
		{
			if (mDirection == eDirection::Left)
				mAnimator->PlayAnimation(L"PlayerWhip_l", true);
			else if (mDirection == eDirection::Right)
				mAnimator->PlayAnimation(L"PlayerWhip_r", true);

			Scene* sdf = SceneManager::GetActiveScene();
			object::Instantiate<Whip>(enums::eLayerType::Weapon);

			attackFlag = true;
		}

		move();
	}

	void Player::kneel()
	{
		if (animationFlag == false)
		{
			if (mDirection == eDirection::Left)
				mAnimator->PlayAnimation(L"KneelDown_l", false);
			else if (mDirection == eDirection::Right)
				mAnimator->PlayAnimation(L"KneelDown_r", false);

			animationFlag = true;
		}

		if (Input::GetKeyUp(eKeyCode::DOWN))
		{
			if (kneelUpFlag == false)
			{
				if (mDirection == eDirection::Left)
					mAnimator->PlayAnimation(L"KneelUp_l", true);
				else if (mDirection == eDirection::Right)
					mAnimator->PlayAnimation(L"KneelUp_r", true);

				kneelUpFlag = true;
			}
		}

		if (Input::GetKey(eKeyCode::LEFT) || Input::GetKey(eKeyCode::RIGHT))
		{
			mState = ePlayerState::Crawl;

			animationFlag = false;
		}
	}

	void Player::crawl()
	{
		// 이동
		Vector3 pos = mTransform->GetPosition();
		if (Input::GetKey(eKeyCode::LEFT) && kneelUpFlag == false)
		{
			if (animationFlag == false)
			{
				mAnimator->PlayAnimation(L"Crawl_l", true);

				animationFlag = true;
				//crawlFlag = true;
			}
			pos.x -= PLAYERCRAWLSPEED * Time::DeltaTime();
			mTransform->SetPosition(pos);
		}
		if (Input::GetKey(eKeyCode::RIGHT) && kneelUpFlag == false)
		{
			if (animationFlag == false)
			{
				mAnimator->PlayAnimation(L"Crawl_r", true);

				animationFlag = true;
				//crawlFlag = true;
			}
			pos.x += PLAYERCRAWLSPEED * Time::DeltaTime();
			mTransform->SetPosition(pos);
		}

		// 아래 방향키가 눌려있지 않다면 일어남
		if (!Input::GetKey(eKeyCode::DOWN))
		{
			if (kneelUpFlag == false)
			{
				if (mDirection == eDirection::Left)
					mAnimator->PlayAnimation(L"KneelUp_l", true);
				else if (mDirection == eDirection::Right)
					mAnimator->PlayAnimation(L"KneelUp_r", true);

				kneelUpFlag = true;
			}
		}

		// 기어가던 도중 방향키에서 손을 때면 멈춤
		if ((Input::GetKeyUp(eKeyCode::LEFT) || Input::GetKeyUp(eKeyCode::RIGHT)) && kneelUpFlag == false)
		{
			if (mDirection == eDirection::Left)
				mAnimator->PlayAnimation(L"Stun/Death_l", false);
			else if (mDirection == eDirection::Right)
				mAnimator->PlayAnimation(L"Stun/Death_r", false);

			animationFlag = false;
		}


	}

	void Player::enter()
	{
		if (exitFlag == false)
		{
			exitFlag = true;

			// 출구와 완전히 겹쳐있지 않으면 겹칠때까지 이동
			if (mTransform->GetPosition().x != exitPos.x)
			{
				startPos = Vector2(mTransform->GetPosition().x, mTransform->GetPosition().y);
			}

			// 방향 체크
			if (mTransform->GetPosition().x - exitPos.x > 0.0f)
				mAnimator->PlayAnimation(L"Wark_l", true);
			else
				mAnimator->PlayAnimation(L"Wark_r", true);
		}

		mTime += Time::DeltaTime();
		if (mTime < 0.66f)
		{
			// 선형 보간법을 활용하여 출구까지 이동
			float t = mTime / 0.66f;
			float x = Lerp(startPos.x, exitPos.x, t);

			Vector3 mPos = mTransform->GetPosition();
			mTransform->SetPosition(x, mPos.y, mPos.z);
		}

		if (mTime >= 0.66f)
		{
			mAnimator->PlayAnimation(L"Enter", true);
		}

		// NextLevel 씬으로 이동 후 맵 초기화
		if (mTime >= 2.0f)
		{
			mState = ePlayerState::Idle;
			InitializeFlag();

			if (nextFlag == false)
			{
				SceneManager::LoadScene(L"NextLevelScene");
				nextFlag = true;
			}
			else
			{
				SceneManager::LoadScene(L"TestScene");
				nextFlag = false;
			}
		}
	}

	void Player::ghost()
	{
		if (animationFlag == false)
		{
			if (mDirection == eDirection::Left)
				mAnimator->PlayAnimation(L"Idle/Ghost_l", true);
			else if (mDirection == eDirection::Right)
				mAnimator->PlayAnimation(L"Idle/Ghost_r", true);

			animationFlag = true;
		}

		mRigidbody->SetGround(false);
		mRigidbody->SetVelocity(Vector2::Zero);
		mRigidbody->SetGravity(Vector2::Zero);

		move();

		if (Input::GetKeyDown(eKeyCode::LEFT))
		{
			mDirection = eDirection::Left;
			animationFlag = false;
		}
		if (Input::GetKeyDown(eKeyCode::RIGHT))
		{
			mDirection = eDirection::Right;
			animationFlag = false;
		}
	}

	void Player::move()
	{
		Vector3 pos = mTransform->GetPosition();

		// 
		if (mState == ePlayerState::Move
			|| mState == ePlayerState::Attack
			|| mState == ePlayerState::Jump
			|| mState == ePlayerState::Fall
			|| mState == ePlayerState::FallLong)
		{
			if (Input::GetKey(eKeyCode::LEFT))
			{
				if (Input::GetKey(eKeyCode::LSHIFT))
					pos.x -= PLAYERRUNSPEED * Time::DeltaTime();
				else
					pos.x -= PLAYERWALKSPEED * Time::DeltaTime();

			}
			if (Input::GetKey(eKeyCode::RIGHT))
			{
				if (Input::GetKey(eKeyCode::LSHIFT))
					pos.x += PLAYERRUNSPEED * Time::DeltaTime();
				else
					pos.x += PLAYERWALKSPEED * Time::DeltaTime();
			}

			mTransform->SetPosition(pos);
		}
		else if (mState == ePlayerState::Ghost)
		{
			Vector2 pos = Vector2::Zero;
			if (Input::GetKey(eKeyCode::UP))
			{
				pos += Vector2(0.0f, -5.0f);
			}
			if (Input::GetKey(eKeyCode::LEFT))
			{
				pos += Vector2(-5.0f, 0.0f);
			}
			if (Input::GetKey(eKeyCode::DOWN))
			{
				pos += Vector2(0.0f, 5.0f);
			}
			if (Input::GetKey(eKeyCode::RIGHT))
			{
				pos += Vector2(5.0f, 0.0f);
			}

			mRigidbody->SetVelocity(pos);
		}
		
	}

	void Player::AnimationComplete()
	{
		mState = ePlayerState::Idle;

		animationFlag = false;
		kneelUpFlag = false;
	}

	void Player::WhipComplete()
	{
		mState = ePlayerState::Idle;

		animationFlag = false;
	}

	void Player::KneelDownEnd()
	{
		kneelDownEndFlag = true;
	}

	void Player::KneelUpComplete()
	{
		mState = ePlayerState::Idle;

		animationFlag = false;
		kneelUpFlag = false;
	}

	void Player::InitializeFlag()
	{
		animationFlag = false;
		idleFlag = false;
		moveFlag = false;
		jumpFlag = false;
		fallFlag = false;
		falllongFlag = false;
		attackFlag = false;
		kneelUpFlag = false;
		kneelDownEndFlag = false;
		crawlFlag = false;
		exitFlag = false;

		mTime = 0.0f;
	}
}
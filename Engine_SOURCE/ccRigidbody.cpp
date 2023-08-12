#include "ccRigidbody.h"
#include "ccTime.h"
#include "ccGameObject.h"
#include "ccTransform.h"

namespace cc
{
	Rigidbody::Rigidbody()
		: Component(eComponentType::Rigidbody)
		, mMass(1.0f)
		, mForce(Vector2::Zero)
		, mAccelation(Vector2::Zero)
		, mVelocity(Vector2::Zero)
		, mActive(true)
	{
		mLimitedVelocity.x = 10.0f;
		mLimitedVelocity.y = 10.0f;
		mbGround = false;
		mGravity = Vector2(0.0f, 10.0f);
		mFriction = 5.0f;
		for (UINT i = 0; i < 4; i++)
			dirLock[i] = false;
	}

	Rigidbody::~Rigidbody()
	{

	}

	void Rigidbody::Initialize()
	{

	}

	void Rigidbody::Update()
	{
		if (mActive == true)
		{
			// F = M * A
			// A = M / F
			mAccelation = mForce / mMass;

			// 속도에 가속도를 더해준다.
			mVelocity += mAccelation * Time::DeltaTime();

			if (mbGround)
			{
				// 땅위에 있을때
				Vector2 gravity = mGravity;
				gravity.Normalize();

				float dot = mVelocity.Dot(gravity);
				mVelocity -= gravity * dot;
			}
			else
			{
				mVelocity += mGravity * Time::DeltaTime();
			}

			// 중력가속도 최대 속도 제한
			Vector2 gravity = mGravity;
			gravity.Normalize();
			float dot = mVelocity.Dot(gravity);
			gravity = gravity * dot;

			Vector2 sideVelocity = mVelocity - gravity;
			if (mLimitedVelocity.y < gravity.Length())
			{
				gravity.Normalize();
				gravity *= mLimitedVelocity.y;
			}

			if (mLimitedVelocity.x < sideVelocity.Length())
			{
				sideVelocity.Normalize();
				sideVelocity *= mLimitedVelocity.x;
			}

			// 마찰력 조건 ( 적용된 힘이 없고, 속도가 0이 아님)
			if (!(mVelocity == Vector2::Zero))
			{
				//속도에 반대방향으로 마찰력이 적용된다.
				Vector2 friction = -mVelocity;
				friction.Normalize();
				friction = friction * mFriction * mMass * Time::DeltaTime();

				//마찰력으로 인한 속도 감소가 현재 속도보다 큰 경우
				if (mVelocity.Length() < friction.Length())
				{
					mVelocity = Vector2::Zero;
				}
				else
				{
					mVelocity += friction;
				}
			}

			// dirLock가 true일 경우 이동하지 않아야 함
			if (dirLock[(UINT)eDirection::Up] == true && mVelocity.y > 0.0f)
				mVelocity.y = 0.0f;
			if (dirLock[(UINT)eDirection::Down] == true && mVelocity.y < 0.0f)
				mVelocity.y = 0.0f;
			if (dirLock[(UINT)eDirection::Left] == true && mVelocity.x < 0.0f)
				mVelocity.x = 0.0f;
			if (dirLock[(UINT)eDirection::Right] == true && mVelocity.x > 0.0f)
				mVelocity.x = 0.0f;
			
			// 속도에 맞게끔 물체를 이동시킨다.
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector3 pos = tr->GetPosition();
			pos.x = pos.x + mVelocity.x * Time::DeltaTime();
			pos.y = pos.y - mVelocity.y * Time::DeltaTime();
			tr->SetPosition(pos);
			mForce = Vector2::Zero;
		}
	}

	void Rigidbody::LateUpdate()
	{

	}

	void Rigidbody::Render()
	{

	}


	void Rigidbody::AddForce(Vector2 force)
	{
		mForce += force;
	}
}
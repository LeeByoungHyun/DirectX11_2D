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

			// �ӵ��� ���ӵ��� �����ش�.
			mVelocity += mAccelation * Time::DeltaTime();

			if (mbGround)
			{
				// ������ ������
				Vector2 gravity = mGravity;
				gravity.Normalize();

				float dot = mVelocity.Dot(gravity);
				mVelocity -= gravity * dot;
			}
			else
			{
				mVelocity += mGravity * Time::DeltaTime();
			}

			// �߷°��ӵ� �ִ� �ӵ� ����
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

			// ������ ���� ( ����� ���� ����, �ӵ��� 0�� �ƴ�)
			if (!(mVelocity == Vector2::Zero))
			{
				//�ӵ��� �ݴ�������� �������� ����ȴ�.
				Vector2 friction = -mVelocity;
				friction.Normalize();
				friction = friction * mFriction * mMass * Time::DeltaTime();

				//���������� ���� �ӵ� ���Ұ� ���� �ӵ����� ū ���
				if (mVelocity.Length() < friction.Length())
				{
					mVelocity = Vector2::Zero;
				}
				else
				{
					mVelocity += friction;
				}
			}

			// dirLock�� true�� ��� �̵����� �ʾƾ� ��
			if (dirLock[(UINT)eDirection::Up] == true && mVelocity.y > 0.0f)
				mVelocity.y = 0.0f;
			if (dirLock[(UINT)eDirection::Down] == true && mVelocity.y < 0.0f)
				mVelocity.y = 0.0f;
			if (dirLock[(UINT)eDirection::Left] == true && mVelocity.x < 0.0f)
				mVelocity.x = 0.0f;
			if (dirLock[(UINT)eDirection::Right] == true && mVelocity.x > 0.0f)
				mVelocity.x = 0.0f;
			
			// �ӵ��� �°Բ� ��ü�� �̵���Ų��.
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
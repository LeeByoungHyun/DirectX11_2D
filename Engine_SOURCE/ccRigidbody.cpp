#include "ccRigidbody.h"
#include "ccTime.h"
#include "ccGameObject.h"
#include "ccTransform.h"

namespace cc
{
	Rigidbody::Rigidbody()
		: Component(eComponentType::Rigidbody)
		, mMass(0.0f)
		, mForce(Vector2::Zero)
		, mAccelation(Vector2::Zero)
		, mVelocity(Vector2::Zero)
	{
		mLimitedVelocity.x = 1000.0f;
		mLimitedVelocity.y = 400.0f;
		mbGround = false;
		mGravity = Vector2(0.0f, 800.0f);
		mFriction = 100.0f;
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
				friction *= mFriction * mMass * Time::DeltaTime();

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

			// �ӵ��� �°Բ� ��ü�� �̵���Ų��.
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector3 pos = tr->GetPosition();
			pos.x = pos.x + mVelocity.x * Time::DeltaTime();
			pos.y = pos.y + mVelocity.y * Time::DeltaTime();
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
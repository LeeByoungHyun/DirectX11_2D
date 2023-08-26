#pragma once
#include "ccScript.h"

namespace cc
{
	class PlayerCheckGroundScript : public Script
	{
	public:
		PlayerCheckGroundScript();
		~PlayerCheckGroundScript();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;

	private:
		bool IsFalling();
		bool IsOnGround();
		void collisionCheck(Collider2D* other);

		bool onGround;
		bool onAir;
	};
}
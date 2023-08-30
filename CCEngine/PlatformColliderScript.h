#pragma once
#include "ccScript.h"

namespace cc
{
	class PlatformColliderScript : public Script
	{
	public:
		PlatformColliderScript();
		~PlatformColliderScript();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;

	private:
		void Push(Collider2D* other);
	};
}
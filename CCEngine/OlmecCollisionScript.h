#pragma once
#include "ccScript.h"

namespace cc
{
	class OlmecCollisionScript : public Script
	{
	public:
		OlmecCollisionScript();
		~OlmecCollisionScript();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;

	private:
		void PushObject(Collider2D* other);
		void PushOlmec(Collider2D* other);
		void collisionCheck(Collider2D* other);

		double mTime;
		bool crashFlag;
	};
}
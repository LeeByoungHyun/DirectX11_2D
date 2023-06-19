#pragma once
#include "ccEntity.h"

namespace cc
{
	using namespace cc::enums;
	using namespace cc::math;

	class GameObject;
	class Component : public Entity
	{
	public:
		Component(eComponentType type);
		~Component();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

		GameObject* GetOwner() { return mOwner; }
		void SetOwner(GameObject* owner) { mOwner = owner; }

	private:
		eComponentType mType;
		GameObject* mOwner;
	};
}

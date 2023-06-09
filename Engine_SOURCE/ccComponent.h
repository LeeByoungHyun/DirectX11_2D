#pragma once
#include "ccEntity.h"

namespace cc
{
	using namespace cc::enums;

	class Component : public Entity
	{
	public:
		Component();
		~Component();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

	private:
		eComponentType mType;

	};
}

#pragma once
#include "ccComponent.h"


namespace cc
{
	class Script : public Component
	{
	public:
		Script();
		~Script();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:

	};
}
#pragma once
#include "..\\Engine_SOURCE\\ccGameObject.h"


namespace gui
{
	class DebugObject : public cc::GameObject
	{
	public:
		DebugObject();
		~DebugObject();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:
	};
}
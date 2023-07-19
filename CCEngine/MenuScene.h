#pragma once
#include "..\Engine_SOURCE\ccScene.h"

namespace cc
{
	class MenuScene : public Scene
	{
	public:
		MenuScene();
		virtual ~MenuScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:

	};
}
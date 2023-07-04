#pragma once
#include "..\Engine_SOURCE\ccScene.h"

namespace cc
{
	class TutorialScene : public Scene
	{
	public:
		TutorialScene();
		virtual ~TutorialScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:
		GameObject* mapTest;
		GameObject* marine;
		GameObject* mouse;
		GameObject* camera;
	};
}
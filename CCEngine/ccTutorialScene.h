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

		virtual void OnEnter() override;
		virtual void OnExit() override;

	private:
		class GameObject* camera;
		class GameObject* mapTest;
		class Marine* marine;
		class TestGun* testGun;
		class GameObject* mouse;
		//GameObject* gun;

	};
}
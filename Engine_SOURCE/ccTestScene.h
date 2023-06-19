#pragma once
#include "ccScene.h"


namespace cc
{
	class TestScene : public Scene
	{
	public:
		TestScene();
		~TestScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:

	};
}
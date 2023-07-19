#pragma once
#include "..\Engine_SOURCE\ccScene.h"

namespace cc
{
	class SurfaceScene : public Scene
	{
	public:
		SurfaceScene();
		virtual ~SurfaceScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:

	};
}
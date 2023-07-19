#pragma once
class PlayScene
{
};

#pragma once
#include "..\Engine_SOURCE\ccScene.h"

namespace cc
{
	class PlayScene : public Scene
	{
	public:
		PlayScene();
		virtual ~PlayScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void CreateMap();

	private:

	};
}
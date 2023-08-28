#pragma once
class NextLevelScene
{
};

#pragma once
#include "..\Engine_SOURCE\ccScene.h"


namespace cc
{
	class NextLevelScene : public Scene
	{
	public:
		NextLevelScene();
		virtual ~NextLevelScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

		void CreateLevel();
		void MaskingTile();

	private:
		std::vector<std::vector<int>> map;
		std::vector<std::vector<class Tile*>> mapTile;
	};
}
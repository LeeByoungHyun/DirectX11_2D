#pragma once
class PlayScene
{
};

#pragma once
#include "..\Engine_SOURCE\ccScene.h"

namespace cc
{
	const int MAPCOLUMN = 36;
	const int MAPROW = 44;

	class PlayScene : public Scene
	{
	public:
		PlayScene();
		virtual ~PlayScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void CreatePath();
		void CreateMap();
		void MaskingTile();

	private:
		std::vector<std::vector<int>> map;
		std::vector<std::vector<class Tile*>> mapTile;
		std::vector<std::vector<int>> mapPath;
	};
}
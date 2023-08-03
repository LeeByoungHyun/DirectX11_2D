#pragma once
#include "..\Engine_SOURCE\ccScene.h"

namespace cc
{
	class BossScene : public Scene
	{
	public:
		BossScene();
		virtual ~BossScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void CreateMap();
		void MaskingTile();

	private:
		std::vector<std::vector<int>> map;
		std::vector<std::vector<class Tile*>> mapTile;
		std::vector<std::vector<int>> mapPath;
	};
}
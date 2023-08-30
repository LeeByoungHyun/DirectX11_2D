#pragma once
#include "..\Engine_SOURCE\ccScene.h"


namespace cc
{
	class TestScene : public Scene
	{
	public:
		TestScene();
		virtual ~TestScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

		void CreatePath();
		void CreateLevel();
		void ResetMap();
		void MaskingTile();
		void RemoveMapTile(int col, int row) 
		{ 
			map[col][row] = 0; 
			mapTile[col][row] = 0;
		}

		void SetTileDestroyedFlag(bool flag) { TileDestroyedFlag = flag; }

	private:
		std::vector<std::vector<int>> map;
		std::vector<std::vector<class Tile*>> mapTile;
		std::vector<std::vector<int>> mapPath;

		class MainCamera* mainCamera;

		Vector2 entrancePos;

		bool TileDestroyedFlag;
	};
}
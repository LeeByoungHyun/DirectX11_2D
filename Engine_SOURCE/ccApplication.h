#pragma once
#include "CCEngine.h"
#include "ccGraphicDevice_Dx11.h"
#include "ccScene.h"

namespace cc
{
	class Application
	{
	public:
		Application();
		~Application();
		
		void Run();

		void Initialize();
		void Update();
		void LateUpdate();
		void FixedUpdate();
		void Render();
		void Present();
		void Destroy();

		void SetWindow(HWND hwnd, UINT width, UINT height);

		UINT GetWidth() { return mWidth; }
		UINT GetHeight() { return mHeight; }
		HWND GetHwnd() { return mHwnd; }

	private:
		bool mbInitialize = false;
		std::unique_ptr<cc::graphics::GraphicDevice_Dx11> graphicDevice;

		HWND mHwnd;
		UINT mWidth;
		UINT mHeight;

		double mTime;
	};
}

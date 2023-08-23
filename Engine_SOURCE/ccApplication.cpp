#include "ccApplication.h"
#include "ccInput.h"
#include "ccTime.h"
#include "ccRenderer.h"
#include "ccSceneManager.h"
#include "ccCollisionManager.h"

namespace cc
{
	Application::Application()
		: graphicDevice(nullptr)
		, mHwnd(NULL)
		, mWidth(-1)
		, mHeight(-1)
	{
		mTime = 0.0f;
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		mTime += Time::DeltaTime();
		
		Update();
		//if (mTime >= 1.0f / 60.0f)
		//{
		//	FixedUpdate();
		//	mTime = 0.0f;
		//}
		FixedUpdate();
		LateUpdate();
		Render();
		Destroy();
	}

	void Application::Initialize()
	{
		Time::Initiailize();
		Input::Initialize();

		renderer::Initialize();
		SceneManager::Initialize();
	}

	void Application::Update()
	{
		Time::Update();
		Input::Update();
		//CollisionManager::Update();
		SceneManager::Update();
	}

	void Application::LateUpdate()
	{
		SceneManager::LateUpdate();
	}

	void Application::FixedUpdate()
	{
		CollisionManager::Update();
	}

	void Application::Render()
	{
		Time::Render();

		graphicDevice->ClearTarget();
		graphicDevice->UpdateViewPort();

		//SceneManager::Render();
		renderer::Render();
		//graphicDevice->Draw();

		//graphicDevice->Present();
	}

	void Application::Present()
	{
		graphicDevice->Present();
	}

	void Application::Destroy()
	{
		SceneManager::Destroy();
	}

	void Application::SetWindow(HWND hwnd, UINT width, UINT height)
	{
		if (graphicDevice == nullptr)
		{
			mHwnd = hwnd;
			mWidth = width;
			mHeight = height;

			graphicDevice = std::make_unique<cc::graphics::GraphicDevice_Dx11>();
			cc::graphics::GetDevice() = graphicDevice.get();
		}

		RECT rt = { 0, 0, (LONG)width , (LONG)height };
		AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, false);
		SetWindowPos(mHwnd, nullptr, 0, 0, rt.right - rt.left, rt.bottom - rt.top, 0);
		ShowWindow(mHwnd, true);
		UpdateWindow(mHwnd);
	}

}

#include "ccScene.h"

namespace cc
{
	Scene::Scene()
	{

	}

	Scene::~Scene()
	{

	}

	void Scene::Initialize()
	{
		
	}

	void Scene::Update()
	{
		for (Layer* layer : mLayers)
		{
			layer->Update();
		}
	}

	void Scene::LateUpdate()
	{
	}
	void Scene::Render()
	{
		for (Layer* layer : mLayers)
		{
			layer->Render();
		}
	}
}

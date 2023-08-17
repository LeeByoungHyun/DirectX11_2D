#pragma once
#include "ccLayer.h"
#include "ccGameObject.h"
#include "ccScene.h"
#include "ccSceneManager.h"
#include "ccTransform.h"
#include "..//CCEngine//MainCamera.h"


namespace cc::object
{
	//extern Vector3 cameraPos;
	//extern Vector2 screenSize;

	template <typename T>
	static __forceinline T* Instantiate(enums::eLayerType layer)
	{
		T* gameObj = new T();
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(layer, gameObj);
		gameObj->SetType(layer);
		gameObj->Initialize();

		return gameObj;
	}

	template <typename T>
	static __forceinline T* Instantiate(Vector3 pos, enums::eLayerType layer)
	{
		T* gameObj = new T();
		Transform* tr = gameObj->GetComponent<Transform>();
		tr->SetPosition(pos);

		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(layer, gameObj);
		gameObj->SetType(layer);
		gameObj->Initialize();

		return gameObj;
	}

	template <typename T>
	static __forceinline T* Instantiate(Vector3 pos, Vector3 rotate, enums::eLayerType layer)
	{
		T* gameObj = new T();
		Transform* tr = gameObj->GetComponent<Transform>();
		tr->SetPosition(pos);
		tr->SetRotation(rotate);

		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(layer, gameObj);
		gameObj->SetType(layer);
		gameObj->Initialize();

		return gameObj;
	}

	template <typename T>
	static __forceinline T* Instantiate(Vector3 pos, Vector3 rotate, Vector3 scale, enums::eLayerType layer)
	{
		T* gameObj = new T();
		Transform* tr = gameObj->GetComponent<Transform>();
		tr->SetPosition(pos);
		tr->SetRotation(rotate);
		tr->SetScale(scale);

		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(layer, gameObj);
		gameObj->SetType(layer);
		gameObj->Initialize();

		return gameObj;
	}

	template <typename T>
	static void Instantiate(T* gameObj, enums::eLayerType layer)
	{
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(layer, gameObj);
		gameObj->SetType(layer);
		gameObj->Initialize();
	}

	static __forceinline void Destroy(GameObject* gameObj)
	{
		gameObj->SetState(cc::GameObject::eState::Dead);
	}

	static void CheckActive(GameObject* gameObj)
	{
		//Vector3 mPos = gameObj->GetComponent<Transform>()->GetPosition();
		//Vector3 cameraPos = MainCamera::GatCameraPos();
		//Vector2 screenSize = MainCamera::screenSize;
		//if (cameraPos.x - screenSize.x <= mPos.x && mPos.x <= cameraPos.x + screenSize.x
		//	&& cameraPos.y - screenSize.y <= mPos.y && mPos.y <= cameraPos.y + screenSize.y)
		//	gameObj->SetState(GameObject::eState::Active);
		//else
		//	gameObj->SetState(GameObject::eState::Pause);
	}
}
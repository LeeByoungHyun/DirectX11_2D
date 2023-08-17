#include "ccGameObject.h"
#include "ccRenderer.h"
#include "ccGraphicDevice_Dx11.h"
#include "ccTransform.h"
#include "ccObject.h"

namespace cc
{
	extern Vector3 cameraPos;
	extern Vector2 screenSize;

	GameObject::GameObject()
		: mState(eState::Active)
	{
		AddComponent<Transform>();
		collisionFlag = false;
	}

	GameObject::~GameObject()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			delete comp;
			comp = nullptr;
		}

		for (Script* script : mScripts)
		{
			if (script == nullptr)
				continue;

			delete script;
			script = nullptr;
		}
	}

	void GameObject::Initialize()
	{

	}

	void GameObject::Update()
	{
		// 화면 범위 밖으로 나가면 Phase
		Vector3 mPos = this->GetComponent<Transform>()->GetPosition();
		if (cameraPos.x - screenSize.x <= mPos.x && mPos.x <= cameraPos.x + screenSize.x
			&& cameraPos.y - screenSize.y <= mPos.y && mPos.y <= cameraPos.y + screenSize.y)
			mState = eState::Active;
		else
			mState = eState::Pause;

		//object::CheckActive(this);

		if (mState != eState::Active)
			return;

		for (Component* comp : mComponents)
		{
			comp->Update();
		}

		for (Script* script : mScripts)
		{
			script->Update();
		}

		collisionFlag = false;
	}

	void GameObject::LateUpdate()
	{
		if (mState != eState::Active)
			return;

		for (Component* comp : mComponents)
		{
			comp->LateUpdate();
		}

		for (Script* script : mScripts)
		{
			script->LateUpdate();
		}
	}

	void GameObject::Render()
	{
		if (mState != eState::Active)
			return;

		for (Component* comp : mComponents)
		{
			comp->Render();
		}

		for (Script* script : mScripts)
		{
			script->Render();
		}
	}
}

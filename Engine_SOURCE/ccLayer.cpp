#include "ccLayer.h"

namespace cc
{
	Layer::Layer()
	{
		addGameObj = {};
	}

	Layer::~Layer()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;
		
			delete gameObj;
			gameObj = nullptr;
		}
	}

	void Layer::Initialize()
	{

	}

	void Layer::Update()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			//if (gameObj->GetState()
			//	!= GameObject::eState::Active)
			//	continue;

			if (gameObj == nullptr)
				continue;
		
			gameObj->Update();	
		}
	}

	void Layer::LateUpdate()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			//if (gameObj->GetState()
			//	!= GameObject::eState::Active)
			//	continue;

			if (gameObj == nullptr)
				continue;

			gameObj->LateUpdate();
		}
	}

	void Layer::Render()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			//if (gameObj->GetState()
			//	!= GameObject::eState::Active)
			//	continue;

			if (gameObj == nullptr)
				continue;

			gameObj->Render();
		}
	}

	void Layer::Destory()
	{
		// dead ������Ʈ ��Ƶα�
		std::set<GameObject*> deleteGameObj = {};
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj->GetState()
				== GameObject::eState::Dead)
				deleteGameObj.insert(gameObj);
		}

		// daed ������Ʈ ���ܽ�Ű�� layer����
		typedef std::vector<GameObject*>::iterator GameObjectIter;
		for (GameObjectIter iter = mGameObjects.begin()
			; iter != mGameObjects.end(); )
		{
			std::set<GameObject*>::iterator deleteIter
				= deleteGameObj.find(*(iter));

			if (deleteIter != deleteGameObj.end())
			{
				iter = mGameObjects.erase(iter);
				continue;
			}

			iter++;
		}

		//�޸� ����
		for (GameObject* gameObj : deleteGameObj)
		{
			delete gameObj;
			gameObj = nullptr;
		}
	}

	void Layer::AddGameObject(GameObject* gameObj)
	{
		//mGameObjects.push_back(gameObj);

		addGameObj.insert(gameObj);
	}

	void Layer::Subjoin()
	{
		for (GameObject* gameObj : addGameObj)
		{
			mGameObjects.push_back(gameObj);
		}

		addGameObj.clear();
	}
	void Layer::ClearGameObject()
	{
		mGameObjects.clear();
		mGameObjects.resize(0);
		mGameObjects.shrink_to_fit();
	}
}
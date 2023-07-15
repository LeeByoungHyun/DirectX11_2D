#include "ccEntity.h"


namespace cc
{
	Entity::Entity()
		: mName(L"")
		, mColliderID((UINT64)this)
	{

	}

	Entity::~Entity()
	{
	}

}

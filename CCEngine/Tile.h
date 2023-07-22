#pragma once
#include "ccGameObject.h"
#include "ccMeshRenderer.h"
#include "ccTransform.h"

namespace cc
{
	class Tile : public GameObject
	{
	public:
		Tile();
		virtual ~Tile();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		virtual void Masking();
		void SetMask(int direct, bool check) { masking[direct] = check; }

	protected:
		MeshRenderer* mMeshRenderer;
		Transform* mTransform;

		bool masking[4];
		bool masked[4];
	};
}

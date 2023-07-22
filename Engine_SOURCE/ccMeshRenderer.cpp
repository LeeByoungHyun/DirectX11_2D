#include "ccMeshRenderer.h"
#include "ccGameObject.h"
#include "ccTransform.h"
#include "ccRenderer.h"
#include "ccAnimator.h"

namespace cc
{
	MeshRenderer::MeshRenderer()
		: Component(eComponentType::MeshRenderer)
	{

	}

	MeshRenderer::~MeshRenderer()
	{

	}

	void MeshRenderer::Initialize()
	{

	}

	void MeshRenderer::Update()
	{

	}

	void MeshRenderer::LateUpdate()
	{

	}

	void MeshRenderer::Render()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		// offset+
		tr->BindConstantBuffer();

		mMesh->BindBuffer();
		mMaterial->Binds();

		Animator* animator = GetOwner()->GetComponent<Animator>();
		if (animator)
		{
			animator->Binds();
		}

		mMesh->Render();

		mMaterial->Clear();
	}
}
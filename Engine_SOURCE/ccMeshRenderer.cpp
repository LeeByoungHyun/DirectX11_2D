#include "ccMeshRenderer.h"
#include "ccGameObject.h"
#include "ccTransform.h"
#include "ccRenderer.h"

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
		tr->BindConstantBuffer();

		//mMesh->BindBuffer();
		//mShader->Binds();

		renderer::mesh->BindBuffer();
		renderer::shader->Binds();
		GetDevice()->DrawIndexed(renderer::mesh->GetIndexCount(), 0, 0);
	}
}
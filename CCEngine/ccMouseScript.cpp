#include "ccMouseScript.h"
#include "ccTransform.h"
#include "ccGameObject.h"
#include "ccTime.h"
#include "ccinput.h"
#include "ccApplication.h"
#include "ccCamera.h"
#include "ccMath.h"

extern cc::Application application;

namespace cc
{
	void MouseScript::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		Vector2 mousePos = Input::GetMousePos();	// ������ ���� ���콺 ��ǥ
		Vector3 p = Vector3(mousePos.x, mousePos.y, 0.0f);

		Viewport viewport;
		viewport.width = application.GetWidth();
		viewport.height = application.GetHeight();
		viewport.x = 0;
		viewport.y = 0;
		viewport.minDepth = 0.0f;
		viewport.maxDepth = 1.0f;

		p = viewport.Unproject(p, Camera::GetProjectionMatrix(), Camera::GetViewMatrix(), Matrix::Identity);
		tr->SetPosition(p);

		/*
		// ��������� ���콺 ��ǥ�� -1 ~ 1 ������ ������ ��ȯ (NDC ��ȯ)
		float ndcX = (2.0f * mousePos.x / application.GetWidth()) - 1.0f;
		float ndcY = 1.0f - (2.0f * mousePos.y / application.GetHeight());

		// NDC ��ǥ ���� ��ǥ�� ��ȯ
		XMMATRIX projectionMatrix = Camera::GetProjectionMatrix();  // ���� ���
		XMMATRIX viewMatrix = Camera::GetViewMatrix();  // �� ���
		XMMATRIX worldMatrix = tr->GetWorldMatrix();  // ���� ���

		XMMATRIX viewProjectionMatrix = viewMatrix * projectionMatrix;
		XMMATRIX inverseViewProjectionMatrix = XMMatrixInverse(nullptr, viewProjectionMatrix);	// ��������� �����

		XMVECTOR worldPos = XMVectorSet(ndcX, ndcY, 0.0f, 1.0f);
		worldPos = XMVector4Transform(worldPos, inverseViewProjectionMatrix);

		// ���콺�� ���� ��ǥ
		float worldX = XMVectorGetX(worldPos);
		float worldY = XMVectorGetY(worldPos);
		float worldZ = XMVectorGetZ(worldPos);

		tr->SetPosition(Vector3(worldX, worldY, worldZ));
		*/
	}
}
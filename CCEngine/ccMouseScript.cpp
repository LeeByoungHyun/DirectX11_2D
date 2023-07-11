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

		Vector2 mousePos = Input::GetMousePos();	// 윈도우 상의 마우스 좌표
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
		// 윈도우상의 마우스 좌표를 -1 ~ 1 사이의 값으로 변환 (NDC 변환)
		float ndcX = (2.0f * mousePos.x / application.GetWidth()) - 1.0f;
		float ndcY = 1.0f - (2.0f * mousePos.y / application.GetHeight());

		// NDC 좌표 월드 좌표로 변환
		XMMATRIX projectionMatrix = Camera::GetProjectionMatrix();  // 투영 행렬
		XMMATRIX viewMatrix = Camera::GetViewMatrix();  // 뷰 행렬
		XMMATRIX worldMatrix = tr->GetWorldMatrix();  // 월드 행렬

		XMMATRIX viewProjectionMatrix = viewMatrix * projectionMatrix;
		XMMATRIX inverseViewProjectionMatrix = XMMatrixInverse(nullptr, viewProjectionMatrix);	// 투영행렬의 역행렬

		XMVECTOR worldPos = XMVectorSet(ndcX, ndcY, 0.0f, 1.0f);
		worldPos = XMVector4Transform(worldPos, inverseViewProjectionMatrix);

		// 마우스의 월드 좌표
		float worldX = XMVectorGetX(worldPos);
		float worldY = XMVectorGetY(worldPos);
		float worldZ = XMVectorGetZ(worldPos);

		tr->SetPosition(Vector3(worldX, worldY, worldZ));
		*/
	}
}
#include "ccRenderer.h"
#include "ccInput.h"
#include "ccTime.h"

namespace renderer
{
	Vertex vertexes[4] = {};

	// Input Layout (정점 정보)
	ID3D11InputLayout* triangleLayout = nullptr;

	// Vertex Buffer
	cc::Mesh* mesh = nullptr;

	// Constant Buffer
	ID3D11Buffer* triangleConstantBuffer = nullptr;

	cc::Shader* shader = nullptr;

	// error blob
	//ID3DBlob* errorBlob = nullptr;
	
	// Vertex Shader code -> Binary Code
	//ID3DBlob* triangleVSBlob = nullptr;
	
	// Vertex Shader
	//ID3D11VertexShader* triangleVSShader = nullptr;

	// Pixel Shader code -> Binary Code
	//ID3DBlob* trianglePSBlob = nullptr;

	// Vertex Shader
	//ID3D11PixelShader* trianglePSShader = nullptr;

	// Index Buffer
	//ID3D11Buffer* triangleIdxBuffer = nullptr;

	Vector4 pos(0.0f, 0.0f, 0.0f, 1.0f);

	void SetupState()
	{

	}

	void LoadBuffer()
	{
		mesh = new cc::Mesh();
		mesh->CreateVertexBuffer(vertexes, 4);

		std::vector<UINT> indexes = {};
		indexes.push_back(0);
		indexes.push_back(1);
		indexes.push_back(2);
		indexes.push_back(0);
		indexes.push_back(2);
		indexes.push_back(3);
		mesh->CreateIndexBuffer(indexes.data(), indexes.size());

		// Constant Buffer
		D3D11_BUFFER_DESC triangleCSDesc = {};
		triangleCSDesc.ByteWidth = sizeof(Vector4);
		triangleCSDesc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_CONSTANT_BUFFER;
		triangleCSDesc.Usage = D3D11_USAGE::D3D11_USAGE_DYNAMIC;
		triangleCSDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

		cc::graphics::GetDevice()->CreateBuffer(&triangleConstantBuffer, &triangleCSDesc, nullptr);
	}

	void LoadShader()
	{
		cc::graphics::GetDevice()->CreateShader();

		shader = new cc::Shader();
		shader->Create(eShaderStage::VS, L"TriangleVS.hlsl", "main");
		shader->Create(eShaderStage::PS, L"TrianglePS.hlsl", "main");
	}

	void Initialize()
	{
		/*
		// 삼각형 정점
		triangleVertexes[0].pos = Vector3(-0.5f, 0.75f, 0.0f);
		triangleVertexes[0].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);

		triangleVertexes[1].pos = Vector3(-0.25f, 0.25f, 0.0f);
		triangleVertexes[1].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		triangleVertexes[2].pos = Vector3(-0.75f, 0.25f, 0.0f);
		triangleVertexes[2].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

		// 사각형 정점
		rectangleVertexes[0].pos = Vector3(0.75f, 0.75f, 0.0f);
		rectangleVertexes[0].color = Vector4(1.0f, 1.0f, 1.0f, 1.0f);

		rectangleVertexes[1].pos = Vector3(0.75f, 0.25f, 0.0f);
		rectangleVertexes[1].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		rectangleVertexes[2].pos = Vector3(0.25f, 0.25f, 0.0f);
		rectangleVertexes[2].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		rectangleVertexes[3].pos = Vector3(0.75f, 0.75f, 0.0f);
		rectangleVertexes[3].color = Vector4(1.0f, 1.0f, 1.0f, 1.0f);

		rectangleVertexes[4].pos = Vector3(0.25f, 0.25f, 0.0f);
		rectangleVertexes[4].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

		rectangleVertexes[5].pos = Vector3(0.25f, 0.75f, 0.0f);
		rectangleVertexes[5].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

		// 육각형 정점
		hexagonVertexes[0].pos = Vector3(-0.6f, -0.25f, 0.0f);
		hexagonVertexes[0].color = Vector4(1.0f, 1.0f, 1.0f, 1.0f);

		hexagonVertexes[1].pos = Vector3(-0.4f, -0.25f, 0.0f);
		hexagonVertexes[1].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);

		hexagonVertexes[2].pos = Vector3(-0.2f, -0.5f, 0.0f);
		hexagonVertexes[2].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		hexagonVertexes[3].pos = Vector3(-0.6f, -0.25f, 0.0f);
		hexagonVertexes[3].color = Vector4(1.0f, 1.0f, 1.0f, 1.0f);

		hexagonVertexes[4].pos = Vector3(-0.2f, -0.5f, 0.0f);
		hexagonVertexes[4].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		hexagonVertexes[5].pos = Vector3(-0.4f, -0.75f, 0.0f);
		hexagonVertexes[5].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

		hexagonVertexes[6].pos = Vector3(-0.6f, -0.25f, 0.0f);
		hexagonVertexes[6].color = Vector4(1.0f, 1.0f, 1.0f, 1.0f);

		hexagonVertexes[7].pos = Vector3(-0.4f, -0.75f, 0.0f);
		hexagonVertexes[7].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

		hexagonVertexes[8].pos = Vector3(-0.6f, -0.75f, 0.0f);
		hexagonVertexes[8].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);

		hexagonVertexes[9].pos = Vector3(-0.6f, -0.25f, 0.0f);
		hexagonVertexes[9].color = Vector4(1.0f, 1.0f, 1.0f, 1.0f);

		hexagonVertexes[10].pos = Vector3(-0.6f, -0.75f, 0.0f);
		hexagonVertexes[10].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);

		hexagonVertexes[11].pos = Vector3(-0.8f, -0.5f, 0.0f);
		hexagonVertexes[11].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

		// 별 정점
		starVertexes[0].pos = Vector3(0.0f, 0.5f, 0.0f);
		starVertexes[0].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);

		starVertexes[1].pos = Vector3(0.294f, -0.404f, 0.0f);
		starVertexes[1].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);

		starVertexes[2].pos = Vector3(0.0f, 0.05f, 0.0f);
		starVertexes[2].color = Vector4(1.0f, 1.0f, 1.0f, 1.0f);

		starVertexes[3].pos = Vector3(0.475f, 0.154f, 0.0f);
		starVertexes[3].color = Vector4(1.0f, 1.0f, 0.0f, 1.0f);

		starVertexes[4].pos = Vector3(-0.294f, -0.404f, 0.0f);
		starVertexes[4].color = Vector4(1.0f, 1.0f, 0.0f, 1.0f);

		starVertexes[5].pos = Vector3(0.0f, 0.05f, 0.0f);
		starVertexes[5].color = Vector4(1.0f, 1.0f, 1.0f, 1.0f);

		starVertexes[6].pos = Vector3(0.294f, -0.404f, 0.0f);
		starVertexes[6].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		starVertexes[7].pos = Vector3(-0.475, 0.154f, 0.0f);
		starVertexes[7].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		starVertexes[8].pos = Vector3(0.0f, 0.05f, 0.0f);
		starVertexes[8].color = Vector4(1.0f, 1.0f, 1.0f, 1.0f);

		starVertexes[9].pos = Vector3(-0.294f, -0.404f, 0.0f);
		starVertexes[9].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

		starVertexes[10].pos = Vector3(0.0f, 0.5f, 0.0f);
		starVertexes[10].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

		starVertexes[11].pos = Vector3(0.0f, 0.05f, 0.0f);
		starVertexes[11].color = Vector4(1.0f, 1.0f, 1.0f, 1.0f);

		starVertexes[12].pos = Vector3(-0.475f, 0.155f, 0.0f);
		starVertexes[12].color = Vector4(1.0f, 0.0f, 1.0f, 1.0f);

		starVertexes[13].pos = Vector3(0.475f, 0.155f, 0.0f);
		starVertexes[13].color = Vector4(1.0f, 0.0f, 1.0f, 1.0f);

		starVertexes[14].pos = Vector3(0.0f, 0.05f, 0.0f);
		starVertexes[14].color = Vector4(1.0f, 1.0f, 1.0f, 1.0f);

		// 원 정점
		double radius = 0.4f;	// 반지름
		double centerX = 0.5f;	// 중심점
		double centerY = -0.5f;
		for (int i = 360; i > 0; i--)
		{
			float newX = centerX + cos((double)i / 180 * 3.141592) * radius;
			float newY = centerY + sin((double)i / 180 * 3.141592) * radius;
			circleVertexes[360 - i].pos = Vector3(newX, newY, 0.0f);
			circleVertexes[360 - i].color = Vector4(1.0f, 1.0f, 1.0f, 1.0f);
		}
		*/

		vertexes[0].pos = Vector3(-0.5f, 0.5f, 0.0f);
		vertexes[0].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);

		vertexes[1].pos = Vector3(0.5f, 0.5f, 0.0f);
		vertexes[1].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		vertexes[2].pos = Vector3(0.5f, -0.5f, 0.0f);
		vertexes[2].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

		vertexes[3].pos = Vector3(-0.5f, -0.5f, 0.0f);
		vertexes[3].color = Vector4(1.0f, 1.0f, 1.0f, 1.0f);

		SetupState();
		LoadBuffer();
		LoadShader();
	}

	void Update()
	{
		if (cc::Input::GetKey(cc::eKeyCode::W))
			pos += Vector4(0.0f, 0.1f * cc::Time::DeltaTime(), 0.0f, 1.0f);
		if (cc::Input::GetKey(cc::eKeyCode::S))
			pos += Vector4(0.0f, -0.1f * cc::Time::DeltaTime(), 0.0f, 1.0f);
		if (cc::Input::GetKey(cc::eKeyCode::A))
			pos += Vector4(-0.1f * cc::Time::DeltaTime(), 0.0f, 0.0f, 1.0f);
		if (cc::Input::GetKey(cc::eKeyCode::D))
			pos += Vector4(0.1f * cc::Time::DeltaTime(), 0.0f, 0.0f, 1.0f);

		cc::graphics::GetDevice()->SetConstantBuffer(triangleConstantBuffer, &pos, sizeof(Vector4));
		cc::graphics::GetDevice()->BindConstantBuffer(eShaderStage::VS, eCBType::Transform, triangleConstantBuffer);
	}

	void Release()
	{
		if (triangleLayout != nullptr)
			triangleLayout->Release();

		if (triangleConstantBuffer != nullptr)
			triangleConstantBuffer->Release();
	}
}




#include "ccRenderer.h"



namespace cc::renderer
{
	Vertex triangleVertexes[3] = {};
	Vertex rectangleVertexes[6] = {};
	Vertex hexagonVertexes[12] = {};
	Vertex starVertexes[15] = {};
	Vertex circleVertexes[360] = {};

	// Input Layout (정점 정보)
	ID3D11InputLayout* triangleLayout = nullptr;
	ID3D11InputLayout* rectangleLayout = nullptr;
	ID3D11InputLayout* hexagonLayout = nullptr;
	ID3D11InputLayout* starLayout = nullptr;
	ID3D11InputLayout* circleLayout = nullptr;

	// Vertex Buffer
	ID3D11Buffer* triangleBuffer = nullptr;
	ID3D11Buffer* rectangleBuffer = nullptr;
	ID3D11Buffer* hexagonBuffer = nullptr;
	ID3D11Buffer* starBuffer = nullptr;
	ID3D11Buffer* circleBuffer = nullptr;

	// error blob
	ID3DBlob* errorBlob = nullptr;
	
	// Vertex Shader code -> Binary Code
	ID3DBlob* triangleVSBlob = nullptr;
	ID3DBlob* rectangleVSBlob = nullptr;
	ID3DBlob* hexagonVSBlob = nullptr;
	ID3DBlob* starVSBlob = nullptr;
	ID3DBlob* circleVSBlob = nullptr;

	// Vertex Shader
	ID3D11VertexShader* triangleVSShader = nullptr;
	ID3D11VertexShader* rectangleVSShader = nullptr;
	ID3D11VertexShader* hexagonVSShader = nullptr;
	ID3D11VertexShader* starVSShader = nullptr;
	ID3D11VertexShader* circleVSShader = nullptr;

	// Pixel Shader code -> Binary Code
	ID3DBlob* trianglePSBlob = nullptr;
	ID3DBlob* rectanglePSBlob = nullptr;
	ID3DBlob* hexagonPSBlob = nullptr;
	ID3DBlob* starPSBlob = nullptr;
	ID3DBlob* circlePSBlob = nullptr;

	// Vertex Shader
	ID3D11PixelShader* trianglePSShader = nullptr;
	ID3D11PixelShader* rectanglePSShader = nullptr;
	ID3D11PixelShader* hexagonPSShader = nullptr;
	ID3D11PixelShader* starPSShader = nullptr;
	ID3D11PixelShader* circlePSShader = nullptr;

	// Index Buffer
	ID3D11Buffer* triangleIdxBuffer = nullptr;

	// Constant Buffer
	ID3D11Buffer* triangleConstantBuffer = nullptr;

	void SetupState()
	{

	}

	void LoadBuffer()
	{
		// 삼각형 정점 버퍼
		D3D11_BUFFER_DESC triangleDesc = {};
		triangleDesc.Usage = D3D11_USAGE::D3D11_USAGE_DYNAMIC;
		triangleDesc.ByteWidth = sizeof(Vertex) * 3;
		triangleDesc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_VERTEX_BUFFER;
		triangleDesc.CPUAccessFlags = D3D11_CPU_ACCESS_FLAG::D3D11_CPU_ACCESS_WRITE;

		// 사각형 정점 버퍼
		D3D11_BUFFER_DESC rectangleDesc = {};
		rectangleDesc.Usage = D3D11_USAGE::D3D11_USAGE_DYNAMIC;
		rectangleDesc.ByteWidth = sizeof(Vertex) * 6;
		rectangleDesc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_VERTEX_BUFFER;
		rectangleDesc.CPUAccessFlags = D3D11_CPU_ACCESS_FLAG::D3D11_CPU_ACCESS_WRITE;

		// 육각형 정점 버퍼
		D3D11_BUFFER_DESC hexagonDesc = {};
		hexagonDesc.Usage = D3D11_USAGE::D3D11_USAGE_DYNAMIC;
		hexagonDesc.ByteWidth = sizeof(Vertex) * 12;
		hexagonDesc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_VERTEX_BUFFER;
		hexagonDesc.CPUAccessFlags = D3D11_CPU_ACCESS_FLAG::D3D11_CPU_ACCESS_WRITE;

		// 별 정점 버퍼
		D3D11_BUFFER_DESC starDesc = {};
		starDesc.Usage = D3D11_USAGE::D3D11_USAGE_DYNAMIC;
		starDesc.ByteWidth = sizeof(Vertex) * 15;
		starDesc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_VERTEX_BUFFER;
		starDesc.CPUAccessFlags = D3D11_CPU_ACCESS_FLAG::D3D11_CPU_ACCESS_WRITE;

		// 원 정점 버퍼
		D3D11_BUFFER_DESC circleDesc = {};
		circleDesc.Usage = D3D11_USAGE::D3D11_USAGE_DYNAMIC;
		circleDesc.ByteWidth = sizeof(Vertex) * 360;
		circleDesc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_VERTEX_BUFFER;
		circleDesc.CPUAccessFlags = D3D11_CPU_ACCESS_FLAG::D3D11_CPU_ACCESS_WRITE;

		// 정점 버퍼 생성
		D3D11_SUBRESOURCE_DATA triangleData = {};
		triangleData.pSysMem = triangleVertexes;
		cc::graphics::GetDevice()->CreateBuffer(&triangleBuffer, &triangleDesc, &triangleData);

		D3D11_SUBRESOURCE_DATA rectangleData = {};
		rectangleData.pSysMem = rectangleVertexes;
		cc::graphics::GetDevice()->CreateBuffer(&rectangleBuffer, &rectangleDesc, &rectangleData);
		
		D3D11_SUBRESOURCE_DATA hexagonData = {};
		hexagonData.pSysMem = hexagonVertexes;
		cc::graphics::GetDevice()->CreateBuffer(&hexagonBuffer, &hexagonDesc, &hexagonData);

		D3D11_SUBRESOURCE_DATA starData = {};
		starData.pSysMem = starVertexes;
		cc::graphics::GetDevice()->CreateBuffer(&starBuffer, &starDesc, &starData);

		D3D11_SUBRESOURCE_DATA circleData = {};
		circleData.pSysMem = circleVertexes;
		cc::graphics::GetDevice()->CreateBuffer(&circleBuffer, &circleDesc, &circleData);

		std::vector<UINT> indexes = {};
		indexes.push_back(0);
		indexes.push_back(1);
		indexes.push_back(2);


		// Index Buffer
		D3D11_BUFFER_DESC triangleIdxDesc = {};
		triangleIdxDesc.ByteWidth = sizeof(UINT) * indexes.size();
		triangleIdxDesc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_INDEX_BUFFER;
		triangleIdxDesc.Usage = D3D11_USAGE_DEFAULT;
		triangleIdxDesc.CPUAccessFlags = 0;

		D3D11_SUBRESOURCE_DATA triangleIdxData = {};
		triangleIdxData.pSysMem = indexes.data();
		cc::graphics::GetDevice()->CreateBuffer(&triangleIdxBuffer, &triangleIdxDesc, &triangleIdxData);

		// Constant Buffer
		D3D11_BUFFER_DESC triangleCSDesc = {};
		triangleCSDesc.ByteWidth = sizeof(Vector4);
		triangleCSDesc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_CONSTANT_BUFFER;
		triangleCSDesc.Usage = D3D11_USAGE::D3D11_USAGE_DYNAMIC;
		triangleCSDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

		cc::graphics::GetDevice()->CreateBuffer(&triangleConstantBuffer, &triangleCSDesc, nullptr);

		Vector4 pos(0.3f, 0.0f, 0.0f, 1.0f);
		cc::graphics::GetDevice()->SetConstantBuffer(triangleConstantBuffer, &pos, sizeof(Vector4));
		cc::graphics::GetDevice()->BindConstantBuffer(eShaderStage::VS, eCBType::Transform, triangleConstantBuffer);
	}

	void LoadShader()
	{
		cc::graphics::GetDevice()->CreateShader();
	}

	void Initialize()
	{
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


		SetupState();
		LoadBuffer();
		LoadShader();
	}
}




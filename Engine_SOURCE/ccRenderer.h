#pragma once
#include "CCEngine.h"
#include "ccGraphicDevice_Dx11.h"

using namespace cc::math;
namespace renderer
{
	struct Vertex
	{
		Vector3 pos;
		Vector4 color;
	};

	extern ID3DBlob* errorBlob;

	// 삼각형
	extern Vertex triangleVertexes[];
	extern ID3D11InputLayout* triangleLayout;
	extern ID3D11Buffer* triangleBuffer;
	extern ID3DBlob* triangleVSBlob;
	extern ID3D11VertexShader* triangleVSShader;
	extern ID3DBlob* trianglePSBlob;
	extern ID3D11PixelShader* trianglePSShader;
	extern ID3D11Buffer* triangleIdxBuffer;
	extern ID3D11Buffer* triangleConstantBuffer;

	// 사각형
	extern Vertex rectangleVertexes[];
	extern ID3D11InputLayout* rectangleLayout;
	extern ID3D11Buffer* rectangleBuffer;
	extern ID3DBlob* rectangleVSBlob;
	extern ID3D11VertexShader* rectangleVSShader;
	extern ID3DBlob* rectanglePSBlob;
	extern ID3D11PixelShader* rectanglePSShader;

	// 육각형
	extern Vertex hexagonVertexes[];
	extern ID3D11InputLayout* hexagonLayout;
	extern ID3D11Buffer* hexagonBuffer;
	extern ID3DBlob* hexagonVSBlob;
	extern ID3D11VertexShader* hexagonVSShader;
	extern ID3DBlob* hexagonPSBlob;
	extern ID3D11PixelShader* hexagonPSShader;

	// 별
	extern Vertex starVertexes[];
	extern ID3D11InputLayout* starLayout;
	extern ID3D11Buffer* starBuffer;
	extern ID3DBlob* starVSBlob;
	extern ID3D11VertexShader* starVSShader;
	extern ID3DBlob* starPSBlob;
	extern ID3D11PixelShader* starPSShader;

	// 원
	extern Vertex circleVertexes[];
	extern ID3D11InputLayout* circleLayout;
	extern ID3D11Buffer* circleBuffer;
	extern ID3DBlob* circleVSBlob;
	extern ID3D11VertexShader* circleVSShader;
	extern ID3DBlob* circlePSBlob;
	extern ID3D11PixelShader* circlePSShader;

	void Initialize();
	void Update();
	void Release();
}

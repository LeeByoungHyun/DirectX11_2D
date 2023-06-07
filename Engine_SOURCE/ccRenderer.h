#pragma once
#include "CCEngine.h"
#include "ccGraphicDevice_Dx11.h"
#include "ccMesh.h"
#include "ccShader.h"

using namespace cc::math;
namespace renderer
{
	struct Vertex
	{
		Vector3 pos;
		Vector4 color;
	};

	extern ID3DBlob* errorBlob;

	// »ï°¢Çü
	extern Vertex Vertexes[];
	extern ID3D11InputLayout* triangleLayout;
	extern cc::Mesh* mesh;
	extern ID3D11Buffer* triangleConstantBuffer;
	extern cc::Shader* shader;
	//extern ID3D11PixelShader* trianglePSShader;

	void Initialize();
	void Update();
	void Release();
}

#include "guiEditor.h"
#include "ccMesh.h"
#include "ccResourceManager.h"
#include "ccTransform.h"
#include "ccMeshRenderer.h"
#include "ccMaterial.h"
#include "ccRenderer.h"
#include "../CCEngine/ccGridScript.h"

namespace gui
{
	using namespace cc::enums;
	std::vector<Widget*> Editor::mWidgets = {};
	std::vector<EditorObject*> Editor::mEditorObjects = {};
	std::vector<DebugObject*> Editor::mDebugObjects = {};

	void Editor::Initialize()
	{
		mDebugObjects.resize((UINT)eColliderType::End);

		std::shared_ptr<cc::Mesh> mesh
			= cc::ResourceManager::Find<cc::Mesh>(L"DebugRect");
		std::shared_ptr<cc::Material> material
			= cc::ResourceManager::Find<cc::Material>(L"DebugMaterial");

		mDebugObjects[(UINT)eColliderType::Rect] = new DebugObject();
		mDebugObjects[(UINT)eColliderType::Rect]->AddComponent<cc::Transform>();
		cc::MeshRenderer* mr
			= mDebugObjects[(UINT)eColliderType::Rect]->AddComponent<cc::MeshRenderer>();
		mr->SetMaterial(material);
		mr->SetMesh(mesh);

		// grid
		EditorObject* grid = new EditorObject();
		grid->SetName(L"Grid");

		mr = grid->AddComponent<cc::MeshRenderer>();
		mr->SetMesh(cc::ResourceManager::Find<cc::Mesh>(L"RectMesh"));
		mr->SetMaterial(cc::ResourceManager::Find<cc::Material>(L"GridMaterial"));
		cc::GridScript* gridSc = grid->AddComponent<cc::GridScript>();
		gridSc->SetCamera(renderer::cameras[0]);

		mEditorObjects.push_back(grid);
	}

	void Editor::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Editor::Update()
	{
		for (EditorObject* obj : mEditorObjects)
		{
			obj->Update();
		}
	}

	void Editor::LateUpdate()
	{
		for (EditorObject* obj : mEditorObjects)
		{
			obj->LateUpdate();
		}
	}

	void Editor::Render()
	{
		for (EditorObject* obj : mEditorObjects)
		{
			obj->Render();
		}

		for (const cc::graphics::DebugMesh& mesh
			: renderer::debugMeshs)
		{
			DebugRender(mesh);
		}
	}

	void Editor::Release()
	{

	}

	void Editor::DebugRender(const cc::graphics::DebugMesh& mesh)
	{
		DebugObject* debugObj = mDebugObjects[(UINT)mesh.type];

		// 위치 크기 회전 정보를 받아와서
		// 해당 게임오브젝트위에 그려주면된다.
		debugObj->Render();
	}
}
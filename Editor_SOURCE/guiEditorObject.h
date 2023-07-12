#pragma once
#include "ccGameObject.h"

namespace gui
{
	class EditorObject : public cc::GameObject
	{
	public:
		EditorObject();
		virtual ~EditorObject();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;
	};
}
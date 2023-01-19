//
// Created by abdoulayedia on 18.01.2023
//
#include "Application.h"

namespace dp {
	int Application::Run() {
		Application* instance = Application::GetInstance();
		if (instance == nullptr) return -1;

		while (instance->IsRunning()) {
			instance->HandleInputs();
			instance->Update();
			instance->Render();
		}

		return 0;
	}
	void Application::HandleInputs() {}
	void Application::Update() {
		_editor.OnUpdate();
	}
	void Application::Render() {
		_editor.OnRender();
	}
} // namespace dp
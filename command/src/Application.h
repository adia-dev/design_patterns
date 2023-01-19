//
// Created by abdoulayedia on 18.01.2023
//
#pragma once

#include "Editor.h"
#include "Shortcut.h"

namespace dp {
	// Application
	class Application {
	  public:
		static Application* GetInstance() {
			if (_instance == nullptr) {
				_instance = std::make_shared<Application>();
			}

			return _instance.get();
		}

		static int Run();
		bool       IsRunning() const { return _isRunning; }

		Application()  = default;
		~Application() = default;

	  private:
		Application(Application const&)            = delete;
		Application& operator=(const Application&) = delete;

		void HandleInputs();
		void Update();
		void Render();

		Editor                _editor;
		std::vector<Shortcut> _shortcuts;
		bool                  _isRunning = true;

		inline static std::shared_ptr<Application> _instance = nullptr;
	};
} // namespace dp

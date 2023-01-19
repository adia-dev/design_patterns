//
// Created by abdoulayedia on 18.01.2023
//
#pragma once

#include "Button.h"

namespace dp {

	// Invoker
	class Editor {
	  public:
		Editor();
		Editor(const std::string& content);
		~Editor() = default;

		void OnRender();
		void OnUpdate();

	  private:
		std::string         _content;
		std::vector<Button> _buttons;

		void InitButtons();
	};
} // namespace dp

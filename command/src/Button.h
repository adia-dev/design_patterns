//
// Created by abdoulayedia on 18.01.2023
//
#pragma once

#include "Invoker.h"

namespace dp {

	enum class ButtonState { None = -1, Idle, Hover, Pressed, Active, Disabled, Processing };

	// Invoker
	class Button: public Invoker {
	  public:
		Button() = default;
		Button(const std::string& label, const ButtonState& state = ButtonState::Idle): _label(label), _state(state) {}
		~Button() = default;

		void OnRender(bool sameLine = false) {
			std::cout << _label;
			if (sameLine)
				std::cout << " - ";
			else
				std::cout << std::endl;
		}
		void OnClick() {
			_state = ButtonState::Pressed;
			Invoke();
		}

	  private:
		std::string _label = "Button";
		ButtonState _state = ButtonState::Idle;
	};
} // namespace dp

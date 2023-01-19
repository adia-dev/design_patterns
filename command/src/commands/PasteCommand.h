//
// Created by abdoulayedia on 18.01.2023
//
#pragma once

#include "../Command.h"

namespace dp {
	// PasteCommand
	class PasteCommand: public Command {
	  public:
		PasteCommand()  = default;
		~PasteCommand() = default;

		void Execute() override { std::cout << "Paste" << std::endl; }

	  private:
	};
} // namespace dp

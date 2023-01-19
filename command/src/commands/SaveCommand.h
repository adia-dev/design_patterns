//
// Created by abdoulayedia on 18.01.2023
//
#pragma once

#include "../Command.h"

namespace dp {
	// SaveCommand
	class SaveCommand: public Command {
	  public:
		SaveCommand()  = default;
		~SaveCommand() = default;

		void Execute() override { std::cout << "Save" << std::endl; }

	  private:
	};
} // namespace dp

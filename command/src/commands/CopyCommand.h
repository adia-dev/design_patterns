//
// Created by abdoulayedia on 18.01.2023
//
#pragma once

#include "../Command.h"

namespace dp {
	// CopyCommand
	class CopyCommand: public Command {
	  public:
		CopyCommand()  = default;
		~CopyCommand() = default;

		void Execute() override { std::cout << "Copy" << std::endl; }

	  private:
	};
} // namespace dp

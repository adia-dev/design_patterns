//
// Created by abdoulayedia on 18.01.2023
//
#pragma once

#include "Command.h"

namespace dp {
	// CommandHistory
	class CommandHistory {
	  public:
		CommandHistory()  = default;
		~CommandHistory() = default;

		void     Push(Command* command) { _commands.push(command); }
		void     Pop() { _commands.pop(); }
		Command* Top() { return _commands.top(); }

	  private:
		std::stack<Command*> _commands;
	};
} // namespace dp

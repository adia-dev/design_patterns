//
// Created by abdoulayedia on 18.01.2023
//
#pragma once

#include "CommandHistory.h"

namespace dp {
	// Invoker
	class Invoker {
	  public:
		Invoker()          = default;
		virtual ~Invoker() = default;

		virtual void Invoke() {
			for (auto command : _commands) {
				if (command == nullptr) continue;
				command->Execute();
				_history.Push(command);
			}
		}
		virtual void AddCommand(Command* command) { _commands.push_back(command); }
		virtual void RemoveCommand(Command* command) { std::remove(_commands.begin(), _commands.end(), command); }
		virtual void SetCommands(const std::vector<Command*>& commands) {
			_commands.clear();
			_commands = commands;
		}

		CommandHistory GetHistory() const { return _history; }

	  protected:
		std::vector<Command*> _commands;
		CommandHistory        _history;
	};
} // namespace dp

//
// Created by abdoulayedia on 18.01.2023
//
#pragma once

#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>
#include <stack>
#include <string>
#include <vector>

namespace dp {
	// Command
	class Command {
	  public:
		virtual ~Command() = default;
		Command()          = default;

		virtual void Execute() = 0;

		bool operator==(const Command& command) { return _name == command._name; }

	  protected:
		std::string _name;
	};
} // namespace dp

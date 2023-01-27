#pragma once
#include "Command.h"

class CmdSetFillMode : public Command {
public:
	const char* GetName() {
		return "SetFillMode";
	}
	const char* GetDescription() {
		return "Set the triangle fill mode";
	}
	bool Execute(const std::vector<std::string>& params) = 0;
};


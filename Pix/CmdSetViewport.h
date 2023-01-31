#pragma once

#include "Command.h"

class CmdSetViewport : public Command
{
public:
	const char* GetName() override
	{
		return "SetViweport";
	}

	const char* GetDescription() override
	{
		return
			"SetViweport(x, y, width, height)\n"
			"\n"
			"- sets the visible viewport to clip geometry.";
	}

	bool Execute(const std::vector<std::string>& params) override;
};
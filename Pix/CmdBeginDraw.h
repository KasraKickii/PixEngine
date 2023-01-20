#pragma once
#include "Command.h"

class  CmdBeginDraw : public Command {
	
	const char* GetName() {
		return "BeginDraw";
	}
	const char* GetDescription() {
		return "BeginDraw(topology) begin drawing a parimitive";
	}
	 bool Execute(const std::vector<std::string>&params) = 0;
};


#include "CmdSetCullMode.h"
#include "PrimitivesManager.h"

bool CmdSetCullMode::Execute(const std::vector<std::string>& params)
{
	if ( params.size() < 0)
		return false;

	if (params[0] == "none" || params[0] == "None")
		PrimitivesManager::Get()->SetCullMode(CullMode::None);
	else if (params[0] == "back" || params[0] == "Back")
		PrimitivesManager::Get()->SetCullMode(CullMode::Back);
	else if (params[0] == "front" || params[0] == "Front")
		PrimitivesManager::Get()->SetCullMode(CullMode::Front);


	return true;
}

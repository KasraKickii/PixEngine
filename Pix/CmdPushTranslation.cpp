#include "CmdPushTranslation.h"
#include "MatrixStack.h"
#include "VariableCache.h"

bool CmdPushTranslation::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 3)
		return false;
	
	float x = VariableCache::Get()->GetFloat(params[0]);
	float y = VariableCache::Get()->GetFloat(params[1]);
	float z = VariableCache::Get()->GetFloat(params[2]);

	MatrixStack::Get()->PushTranslation({ x, y, z });
	return true;
}
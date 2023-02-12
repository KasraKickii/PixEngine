#include "CmdSetResolution.h"

#include <XEngine.h>

float gResolutionX = 0.0f;
float gResolutionY = 0.0f;

bool CmdSetResolution::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 2)
		return false;

	const int width = stoi(params[0]);
	const int height = stoi(params[1]);
	const int pixelSize = params.size() > 2 ? stoi(params[2]) : 1;
	const bool showGrid = params.size() > 3 && params[3] == "true";
	gResolutionX = (float)width;
	gResolutionY = (float)height;

	X::InitRenderTexture(width, height, pixelSize);

	if (showGrid && pixelSize > 1)
		X::DrawScreenGrid(pixelSize, X::Colors::DarkGray);

	return true;
}

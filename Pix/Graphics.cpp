#include "Graphics.h"
#include "DepthBuffer.h"
#include "Viewport.h"
#include "Clipper.h"
#include "MatrixStack.h"
#include "Camera.h"
#include "PrimitivesManager.h"

void Graphics::NewFrame()
{
	DepthBuffer::Get()->OnNewFrame();
	Viewport::Get()->OnNewFrame();
	Clipper::Get()->OnNewFrame();
	MatrixStack::Get()->OnNewFrame();
	Camera::Get()->OnNewFrame();
	PrimitivesManager::Get()->OnNewFrame();
}
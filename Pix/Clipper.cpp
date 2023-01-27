#include "Clipper.h"
#include "Viewport.h"
const short BIT_INSIDE = 0;
const short BIT_LEFT = 1<<1;
const short BIT_RIGHT = 1<< 2;
const short BIT_BOTTOM = 1<<3;
const short BIT_TOP = 1 << 4;

enum  class ClipEdge : short
{
	Left,
	Bottom,
	Right,
	Top,
	Count
};

Clipper* Clipper::Get()
{
	static Clipper sInstance;
	return &sInstance;
}

void Clipper::OnNewFrame() {

}
short GetOutputCode(float x, float y) {
	short code = BIT_INSIDE;

	if (x < Viewport::Get()->GetMinX()) {
		code |= BIT_LEFT;
	}
	else if (x > Viewport::Get()->GetMaxX()) {
		code |= BIT_RIGHT;
	}
	else if (y < Viewport::Get()->GetMinY()) {
		code |= BIT_TOP;
	}
	else if (y > Viewport::Get()->GetMaxY()) {
		code |= BIT_BOTTOM;
	}
	return code;
}
bool Clipper::ClipPoint(const Vertex& v) {
	if (!mClipping) {
		return false;
	}
	float maxX = Viewport::Get()->GetMaxX();
	float maxY = Viewport::Get()->GetMaxY();
	float minX = Viewport::Get()->GetMinX();
	float minY = Viewport::Get()->GetMinY();
	return v.pos.x < minX || v.pos.x> maxX
		|| v.pos.y < minY || v.pos.y> maxY;
}
bool Clipper::ClipLine(Vertex& v0, Vertex& v1) {
	if (!mClipping) {
		return false;
	}
	float maxX = Viewport::Get()->GetMaxX();
	float maxY = Viewport::Get()->GetMaxY();
	float minX = Viewport::Get()->GetMinX();
	float minY = Viewport::Get()->GetMinY();
	short codeV0 = GetOutputCode(v0.pos.x, v0.pos.y);
	short codeV1 = GetOutputCode(v1.pos.x, v1.pos.y);
	bool cullLine = false;

	while (true)
	{
		if (!(codeV0 | codeV1)) {
			cullLine = true;
			break;
		}
	else if (codeV0 & codeV1) {
		
			break;
		}
	else
		{
			float t = 0.0f;
			short outcodeOut = codeV1 > codeV0 ? codeV1 : codeV0;
			if (outcodeOut & BIT_TOP) {
				t = (minY - v0.pos.y) / (v1.pos.y - v0.pos.y);

			}
			else if (outcodeOut & BIT_BOTTOM) {
				t = (maxY - v0.pos.y) / (v1.pos.y - v0.pos.y);

			}
			else if (outcodeOut & BIT_LEFT) {
				t = (minY - v0.pos.y) / (v1.pos.y - v0.pos.y);

			}
			else if (outcodeOut & BIT_RIGHT) {
				t = (maxY - v0.pos.y) / (v1.pos.y - v0.pos.y);

			}
			if (outcodeOut == codeV0) {
				v0 = LerpVertex(v0, v1, t);
				codeV0 = GetOutputCode(v0.pos.x , v0.pos.y);
			}
			else {
				v1 = LerpVertex(v0, v1, t);
				codeV1 = GetOutputCode(v1.pos.x, v1.pos.y);
			}
		}
	}
	return cullLine;
}

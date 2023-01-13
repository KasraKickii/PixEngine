#pragma once

struct Vector2 {
	float x, y, z;
	Vector2() { x = 0.0f; y = 0.0f; z = 0.0f; }
	Vector2(float s) { x = s; y = s; z = s; }
};
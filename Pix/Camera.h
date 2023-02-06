#pragma once
#include "Matrix4.h"

class Camera
{
public:

	void OnNewFrame();
	static Camera* Get();
	void SetPosition(const Vector3& pos);
	void SetDirection(const Vector3& dir);
	void SetNearPlane(float nPlane);
	void SetFarPlane(float fPlane);
	void SetFOV(float fov);

	Matrix4 GetViewMatrix() const;
	Matrix4 GetProjectionMatrix() const;

	const Vector3& GetPosition() const { return mPosition; }
	const Vector3& GetDirection() const { return mDirection; }
private:
	Vector3 mPosition = { 0.f, 0.f, 0.f };
	Vector3 mDirection = { 0.f, 0.f, 1.f };
	float mNearPlane = 0.01f;
	float mFarPlane = 100.f;
	float mFOV = 1.57f;
};

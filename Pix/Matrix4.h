#pragma once
#include "Vector3.h"
struct Matrix4 {
	float 
		_11, _12, _13, _14,
		_21, _22, _23, _24,
		_31, _32, _33, _34,
		_41, _42, _43, _44;
	
	Matrix4()
		: _11(1.0f), _12(0.0f), _13(0.0f), _14(0.f),
		_21(0.0f), _22(1.0f), _23(0.0f), _24(0.0f),
		_31(0.0f), _32(0.0f), _33(1.0f), _34(0.0f),
		_41(0.0f), _42(0.0f), _43(0.0f), _44(1.f)
	{

	}
	Matrix4(float a11, float a12, float a13, float a14,
		float a21, float a22, float a23, float a24,
		float a31, float a32, float a33, float a34,
		float a35, float a36, float a37, float a38);
	Matrix4 operator+ (const Matrix4& rhs) const {
		return Matrix4(
			_11 + rhs._11, _12 + rhs._12, _13 + rhs._13, _14 + rhs._34,
			_21 + rhs._21, _22 + rhs._22, _23 + rhs._23, _24 + rhs._24,
			_31 + rhs._31, _32 + rhs._32, _33 + rhs._33, _34 + rhs._34,
			_41 + rhs._41, _42 + rhs._42, _43 + rhs._43, _44 + rhs._44
		);
	}
	Matrix4 operator* (float s) const {
	 
		return Matrix4 (
				_11 * s, _12 * s, _13 * s, _14 * s,
		     	_21 * s, _22 * s, _23 * s, _24 * s,
			    _31 * s, _32 * s, _33 * s, _34 * s,
		     	_41 * s, _42 * s, _43 * s, _44 * s
		);
	
	};
	Matrix4 operator* (const Matrix4& rhs) const
	{
		return Matrix4
		(   (_11 * rhs._11) + (_12 * rhs._21) + (_13 * rhs._31) + (_14 * rhs._41),
			(_11 * rhs._12) + (_12 * rhs._22) + (_13 * rhs._32) + (_14 * rhs._42),
			(_11 * rhs._13) + (_12 * rhs._23) + (_13 * rhs._33) + (_14 * rhs._43),
			(_11 * rhs._14) + (_12 * rhs._24) + (_13 * rhs._34) + (_14 * rhs._44),

			(_21 * rhs._11) + (_22 * rhs._21) + (_33 * rhs._31) + (_24 * rhs._41),
			(_21 * rhs._12) + (_22 * rhs._22) + (_33 * rhs._32) + (_24 * rhs._42),
			(_21 * rhs._13) + (_22 * rhs._23) + (_33 * rhs._33) + (_24 * rhs._43),
			(_21 * rhs._14) + (_22 * rhs._24) + (_33 * rhs._34) + (_24 * rhs._44),

			(_31 * rhs._11) + (_32 * rhs._21) + (_33 * rhs._31) + (_34 * rhs._41),
			(_31 * rhs._12) + (_32 * rhs._22) + (_33 * rhs._32) + (_34 * rhs._42),
			(_31 * rhs._13) + (_32 * rhs._23) + (_33 * rhs._33) + (_34 * rhs._43),
			(_31 * rhs._14) + (_32 * rhs._24) + (_33 * rhs._34) + (_34 * rhs._44),

			(_41 * rhs._11) + (_42 * rhs._21) + (_43 * rhs._31) + (_44 * rhs._41),
			(_41 * rhs._12) + (_42 * rhs._22) + (_43 * rhs._32) + (_44 * rhs._42),
			(_41 * rhs._13) + (_42 * rhs._23) + (_43 * rhs._33) + (_44 * rhs._43),
			(_41 * rhs._14) + (_42 * rhs._24) + (_43 * rhs._34) + (_44 * rhs._44)
            );
	}

	static Matrix4 Identity() {
	
		return Matrix4(
			1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f
		);
	};
	static Matrix4 RotationX(float rad)
	{
		return Matrix4(

					1.f,		0.f,		0.f,		0.f,
					0.f,		cosf(rad),	sinf(rad),	0.f,
					0.f,		-sinf(rad),	cosf(rad),	0.f,
					0.f,		0.f,		0.f,		1.f
		);
	}
	static Matrix4 RotationY(float rad)
	{
		return Matrix4(
			cosf(rad),	0.f,		-sinf(rad),	0.f,
			0.f,		1.f,		0.f,		0.f,
			sinf(rad),	0.f,		cosf(rad),	0.f,
			0.f,		0.f,		0.f,		1.f
		);
	}
	static Matrix4 RotationZ(float rad)
	{
		return Matrix4(
			cosf(rad),	sinf(rad),	0.f,		0.f,
			-sinf(rad),	cosf(rad),	0.f,		0.f,
			0.f,		0.f,		1.f,		0.f,
			0.f,		0.f,		0.f,		1.f
		);
	}
	static Matrix4 Scale(float s)
	{
		return{
			s,		0.f,	0.f,	0.f,
			0.f,	s,		0.f,	0.f,
			0.f,	0.f,	s,		0.f,
			0.f,	0.f,	0.f,	s
		};
	}
	static Matrix4 Scale(const Vector3& s)
	{
		return Matrix4(
			s.x,	0.f,	0.f,	0.f,
			0.f,	s.y,	0.f,	0.f,
			0.f,	0.f,	s.z,	0.f,
			0.f,	0.f,	0.f,	1.0f
		);
	}
	static Matrix4 Translate(const Vector3& d)
	{
		return Matrix4(
			1.0f,	0.f,	0.f,	0.f,
			0.f,	1.f,	0.f,	0.f,
			0.f,	0.f,	1.f,	0.f,
			d.x,	d.y,	d.z,	1.0f
		);
	}
	static Matrix4 Translate(float dx, float dy, float dz)
	{
		return Matrix4(
			1.0f,	0.f,	0.f,	0.f,
			0.f,	1.f,	0.f,	0.f,
			0.f,	0.f,	1.f,	0.f,
			dx,		dy,		dz,		1.0f
		);
	}

};
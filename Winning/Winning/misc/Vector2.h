#ifndef _VECTOR2_H
#define _VECTOR2_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Vector2
{
public:
	float X, Y, Z;

	float GetLength()
	{
		return sqrtf((X*X) + (Y*Y));
	}
	static float Length(Vector2 v)
	{
		return sqrtf((v.X*v.X) + (v.Y*v.Y));
	}


	float GetLengthSquared()
	{
		return (pow(X, 2) + pow(Y, 2));
	}
	void Normalize ()
	{
		if (GetLength() != 0)
		{
			X /= GetLength();
			Y /= GetLength();
		}
	}
	static float DotProduct (Vector2 vPos, Vector2 vPos2)
	{
		return (vPos.X * vPos2.X) + (vPos.Y * vPos2.Y);
	}	

	static float CrossProduct(const Vector2 &v1, const Vector2 &v2)
	{
		return (v1.X*v2.Y) - (v1.Y*v2.X);
	}

	float GetAngle()
	{
		return atan2(Y,X);
	}
	static float GetAngleBetween (Vector2 vPos, Vector2 vPos2)
	{
		return vPos.GetAngle() - vPos2.GetAngle();
	}
	void RotateClockWise()
	{
		float temp = Y;
		Y = -X;
		X = temp;
	}
	void RotateVector2DClockwise(float ang)
	{
	 float t,
		   cosa = cos(ang),
		   sina = sin(ang);
	 t = X; X = t*cosa + Y*sina; Y = -t*sina + Y*cosa;
	}
	void RotateAntiClockWise()
	{
		float temp = X;
		X = Y;
		Y = -temp;
	}

	void operator+=(Vector2 vPos)
	{
		X += vPos.X;
		Y += vPos.Y;
	}
	void operator*=(Vector2 vPos)
	{
		X *= vPos.X;
		Y *= vPos.Y;
	}
	void operator*=(float f)
	{
		X *= f;
		Y *= f;
	}
	void operator-=(Vector2 vPos)
	{
		X -= vPos.X;
		Y -= vPos.Y;
	}
	Vector2 operator+(Vector2 vPos)
	{
		Vector2 newVec;
		newVec.X = X + vPos.X;
		newVec.Y = Y + vPos.Y;
		return newVec;
	}
	Vector2 operator-(Vector2 vPos)
	{
		Vector2 newVec;
		newVec.X = X - vPos.X;
		newVec.Y = Y - vPos.Y;
		return newVec;

	}
	Vector2 operator*(Vector2 vPos)
	{
		Vector2 newVec;
		newVec.X = X * vPos.X;
		newVec.Y = Y * vPos.Y;
		return newVec;
	}
	Vector2 operator*(float f)
	{
		Vector2 newVec;
		newVec.X = X * f;
		newVec.Y = Y * f;
		return newVec;
	}

	Vector2 operator/(float f)
	{
		Vector2 newVec;
		newVec.X = X / f;
		newVec.Y = Y / f;
		return newVec;
	}
	
	Vector2 operator+(float f)
	{
		Vector2 newVec;
		newVec.X = X + f;
		newVec.Y = Y + f;
		return newVec;
	}

};

class Matrix
{

	float fData[9];
public:
	Matrix(float d[9])
	{
		memcpy(fData, d, sizeof(fData));
	}

	~Matrix(void);

	static Matrix CreateIdentity()
	{
		float d[9] = {1, 0, 0,
					  0, 1, 0,
					  0, 0, 1};
		return Matrix(d);
	}

	static Matrix CreatefRotation(float Rad)
	{
		float s = sinf(Rad);
		float c = cosf(Rad);

		float d[9] = {c, s, 0,
					 -s, c, 0, 
					  0, 0, 1};

		return Matrix(d);
	}
	static Matrix CreateTranslations(Vector2 vPos)
	{
		float X = vPos.X;
		float Y = vPos.Y;
		float d[9] = {X, 0, 0, 
					  0, Y, 0, 
					  0, 0, 1};

		return Matrix(d);
	}

	static Vector2 GetTranslations(Matrix &m)
	{
		Vector2 newvec;
		newvec.X = m.fData[0];
		newvec.Y = m.fData[4];
		return newvec;
	}

	static float GetfRotation(Matrix &m)
	{
		//float Rad;

		//return Rad;
	}

	void SetTranslations(float X, float Y)
	{
		fData[0] = X;
		fData[4] = Y;
	}

	void SetfRotation(float Rad)
	{
		float s = sinf(Rad);
		float c = cosf(Rad);

		fData[0] = c;
		fData[1] = s;
		fData[3] = -s;
		fData[4] = c;
	}
	Matrix operator*(Matrix other)
	{
		float d[9] = {};

		d[0] = fData[0] * other.fData[0] + fData[1] * other.fData[3] + fData[2] * other.fData[6];
		d[1] = fData[0] * other.fData[1] + fData[1] * other.fData[4] + fData[2] * other.fData[7];
		d[2] = fData[0] * other.fData[2] + fData[1] * other.fData[5] + fData[2] * other.fData[8];

		d[3] = fData[3] * other.fData[0] + fData[4] * other.fData[3] + fData[5] * other.fData[6];
		d[4] = fData[3] * other.fData[1] + fData[4] * other.fData[4] + fData[5] * other.fData[7];
		d[5] = fData[3] * other.fData[2] + fData[4] * other.fData[5] + fData[5] * other.fData[8];

		d[6] = fData[6] * other.fData[0] + fData[7] * other.fData[3] + fData[8] * other.fData[6];
		d[7] = fData[6] * other.fData[1] + fData[7] * other.fData[4] + fData[8] * other.fData[7];
		d[8] = fData[6] * other.fData[2] + fData[7] * other.fData[5] + fData[8] * other.fData[8];

		return d;
	}

};

#endif




#pragma once
#include <d3dx9.h>
typedef D3DXQUATERNION Quaternion;

#define PI 3.1416f

#define degToRad(deg) ((deg) * (PI / 180))
#define radToDeg(rad) ((rad) / (PI / 180))

// QuautanionÇ∆Vector3ÇÃä|ÇØéZ
static D3DXVECTOR3 operator*(const Quaternion & qua, const D3DXVECTOR3 & vec)
{
	Quaternion r(vec.x, vec.y, vec.z, 0);
	Quaternion qInv;
	D3DXQuaternionInverse(&qInv, &qua);
	Quaternion qA = (qua*r);
	Quaternion rPrime(qA*qInv);
	return D3DXVECTOR3(rPrime.x, rPrime.y, rPrime.z);
}

// âÒì]çsóÒ
static Quaternion QuaternionFromEuler(float x, float y, float z)
{
	Quaternion qua;
	D3DXQuaternionRotationYawPitchRoll(&qua, degToRad(y), degToRad(x), degToRad(z));
	return qua;
}

// âÒì]çsóÒ
static Quaternion QuaternionFromEuler(const D3DXVECTOR3& v)
{
	return QuaternionFromEuler(v.x, v.y, v.z);
}

// ÉIÉCÉâÅ[ÇÃï˚íˆéÆ
static D3DXVECTOR3 QuaternionToEuler(const Quaternion& qua)
{
	float q0q0 = qua.x * qua.x;
	float q0q1 = qua.x * qua.y;
	float q0q2 = qua.x * qua.z;
	float q0q3 = qua.x * qua.w;
	float q1q1 = qua.y * qua.y;
	float q1q2 = qua.y * qua.z;
	float q1q3 = qua.y * qua.w;
	float q2q2 = qua.z * qua.z;
	float q2q3 = qua.z * qua.w;
	float q3q3 = qua.w * qua.w;
	float roll = atan2f(2.0 * (q2q3 + q0q1), q0q0 - q1q1 - q2q2 + q3q3);
	float pitch = asinf(2.0 * (q0q2 - q1q3));
	float yaw = atan2f(2.0 * (q1q2 + q0q3), q0q0 + q1q1 - q2q2 - q3q3);
	return { pitch, yaw, roll };
}
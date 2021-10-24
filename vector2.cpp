#include "vector2.h"

D3DXVECTOR2 operator*(const D3DXVECTOR2 & v1, const D3DXVECTOR2 & v2)
{
	return { v1.x * v2.x, v1.y * v2.y };
}

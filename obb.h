#pragma once

enum Direction{
	eRight,
	eUp,
	eForward,
	eMax
};

enum class ResourceTag;

class OBB 
{
public:
	OBB(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 adj, D3DXVECTOR3 rot);
	~OBB();
	D3DXVECTOR3 GetDirection(int elem) const;
	float GetLength(int elem) const;
	D3DXVECTOR3 GetPosition() const;

	void SetObb(D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 adj, D3DXVECTOR3 rot);
	class Box* GetBox() const { return m_DebugBox; }

public:
	D3DXVECTOR3 m_Position;		// 中心点
	D3DXVECTOR3 m_Direction[3];	// 方向ベクトル
	float m_Length[3];			// 長さ
	Box* m_DebugBox;
	ResourceTag m_TextureTag;
};
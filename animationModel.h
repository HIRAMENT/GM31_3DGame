#pragma once

#include <unordered_map>
#include "resource.h"
#include "assimp/cimport.h"
#include "assimp/scene.h"
#include "assimp/postprocess.h"
#include "assimp/matrix4x4.h"
#pragma comment (lib, "assimp-vc140-mt.lib")

// �ό`�㒸�_�\����
struct DEFORM_VERTEX
{
	aiVector3D Position;
	aiVector3D Normal;

	int			BoneNum;
	std::string BoneName[4]; // �{���̓{�[���C���f�b�N�X�ŊǗ�����ׂ�
	float		BoneWeight[4]; // �ǂ��ɂ������Ă��邩�̊���
};

// �{�[���\����
struct BONE
{
	aiMatrix4x4 Matrix;
	aiMatrix4x4 AnimationMatrix;
	aiMatrix4x4 OffsetMatrix;
};

class AnimationModel 
{
private:
	const aiScene* m_AiScene = nullptr;
	//std::unordered_map<std::string, const aiScene*> m_Animation;

	ID3D11Buffer** m_VertexBuffer;
	ID3D11Buffer** m_IndexBuffer;

	std::unordered_map<std::string, ID3D11ShaderResourceView*> m_Texture;

	std::vector<DEFORM_VERTEX>* m_DeformVertex;
	std::unordered_map<std::string, BONE> m_Bone;

	D3DXVECTOR3 m_Size;

	void CreateBone(aiNode* node);
	void UpdateBoneMatrix(aiNode* node, aiMatrix4x4 matrix);

public:
	AnimationModel(const char *FileName);

	void Load(const char *FileName);
	//void LoadAnimation(const char *FileName, const char *Name);
	void Unloard();
	//void Update(const char *AnimationName1, const char *AnimationName2, int frame, float BlendRate);
	void Update(AnimationTag animationTag1, AnimationTag animationTag2, int frame, float BlendRate);
	void Draw();

	D3DXVECTOR3 GetSize() const { return m_Size; }
	
};

class Animation
{
private:
	const aiScene* m_Animation;
public:
	Animation(const char* FileName);

	const aiScene* GetAnimation() { return m_Animation; }
	int GetAnimationCount() const { return m_Animation->mAnimations[0]->mChannels[0]->mNumPositionKeys; }

private:
	void Load(const char * FileName);
};
#include "common.hlsl"

void main(in VS_IN In, out PS_IN Out)
{
	// �P���_���̃f�[�^���󂯎��A�������āA�o�͂���

	// ���_�ϊ������@���̏����͕K���K�v
	matrix wvp;									// �s��ϐ����쐬
	wvp = mul(World, View);						// wvp = ���[���h�s�� * �J�����s��
	wvp = mul(wvp, Projection);					// wvp = wvp * �v���W�F�N�V�����s��
	Out.Position = mul(In.Position, wvp);		// �ϊ����ʂ��o�͂���

	// ��������
	float4 worldNormal, normal;				// ���̒l���O�ɂ��ăR�s�[ (���s�ړ��͂��Ȃ�����)
	normal = float4(In.Normal.xyz, 0.0f);	// �@�������[���h�s��f��]����
	worldNormal = mul(normal, World);		// ��]��̖@���𐳋K��
	worldNormal = normalize(worldNormal);	// ��]��̖@���o�� (In.Normal�ł͂Ȃ���]��̖@�����o��)
	Out.Normal = worldNormal;

	// �󂯎�������̒��_�̃f�B�t���[�Y���o��
	Out.Diffuse = In.Diffuse;

	// ���_�Ƀe�N�X�`�����W���o��
	Out.TexCoord = In.TexCoord;

	// ���[���h�ϊ��������_���W���o��
	Out.WorldPosition = mul(In.Position, World);
}
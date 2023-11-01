//����������������������������������������������//
// �ڍ�   �F�J���[�ƃe�N�X�`����K�v�Ƃ���UI�̃e�N�X�`���p���_�V�F�[�_�[
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �\���� �� //

// ���_�V�F�[�_�[�ɓ����Ă�����
struct S_VS_IN
{
    float2 position : CLIQUES0; // �ʒu���W
    float4 color : CLIQUES1; // �F
    float2 uv : CLIQUES2; // �e�N�X�`��
};

// ���_�V�F�[�_�[����o�͂�����
struct S_VS_OUT
{
    float4 position : SV_POSITION;  // �ʒu���W
    float4 color : COLOR0;          // �F
    float2 uv : TEXCOORD0;          // UV���W
};


// �� ���C���֐� �� //
S_VS_OUT vs_main(S_VS_IN in_vs)
{
	// �� �ϐ��錾 �� //
    S_VS_OUT out_vs; // ���_�V�F�[�_�[����n�����
    
    
	// �n���ꂽ���̃Z�b�g
    out_vs.position = float4(in_vs.position, 0.0f, 1.0f);
    out_vs.color = in_vs.color;
    out_vs.uv = in_vs.uv;
    

    // �o�͌��ʂ𑗂�
    return out_vs;
}


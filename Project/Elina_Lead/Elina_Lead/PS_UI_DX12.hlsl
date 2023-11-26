//����������������������������������������������//
// �ڍ�   �F�J���[�ƃe�N�X�`����K�v�Ƃ���UI�̃e�N�X�`���p�s�N�Z���V�F�[�_�[
// ����   �Fuv���W��-10�Ȃ�J���[�����蓖�Ă�
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �\���� �� //

// �s�N�Z���V�F�[�_�[�ɓ����Ă�����
struct S_PS_IN
{
    float4 position : SV_POSITION;  // �ʒu���W
    float4 color : COLOR0;          // �F
    float2 uv : TEXCOORD0;     // UV���W
};


// �� �e�N�X�`�� �� //

// �e�N�X�`���n���h��
Texture2D<float4> tex_color : register(t0);


// �� �ÓI�T���v���[ �� //

// �T���v���[�n���h��
SamplerState samp0 : register(s0);


// �� ���C���֐� �� //
float4 ps_main(S_PS_IN in_ps) : SV_TARGET
{
    // �� �ϐ��錾 �� //
    float4 out_color = in_ps.color;   // �F
    
    
    // �e�N�X�`���J���[��������
    out_color *= tex_color.Sample(samp0, in_ps.uv);
	
    
    // �J���[���o��
    return out_color;
}


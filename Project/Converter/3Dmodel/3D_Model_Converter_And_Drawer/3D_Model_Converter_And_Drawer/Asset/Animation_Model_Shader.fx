// �� �\���� �� //

// �{�[���E�F�C�g�̏��̍\����
struct S_Bone_Weight
{
	float weight = 0.0f;	// �{�[���E�F�C�g�l
	
	int index = 0;	// �{�[���̃C���f�b�N�X�ԍ�
};


// ���_�V�F�[�_�[�ɓn�������̍\����
struct S_VS_IN
{
	float4 position : POSITION;	// �ʒu���W

	float2 uv : TEXCOORD0;		// uv���W

	float4 color : COLOR;		// ���_�J���[
	
	float3 normal : NORMAL;		// �@���x�N�g��
	float3 tangent : TANGENT;	// �^���W�F���g�x�N�g��
	float3 bi_normal : BINORMAL;	// �]�@���x�N�g��
	
	S_Bone_Weight bone_weight[4] : BONEWEIGHT;	// �{�[���E�F�C�g���
};


// �s�N�Z���V�F�[�_�[�ɓn�������̍\����
struct S_PS_IN
{
	float4 position : SV_POSITION;	// �ʒu���W
	
	float2 uv : TEXCOORD0;		// uv���W
	
	float4 color : COLOR0;	// ���_�J���[
	
	float3 normal : NORMAL;		// �@���x�N�g��
	float3 tangent : TANGENT;	// �^���W�F���g�x�N�g��
	float3 bi_normal : BINORMAL;	// �]�@���x�N�g��
};


// ���[���h�s��A�r���[�s��A�ˉe�s��̏��̍\����
struct S_WVP_MATRIX
{
	float4x4 world_matrix;		// ���[���h�s��
	float4x4 view_matrix;		// �r���[�s��
	float4x4 projection_matrix; // �ˉe�s��
};


// �� �萔�o�b�t�@ �� //

// ���[���h�s��A�r���[�s��A�ˉe�s��̏��̒萔�o�b�t�@
cbuffer CB_WVP_MATRIX : register(b0)
{
	S_WVP_MATRIX cb_wvp;
};


// �{�[���}�g���N�X�̒萔�o�b�t�@
cbuffer CS_BONE_MATRIX : register(b0)
{
	matrix cb_bone_matrix[100];
};


// �� �e�N�X�`���[ �� //
Texture2D main_color_texture : register(t0);	// ���C���ƂȂ�F�̃e�N�X�`��


// �� �T���v���[ �� //
sampler main_color_texture_sampler : register(s0);	// ���C���ƂȂ�F�̃e�N�X�`���̃T���v���[


// �� �֐� �� //

// ���_�V�F�[�_�[
S_PS_IN VS(S_VS_IN vs_input)
{
	// �� �ϐ��錾 �� //
	S_PS_IN vs_output;	// �s�N�Z���V�F�[�_�[�ɓn�����̍\����
	
	float4x4 bone_weight_result = (float4x4) 0;	// �{�[���E�F�C�g�̉e���l
	
	
	// �{�[���E�F�C�g�̉e���l���v�Z
	for (int i = 0; i < 4; i++)
	{
        bone_weight_result += cb_bone_matrix[vs_input.bone_weight[i].index] * vs_input.bone_weight[i].weight;
    }
	
	// �{�[���̈ړ��ɂ�钸�_�̈ړ����s��
    vs_input.position = mul(bone_weight_result, vs_input.position);
	
	// ���[���h�s��A�r���[�s��A�ˉe�s����|�����킹��
	vs_output.position = mul(cb_wvp.world_matrix, vs_input.position);
	vs_output.position = mul(cb_wvp.view_matrix, vs_output.position);
	vs_output.position = mul(cb_wvp.projection_matrix, vs_output.position);
	
	
	// uv���W��ݒ�
	vs_output.uv = vs_input.uv;
	
	// �F��ݒ�
	vs_output.color = vs_input.color;
	
	// �@���x�N�g����ݒ�
	vs_output.normal = vs_input.normal;
	
	// �^���W�F���g�x�N�g����ݒ�
	vs_output.tangent = vs_input.tangent;
	
	// �]�@���x�N�g����ݒ�
	vs_output.bi_normal = vs_input.bi_normal;
	
	// �v�Z��������Ԃ�
	return vs_output;
}


// �s�N�Z���V�F�[�_�[
float4 PS(S_PS_IN ps_input) : SV_Target
{
	return ps_input.color * main_color_texture.Sample(main_color_texture_sampler, ps_input.uv);
}

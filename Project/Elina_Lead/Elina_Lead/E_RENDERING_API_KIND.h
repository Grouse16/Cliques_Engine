//����������������������������������������������//
// �ڍ�   �F�����_�����O�pAPI�̎�ނ��w�肷��񋓂̒�`
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_E_RENDERING_API_KIND_H_FILE
#define D_INCLUDE_GUARD_E_RENDERING_API_KIND_H_FILE


// �� �l�[���X�y�[�X �� //

// �v���b�g�t�H�[���ŕ��򂷂鏉�����Ɖ���𐧌䂷��N���X���Ăяo�����߂̖��O
namespace PLATFORM
{
	// �� �� �� //

	// �����_�����O�pAPI�̎�ނ��w�肷���
	enum class E_RENDERING_API_KIND
	{
		e_DX11,		// �_�C���N�g�G�b�N�X�P�P
		e_DX12,		// �_�C���N�g�G�b�N�X�P�Q
		e_OPENGL,	// �I�[�v��GL
		e_VULKAN,	// �o���J��
		e_UNKNOWN,	// ���ʕs��
	};
}


#endif // !D_INCLUDE_GUARD_E_RENDERING_API_KIND_H_FILE

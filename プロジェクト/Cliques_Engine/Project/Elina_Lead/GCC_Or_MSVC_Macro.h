//����������������������������������������������//
// �ڍ�   �F�R���p�C����GCC��MSVC�̂ǂ���ł��邩�𔻒肷��}�N��
// ����   �F
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_GCC_OR_MSVC_MACRO_H_FILE
#define D_INCLUDE_GUARD_GCC_OR_MSVC_MACRO_H_FILE


// �� �}�N�� �� //

// GCC�ɂ��R���p�C����
#ifdef __GNUC__
#define D_GCC_COMPILE true	// GCC�ɂ��R���p�C���ł��邱�Ƃ������}�N��

// MSVC�ɂ��R���p�C����
#elif defined(_MSC_VER)
#define D_MSVC_COMPILE true	// MSVC�ɂ��R���p�C���ł��邱�Ƃ������}�N��

// �ǂ���ł��Ȃ���
#else
#define D_COMPILER_LOST true	// �s���ȃR���p�C���ɂ��R���p�C���ł��邱�Ƃ������}�N��
#endif

#endif // !D_INCLUDE_GUARD_GCC_OR_MSVC_MACRO_H_FILE


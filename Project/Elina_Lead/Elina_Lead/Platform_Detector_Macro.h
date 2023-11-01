//����������������������������������������������//
// �ڍ�   �F�v���b�g�t�H�[�����o�p�}�N��
// ����   �Fhttps://www.yokoweb.net/dokuwiki/programing/c-language/compiler-os-macro-define
// �쐬�� �F���◴��
//����������������������������������������������//


// �� ���d�C���N���[�h�K�[�h �� //
#ifndef D_INCLUDE_GUARD_PLATFORM_DETECTOR_MACRO_H_FILE
#define D_INCLUDE_GUARD_PLATFORM_DETECTOR_MACRO_H_FILE


// �� �}�N�� �� //

//-��- �E�B���h�E�Y -��-//
#if (defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(WIN64) || defined(_WIN64) || defined(__WIN64) || defined(__MINGW32__) || defined(__MINGW64__) || defined(_WINDOWS) || defined(_CONSOLE)) && !defined(__CYGWIN__)

// �E�B���h�E�YOS�ł��邱�Ƃ������}�N��
#define D_OS_IS_WINDOWS


//-��- �}�b�N -��-//
#elif defined(__MACH__)

// �}�b�NOS�ł��邱�Ƃ������}�N��
#define D_OS_IS_MAC


//-��- ���i�b�N�X -��-//
#elif defined(__linux__) || defined(__linux)

// ���i�b�N�XOS�ł��邱�Ƃ������}�N��
#define D_OS_IS_LINUX


//-��- ���j�b�N�X -��-//
#elif defined(__unix__) || defined(__unix) || defined(__CYGWIN__)

// ���j�b�N�XOS�ł��邱�Ƃ������}�N��
#define D_OS_IS_UNIX


//-��- ���m�s�� -��-//
#else

// OS�����m�ł��Ȃ��������Ƃ������}�N��
#define D_OS_IS_UNKNOWN

#endif


#endif // !D_INCLUDE_GUARD_PLATFORM_DETECTOR_MACRO_H_FILE


//��======================================================================��
// Copyright 2023 ���◴��
// 
// ���������̃R�[�h�������̃v���W�F�N�g�ɗ��p�������̂ł���΁A
// ���[���A�h���X�Ftakasaka.ryusei1116@gmail.com
// �܂��́A���◴���܂ł��A�����������B
// �R�[�h�̕s�������̉����A�ŐV�̏�Ԃ̒񋟂ȂǂɑΉ��������܂��B
//��======================================================================��


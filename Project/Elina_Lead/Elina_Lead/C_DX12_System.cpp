//����������������������������������������������//
// �ڍ�   �FDX12�̋@�\���g�����߂̃N���X
// ����   �FDX12�ݒ��`�揈�����s��
// �쐬�� �F���◴��
//����������������������������������������������//


// �� �t�@�C���Ђ炫 �� //
#include <string>


// �� OS���m �� //
#include "Platform_Detector_Macro.h"
#ifdef D_OS_IS_WINDOWS

#include "C_Windows_System.h"

#include "C_DX12_System.h"
#include "C_DX12_Input_Layout_Setting_System.h"
#include "C_DX12_Streaming_Output_Buffer_Base.h"
#include "C_DX12_Blend_State_Setting_System.h"
#include "C_DX12_Rasterrizer_State_Setting_System.h"
#include "C_DX12_Sampling_Setting_System.h"
#include "C_DX12_Stencil_State_Setting_System.h"
#include "C_DX12_Cached_PSO_Base.h"
#include "C_DX12_Font_Data_Set.h"

#ifdef _DEBUG
#include "C_Log_System.h"
#endif // _DEBUG


// �� ���C�u�����Ђ炫 �� //
#pragma comment (lib, "d3d12.lib")
#pragma comment (lib, "dxgi.lib")
#pragma comment (lib, "dxguid.lib")
#pragma comment (lib, "D3DCompiler.lib")


// ���@�O�� �� //
#ifndef TEXTURE_CHALLEGE
#include <DirectXTex.h>
#pragma comment (lib, "DirectXTex.lib")
#endif


// �� �l�[���X�y�[�X�̏ȗ� �� //
using namespace RENDERING::GRAPHICS::DX12;


// �� �֐� �� //

//==�� �v���C�x�[�g ��==//

//-��-  ������  -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R���X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_DX12_System::C_DX12_System(void)
{
    return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�o�C�X��`��R�}���h�A�����_�����O��̐ݒ�̏�����
// ����   �Fvoid
// �߂�l �Fbool �����グ�ɐ������Ă�����true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_DX12_System::M_DirectX12_Init(void)
{
    // �� �f�o�b�O���̂݃Z�b�g�A�b�v�J�n��ʒm �� //
#if _DEBUG
    DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_BLACK, DEBUGGER::LOG::E_LOG_COLOR::e_GREEN);
    DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED, "-��-��-��-��-��-��-��-DX12�̃Z�b�g�A�b�v�J�n-��-��-��-��-��-��-��-");
#endif // _DEBUG


    // DX12�p�ϐ��Q�̏�����
    mpr_variable.reset(new C_DX12_System::SPr_Variable());


    // �� �t�@�N�g���̐��� �� //  �i�S��ʕ\���J�ڗp�V�X�e���j  // ���s�ŏ������𒆒f
    if (M_Create_Factory() == false)
    {
        return false;
    }


    // �� �f�o�C�X�̐��� �� //  �i���z�A�_�v�^�[�j  // ���s�ŏ������𒆒f
    if (M_Create_Device() == false)
    {
        return false;
    }


    // �� �R�}���h�A���P�[�^�[�̐��� �� //  �iGPU�R�}���h�̃X�g���[�W���蓖�ăV�X�e���j  // ���s�ŏ������𒆒f
    if (M_Create_Command_Allocator() == false)
    {
        return false;
    }


    // �� �R�}���h���X�g�̐��� �� //  �i�`�施�߂̃��X�g�̃J�v�Z���j  // ���s�ŏ������𒆒f
    if (M_Create_Command_List() == false)
    {
        return false;
    }


    // �� �R�}���h�L���[�̐��� �� //  �i�`����s�V�X�e���j  // ���s�ŏ������𒆒f
    if (M_Create_Command_Queue() == false)
    {
        return false;
    }


    // �� �t�F���X�̐��� �� //  �i�`�擯���p�V�X�e���j  // ���s�ŏ������𒆒f
    if (M_Create_Fence() == false)
    {
        return false;
    }


    // �� �X���b�v�`�F�C���̐��� �� //  �i��ʃo�b�t�@�؂�ւ��p�V�X�e���j  // ���s�ŏ������𒆒f
    if (M_Create_Swap_Chain() == false)
    {
        return false;
    }


    // �� �����_�[�^�[�Q�b�g�r���[�̐��� �� //  �i�����_�����O��̉�ʃo�b�t�@�؂�ւ��p�V�X�e���j  // ���s�ŏ������𒆒f
    if (M_Create_Render_Target_View_Descriptor_Heap() == false)
    {
        return false;
    }


    // �� �[�x�X�e���V���r���[�̐��� �� //  �i�[�x�X�e���V���K�p��̉�ʃo�b�t�@�̐؂�ւ��p�V�X�e���j  // ���s�ŏ������𒆒f
    if (M_Create_Depth_Stencil_View_Descriptor_Heap() == false)
    {
        return false;
    }


    // ��ʂ�h��Ԃ��F��ݒ�
    mpr_variable->s_frame_work.clear_color[(int)E_DX12_PARAMATOR::e_RED] = 0.0f; // ��
    mpr_variable->s_frame_work.clear_color[(int)E_DX12_PARAMATOR::e_GREEN] = 0.8f; // ��
    mpr_variable->s_frame_work.clear_color[(int)E_DX12_PARAMATOR::e_BLUE] = 0.8f; // ��
    mpr_variable->s_frame_work.clear_color[(int)E_DX12_PARAMATOR::e_ALPHA] = 1.0f; // ��

	// ��������
	return true;
}


//-��- ���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�t�@�N�g���𐶐�����(�S��ʕ\���J�ڗp�V�X�e��)
// ����   �Fvoid
// �߂�l �Fbool �����������������ǂ�����Ԃ� ������true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_DX12_System::M_Create_Factory(void)
{
    // �� �ϐ��錾 ��  //
    UINT flg_DXGI = 0;  // �@�\�ݒ�p���


    // �� �f�o�b�O�p�ݒ�
#if _DEBUG

    // �� �ϐ��錾 �� //
    ID3D12Debug* handle_debug_setting = nullptr;   // �f�o�b�O�p�ݒ�̃A�h���X


    // �f�o�b�O�p���擾
    D3D12GetDebugInterface(IID_PPV_ARGS(&handle_debug_setting));


    // �f�o�b�O���C���[��L����
    if (handle_debug_setting != nullptr)
    {
        handle_debug_setting->EnableDebugLayer();
        handle_debug_setting->Release();
    }

    // �f�o�b�O��Ԃ��w��
    flg_DXGI |= DXGI_CREATE_FACTORY_DEBUG;

#endif

    // �\���ݒ�p���̐���
    if (FAILED(CreateDXGIFactory2(flg_DXGI, IID_PPV_ARGS(mpr_variable->s_frame_work.factory.ReleaseAndGetAddressOf()))))
    {
        // �� �f�o�b�O���Ȃ珉�����̎��s��\�� �� //
#if _DEBUG
        DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
        DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, "�t�@�N�g���̐����Ɏ��s");
#endif // _DEBUG

        return false;   // ���s������G���[�Ŕ�����
    }

    // �� �f�o�b�O���Ȃ琬����\�� �� //
#if _DEBUG
    DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
    DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED, "�t�@�N�g���̐����ɐ���");
#endif // _DEBUG

    return true;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�o�C�X�𐶐�����(�S��ʕ\���J�ڗp�V�X�e��)
// ����   �Fvoid
// �߂�l �Fbool �����������������ǂ�����Ԃ� ������true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_DX12_System::M_Create_Device(void)
{
    // �� �萔�錾 �� //
    constexpr int con_DX12_FEATURE_LEVEL_SUM = 5;    // ���݂�dx12�̋@�\���x����


    // �� �ϐ��錾 �� //
    Microsoft::WRL::ComPtr<IDXGIAdapter> adapter;   // �A�_�v�^�[�i�o�͐�j���

    std::vector<D3D_FEATURE_LEVEL> can_attach_device_level_list_in_dx12;      // dx12�Ŏg�p�\�ȋ@�\���x�����X�g


    // �� �A�_�v�^�[���擾 �� //   // ���s�Ȃ�G���[
    if (FAILED(mpr_variable->s_frame_work.factory->EnumAdapters(0, adapter.GetAddressOf())))
    {
        // �� �f�o�b�O���Ȃ珉�����̎��s��\�� �� //
#if _DEBUG
        DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
        DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, "�A�_�v�^�[�̎擾�Ɏ��s");
#endif // _DEBUG

        return false;
    }


    // �� �f�o�b�O���Ȃ琬����\�� �� //
#if _DEBUG
    DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
    DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED, "�A�_�v�^�[�̎擾�ɐ���");
#endif // _DEBUG


    // �� �ϐ��錾 �� //
    HRESULT device_creation_result = E_FAIL; // �@�\���x���擾���̏����̌���

    int l_feature_num = 0;  // �����������@�\�ԍ�


    // �� �f�o�C�X���� �� //

    // DX12�Ŏg�p�\�ȋ@�\���x�����w�肷��i���x���̍����ō~���ɕ��ׂ�j
    can_attach_device_level_list_in_dx12.reserve(con_DX12_FEATURE_LEVEL_SUM);
    can_attach_device_level_list_in_dx12.emplace_back(D3D_FEATURE_LEVEL::D3D_FEATURE_LEVEL_12_2);
    can_attach_device_level_list_in_dx12.emplace_back(D3D_FEATURE_LEVEL::D3D_FEATURE_LEVEL_12_1);
    can_attach_device_level_list_in_dx12.emplace_back(D3D_FEATURE_LEVEL::D3D_FEATURE_LEVEL_12_0);
    can_attach_device_level_list_in_dx12.emplace_back(D3D_FEATURE_LEVEL::D3D_FEATURE_LEVEL_11_1);
    can_attach_device_level_list_in_dx12.emplace_back(D3D_FEATURE_LEVEL::D3D_FEATURE_LEVEL_11_0);


    // �����\�ȃ��x����������܂ŌJ��Ԃ�
    for (l_feature_num = 0; l_feature_num < con_DX12_FEATURE_LEVEL_SUM && FAILED(device_creation_result); l_feature_num++)
    {
        device_creation_result = D3D12CreateDevice(adapter.Get(), can_attach_device_level_list_in_dx12[l_feature_num], IID_PPV_ARGS(&mpr_variable->s_frame_work.device));
    }


    // �ǂ̋@�\�����Ȃ�������G���[�Ŕ�����iwindows7��8�̏ꍇ�͂��̋����ƂȂ�\���������j
    if (FAILED(device_creation_result))
    {
        // �� �f�o�b�O���Ȃ珉�����̎��s��\�� �� //
#if _DEBUG
        DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
        DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, "�f�o�C�X�̐����Ɏ��s");
#endif // _DEBUG

        return false;
    }


    // �� �f�o�b�O���Ȃ琬����\�� �� //
#if _DEBUG
    l_feature_num -= 1;
    DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
    DEBUGGER::LOG::C_Log_System::M_Print_Log
    (
        DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP,
        DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED,
        "�f�o�C�X�̐����ɐ����[��ʁF" + M_Convert_D3D_FEATURE_LEVEL_Enum_To_String(can_attach_device_level_list_in_dx12[l_feature_num]));
#endif // _DEBUG

    return true;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R�}���h�A���P�[�^�[�𐶐�����iGPU�R�}���h�̃X�g���[�W���蓖�ăV�X�e���j
// ����   �Fvoid
// �߂�l �Fbool �����������������ǂ�����Ԃ� ������true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_DX12_System::M_Create_Command_Allocator(void)
{
    // �� �R�}���h�A���P�[�^�𐶐� �� //  // ���s�Ȃ�G���[
    if (FAILED(mpr_variable->s_frame_work.device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(mpr_variable->s_command.allocator.GetAddressOf()))))
    {
        // �� �f�o�b�O���Ȃ珉�����̎��s��\�� �� //
#if _DEBUG
        DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
        DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, "�R�}���h�A���P�[�^�̐����Ɏ��s");
#endif // _DEBUG

        return false;   // ���s������G���[�Ŕ�����
    }


    // �� �f�o�b�O���Ȃ琬����\�� �� //
#if _DEBUG
    DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
    DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED, "�R�}���h�A���P�[�^�̐����ɐ���");
#endif // _DEBUG


    // �R�}���h�A���P�[�^�̃�������������
    mpr_variable->s_command.allocator->Reset();

    return true;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R�}���h���X�g�𐶐�����i�`�施�߂̃��X�g�̃J�v�Z���j
// ����   �Fvoid
// �߂�l �Fbool �����������������ǂ�����Ԃ� ������true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_DX12_System::M_Create_Command_List(void)
{
    // �� �R�}���h���X�g�̐��� �� //    // ���s�Ȃ�G���[
    if (FAILED(mpr_variable->s_frame_work.device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, mpr_variable->s_command.allocator.Get(), nullptr, IID_PPV_ARGS(mpr_variable->s_command.list.GetAddressOf()))))
    {
        // �� �f�o�b�O���Ȃ珉�����̎��s��\�� �� //
#if _DEBUG
        DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
        DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, "�R�}���h���X�g�̐����Ɏ��s");
#endif // _DEBUG

        return false;   // ���s������G���[�Ŕ�����
    }


    // �� �f�o�b�O���Ȃ琬����\�� �� //
#if _DEBUG
    DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
    DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED, "�R�}���h���X�g�̐����ɐ���");
#endif // _DEBUG

    // �R�}���h���X�g��������ԂɃ��Z�b�g
    mpr_variable->s_command.list->Close();

    return true;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R�}���h�L���[�𐶐�����i�`����s�V�X�e���j
// ����   �Fvoid
// �߂�l �Fbool �����������������ǂ�����Ԃ� ������true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_DX12_System::M_Create_Command_Queue(void)
{
    // �� �ϐ��錾 �� //
    D3D12_COMMAND_QUEUE_DESC desc_command_queue;    // �R�}���h�L���[�����p���


    // ������
    ZeroMemory(&desc_command_queue, sizeof(desc_command_queue));

    // �R�}���h�������ݕ��@���w��
    desc_command_queue.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;

    // �D��x�ݒ�
    desc_command_queue.Priority = 0;

    // GPU�^�C���A�E�g�ݒ�
    desc_command_queue.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;

    // �R�}���h�L���[�ɓK������m�[�h(GPU�╨���A�_�v�^�[)�̐�
    desc_command_queue.NodeMask = 0;


    // �� �R�}���h�L���[�𐶐� �� //         // ���s�Ȃ�G���[
    if (FAILED(mpr_variable->s_frame_work.device->CreateCommandQueue(&desc_command_queue, IID_PPV_ARGS(mpr_variable->s_command.queue.GetAddressOf()))))
    {
        // �� �f�o�b�O���Ȃ珉�����̎��s��\�� �� //
#if _DEBUG
        DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
        DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, "�R�}���h�L���[�̐����Ɏ��s");
#endif // _DEBUG

        return false;
    }


    // �� �f�o�b�O���Ȃ琬����\�� �� //
#if _DEBUG
    DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
    DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED, "�R�}���h�L���[�̐����ɐ���");
#endif // _DEBUG

    return true;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�t�F���X�𐶐�����i�`�擯���p�V�X�e���j
// ����   �Fvoid
// �߂�l �Fbool �����������������ǂ�����Ԃ� ������true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_DX12_System::M_Create_Fence(void)
{
    // �R�}���h�L���[�p�̃t�F���X������
    mpr_variable->s_render.fence_event = CreateEvent(NULL, FALSE, FALSE, NULL);


    // �� �t�F���X�𐶐� �� //   // ���s�Ȃ�G���[
    if (FAILED(mpr_variable->s_frame_work.device->CreateFence(0, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(mpr_variable->s_render.queue_fence.GetAddressOf()))))
    {
        // �� �f�o�b�O���Ȃ珉�����̎��s��\�� �� //
#if _DEBUG
        DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
        DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, "�t�F���X�̐����Ɏ��s");
#endif // _DEBUG

        return false;
    }


    // �� �f�o�b�O���Ȃ琬����\�� �� //
#if _DEBUG
    DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
    DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED, "�t�F���X�̐����ɐ���");
#endif // _DEBUG

    return true;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�X���b�v�`�F�C���𐶐�����i��ʃo�b�t�@�؂�ւ��p�V�X�e���j
// ����   �Fvoid
// �߂�l �Fbool �����������������ǂ�����Ԃ� ������true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_DX12_System::M_Create_Swap_Chain(void)
{
    // �� �ϐ��錾 ��  //
    DXGI_SWAP_CHAIN_DESC desc_swap_chain;   // �X���b�v�`�F�C���ݒ�p���


    // ������
    ZeroMemory(&desc_swap_chain, sizeof(desc_swap_chain));

    // �o�b�N�o�b�t�@�̃t�H�[�}�b�g
    desc_swap_chain.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;

    // �T���v�����O�p�o�b�t�@��
    desc_swap_chain.SampleDesc.Count = 1;

    // ��ʂ�CPU�A�N�Z�X���@�ݒ�
    desc_swap_chain.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;

    // ��ʐ�
    desc_swap_chain.BufferCount = (int)E_DX12_PARAMATOR::e_RENDER_TARGET_BUFFER_SUM;

    // �E�B���h�E�ւ̃n���h��
    desc_swap_chain.OutputWindow = OS::WINDOWS::C_Windows_System::M_Get_Window_Handle();

    // �E�B���h�E���[�h�ł��邩�ǂ���
    desc_swap_chain.Windowed = TRUE;

    // �\���ؑ֌�I�v�V����
    desc_swap_chain.SwapEffect = DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL;

    // �X���b�v�`�F�C������I�v�V����
    desc_swap_chain.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;


    // �� �X���b�v�`�F�C���𐶐� �� //      // ���s�Ȃ�G���[
    if (FAILED(mpr_variable->s_frame_work.factory->CreateSwapChain(mpr_variable->s_command.queue.Get(), &desc_swap_chain, (IDXGISwapChain**)mpr_variable->s_frame_work.swap_chain.GetAddressOf())))
    {
        // �� �f�o�b�O���Ȃ珉�����̎��s��\�� �� //
#if _DEBUG
        DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
        DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, "�X���b�v�`�F�C���̐����Ɏ��s");
#endif // _DEBUG

        return false;
    }


    // �� �f�o�b�O���Ȃ琬����\�� �� //
#if _DEBUG
    DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
    DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED, "�X���b�v�`�F�C���̐����ɐ���");
#endif // _DEBUG

    return true;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�����_�[�^�[�Q�b�g�r���[�𐶐�����i�����_�����O��̉�ʃo�b�t�@�؂�ւ��p�V�X�e���j
// ����   �Fvoid
// �߂�l �Fbool �����������������ǂ�����Ԃ� ������true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_DX12_System::M_Create_Render_Target_View_Descriptor_Heap(void)
{
    // �� �ϐ��錾 �� //
    D3D12_DESCRIPTOR_HEAP_DESC desc_descriptor_heap;   // �f�X�N���v�^�q�[�v�ݒ�p���


    // ������
    ZeroMemory(&desc_descriptor_heap, sizeof(desc_descriptor_heap));

    // �q�[�v���̃f�X�N���v�^�̎��
    desc_descriptor_heap.Type = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;

    // �f�X�N���v�^�̐�
    desc_descriptor_heap.NumDescriptors = (int)E_DX12_PARAMATOR::e_RENDER_TARGET_BUFFER_SUM;

    // �q�[�v�I�v�V����
    desc_descriptor_heap.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;

    // �f�X�N���v�^�ɓK������m�[�h(GPU�╨���A�_�v�^�[)�̐�
    desc_descriptor_heap.NodeMask = 0;


    // �� �����_�[�^�[�Q�b�g�q�[�v�̐��� �� //     // ���s�Ȃ�G���[
    if (FAILED(mpr_variable->s_frame_work.device->CreateDescriptorHeap(&desc_descriptor_heap, IID_PPV_ARGS(mpr_variable->s_render.rtv.heap.GetAddressOf()))))
    {
        // �� �f�o�b�O���Ȃ珉�����̎��s��\�� �� //
#if _DEBUG
        DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
        DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, "�����_�[�^�[�Q�b�g�q�[�v�����Ɏ��s");
#endif // _DEBUG

        return false;   // ���s������G���[�Ŕ�����
    }


    // �� �f�o�b�O���Ȃ琬����\�� �� //
#if _DEBUG
    DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
    DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED, "�����_�[�^�[�Q�b�g�q�[�v�̐����ɐ���");
#endif // _DEBUG


    // �� �ϐ��錾 �� //
    UINT byte_of_handle = mpr_variable->s_frame_work.device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV); // �n���h������ɑ΂���o�C�g��(�A�h���X����p)


    // �S�Ẵo�b�t�@�Ƀ����_�[�^�[�Q�b�g��ݒ�
    for (UINT loop_x = 0; loop_x < (int)E_DX12_PARAMATOR::e_RENDER_TARGET_BUFFER_SUM; loop_x++)
    {
        // ��ʂ̃o�b�t�@�Ƀ����_�[�^�[�Q�b�g���w��
        if (FAILED(mpr_variable->s_frame_work.swap_chain->GetBuffer(loop_x, IID_PPV_ARGS(mpr_variable->s_render.rtv.render_buffer[loop_x].GetAddressOf()))))
        {
            // �� �f�o�b�O���Ȃ珉�����̎��s��\�� �� //
#if _DEBUG
            DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
            DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, ((std::string)"Buffer_Count:" + std::to_string(loop_x) + "-" + "�����_�[�^�[�Q�b�g�̎擾�Ɏ��s").c_str());
#endif // _DEBUG

            return false;   // ���s������G���[�Ŕ�����
        }


        // �� �f�o�b�O���Ȃ琬����\�� �� //
#if _DEBUG
        DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
        DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED, ((std::string)"�����_�[�^�[�Q�b�g�̎擾�ɐ���" + "-buffer_count:" + std::to_string(loop_x)).c_str());
#endif // _DEBUG


        // ��Ԗڂ̃f�X�N���v�^�̃A�h���X���w��
        mpr_variable->s_render.rtv.handle[loop_x] = mpr_variable->s_render.rtv.heap->GetCPUDescriptorHandleForHeapStart();

        // ���̃f�X�N���v�^�܂ł��炷
        mpr_variable->s_render.rtv.handle[loop_x].ptr += (SIZE_T)loop_x * (SIZE_T)byte_of_handle;

        // �����_�[�^�[�Q�b�g�r���[����
        mpr_variable->s_frame_work.device->CreateRenderTargetView(mpr_variable->s_render.rtv.render_buffer[loop_x].Get(), nullptr, mpr_variable->s_render.rtv.handle[loop_x]);
    }

    return true;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�[�x�X�e���V���r���[�𐶐�����i�[�x�X�e���V���K�p��̉�ʃo�b�t�@�̐؂�ւ��p�V�X�e���j
// ����   �Fvoid
// �߂�l �Fbool �����������������ǂ�����Ԃ� ������true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_DX12_System::M_Create_Depth_Stencil_View_Descriptor_Heap(void)
{
    // �� �[�x�X�e���V���q�[�v �� //    //�i�Ǘ��p�؍\���j
    {
        // �� �ϐ��錾 �� //
        D3D12_DESCRIPTOR_HEAP_DESC desc_descriptor_heap;   // �f�X�N���v�^�q�[�v�ݒ�p���


        // ������
        ZeroMemory(&desc_descriptor_heap, sizeof(desc_descriptor_heap));

        // �q�[�v���̃f�X�N���v�^�̎��
        desc_descriptor_heap.Type = D3D12_DESCRIPTOR_HEAP_TYPE_DSV;

        // �f�X�N���v�^�̐�
        desc_descriptor_heap.NumDescriptors = 1;

        // �q�[�v�I�v�V����
        desc_descriptor_heap.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;

        // �f�X�N���v�^�ɓK������m�[�h(GPU�╨���A�_�v�^�[)�̐�
        desc_descriptor_heap.NodeMask = 0;


        // �� �[�x�X�e���V���q�[�v�̐��� �� //     // ���s�Ȃ�G���[
        if (FAILED(mpr_variable->s_frame_work.device->CreateDescriptorHeap(&desc_descriptor_heap, IID_PPV_ARGS(mpr_variable->s_render.dsv.heap.GetAddressOf()))))
        {
            // �� �f�o�b�O���Ȃ珉�����̎��s��\�� �� //
#if _DEBUG
            DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
            DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, "�[�x�X�e���V���q�[�v�̐����Ɏ��s");
#endif // _DEBUG

            return false;
        }
    }


    // �� �f�o�b�O���Ȃ珉�����̐�����\�� �� //
#if _DEBUG
    DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
    DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED, "�[�x�X�e���V���q�[�v�̐����ɐ���");
#endif // _DEBUG


    // �� �[�x�X�e���V���o�b�t�@�p�q�[�v �� //
    {
        // �� �ϐ��錾 �� //
        D3D12_HEAP_PROPERTIES heap_propertie;   // �q�[�v�������̐ݒ�

        D3D12_RESOURCE_DESC desc_resource;    // ���\�[�X�ݒ�

        D3D12_CLEAR_VALUE clear_setting = {};   // �[�x�X�e���V���o�b�t�@�N���A���̃p�����[�^


        // �� �q�[�v�������̐ݒ� �� //

        // ������
        ZeroMemory(&heap_propertie, sizeof(heap_propertie));

        // �q�[�v�̓���̎��
        heap_propertie.Type = D3D12_HEAP_TYPE_DEFAULT;

        // CPU�̃��������y�[�W���O�ɂ���ĕ����̃������Ƃ��Ĉ����Ă��鎞�ɂǂ̂悤�ɂ��̃������ɃA�N�Z�X���邩
        heap_propertie.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;

        // �������v�[��(�N�����Ɉ�C�ɃA�v���Ŏg�p����f�[�^���m�ۂ���ꏊ)�̎�ނ��w�肷��
        heap_propertie.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;

        // �q�[�v�������𐶐�����m�[�h(GPU�╨���A�_�v�^�[)�̐�
        heap_propertie.CreationNodeMask = 1;

        // ���\�[�X�����݂���m�[�h�̐�(GPU�╨���A�_�v�^�[)�̐�
        heap_propertie.VisibleNodeMask = heap_propertie.CreationNodeMask;


        // �� ���\�[�X�̐ݒ� �� //

        // ������
        ZeroMemory(&desc_resource, sizeof(desc_resource));

        // �g�p����郊�\�[�X�̎��
        desc_resource.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;

        // �ݒ肷�郊�\�[�X���̔z�u�ԍ�
        desc_resource.Alignment = 0;

        // ���\�[�X�̃o�C�g��
        desc_resource.Width = 1920;

        // ���\�[�X�̔z��
        desc_resource.Height = 1080;

        // ���\�[�X�̐[���A�܂��͔z��
        desc_resource.DepthOrArraySize = 1;

        // MIPMAP���x��(���̐��l�ɉ����ăs�N�Z�������{�ɂȂ�)
        desc_resource.MipLevels = 0;

        // ���\�[�X��DX12�����p�ӂ����^���ǂ���
        desc_resource.Format = DXGI_FORMAT_D32_FLOAT;


        // �� �T���v�����O�ݒ� �� //

        // �T���v�����O��
        desc_resource.SampleDesc.Count = 1;

        // �T���v�����O���̃N�I���e�B
        desc_resource.SampleDesc.Quality = 0;


        // �e�N�X�`�����C�A�E�g�̃I�v�V����
        desc_resource.Layout = D3D12_TEXTURE_LAYOUT_UNKNOWN;

        // ���\�[�X�𑀍삷�邽�߂̃I�v�V����
        desc_resource.Flags = D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL | D3D12_RESOURCE_FLAG_DENY_SHADER_RESOURCE;


        
        // �� �[�x�X�e���V���o�b�t�@�N���A�ݒ� �� //

        // �N���A�p�̕ϐ��̃f�[�^�`��
        clear_setting.Format = DXGI_FORMAT_D32_FLOAT;

        // �������p�[�x�l
        clear_setting.DepthStencil.Depth = 1.0f;

        // �������p�X�e���V���l
        clear_setting.DepthStencil.Stencil = 0;


        // �� �[�x�X�e���V���o�b�t�@���� �� //
        if (FAILED(mpr_variable->s_frame_work.device->CreateCommittedResource(&heap_propertie, D3D12_HEAP_FLAG_NONE, &desc_resource, D3D12_RESOURCE_STATE_DEPTH_WRITE, &clear_setting, IID_PPV_ARGS(&mpr_variable->s_render.dsv.buffer))))
        {
            // �� �f�o�b�O���Ȃ珉�����̎��s��\�� �� //
#if _DEBUG
            DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
            DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, "�[�x�X�e���V���o�b�t�@�̐����Ɏ��s");
#endif // _DEBUG

            return false;
        }
    }


    // �� �f�o�b�O���Ȃ珉�����̐�����\�� �� //
#if _DEBUG
    DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
    DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED, "�[�x�X�e���V���o�b�t�@�̐����ɐ���");
#endif // _DEBUG


    // �� �[�x�X�e���V���r���[ �� //
    {
        // �� �ϐ��錾 �� //
        D3D12_DEPTH_STENCIL_VIEW_DESC dsv_desc = {};    //�[�x�X�e���V���r���[�ݒ�p���


        // �[�x�X�e���V���o�b�t�@�̃f�[�^�`��
        dsv_desc.Format = DXGI_FORMAT_D32_FLOAT;

        // �[�x�X�e���V���o�b�t�@�̐��@�i�e�N�X�`���`���j
        dsv_desc.ViewDimension = D3D12_DSV_DIMENSION_TEXTURE2D;

        // �e�N�X�`���̎g�p���@
        dsv_desc.Flags = D3D12_DSV_FLAG_NONE;


        // �A�h���X�̎擾
        mpr_variable->s_render.dsv.handle = mpr_variable->s_render.dsv.heap->GetCPUDescriptorHandleForHeapStart();

        //�[�x�X�e���V���r���[����
        mpr_variable->s_frame_work.device->CreateDepthStencilView(mpr_variable->s_render.dsv.buffer.Get(), &dsv_desc, mpr_variable->s_render.dsv.handle);
    }

    return true;
}

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���_�o�b�t�@�𐶐�����
// ����   �FC_DX12_Vertex_Setting_Inform * & �Z�b�g��̒��_�f�[�^, const C_Create_Vertex_Buffer_Inform & ���_�f�[�^�����p���(const)
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_System::M_Create_Vertex_Buffer(DX12INSTANCE::C_DX12_Vertex_Setting_Inform * & in_dx12_vertex_inform, const CREATE::C_Create_Vertex_Buffer_Inform & in_create_inform)
{
    // �� �ϐ��錾 �� //
    D3D12_HEAP_PROPERTIES heap_properties;   // �q�[�v�������̐ݒ�

    D3D12_RESOURCE_DESC desc_resource;    // ���\�[�X�ݒ�


    // �� �q�[�v�������̐ݒ� �� //

    // ������
    ZeroMemory(&heap_properties, sizeof(heap_properties));

    // �q�[�v�̓���̎��
    heap_properties.Type = D3D12_HEAP_TYPE_UPLOAD;

    // CPU�̃��������y�[�W���O�ɂ���ĕ����̃������Ƃ��Ĉ����Ă��鎞�ɂǂ̂悤�ɂ��̃������ɃA�N�Z�X���邩
    heap_properties.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;

    // �������v�[��(�N�����Ɉ�C�ɃA�v���Ŏg�p����f�[�^���m�ۂ���ꏊ)�̎�ނ��w�肷��
    heap_properties.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;

    // �q�[�v�������𐶐�����m�[�h(GPU�╨���A�_�v�^�[)�̐�
    heap_properties.CreationNodeMask = 0;

    // ���\�[�X�����݂���m�[�h�̐�(GPU�╨���A�_�v�^�[)�̐�
    heap_properties.VisibleNodeMask = heap_properties.CreationNodeMask;


    // �� ���\�[�X�̐ݒ� �� //

    // ������
    ZeroMemory(&desc_resource, sizeof(desc_resource));

    // �g�p����郊�\�[�X�̎��
    desc_resource.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;

    // �ݒ肷�郊�\�[�X���̔z�u�ԍ�
    desc_resource.Alignment = 0;

    // ���\�[�X�̃o�C�g��
    desc_resource.Width = in_create_inform.size_of_vertex * in_create_inform.vertex_sum;

    // ���\�[�X�̔z��ԍ�
    desc_resource.Height = 1;

    // ���\�[�X�̐[���A�܂��͔z��
    desc_resource.DepthOrArraySize = 1;

    // MIPMAP���x��(���̐��l�ɉ����ăs�N�Z�������{�ɂȂ�)
    desc_resource.MipLevels = 1;

    // ���\�[�X��DX12�����p�ӂ����^���ǂ���
    desc_resource.Format = DXGI_FORMAT_UNKNOWN;


    // �� �T���v�����O�ݒ� �� //

    // �T���v�����O��
    desc_resource.SampleDesc.Count = 1;

    // �T���v�����O���̃N�I���e�B
    desc_resource.SampleDesc.Quality = 0;


    // �e�N�X�`�����C�A�E�g�̃I�v�V����
    desc_resource.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;

    // ���\�[�X�𑀍삷�邽�߂̃I�v�V����
    desc_resource.Flags = D3D12_RESOURCE_FLAG_NONE;


    // ���_�o�b�t�@�̃A�h���X�ݒ�𐶐�(���s�ŃG���[���o���Ĕ�����)
    if (FAILED(mpr_variable->s_frame_work.device->CreateCommittedResource
    (
        &heap_properties,
        D3D12_HEAP_FLAG_NONE,
        &desc_resource,
        D3D12_RESOURCE_STATE_GENERIC_READ,
        nullptr,
        IID_PPV_ARGS(in_dx12_vertex_inform->m_vertex_buffer_data.GetAddressOf())))
        || in_dx12_vertex_inform->m_vertex_buffer_data == nullptr
    )
    {
        return;
    }


    // �� ���_�o�b�t�@�ݒ� �� //

    // �o�b�t�@�̍��W
    in_dx12_vertex_inform->m_vertex_buffer_view.BufferLocation = in_dx12_vertex_inform->m_vertex_buffer_data->GetGPUVirtualAddress();

    // ���_�o�b�t�@�̃o�C�g��
    in_dx12_vertex_inform->m_vertex_buffer_view.SizeInBytes = in_create_inform.size_of_vertex * in_create_inform.vertex_sum;

    // �v�f�̃o�C�g��
    in_dx12_vertex_inform->m_vertex_buffer_view.StrideInBytes = in_create_inform.size_of_vertex;

    return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�C���f�b�N�X�o�b�t�@�𐶐�����
// ����   �FC_DX12_Vertex_Setting_Inform * & �Z�b�g��̒��_�f�[�^, const C_Create_Vertex_Buffer_Inform & ���_�f�[�^�����p���(const)
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_System::M_Create_Index_Buffer(DX12INSTANCE::C_DX12_Vertex_Setting_Inform * & in_dx12_vertex_inform, const CREATE::C_Create_Vertex_Buffer_Inform & in_create_inform)
{
    // �� �ϐ��錾 �� //
    D3D12_HEAP_PROPERTIES heap_propertie;   // �q�[�v�������̐ݒ�

    D3D12_RESOURCE_DESC desc_resource;    // ���\�[�X�ݒ�

    int byte_size = in_create_inform.index_sum * sizeof(uint32_t);  // �o�C�g��


    // �� �q�[�v�������̐ݒ� �� //

    // ������
    ZeroMemory(&heap_propertie, sizeof(heap_propertie));

    // �q�[�v�̓���̎��
    heap_propertie.Type = D3D12_HEAP_TYPE_UPLOAD;

    // CPU�̃��������y�[�W���O�ɂ���ĕ����̃������Ƃ��Ĉ����Ă��鎞�ɂǂ̂悤�ɂ��̃������ɃA�N�Z�X���邩
    heap_propertie.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;

    // �������v�[��(�N�����Ɉ�C�ɃA�v���Ŏg�p����f�[�^���m�ۂ���ꏊ)�̎�ނ��w�肷��
    heap_propertie.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;

    // �q�[�v�������𐶐�����m�[�h(GPU�╨���A�_�v�^�[)�̐�
    heap_propertie.CreationNodeMask = 0;

    // ���\�[�X�����݂���m�[�h�̐�(GPU�╨���A�_�v�^�[)�̐�
    heap_propertie.VisibleNodeMask = heap_propertie.CreationNodeMask;


    // �� ���\�[�X�̐ݒ� �� //

    // ������
    ZeroMemory(&desc_resource, sizeof(desc_resource));

    // �g�p����郊�\�[�X�̎��
    desc_resource.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;

    // �ݒ肷�郊�\�[�X���̔z��
    desc_resource.Alignment = 0;

    // ���\�[�X�̃o�C�g��
    desc_resource.Width = byte_size;

    // ���\�[�X�̔z��ԍ�
    desc_resource.Height = 1;

    // ���\�[�X�̐[���A�܂��͔z��
    desc_resource.DepthOrArraySize = 1;

    // MIPMAP���x��(���̐��l�ɉ����ăs�N�Z�������{�ɂȂ�)
    desc_resource.MipLevels = 1;

    // ���\�[�X��DX12�����p�ӂ����^���ǂ���
    desc_resource.Format = DXGI_FORMAT_UNKNOWN;


    // �� �T���v�����O�ݒ� �� //

    // �T���v�����O��
    desc_resource.SampleDesc.Count = 1;

    // �T���v�����O���̃N�I���e�B
    desc_resource.SampleDesc.Quality = 0;


    // �e�N�X�`�����C�A�E�g�̃I�v�V����
    desc_resource.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;

    // ���\�[�X�𑀍삷�邽�߂̃I�v�V����
    desc_resource.Flags = D3D12_RESOURCE_FLAG_NONE;


    // ���_�o�b�t�@�̃A�h���X�ݒ�𐶐�(���s�ŃG���[���o���Ĕ�����)
    if (FAILED(mpr_variable->s_frame_work.device->CreateCommittedResource
    (
        &heap_propertie,
        D3D12_HEAP_FLAG_NONE,
        &desc_resource,
        D3D12_RESOURCE_STATE_GENERIC_READ,
        nullptr,
        IID_PPV_ARGS(in_dx12_vertex_inform->m_index_buffer_data.GetAddressOf())))
        || in_dx12_vertex_inform->m_index_buffer_data == nullptr
    )
    {
        return;
    }


    // GPU�ł̃A�h���X�����
    in_dx12_vertex_inform->m_index_buffer_view.BufferLocation = in_dx12_vertex_inform->m_index_buffer_data->GetGPUVirtualAddress();

    // �C���f�b�N�X�o�b�t�@�̃o�C�g��
    in_dx12_vertex_inform->m_index_buffer_view.SizeInBytes = byte_size;

    // �C���f�b�N�X�o�b�t�@�̃f�[�^�`��
    in_dx12_vertex_inform->m_index_buffer_view.Format = DXGI_FORMAT_R32_UINT;

    return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�萔�f�[�^�p�̃q�[�v�𐶐�����
// ����   �FC_DX12_Constant_Setting_Inform * & �ݒ��̒萔�p�̃f�[�^, const C_Create_Constant_Buffer_Inform & �萔�p�f�[�^�����p���(const)
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_System::M_Create_Constant_Heap(DX12INSTANCE::C_DX12_Constant_Setting_Inform * & in_dx12_constant_setting, const CREATE::C_Create_Constant_Buffer_Inform & in_create_inform)
{
    // �� �ϐ��錾 �� //
    D3D12_DESCRIPTOR_HEAP_DESC descriptor_heap_desc{};  // �e�N�X�`���p�̃q�[�v�̐����p���


    // �q�[�v�ŊǗ�����f�[�^�̊Ǘ�
    descriptor_heap_desc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;

    // �f�[�^��
    descriptor_heap_desc.NumDescriptors = in_create_inform.m_list_size;

    // �V�F�[�_�[����ҏW�ł��邩�ǂ���
    descriptor_heap_desc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;

    // �A�_�v�^�[�̃m�[�h��
    descriptor_heap_desc.NodeMask = 0;


    // �e�N�X�`���q�[�v�̐���
    if (FAILED(mpr_variable->s_frame_work.device->CreateDescriptorHeap(&descriptor_heap_desc, IID_PPV_ARGS(&in_dx12_constant_setting->m_constant_buffer_heap))))
    {
        return;
    }

    return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�萔�f�[�^�p�̏��𐶐�����
// ����   �FC_DX12_Constant_Setting_Inform * & �ݒ��̒萔�p�̃f�[�^, const C_Create_Constant_Buffer_Inform & �萔�p�f�[�^�����p���(const)
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_System::M_Create_Constant_Resource(DX12INSTANCE::C_DX12_Constant_Setting_Inform * & in_dx12_constant_setting, const CREATE::C_Create_Constant_Buffer_Inform & in_create_inform)
{
    // �� �萔 �� //
    const int con_CONSTANT_BUFFER_ONE_BYTE = 256;	// �萔�o�b�t�@����̃o�C�g��


    // �� �萔�o�b�t�@�f�[�^�𐶐� �� //
    {
        // �� �ϐ��錾 �� //
        D3D12_HEAP_PROPERTIES constant_data_prop;   // �萔�f�[�^�����p�̃v���p�e�B�ݒ�
        
        D3D12_RESOURCE_DESC constant_data_desc;     // �萔�o�b�t�@�̃f�[�^�̐ݒ�


        // �� �v���p�e�B�ݒ� �� //

        // �q�[�v�̓���̎��
        constant_data_prop.Type = D3D12_HEAP_TYPE_UPLOAD;

        // CPU�̃��������y�[�W���O�ɂ���ĕ����̃������Ƃ��Ĉ����Ă��鎞�ɂǂ̂悤�ɂ��̃������ɃA�N�Z�X���邩
        constant_data_prop.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
    
        // �������v�[��(�N�����Ɉ�C�ɃA�v���Ŏg�p����f�[�^���m�ۂ���ꏊ)�̎�ނ��w�肷��
        constant_data_prop.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;
    
        // �q�[�v�������𐶐�����m�[�h(GPU�╨���A�_�v�^�[)�̐�
        constant_data_prop.CreationNodeMask = 1;
    
        // ���\�[�X�����݂���m�[�h�̐�(GPU�╨���A�_�v�^�[)�̐�
        constant_data_prop.VisibleNodeMask = 1;


        // �� �f�[�^�ݒ� �� //

        // �g�p����郊�\�[�X�̎��
        constant_data_desc.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;

        // �ݒ肷�郊�\�[�X���̔z�u�ʒu���w��
        constant_data_desc.Alignment = 0;

        // ���\�[�X�̃o�C�g��
        constant_data_desc.Width = con_CONSTANT_BUFFER_ONE_BYTE; // �萔�o�b�t�@�T�C�Y��256�o�C�g�łȂ���΂Ȃ�Ȃ�

        // ���\�[�X�̔z��ԍ�
        constant_data_desc.Height = in_create_inform.m_list_size;

        // ���\�[�X�̐[���A�܂��͔z��
        constant_data_desc.DepthOrArraySize = 1;

        // MIPMAP���x��(���̐��l�ɉ����ăs�N�Z�������{�ɂȂ�)
        constant_data_desc.MipLevels = 1;

        // ���\�[�X��DX12�����p�ӂ����^���ǂ���
        constant_data_desc.Format = DXGI_FORMAT_UNKNOWN;
        

        // �� �T���v�����O�ݒ� �� //

        // �T���v�����O��
        constant_data_desc.SampleDesc.Count = 1;

        // �T���v�����O���̃N�I���e�B
        constant_data_desc.SampleDesc.Quality = 0;

        // �e�N�X�`�����C�A�E�g�̃I�v�V����
        constant_data_desc.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;

        // ���\�[�X�𑀍삷�邽�߂̃I�v�V����
        constant_data_desc.Flags = D3D12_RESOURCE_FLAG_NONE;


        // �萔�o�b�t�@�̃f�[�^�𐶐�
        if (FAILED(mpr_variable->s_frame_work.device->CreateCommittedResource(&constant_data_prop, D3D12_HEAP_FLAG_NONE, &constant_data_desc, D3D12_RESOURCE_STATE_GENERIC_READ, nullptr, IID_PPV_ARGS(&in_dx12_constant_setting->m_constant_buffer_data))))
        {
            return;
        }
    }
    

    // �� �萔�o�b�t�@�r���[�̐ݒ� �� //
    {
        // �� �ϐ��錾 �� //
        D3D12_CONSTANT_BUFFER_VIEW_DESC constant_buffer_view_desc = {};  // �萔�o�b�t�@�r���[�����p���
        

        // �萔�o�b�t�@��GPU�ł̃A�h���X
        constant_buffer_view_desc.BufferLocation = in_dx12_constant_setting->m_constant_buffer_data->GetGPUVirtualAddress();
        
        // �o�C�g��
        constant_buffer_view_desc.SizeInBytes = con_CONSTANT_BUFFER_ONE_BYTE * in_create_inform.m_list_size;


        // �萔�o�b�t�@�r���[�̐���
        mpr_variable->s_frame_work.device->CreateConstantBufferView(&constant_buffer_view_desc, in_dx12_constant_setting->m_constant_buffer_heap->GetCPUDescriptorHandleForHeapStart());
    }

    return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�e�N�X�`���p�̃r���[�ƃq�[�v�𐶐�����
// ����   �FC_DX12_Rendering_Texture_Setting_Inform * & �ݒ��̃e�N�X�`���p�̃f�[�^, const C_Create_Texture_Setting_Inform & �e�N�X�`���p�f�[�^�����p���(const)
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_System::M_Create_Texture_Resource_View_And_Heap(DX12INSTANCE::C_DX12_Rendering_Texture_Setting_Inform * & in_dx12_texture_setting, const CREATE::C_Create_Texture_Setting_Inform & in_create_inform)
{
    // �� �f�B�X�N���v�^�q�[�v�̐��� �� //
    {
        // �� �ϐ��錾 �� //
        D3D12_DESCRIPTOR_HEAP_DESC descriptor_heap_desc{};  // �e�N�X�`���p�̃q�[�v�̐����p���


        // �q�[�v�ŊǗ�����f�[�^�̊Ǘ�
        descriptor_heap_desc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;

        // �f�[�^��
        descriptor_heap_desc.NumDescriptors = 1;

        // �V�F�[�_�[����ҏW�ł��邩�ǂ���
        descriptor_heap_desc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;

        // �A�_�v�^�[�̃m�[�h��
        descriptor_heap_desc.NodeMask = 0;


        // �e�N�X�`���q�[�v�̐���
        if (FAILED(mpr_variable->s_frame_work.device->CreateDescriptorHeap(&descriptor_heap_desc, IID_PPV_ARGS(&in_dx12_texture_setting->mpr_variable.texture_heap))))
        {
            return;
        }
    }


    // ���@�f�B�X�N���v�^�r���[�̐��� �� //
    {
        // �� �ϐ��錾 �� //
        D3D12_SHADER_RESOURCE_VIEW_DESC resource_view_desc = {};  // �e�N�X�`���p���\�[�X�r���[�ݒ�p�\���̂̐ݒ�


        // �f�[�^�`��
        resource_view_desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;

        // ���\�[�X�̎��
        resource_view_desc.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2D;

        // MIPMAP���x��(���̐��l�ɉ����ăs�N�Z�������{�ɂȂ�)
        resource_view_desc.Texture2D.MipLevels = 1;

        // �~�b�v�}�b�v���ł��ׂ������ׂ̍���
        resource_view_desc.Texture2D.MostDetailedMip = 0;

        // �V�F�[�_�[�ւ̃}�b�s���O���@
        resource_view_desc.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;


        // �r���[�𐶐�����
        mpr_variable->s_frame_work.device->CreateShaderResourceView(in_dx12_texture_setting->mpr_variable.texture_data.Get(), &resource_view_desc, in_dx12_texture_setting->mpr_variable.texture_heap->GetCPUDescriptorHandleForHeapStart());
    }

    return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�e�N�X�`���p�̃f�[�^�𐶐�����
// ����   �FC_DX12_Rendering_Texture_Setting_Inform * & �ݒ��̃e�N�X�`���p�̃f�[�^, const C_Create_Texture_Setting_Inform & �e�N�X�`���p�f�[�^�����p���(const)
// �߂�l �F�߂�l�F�������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_DX12_System::M_Create_Texture_Resource(DX12INSTANCE::C_DX12_Rendering_Texture_Setting_Inform * & in_dx12_texture_setting, const CREATE::C_Create_Texture_Setting_Inform & in_create_inform)
{
    // �� �ϐ��錾 �� //
    D3D12_RESOURCE_DESC resource_desc_for_tex;  // �e�N�X�`�������p�̐ݒ�
    
    D3D12_HEAP_PROPERTIES heap_properties_setting;    // �q�[�v�ݒ�p�̏��


    // �������̏�����
    ZeroMemory(&heap_properties_setting, sizeof(heap_properties_setting));
    ZeroMemory(&resource_desc_for_tex, sizeof(resource_desc_for_tex));
    
    
    // �� �q�[�v�̐ݒ� �� //

    // �q�[�v�̓���̎��
    heap_properties_setting.Type = D3D12_HEAP_TYPE_CUSTOM;

    // CPU�̃��������y�[�W���O�ɂ���ĕ����̃������Ƃ��Ĉ����Ă��鎞�ɂǂ̂悤�ɂ��̃������ɃA�N�Z�X���邩
    heap_properties_setting.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_WRITE_BACK;

    // �������v�[��(�N�����Ɉ�C�ɃA�v���Ŏg�p����f�[�^���m�ۂ���ꏊ)�̎�ނ��w�肷��
    heap_properties_setting.MemoryPoolPreference = D3D12_MEMORY_POOL_L0;

    // �q�[�v�������𐶐�����m�[�h(GPU�╨���A�_�v�^�[)�̐�
    heap_properties_setting.CreationNodeMask = 1;

    // ���\�[�X�����݂���m�[�h�̐�(GPU�╨���A�_�v�^�[)�̐�
    heap_properties_setting.VisibleNodeMask = 1;


    // �� ���\�[�X�̐ݒ� �� //

    // �g�p����郊�\�[�X�̎��
    resource_desc_for_tex.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;

    // �ݒ肷�郊�\�[�X���̔z�u�ԍ�
    resource_desc_for_tex.Alignment = 0;

    // ���\�[�X�̃o�C�g��
    resource_desc_for_tex.Width = in_create_inform.pixel_width;
    in_dx12_texture_setting->mpr_variable.pix_size_x = in_create_inform.pixel_width;

    // ���\�[�X�̔z��ԍ�
    resource_desc_for_tex.Height = in_create_inform.pixel_height;
    in_dx12_texture_setting->mpr_variable.pix_size_y = in_create_inform.pixel_height;

    // ���\�[�X�̐[���A�܂��͔z��
    resource_desc_for_tex.DepthOrArraySize = 1;

    // MIPMAP���x��(���̐��l�ɉ����ăs�N�Z�������{�ɂȂ�)
    resource_desc_for_tex.MipLevels = 1;

    // ���\�[�X��DX12�����p�ӂ����^���ǂ���
    resource_desc_for_tex.Format = DXGI_FORMAT_R8G8B8A8_UNORM;

    // �� �T���v�����O�ݒ� �� //

    // �T���v�����O��
    resource_desc_for_tex.SampleDesc.Count = 1;

    // �T���v�����O���̃N�I���e�B
    resource_desc_for_tex.SampleDesc.Quality = 0;

    // �e�N�X�`�����C�A�E�g�̃I�v�V����
    resource_desc_for_tex.Layout = D3D12_TEXTURE_LAYOUT_UNKNOWN;

    // ���\�[�X�𑀍삷�邽�߂̃I�v�V����
    resource_desc_for_tex.Flags = D3D12_RESOURCE_FLAG_NONE;


    // ���\�[�X�𐶐�����    // ���s������G���[�Ŕ�����
    if (FAILED(mpr_variable->s_frame_work.device->CreateCommittedResource(&heap_properties_setting, D3D12_HEAP_FLAG_NONE, &resource_desc_for_tex, D3D12_RESOURCE_STATE_GENERIC_READ, nullptr, IID_PPV_ARGS(in_dx12_texture_setting->mpr_variable.texture_data.GetAddressOf()))))
    {
        return false;
    }

    return true;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���[�g�V�O�l�`���̃p�����[�^�̐ݒ���s��
// ����   �Fvector<D3D12_ROOT_PARAMETER> & �ݒ�惋�[�g�p�����[�^�[�̎Q��, vector<D3D12_DESCRIPTOR_RANGE> & �ݒ��̃����W�̎Q��, D3D12_DESCRIPTOR_RANGE_TYPE �ݒ肷����, int ���W�X�^�ԍ�, int �V�F�[�_�[�ԍ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
inline void Inline_Set_Root_Parameter(std::vector<D3D12_ROOT_PARAMETER> & in_root_param, std::vector<D3D12_DESCRIPTOR_RANGE> & in_range, D3D12_DESCRIPTOR_RANGE_TYPE in_set_type, int register_num, int shader_num)
{
    // �� �ϐ��錾 �� //
    int set_param_number = (int)in_root_param.size();    // �ݒ��̃p�����[�^�̔z��ԍ�
    int set_range_pos = (int)in_range.size();    // �ݒ��̃����W�ԍ�


    // �z���K�v�Ȃ������₷
    in_root_param.resize(set_param_number + 1);
    in_range.resize(set_range_pos + 1);

    // �p�����[�^�̎��
    in_range[set_range_pos].RangeType = in_set_type;

    // �����̒萔�o�b�t�@��e�N�X�`�������̃��W�X�^�ŊǗ����邩�i�z�񐔁j
    in_range[set_range_pos].NumDescriptors = 1;

    // �V�F�[�_�[�ł̃��W�X�^�ԍ�
    in_range[set_range_pos].BaseShaderRegister = register_num;

    // ���W�X�^�̃X�y�[�X�ԍ�
    in_range[set_range_pos].RegisterSpace = 0;

    // �����W���ŉ��o�C�g�ڂɃf�[�^�����邩
    in_range[set_range_pos].OffsetInDescriptorsFromTableStart = D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND;


    // �� �p�����[�^�ݒ� �� //

    // �X���b�g�̎��
    in_root_param[set_param_number].ParameterType = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;

    // �����W�̔z��
    in_root_param[set_param_number].DescriptorTable.NumDescriptorRanges = 1;

    // �����W�̃A�h���X
    in_root_param[set_param_number].DescriptorTable.pDescriptorRanges = &in_range[set_range_pos];

    // �ǂ̃V�F�[�_�[�ł��̃X���b�g���g����
    in_root_param[set_param_number].ShaderVisibility = (D3D12_SHADER_VISIBILITY)shader_num;

    return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���[�g�V�O�l�`���̃p�����[�^�̐ݒ���s��
// ����   �Fvector<D3D12_STATIC_SAMPLER_DESC> & �T���v���[�ݒ�p���, int ���W�X�^�ԍ�, int �V�F�[�_�[�ԍ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
inline void Inline_Set_Sampler_State(std::vector<D3D12_STATIC_SAMPLER_DESC> & in_sampler_desc, int in_register_num, int in_shader_num)
{
    // �� �ϐ��錾 �� //
    int set_static_number = (int)in_sampler_desc.size();    // �ݒ��̃p�����[�^�̔z��ԍ�


    // �z���K�v�Ȃ������₷
    in_sampler_desc.resize(set_static_number + 1);


    // �t�B���^�����̃I�v�V����
    in_sampler_desc[set_static_number].Filter = D3D12_FILTER_MIN_MAG_MIP_LINEAR;

    // U���W�̏����̎d��
    in_sampler_desc[set_static_number].AddressU = D3D12_TEXTURE_ADDRESS_MODE_WRAP;

    // V���W�̏����̎d��
    in_sampler_desc[set_static_number].AddressV = D3D12_TEXTURE_ADDRESS_MODE_WRAP;

    // W���W�̏����̎d��
    in_sampler_desc[set_static_number].AddressW = D3D12_TEXTURE_ADDRESS_MODE_WRAP;

    // �~�b�v�}�b�v���x���̃I�t�Z�b�g
    in_sampler_desc[set_static_number].MipLODBias = 0.0f;

    // �t�B���^��D3D12_FILTER_ANISOTROPIC�܂���D3D12_FILTER_COMPARISON_ANISOTROPIC�̂Ƃ��Ɏg�p�����N�����v�l
    in_sampler_desc[set_static_number].MaxAnisotropy = 16;

    // �T���v�����O���ꂽ�f�[�^�������̃T���v�����O �f�[�^�Ɣ�r����֐���I��
    in_sampler_desc[set_static_number].ComparisonFunc = D3D12_COMPARISON_FUNC_NEVER;

    // D3D12_TEXTURE_ADDRESS_MODE_BORDER��AddressUVW�ɐݒ肳��Ă��鎞�̋��E���̐F
    in_sampler_desc[set_static_number].BorderColor = D3D12_STATIC_BORDER_COLOR_TRANSPARENT_BLACK;

    // �~�b�v�}�b�v���x���̏ڍדx�̍Œ�l
    in_sampler_desc[set_static_number].MinLOD = 0.0f;

    // �~�b�v�}�b�v���x���̏ڍדx�̍ō��l
    in_sampler_desc[set_static_number].MaxLOD = D3D12_FLOAT32_MAX;

    // �V�F�[�_�[�ł̃��W�X�^�ԍ�
    in_sampler_desc[set_static_number].ShaderRegister = in_register_num;

    // ���W�X�^�̃X�y�[�X�ԍ�
    in_sampler_desc[set_static_number].RegisterSpace = 0;

    // �ǂ̃V�F�[�_�[����A�N�Z�X�ł��邩
    in_sampler_desc[set_static_number].ShaderVisibility = (D3D12_SHADER_VISIBILITY)in_shader_num;

    return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���[�g�V�O�l�`���f�X�N�Ƀf�B�X�N���v�^�X���b�g�ƃT���v���[��ݒ肷��
// ����   �FD3D12_ROOT_SIGNATURE_DESC & ���[�g�V�O�l�`���̐ݒ�p���̎Q��, vector<D3D12_ROOT_PARAMETER> & �f�B�X�N���v�^�ݒ�p���̎Q��, vector<D3D12_STATIC_SAMPLER_DESC> & �T���v���[�ݒ�p���̎Q��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
inline void Inline_Set_Parameters_And_Sampler_Desc_To_Root_Signature_Desc(D3D12_ROOT_SIGNATURE_DESC & in_root_signature, std::vector<D3D12_ROOT_PARAMETER> & in_parameter, std::vector<D3D12_STATIC_SAMPLER_DESC> & in_sampler)
{
    // �f�B�X�N���v�^��񂪂���΃f�B�X�N���v�^�X���b�g���ƍŏ��̃A�h���X���Z�b�g
    if (in_parameter.size() > 0)
    {
        in_root_signature.NumParameters = (UINT)in_parameter.size();
        in_root_signature.pParameters = &in_parameter[0];
    }

    // �Ȃ���΃[���N���A����
    else
    {
        in_root_signature.NumParameters = 0;
        in_root_signature.pParameters = nullptr;
    }


    // �T���v���[������΃T���v���[���ƍŏ��̃A�h���X���Z�b�g
    if (in_parameter.size() > 0)
    {
        in_root_signature.NumStaticSamplers = (UINT)in_parameter.size();
        in_root_signature.pStaticSamplers = &in_sampler[0];
    }

    // �Ȃ���΃[���N���A����
    else
    {
        in_root_signature.NumStaticSamplers = 0;
        in_root_signature.pStaticSamplers = nullptr;
    }

    return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�V�F�[�_�[�̃f�[�^��DX12�p�̃o�C�g�R�[�h�ɃZ�b�g����
// ����   �FD3D12_SHADER_BYTECODE & �Z�b�g��̃o�C�g�R�[�h�̎Q��, const C_Shader_Code * �Z�b�g����V�F�[�_�[�R�[�h
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
inline void Inline_Set_Shader_Data(D3D12_SHADER_BYTECODE & in_set_code, const ASSET::SHADER::C_Shader_Code * in_shader_code)
{
    // �V�F�[�_�[�̃R�[�h���Ȃ��Ȃ甲����
    if (in_shader_code == nullptr)
    {
        return;
    }

    // �o�C�g�R�[�h�̃A�h���X�ƃT�C�Y���Z�b�g
    in_set_code.pShaderBytecode = in_shader_code->M_Get_Compiled_Cord().get();
    in_set_code.BytecodeLength = in_shader_code->M_Get_Cord_Size();

    return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���[�g�V�O�l�`���f�X�N���烋�[�g�V�O�l�`�����V���A���C�Y����������
// ����   �Fconst D3D12_ROOT_SIGNATURE_DESC & ���[�g�V�O�l�`����ݒ肷�邽�߂̏��̎Q��(const), ComPtr<ID3D12RootSignature> & ���[�g�V�O�l�`���̐ݒ��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_DX12_System::M_Serialize_And_Creat_RootSignature_By_Desc(const D3D12_ROOT_SIGNATURE_DESC & in_root_signature_desc, Microsoft::WRL::ComPtr<ID3D12RootSignature> & in_root_signature)
{
    // �� �ϐ��錾 �� //
    ID3DBlob * root_signature_serialized_data = nullptr;    // ���[�g�����������̃V���A���C�Y�f�[�^�𓾂�


    // �� ���[�g�V�O�l�`�������p�������\�[�X�Ƃ��ăV���A���C�Y���� �� //		// ���s�ŃG���[���o��
    if (FAILED(D3D12SerializeRootSignature(&in_root_signature_desc, D3D_ROOT_SIGNATURE_VERSION_1, &root_signature_serialized_data, nullptr)))
    {
        // �f�o�b�O���͎��s���O���o��
#if _DEBUG
        DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
        DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, "���[�g�V�O�l�`���̃V���A���C�Y���Ɏ��s���܂���");
#endif // _DEBUG

        return false;
    }


    // �� ���[�g�V�O�l�`���̐��� �� //	// ���s�ŃG���[���o��
    if (FAILED(mpr_variable->s_frame_work.device->CreateRootSignature(0, root_signature_serialized_data->GetBufferPointer(), root_signature_serialized_data->GetBufferSize(), IID_PPV_ARGS((ID3D12RootSignature**)&in_root_signature))))
    {
        // �f�o�b�O���͎��s���O���o��
#if _DEBUG
        DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
        DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, "���[�g�V�O�l�`���̐����Ɏ��s���܂���");
#endif // _DEBUG

        return false;
    }


    // �f�o�b�O���͐������O���o��
#if _DEBUG
    DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
    DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED, "���[�g�V�O�l�`���̐����ɐ������܂���");
#endif // _DEBUG

    return true;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���[�g�V�O�l�`���𐶐�����
// ����   �FC_DX12_Rendering_Graphics_Setting_Inform * & �Z�b�g��̕`��p�C�v���C���p�f�[�^, const C_Create_Vertex_Buffer_Inform & �`��p�C�v���C���p�f�[�^�����p���(const)
// �߂�l �Fbool ��������true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_DX12_System::M_Create_Root_Signature(DX12INSTANCE::C_DX12_Rendering_Graphics_Setting_Inform * & in_dx12_pipeline_inform, const CREATE::C_Create_Rendering_Graphics_Setting_Inform & in_create_inform)
{
    // �� �ϐ��錾 �� //
    D3D12_ROOT_SIGNATURE_DESC root_signature_desc;	// ���[�g�����i�V�O�l�`���j�����p���

    std::vector<D3D12_STATIC_SAMPLER_DESC> static_sampler_desc; // �ÓI�T���v���[�����p���

    std::vector<D3D12_DESCRIPTOR_RANGE> range_setting_list;    // �L�q�q�͈̔͂�ݒ肷����

    std::vector<D3D12_ROOT_PARAMETER> paramater_setting_list;  // �e�N�X�`����萔�o�b�t�@��ݒ肷��ꏊ�̐����p���


    // �V�F�[�_�[���Ƀ��\�[�X���`����i�f�B�X�N���v�^�ƃ����W�A�T���v���[�𐶐�����j
    M_Create_Descriptor_And_Sampler_By_Shaders_Inform(in_create_inform.shader_setting->M_Get_Resource_Signature(), paramater_setting_list, range_setting_list, static_sampler_desc);


    // �� ���[�g�V�O�l�`���f�X�N�̐ݒ� �� //

    // ������
    ZeroMemory(&root_signature_desc, sizeof(root_signature_desc));

    // ���[�g�V�O�l�`���f�X�N�Ƀf�B�X�N���v�^�X���b�g�ƃT���v���[��ݒ肷��
    Inline_Set_Parameters_And_Sampler_Desc_To_Root_Signature_Desc(root_signature_desc, paramater_setting_list, static_sampler_desc);

    // ���[�g�����̃��C�A�E�g�I�v�V����
    root_signature_desc.Flags = D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT;


    // �� ���[�g�V�O�l�`���̐��� �� //

    // ���[�g�V�O�l�`���𐶐����Č��ʂ�Ԃ�
    return M_Serialize_And_Creat_RootSignature_By_Desc(root_signature_desc, in_dx12_pipeline_inform->m_root_signature);
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�p�C�v���C���X�e�[�g�𐶐�����
// ����   �FC_DX12_Rendering_Graphics_Setting_Inform * & �Z�b�g��̕`��p�C�v���C���p�f�[�^, const C_Create_Vertex_Buffer_Inform & �`��p�C�v���C���p�f�[�^�����p���(const)
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_DX12_System::M_Create_Pipeline_State(DX12INSTANCE::C_DX12_Rendering_Graphics_Setting_Inform * & in_dx12_pipeline_inform, const CREATE::C_Create_Rendering_Graphics_Setting_Inform & in_create_inform)
{
    // �� �ϐ��錾 �� //
    RENDERING::GRAPHICS::DX12::DX12INSTANCE::C_DX12_Input_Layout_Setting_System input_setting_system;    // ���̓��C�A�E�g�ݒ�p�V�X�e��

    D3D12_GRAPHICS_PIPELINE_STATE_DESC desc_pipeline_state; // �p�C�v���C���ݒ�p���

    D3D12_SHADER_BYTECODE * add_shader_list[] =    // �ݒ肷��V�F�[�_�[�̃A�h���X�̃��X�g
    {
        &desc_pipeline_state.VS,
        &desc_pipeline_state.HS,
        &desc_pipeline_state.DS,
        &desc_pipeline_state.GS,
        &desc_pipeline_state.PS,
    };


    // ������
    ZeroMemory(&desc_pipeline_state, sizeof(desc_pipeline_state));


    // �� ���[�g�V�O�l�`���̃Z�b�g �� //
    desc_pipeline_state.pRootSignature = in_dx12_pipeline_inform->m_root_signature.Get();


    // �V�F�[�_�[�̎�ނ��ƂɎw�肳�ꂽ�ԍ����Z�b�g
    {
        // �� �ϐ��錾 �� //
        const ASSET::SHADER::S_Shader_Byte_Code_List & shader_code_list = in_create_inform.shader_setting->M_Get_Shader_Code_List(); // �w�肳�ꂽ�V�F�[�_�[�Z�b�g�̃R�[�h�̃��X�g


        for (int now_shader_kind = 0; now_shader_kind < (int)ASSET::SHADER::E_SHADER_KIND::e_ALL; now_shader_kind++)
        {
            Inline_Set_Shader_Data(*add_shader_list[now_shader_kind], shader_code_list.list[now_shader_kind]);
        }
    }

    // �V�F�[�_�[�̏���ݒ�
    in_dx12_pipeline_inform->m_shader_setting = *in_create_inform.shader_setting;


    // �� ���̓��C�A�E�g�̐ݒ� �� //
    input_setting_system.M_Create_Input_Layout_By_Create_Inform(desc_pipeline_state.InputLayout, in_create_inform.shader_setting->M_Get_Input_Layout());


    // �� �X�g���[�~���O�o�̓o�b�t�@ �� //
    RENDERING::GRAPHICS::DX12::DX12INSTANCE::C_DX12_Streaming_Output_Buffer_Base::M_Do_Not_Use_Setting(desc_pipeline_state);


    // �� �u�����h��Ԑݒ� �� //
    RENDERING::GRAPHICS::DX12::DX12INSTANCE::C_DX12_Blend_State_Setting_System::M_Set_Blend_State_By_Inform(desc_pipeline_state, in_create_inform);


    // �� �����_�[�^�[�Q�b�g�ōX�V�����T���v���� �� //
    desc_pipeline_state.SampleMask = UINT_MAX;


    // �� ���X�^���C�U�[�ݒ�i�摜�ϊ����̐ݒ�j �� //
    RENDERING::GRAPHICS::DX12::DX12INSTANCE::C_DX12_Rasterrizer_State_Setting_System::M_Law_Cost_Setting(desc_pipeline_state);


    // �� �[�x�X�e���V���ݒ� �� //
    RENDERING::GRAPHICS::DX12::DX12INSTANCE::C_DX12_Stencil_State_Setting_System::M_Disabled_Depth_Stencil(desc_pipeline_state);


    // �� �\�����̖ʂ̐[�x�X�e���V���e�X�g�ݒ� �� //    // �@�����J�����̕��������Ă��邩�ǂ����Ŕ��肷��
    RENDERING::GRAPHICS::DX12::DX12INSTANCE::C_DX12_Stencil_State_Setting_System::M_Test_Keep_Setting(desc_pipeline_state.DepthStencilState.FrontFace);


    // �� �������̖ʂ̐[�x�X�e���V���e�X�g�ݒ� �� //    // �@�����J�����̕��������Ă��邩�ǂ����Ŕ��肷��
    RENDERING::GRAPHICS::DX12::DX12INSTANCE::C_DX12_Stencil_State_Setting_System::M_Test_Keep_Setting(desc_pipeline_state.DepthStencilState.BackFace);


    // �� �}���`�T���v�����O�ݒ� �� //
    RENDERING::GRAPHICS::DX12::DX12INSTANCE::C_DX12_Sampling_Setting_System::M_Sampling_Setting(desc_pipeline_state, in_create_inform.sampling_setting.sampling_count, in_create_inform.sampling_setting.sampling_quality, 0);


    // �� �p�C�v���C���X�e�[�g�̎擾�p�̐ݒ� �� //
    RENDERING::GRAPHICS::DX12::DX12INSTANCE::C_DX12_Cached_PSO_Base::M_Cashe_Nothing(desc_pipeline_state);


    // �� �p�C�v���C������ �� //  // �G���[�Ȃ甲����
    if (FAILED(mpr_variable->s_frame_work.device->CreateGraphicsPipelineState(&desc_pipeline_state, IID_PPV_ARGS(&in_dx12_pipeline_inform->m_pipeline_state_setting))))
    {
        // �f�o�b�O���͎��s�����m
#if _DEBUG
        DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
        DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, "�p�C�v���C���X�e�[�g�̐����Ɏ��s���܂���");
#endif // _DEBUG

        return false;
    }


    // �f�o�b�O���͐������O���o��
#if _DEBUG
    DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
    DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED, "�p�C�v���C���X�e�[�g�̐����ɐ������܂���");
#endif // _DEBUG


    // �ݒ�p�̏����N���[�Y
    input_setting_system.M_Close_Input_Layout_Inform();

    return true;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�V�F�[�_�[���Ƀ��\�[�X���`����i�f�B�X�N���v�^�ƃ����W�A�T���v���[�𐶐�����j
// ����   �Fconst S_All_Shader_Resource_Signatures & �V�F�[�_�[�̃��\�[�X���ʏ��̎Q��, vector<D3D12_ROOT_PARAMETER> & �f�B�X�N���v�^�ݒ�p���̎Q��, vector<D3D12_DESCRIPTOR_RANGE> & �����W�̐ݒ�p���̎Q��, vector<D3D12_STATIC_SAMPLER_DESC> & �T���v���[�ݒ�p���̎Q��
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_System::M_Create_Descriptor_And_Sampler_By_Shaders_Inform(const ASSET::SHADER::S_All_Shader_Resource_Signatures & in_shader_inform, std::vector<D3D12_ROOT_PARAMETER> & in_root_param, std::vector<D3D12_DESCRIPTOR_RANGE> & in_range, std::vector<D3D12_STATIC_SAMPLER_DESC> & in_sampler)
{
    // �� �ϐ��錾 �� //
    int shader_paramater_register_start = 0;    // �V�F�[�_�[�̃f�B�X�N���v�^�̊J�n���W�X�^�ԍ�
    int shader_sampler_register_start = 0;      // �V�F�[�_�[�̃T���v���[�̊J�n���W�X�^�ԍ�


    // �� �S�ẴV�F�[�_�[�ɋ��ʂ�����̐ݒ� �� //
    {
        // �� �ϐ��錾 �� //
        int constant_buffer_sum = (int)in_shader_inform.all_shader_signature.constant_data.size();   // �萔�o�b�t�@��
        int texture_sum = (int)in_shader_inform.all_shader_signature.texture_data.size();   // �e�N�X�`�����\�[�X��
        int sampler_sum = in_shader_inform.all_shader_signature.sampler_sum;   // �T���v���[��
        

        // �V�F�[�_�[�̒萔�o�b�t�@���J��Ԃ�
        for (int now_csv_num = 0; now_csv_num < constant_buffer_sum; now_csv_num++)
        {
            Inline_Set_Root_Parameter(in_root_param, in_range, D3D12_DESCRIPTOR_RANGE_TYPE_CBV, shader_paramater_register_start, D3D12_SHADER_VISIBILITY::D3D12_SHADER_VISIBILITY_ALL);

            shader_paramater_register_start += 1;
        }

        // �V�F�[�_�[�̃e�N�X�`���f�[�^���J��Ԃ�
        for (int now_texture_num = 0; now_texture_num < texture_sum; now_texture_num++)
        {
            Inline_Set_Root_Parameter(in_root_param, in_range, D3D12_DESCRIPTOR_RANGE_TYPE_SRV, shader_paramater_register_start, D3D12_SHADER_VISIBILITY::D3D12_SHADER_VISIBILITY_ALL);

            shader_paramater_register_start += 1;
        }


        // �T���v���[���J��Ԃ�
        for (int now_sampler_num = 0; now_sampler_num < sampler_sum; now_sampler_num++)
        {
            Inline_Set_Sampler_State(in_sampler, shader_sampler_register_start, D3D12_SHADER_VISIBILITY::D3D12_SHADER_VISIBILITY_ALL);

            shader_sampler_register_start += 1;
        }
    }


    // �� �V�F�[�_�[���Ƀf�B�X�N���v�^�̐ݒ� �� //
    for (int now_shader_kind = 0; now_shader_kind < (int)ASSET::SHADER::E_SHADER_KIND::e_ALL; now_shader_kind++)
    {
        // �� �ϐ��錾 �� //
        int constant_buffer_sum = (int)in_shader_inform.signature_list[now_shader_kind].constant_data.size();   // �萔�o�b�t�@��
        int texture_sum = (int)in_shader_inform.signature_list[now_shader_kind].texture_data.size();   // �e�N�X�`�����\�[�X��
        int sampler_sum = (int)in_shader_inform.signature_list[now_shader_kind].sampler_sum;   // �T���v���[��
        int set_param_register_num = shader_paramater_register_start; // �ݒ肷�郌�W�X�^�ԍ�
        int set_sampler_register_num = shader_sampler_register_start; // �ݒ肷�郌�W�X�^�ԍ�


        // �V�F�[�_�[�̒萔�o�b�t�@���J��Ԃ�
        for (int now_csv_num = 0; now_csv_num < constant_buffer_sum; now_csv_num++)
        {
            Inline_Set_Root_Parameter(in_root_param, in_range, D3D12_DESCRIPTOR_RANGE_TYPE_CBV, set_param_register_num, now_shader_kind + 1);  // D3D12_SHADER_VISIBILITY�ł�VERTEX_BUFFER��1����Ȃ̂ō��킹�邽�߂�1���Z

            set_param_register_num += 1;
        }

        // �V�F�[�_�[�̃e�N�X�`���f�[�^���J��Ԃ�
        for (int now_texture_num = 0; now_texture_num < texture_sum; now_texture_num++)
        {
            Inline_Set_Root_Parameter(in_root_param, in_range, D3D12_DESCRIPTOR_RANGE_TYPE_SRV, set_param_register_num, now_shader_kind + 1);

            set_param_register_num += 1;
        }

        // �T���v���[���J��Ԃ�
        for (int now_sampler_num = 0; now_sampler_num < sampler_sum; now_sampler_num++)
        {
            Inline_Set_Sampler_State(in_sampler, set_sampler_register_num, now_shader_kind + 1);

            set_sampler_register_num += 1;
        }
    }

    return;
}


//-��- �X�V -��-//

//-��- �f�o�b�O -��-//
#if _DEBUG
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�o�b�O���̂ݍs���X�V
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_System::M_Debug_Update(void)
{
    // �� �E�B���h�E�^�C�g�����e�X�g�p�ɍX�V �� //
    //OS::BASE::C_OS_System_Base::m_this_instance->M_Set_Window_Title();

    return;
}
#endif // _DEBUG


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���\�[�X�����p�o���A�̃Z�b�g
// ����   �FD3D12_RESOURCE_STATES �؂�ւ��O�̎g�p�@, D3D12_RESOURCE_STATES �؂�ւ��̌�̎g�p�@
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_System::M_Set_Resource_Barrier(D3D12_RESOURCE_STATES in_before, D3D12_RESOURCE_STATES in_after)
{
    // �� �ϐ��錾 �� //
    D3D12_RESOURCE_BARRIER desc_resource_barrier;   // ���\�[�X�o���A�ݒ�p���


    // ������
    ZeroMemory(&desc_resource_barrier, sizeof(desc_resource_barrier));

    // ���\�[�X�o���A�̎��
    desc_resource_barrier.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;

    // ���\�[�X�ւ̃A�h���X
    desc_resource_barrier.Transition.pResource = mpr_variable->s_render.rtv.render_buffer[mpr_variable->s_command.num_back_screen].Get();

    // �T�u���\�[�X�̃C���f�b�N�X
    desc_resource_barrier.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;

    // �؂�ւ��O�̎g�p�@�Z�b�g
    desc_resource_barrier.Transition.StateBefore = in_before;

    // �؂�ւ���̎g�p�@�Z�b�g
    desc_resource_barrier.Transition.StateAfter = in_after;


    // �o���A�̃Z�b�g
    mpr_variable->s_command.list->ResourceBarrier(1, &desc_resource_barrier);
    
    return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F��ʂ��N���A����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_System::M_Clear_Screen(void)
{
    // �����_�[�^�[�Q�b�g�̉�ʏ��N���A
    mpr_variable->s_command.list->ClearRenderTargetView(mpr_variable->s_render.rtv.handle[mpr_variable->s_command.num_back_screen], mpr_variable->s_frame_work.clear_color, 0, nullptr);

    // �[�x�X�e���V���̏�����
    mpr_variable->s_command.list->ClearDepthStencilView(mpr_variable->s_render.dsv.handle, D3D12_CLEAR_FLAG_DEPTH, 1.0f, 0, 0, nullptr);

    //  �r���[�̃o�C���h
    mpr_variable->s_command.list->OMSetRenderTargets(1, &mpr_variable->s_render.rtv.handle[mpr_variable->s_command.num_back_screen], TRUE, &mpr_variable->s_render.dsv.handle);

    return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�R�}���h���s�҂�
// ����   �FID3D12Resource * ���\�[�X�ւ̃A�h���X, D3D12_RESOURCE_STATES �T�u���\�[�X�����̑O�̎g�p�@, D3D12_RESOURCE_STATES �T�u���\�[�X�����̌�̎g�p�@
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_System::M_Wait_For_Command_Queue(void)
{
    // �� �ϐ��錾 �� //
    static int fence_value = 1;  // �t�F���X�̃C���N�������g�𔻒肷�邽�߂̒l
    
    UINT64 result_fence = fence_value; // ���ʂ̃t�F���X�l���󂯎��


    // ���̃t�F���X�l���󂯎��
    mpr_variable->s_command.queue->Signal(mpr_variable->s_render.queue_fence.Get(), result_fence);


    // ����p�̃t�F���X�l���C���N�������g
    fence_value += 1;


    // �� �܂��R�}���h�L���[���I�����Ă��Ȃ����Ƃ��m�F���� �� //
    if (mpr_variable->s_render.queue_fence->GetCompletedValue() < result_fence)
    {
        // ����Fence�ɂ����āAfvalue �̒l�ɂȂ�����t�F���X�C�x���g�����s
        mpr_variable->s_render.queue_fence->SetEventOnCompletion(result_fence, mpr_variable->s_render.fence_event);


        // �C�x���g�����΂���܂ő҂�
        WaitForSingleObject(mpr_variable->s_render.fence_event, INFINITE);
    }

    return;
}

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�r���[�|�[�g�ƃV�U�[�̐ݒ���s��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_System::M_Set_Scissor_And_View_Port(void)
{
    // �� �ϐ��錾 �� //
    D3D12_VIEWPORT view_port = {};	// �r���[�|�[�g�p�����[�^

    D3D12_RECT scissor_rect = {};	// �V�U�[���N�g


    // �� �r���[�|�[�g�ݒ� �� //

    // ��ʃT�C�Y
    view_port.Width = OS::C_OS_System_Base::M_Get_Instance()->M_Get_Window_Size().width;
    view_port.Height = OS::C_OS_System_Base::M_Get_Instance()->M_Get_Window_Size().height;

    // ��ʂ̍�����W
    view_port.TopLeftX = 0.0f;
    view_port.TopLeftY = 0.0f;

    // �[�x�ݒ�
    view_port.MinDepth = 0.0f;
    view_port.MaxDepth = 1.0f;


    // �� �V�U�[���N�g�ݒ� �� //

    // ���W�ݒ�
    scissor_rect.left = 0;
    scissor_rect.right = (LONG)view_port.Width;
    scissor_rect.top = 0;
    scissor_rect.bottom = (LONG)view_port.Height;


    // ��ʃT�C�Y�X�V
    mpr_variable->s_command.list->RSSetViewports(1, &view_port);
    mpr_variable->s_command.list->RSSetScissorRects(1, &scissor_rect);

    return;
}

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�`��R�}���h�������Z�b�g����
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_System::M_Reset_Command(void)
{
    // �R�}���h�A���P�[�^�̃����������������čė��p�\�ɂ���
    mpr_variable->s_command.allocator->Reset();

    // �R�}���h���X�g��������ԂɃ��Z�b�g�i��������Ȃ��Ə������݉\�ɂȂ�Ȃ��j
    mpr_variable->s_command.list->Reset(mpr_variable->s_command.allocator.Get(), nullptr);

    return;
}


//-��- ���ʗp��� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�p�C�v���C���������ɃV�F�[�_�[�̃��\�[�X���ʖ����Z�b�g����
// ����   �Fconst C_DX12_Rendering_Graphics_Setting_Inform * & �p�C�v���C�����
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_System::M_Set_Shader_Resource_Signature_By_Rendering_Setting(const DX12INSTANCE::C_DX12_Rendering_Graphics_Setting_Inform * & in_rendering_setting)
{
    mpr_variable->shader_resource_list.release();
    mpr_variable->shader_resource_list.reset(&in_rendering_setting->m_shader_setting.M_Get_Resource_Signature());

    return;
}


//-��- ��� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�@�\���x���𕶎���ɕϊ�����
// ����   �FD3D_FEATURE_LEVEL �@�\���x���w��p��
// �߂�l �Fstd::string �ϊ���̕�����
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
std::string C_DX12_System::M_Convert_D3D_FEATURE_LEVEL_Enum_To_String(D3D_FEATURE_LEVEL in_feature_level)
{
    // �� �@�\���x���ŕ��� �� //
    switch (in_feature_level)
    {
        // �R���s���[�e�B���O��p���f��
    case D3D_FEATURE_LEVEL_1_0_CORE:
        return "D3D_FEATURE_LEVEL_1_0_CORE";

        // DirectX9
    case D3D_FEATURE_LEVEL_9_1:
        return "D3D_FEATURE_LEVEL_9_1";
    case D3D_FEATURE_LEVEL_9_2:
        return "D3D_FEATURE_LEVEL_9_2";
    case D3D_FEATURE_LEVEL_9_3:
        return "D3D_FEATURE_LEVEL_9_3";

        // DirectX10
    case D3D_FEATURE_LEVEL_10_0:
        return "D3D_FEATURE_LEVEL_10_0";
    case D3D_FEATURE_LEVEL_10_1:
        return "D3D_FEATURE_LEVEL_10_1";

        // DirectX11
    case D3D_FEATURE_LEVEL_11_0:
        return "D3D_FEATURE_LEVEL_11_0";
    case D3D_FEATURE_LEVEL_11_1:
        return "D3D_FEATURE_LEVEL_11_1";

        // DirectX12
    case D3D_FEATURE_LEVEL_12_0:
        return "D3D_FEATURE_LEVEL_12_0";
    case D3D_FEATURE_LEVEL_12_1:
        return "D3D_FEATURE_LEVEL_12_1";
    case D3D_FEATURE_LEVEL_12_2:
        return "D3D_FEATURE_LEVEL_12_2";
    }

    // ����`�̔ԍ�
    return "Undefined";
}


//==��  �p�u���b�N  ��==//

//-��-  �������ƏI����  -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FDX12�V�X�e���̏�����
// ����   �Fvoid
// �߂�l �Fbool �����グ�ɐ������Ă�����true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_DX12_System::M_Set_Up(void)
{
	// DX12�V�X�e���̏�����
	if (M_DirectX12_Init() == false)
	{
        // �� �f�o�b�O���̂݃Z�b�g�A�b�v���s��ʒm �� //
#if _DEBUG
        DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_BLACK, DEBUGGER::LOG::E_LOG_COLOR::e_RED);
        DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_FAILED, "Error-��-��-��-��-��-��-��-DX12�̃Z�b�g�A�b�v���s-��-��-��-��-��-��-��-Error");
#endif // _DEBUG

		return false;	// ���s�Ȃ�G���[��Ԃ��Ĕ�����
	}


    // �� �f�o�b�O���̂݃Z�b�g�A�b�v������ʒm �� //
#if _DEBUG
    DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_BLACK, DEBUGGER::LOG::E_LOG_COLOR::e_GREEN);
    DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::DX12::con_SET_UP_SUCCEEDED, "-��-��-��-��-��-��-��-DX12�̃Z�b�g�A�b�v����-��-��-��-��-��-��-��-");
    DEBUGGER::LOG::C_Log_System::M_Stop_Update_And_Log_Present();
    DEBUGGER::LOG::C_Log_System::M_Console_LOG_Flush();
#endif // _DEBUG

	// ��������
	return true;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �FDX12�𐶐����鏈��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_System::M_Create_DirectX12(void)
{
    // �� �������ăZ�b�g �� //   // ���ɐ������Ă����f�[�^�͏������
    m_this.reset(new C_DX12_System);

    return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_System::M_Release(void)
{
    // ������Ȃ�Ή��
    if (mpr_variable)
    {
        CloseHandle(mpr_variable->s_render.fence_event);
        mpr_variable.reset();
    }
    
    mpr_variable->shader_resource_list.release();

    return;
}

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�f�X�g���N�^
// ����   �Fvoid
// �߂�l �F�Ȃ�
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
C_DX12_System::~C_DX12_System()
{
    M_Release();

	return;
}


//-��- �����_�����O -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�`��J�n�p�̏����A�R�}���h��������������ʂ̃��\�[�X�𓯊����������_�[�^�[�Q�b�g��Ɏw�肷��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_System::M_Rendering_Start(void)
{
    // �� �R�}���h������ �� //
    M_Reset_Command();


    // �`���̉�ʂ���肷��(����ʂ��w��)
    mpr_variable->s_command.num_back_screen = mpr_variable->s_frame_work.swap_chain->GetCurrentBackBufferIndex();


    // ���\�[�X�����p�̃o���A��`�揑�����ݗp�ɕύX (�ύX����������܂ő҂�)
    M_Set_Resource_Barrier(D3D12_RESOURCE_STATE_PRESENT, D3D12_RESOURCE_STATE_RENDER_TARGET);


    // �r���[�|�[�g�ƃV�U�[�̍X�V
    M_Set_Scissor_And_View_Port();


    // ��ʃN���A
    M_Clear_Screen();

    return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���̕`����s���J�n����
// ����   �Fconst unique_ptr<C_Rendering_Graphics_Setting_Inform_Base> & �Z�b�g���郌���_�����O�̐ݒ�̏��(const)
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_System::M_Rendering_Set_Rendering_Setting(const std::unique_ptr<INSTANCE::C_Rendering_Graphics_Setting_Inform_Base> & in_pipeline_inform)
{
    // �� �ϐ��錾 �� //
    const DX12INSTANCE::C_DX12_Rendering_Graphics_Setting_Inform * dx12_pipeline_inform = reinterpret_cast<const DX12INSTANCE::C_DX12_Rendering_Graphics_Setting_Inform * > (in_pipeline_inform.get());   // �`��p�C�v���C���p����DX12�p�փL���X�g�������ʂ̃A�h���X


    // �`�悷��}�`��ݒ�
    mpr_variable->s_command.list->IASetPrimitiveTopology(dx12_pipeline_inform->m_topology_type);

    // ���[�g�V�O�l�`���̃Z�b�g
    mpr_variable->s_command.list->SetGraphicsRootSignature(dx12_pipeline_inform->m_root_signature.Get());

    // �p�C�v���C���X�e�[�g��ݒ肷��
    mpr_variable->s_command.list->SetPipelineState(dx12_pipeline_inform->m_pipeline_state_setting.Get());


    // ���ʗp����ݒ肷��
    M_Set_Shader_Resource_Signature_By_Rendering_Setting(dx12_pipeline_inform);

    return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�萔�f�[�^���Z�b�g����
// ����   �FS_Constant_Buffer_Drawing_Setting & �Z�b�g����萔�f�[�^���
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_System::M_Rendering_Set_Constant_Buffer(INSTANCE::S_Constant_Buffer_Drawing_Setting & in_constant_inform)
{
    // �� �ϐ��錾 �� //
    DX12INSTANCE::C_DX12_Constant_Setting_Inform * dx12_constant_inform = reinterpret_cast<DX12INSTANCE::C_DX12_Constant_Setting_Inform*>(in_constant_inform.add_constant_buffer);   // �`��p����DX12�p�փL���X�g�������ʂ̃A�h���X

    int slot_number = 0;    // �萔�o�b�t�@�ݒ��̃X���b�g�ԍ�

    bool flg_slot_exist = false;    // �X���b�g�𔭌��ł������ǂ����̃t���O


    // �S�V�F�[�_�[���ʂ̒萔�o�b�t�@�ɏ�������
    if (*in_constant_inform.add_attach_shader_kind == ASSET::SHADER::E_SHADER_KIND::e_ALL)
    {
        // �� �ϐ��錾 �� //
        int constant_slot_sum = (int)mpr_variable->shader_resource_list->all_shader_signature.constant_data.size();   // �萔�o�b�t�@��


        // �萔�o�b�t�@�̃X���b�g�����J��Ԃ��A�����񂪈�v�����甭���ł����̂Ŕԍ����w�肵�ă��[�v�𔲂���
        for (int l_now_slot_number = 0; l_now_slot_number < constant_slot_sum && flg_slot_exist == false; l_now_slot_number++)
        {
            if (mpr_variable->shader_resource_list->all_shader_signature.constant_data[l_now_slot_number].signature_name == *in_constant_inform.add_signature_name)
            {
                slot_number = l_now_slot_number;

                flg_slot_exist = true;
            }
        }
    }

    // �e�V�F�[�_�[�ɗp�ӂ���Ă���萔�o�b�t�@�ɏ�������
    else
    {
        // �� �ϐ��錾 �� //
        int constant_slot_sum = (int)mpr_variable->shader_resource_list->signature_list[(int)*in_constant_inform.add_attach_shader_kind].constant_data.size();   // �萔�o�b�t�@�̃X���b�g��
        int slot_skipped = 0;   // �ʉ߂����X���b�g��


        // �S�ẴV�F�[�_�[�ɋ��ʂ���X���b�g�͔�΂�
        slot_skipped = (int)mpr_variable->shader_resource_list->all_shader_signature.constant_data.size();
        slot_skipped += (int)mpr_variable->shader_resource_list->all_shader_signature.texture_data.size();


        // ���̃V�F�[�_�[�p�̃X���b�g�͔�΂�
        for (int now_shader_kind = 0; now_shader_kind < (int)*in_constant_inform.add_attach_shader_kind; now_shader_kind++)
        {
            slot_skipped += (int)mpr_variable->shader_resource_list->signature_list[(int)*in_constant_inform.add_attach_shader_kind].constant_data.size();
            slot_skipped += (int)mpr_variable->shader_resource_list->signature_list[(int)*in_constant_inform.add_attach_shader_kind].texture_data.size();
        }


        // �萔�o�b�t�@�̃X���b�g�����J��Ԃ��A�����񂪈�v�����甭���ł����̂Ŕԍ����w�肵�ă��[�v�𔲂���
        for (int l_slot_number = 0; l_slot_number < constant_slot_sum && flg_slot_exist == false; l_slot_number++)
        {
            if (mpr_variable->shader_resource_list->signature_list[(int)*in_constant_inform.add_attach_shader_kind].constant_data[l_slot_number].signature_name == *in_constant_inform.add_signature_name)
            {
                slot_number = l_slot_number + slot_skipped;

                flg_slot_exist = true;
            }
        }
    }


    // �X���b�g���݂���Ȃ������甲����
    if (flg_slot_exist == false)
    {
        return;
    }


    // �萔�o�b�t�@�p�q�[�v�̃Z�b�g
    mpr_variable->s_command.list->SetDescriptorHeaps(1, &dx12_constant_inform->m_constant_buffer_heap);

    // ���[�g�V�O�l�`���ɒ萔�o�b�t�@��R�t����
    mpr_variable->s_command.list->SetGraphicsRootDescriptorTable(slot_number, dx12_constant_inform->m_constant_buffer_heap->GetGPUDescriptorHandleForHeapStart());

    return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�C���f�b�N�X�ԍ��̃X���b�g�ɒ萔�f�[�^���Z�b�g����
// ����   �Funique_ptr<C_Constant_Buffer_Setting_Inform_Base> & �萔�o�b�t�@�f�[�^, int �Z�b�g��̃C���f�b�N�X�ԍ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_System::M_Rendering_Set_Constant_Buffer_By_Index(std::unique_ptr<INSTANCE::C_Constant_Buffer_Setting_Inform_Base> & in_constant_buffer, int in_set_index_slot_num)
{
    // �� �ϐ��錾 �� //
    DX12::DX12INSTANCE::C_DX12_Constant_Setting_Inform * dx12_constant_buffer = reinterpret_cast<DX12::DX12INSTANCE::C_DX12_Constant_Setting_Inform * >(in_constant_buffer.get());    // �萔�o�b�t�@����DX12�p�փL���X�g�������ʂ̃A�h���X


    // �萔�o�b�t�@�p�q�[�v�̃Z�b�g
    mpr_variable->s_command.list->SetDescriptorHeaps(1, &dx12_constant_buffer->m_constant_buffer_heap);

    // ���[�g�V�O�l�`���ɒ萔�o�b�t�@��R�t����
    mpr_variable->s_command.list->SetGraphicsRootDescriptorTable(in_set_index_slot_num, dx12_constant_buffer->m_constant_buffer_heap->GetGPUDescriptorHandleForHeapStart());

    return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�e�N�X�`���f�[�^���Z�b�g����
// ����   �FS_Texture_Buffer_Drawing_Setting & �Z�b�g����e�N�X�`���f�[�^���
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_System::M_Rendering_Set_Texture(INSTANCE::S_Texture_Buffer_Drawing_Setting & in_texture_inform)
{
    // �� �ϐ��錾 �� //
    DX12INSTANCE::C_DX12_Rendering_Texture_Setting_Inform * dx12_texture_inform = reinterpret_cast<DX12INSTANCE::C_DX12_Rendering_Texture_Setting_Inform*>(in_texture_inform.add_texture_data); // �`��p����DX12�p�փL���X�g�������ʂ̃A�h���X

    int slot_number = 0;    // �e�N�X�`���f�[�^�ݒ��̃X���b�g�ԍ�

    bool flg_slot_exist = false;    // �X���b�g�𔭌��ł������ǂ����̃t���O


    // �S�V�F�[�_�[���ʂ̃e�N�X�`���ɏ�������
    if (*in_texture_inform.add_attach_shader_kind == ASSET::SHADER::E_SHADER_KIND::e_ALL)
    {
        // �� �ϐ��錾 �� //
        int texture_slot_sum = (int)mpr_variable->shader_resource_list->all_shader_signature.texture_data.size();   // �e�N�X�`����
        int slot_skipped = 0;   // �ʉ߂����X���b�g��


        // �萔�o�b�t�@�p�̃X���b�g�͔�΂�
        slot_skipped = (int)mpr_variable->shader_resource_list->all_shader_signature.constant_data.size();


        // �e�N�X�`���̃X���b�g�����J��Ԃ��A�����񂪈�v�����甭���ł����̂Ŕԍ����w�肵�ă��[�v�𔲂���
        for (int l_slot_number = 0; l_slot_number < texture_slot_sum && flg_slot_exist == false; l_slot_number++)
        {
            if (mpr_variable->shader_resource_list->all_shader_signature.texture_data[l_slot_number].signature_name == *in_texture_inform.add_signature_name)
            {
                slot_number = l_slot_number + slot_skipped;

                flg_slot_exist = true;
            }
        }
    }

    // �e�V�F�[�_�[�ɗp�ӂ���Ă���e�N�X�`���ɏ�������
    else
    {
        // �� �ϐ��錾 �� //
        int texture_slot_sum = (int)mpr_variable->shader_resource_list->signature_list[(int)*in_texture_inform.add_attach_shader_kind].texture_data.size();   // �e�N�X�`���̃X���b�g��
        int slot_skipped = 0;   // �ʉ߂����X���b�g��


        // �S�ẴV�F�[�_�[�ɋ��ʂ���X���b�g�͔�΂�
        slot_skipped = (int)mpr_variable->shader_resource_list->all_shader_signature.constant_data.size();
        slot_skipped += (int)mpr_variable->shader_resource_list->all_shader_signature.texture_data.size();


        // ���̃V�F�[�_�[�p�̃X���b�g�͔�΂�
        for (int now_shader_kind = 0; now_shader_kind < (int)*in_texture_inform.add_attach_shader_kind; now_shader_kind++)
        {
            slot_skipped += (int)mpr_variable->shader_resource_list->signature_list[now_shader_kind].constant_data.size();
            slot_skipped += (int)mpr_variable->shader_resource_list->signature_list[now_shader_kind].texture_data.size();
        }


        // �萔�o�b�t�@�p�̃X���b�g�͔�΂�
        slot_skipped += (int)mpr_variable->shader_resource_list->signature_list[(int)*in_texture_inform.add_attach_shader_kind].constant_data.size();


        // �e�N�X�`���̃X���b�g�����J��Ԃ��A�����񂪈�v�����甭���ł����̂Ŕԍ����w�肵�ă��[�v�𔲂���
        for (int l_slot_number = 0; l_slot_number < texture_slot_sum && flg_slot_exist == false; l_slot_number++)
        {
            if (mpr_variable->shader_resource_list->signature_list[(int)*in_texture_inform.add_attach_shader_kind].texture_data[l_slot_number].signature_name == *in_texture_inform.add_signature_name)
            {
                slot_number = l_slot_number + slot_skipped;

                flg_slot_exist = true;
            }
        }
    }


    // �X���b�g���݂���Ȃ������甲����
    if (flg_slot_exist == false)
    {
        return;
    }


    // �e�N�X�`���̊Ǘ��p�̖؍\�����Z�b�g����
    mpr_variable->s_command.list->SetDescriptorHeaps(1, &dx12_texture_inform->mpr_variable.texture_heap);

    // ���[�g�V�O�l�`���ƃe�N�X�`���p�̃f�[�^��R�Â���
    mpr_variable->s_command.list->SetGraphicsRootDescriptorTable(slot_number, dx12_texture_inform->mpr_variable.texture_heap->GetGPUDescriptorHandleForHeapStart());

    return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�C���f�b�N�X�ԍ��̃X���b�g�Ƀe�N�X�`���̃f�[�^���Z�b�g����
// ����   �Funique_ptr<C_Rendering_Texture_Setting_Inform_Base> & �e�N�X�`���f�[�^, int �Z�b�g��̃C���f�b�N�X�ԍ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_System::M_Rendering_Set_Texture_By_Index(std::unique_ptr<INSTANCE::C_Rendering_Texture_Setting_Inform_Base> & in_texture, int in_set_index_slot_num)
{
    // �� �ϐ��錾 �� //
    DX12::DX12INSTANCE::C_DX12_Rendering_Texture_Setting_Inform * dx12_texture = reinterpret_cast<DX12::DX12INSTANCE::C_DX12_Rendering_Texture_Setting_Inform * >(in_texture.get());    // �e�N�X�`������DX12�p�փL���X�g�������ʂ̃A�h���X


    // �e�N�X�`���p�q�[�v�̃Z�b�g
    mpr_variable->s_command.list->SetDescriptorHeaps(1, &dx12_texture->mpr_variable.texture_heap);

    // ���[�g�V�O�l�`���Ƀe�N�X�`����R�t����
    mpr_variable->s_command.list->SetGraphicsRootDescriptorTable(in_set_index_slot_num, dx12_texture->mpr_variable.texture_heap->GetGPUDescriptorHandleForHeapStart());

    return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���̕`������s����
// ����   �Fconst unique_ptr<C_Vertex_Buffer_Setting_Inform_Base> & �Z�b�g���钸�_�f�[�^���(const)
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_System::M_Draw_All_Vertex_By_Index(const std::unique_ptr<INSTANCE::C_Vertex_Buffer_Setting_Inform_Base> & in_vertex_inform)
{
    // �� �ϐ��錾 �� //
    const DX12INSTANCE::C_DX12_Vertex_Setting_Inform * dx12_vertex_inform = reinterpret_cast<const DX12INSTANCE::C_DX12_Vertex_Setting_Inform*> (in_vertex_inform.get());   // ���_�p����DX12�p�փL���X�g�������ʂ̃A�h���X


    // ���_�o�b�t�@���Z�b�g����
    mpr_variable->s_command.list->IASetVertexBuffers(0, 1, &dx12_vertex_inform->m_vertex_buffer_view);

    // �C���f�b�N�X�o�b�t�@���Z�b�g����    
    mpr_variable->s_command.list->IASetIndexBuffer(&dx12_vertex_inform->m_index_buffer_view);

    // �`������s����i�C���f�b�N�X�o�b�t�@���j
    mpr_variable->s_command.list->DrawIndexedInstanced(dx12_vertex_inform->m_draw_index_sum, 1, 0, 0, 0);

    return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F���̕`������s����
// ����   �Fconst unique_ptr<C_Vertex_Buffer_Setting_Inform_Base> & �Z�b�g���钸�_�f�[�^���(const), int �`�悷��C���f�b�N�X�̕`��̊J�n�ԍ�, int �`�悷��C���f�b�N�X�̏I���ԍ�
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_System::M_Draw_Select_Vertex_By_Index(const std::unique_ptr<INSTANCE::C_Vertex_Buffer_Setting_Inform_Base> & in_vertex_inform, int start_point, int end_point)
{
    // �� �ϐ��錾 �� //
    const DX12INSTANCE::C_DX12_Vertex_Setting_Inform * dx12_vertex_inform = reinterpret_cast<const DX12INSTANCE::C_DX12_Vertex_Setting_Inform*> (in_vertex_inform.get());   // ���_�p����DX12�p�փL���X�g�������ʂ̃A�h���X


    // ���_�o�b�t�@���Z�b�g����
    mpr_variable->s_command.list->IASetVertexBuffers(0, 1, &dx12_vertex_inform->m_vertex_buffer_view);

    // �C���f�b�N�X�o�b�t�@���Z�b�g����    
    mpr_variable->s_command.list->IASetIndexBuffer(&dx12_vertex_inform->m_index_buffer_view);

    // �`������s����i�C���f�b�N�X�o�b�t�@���j
    mpr_variable->s_command.list->DrawIndexedInstanced(end_point - start_point, 1, start_point, 0, 0);

    return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F��ʂ��t���b�v���ĕ`�悷�鏈��
// ����   �Fvoid
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_System::M_Rendering_End_And_Swap_Screen(void)
{
    // �� �ϐ��錾 �� //
    ID3D12CommandList * p_command_list = mpr_variable->s_command.list.Get();   // �R�}���h���X�g�̃A�h���X��n�����߂ɕϐ��ɂ���


    // �� �`�施�߂̋L�^�I�� �� //

    // ���\�[�X�����p�̃o���A���o�͗p�ɕύX (�ύX����������܂ő҂�)
    M_Set_Resource_Barrier(D3D12_RESOURCE_STATE_RENDER_TARGET, D3D12_RESOURCE_STATE_PRESENT);


    // �R�}���h���X�g�ւ̋L�^�I��(������ɍs��Ȃ��Ǝ��s�����邱�Ƃ��o���Ȃ�)
    mpr_variable->s_command.list->Close();


    // �R�}���h���s
    mpr_variable->s_command.queue->ExecuteCommandLists(1, &p_command_list);

    // �� ��ʏo�� �� //
    mpr_variable->s_frame_work.swap_chain->Present(1, 0);


#if 1   // �f�o�C�X���폜���ꂽ�炱����I���ɂ��ė��R���擾���邱��
    HRESULT bugresult = mpr_variable->s_frame_work.device->GetDeviceRemovedReason();
#endif


    // �`�抮���҂�
    M_Wait_For_Command_Queue();


    // �f�o�b�O���̂ݍs���X�V
#if _DEBUG
    M_Debug_Update();
#endif // _DEBUG

    return;
}


//-��- ���� -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�������ɒ��_�f�[�^�𐶐�����
// ����   �Funique_ptr<C_Vertex_Buffer_Setting_Inform_Base> & �Z�b�g��̒��_�f�[�^, const C_Create_Vertex_Buffer_Inform & ���_�f�[�^�����p���(const)
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_System::M_Create_Vertex_Inform(std::unique_ptr<INSTANCE::C_Vertex_Buffer_Setting_Inform_Base> & in_set_to, const CREATE::C_Create_Vertex_Buffer_Inform & in_create_inform)
{
    // �� �ϐ��錾 �� //
    DX12INSTANCE::C_DX12_Vertex_Setting_Inform * dx12_vertex_inform = new DX12INSTANCE::C_DX12_Vertex_Setting_Inform();   // DX12�p�̒��_�p���


    // �f�[�^���Z�b�g
    in_set_to.reset(dx12_vertex_inform);


    // ���_�o�b�t�@�𐶐�
    M_Create_Vertex_Buffer(dx12_vertex_inform, in_create_inform);

    // �C���f�b�N�X�o�b�t�@�̐���
    M_Create_Index_Buffer(dx12_vertex_inform, in_create_inform);

    // �`��񐔂��C���f�b�N�X�o�b�t�@���Z�b�g
    dx12_vertex_inform->m_draw_index_sum = in_create_inform.index_sum;

    return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�w�肳�ꂽ�������ɒ萔�f�[�^�𐶐�����
// ����   �Funique_ptr<C_Constant_Buffer_Setting_Inform_Base> & �Z�b�g��̒萔�f�[�^, const C_Create_Constant_Buffer_Inform & �萔�f�[�^�����p���(const)
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_System::M_Create_Constant_Inform(std::unique_ptr<INSTANCE::C_Constant_Buffer_Setting_Inform_Base> & in_constant_inform, const CREATE::C_Create_Constant_Buffer_Inform & in_create_inform)
{
    // �� �ϐ��錾 �� //
    DX12INSTANCE::C_DX12_Constant_Setting_Inform * dx12_constant_inform = new DX12INSTANCE::C_DX12_Constant_Setting_Inform();   // DX12�p�̒萔�p���


    // �� �萔�f�[�^�p�̃q�[�v�𐶐� �� //
    M_Create_Constant_Heap(dx12_constant_inform, in_create_inform);

    // �� �萔�f�[�^�𐶐� �� //
    M_Create_Constant_Resource(dx12_constant_inform, in_create_inform);


    // �f�[�^���Z�b�g
    in_constant_inform.reset(dx12_constant_inform);

    return;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�e�N�X�`���p�̏��𐶐�����
// ����   �Funique_ptr<C_Rendering_Texture_Setting_Inform_Base> & �ݒ��̃p�C�v���C�����, const C_Create_Texture_Setting_Inform & �����p�̏��(const)
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_DX12_System::M_Create_Texture_Inform(std::unique_ptr<INSTANCE::C_Rendering_Texture_Setting_Inform_Base> & in_texture_inform, const CREATE::C_Create_Texture_Setting_Inform & in_create_inform)
{
    // �� �ϐ��錾 �� //
    DX12INSTANCE::C_DX12_Rendering_Texture_Setting_Inform * dx12_texture_inform = new DX12INSTANCE::C_DX12_Rendering_Texture_Setting_Inform(); // DX12�p�̕`��p���


    // �� �e�N�X�`���p�f�[�^�̐��� �� //�@// ���s������G���[�Ŕ�����
    if (M_Create_Texture_Resource(dx12_texture_inform, in_create_inform) == false)
    {
        // �f�o�b�O���͎��s���O���o��
#if _DEBUG
        DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_RED, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
        DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT, "�e�N�X�`���q�[�v�̐����Ɏ��s");
#endif // _DEBUG

        return false;
    }


    // �� �q�[�v�𐶐� �� //
    M_Create_Texture_Resource_View_And_Heap(dx12_texture_inform, in_create_inform);


    // �f�[�^���Z�b�g
    in_texture_inform.reset(dx12_texture_inform);


    // �f�o�b�O���͐������O���o��
#if _DEBUG
    DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
    DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT, "�e�N�X�`���p�f�[�^�̐����ɐ���");
#endif // _DEBUG

    return true;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�`��p�C�v���C���p�̏��𐶐�����
// ����   �Fstd::unique_ptr<C_Rendering_Graphics_Setting_Inform_Base> & �ݒ��̃p�C�v���C�����, const C_Create_Rendering_Graphics_Setting_Inform & �����p�̏��(const)
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_DX12_System::M_Create_Rendering_Graphics_Inform(std::unique_ptr<INSTANCE::C_Rendering_Graphics_Setting_Inform_Base>& in_pipeline_inform, const CREATE::C_Create_Rendering_Graphics_Setting_Inform& in_create_inform)
{
    // �� �ϐ��錾 �� //
    DX12INSTANCE::C_DX12_Rendering_Graphics_Setting_Inform * dx12_pipeline_inform = new DX12INSTANCE::C_DX12_Rendering_Graphics_Setting_Inform(); // DX12�p�̕`��p���


    // �� ���[�g�V�O�l�`���ݒ� �� //�@���s������G���[�Ŕ�����
    if (M_Create_Root_Signature(dx12_pipeline_inform, in_create_inform) == false)
    {
        return false;
    }


    // �� �p�C�v���C���X�e�[�g �� //�@���s������G���[�Ŕ�����
    if (M_Create_Pipeline_State(dx12_pipeline_inform, in_create_inform) == false)
    {
        return false;
    }

    // �f�[�^���Z�b�g
    in_pipeline_inform.reset(dx12_pipeline_inform);


    // �f�o�b�O���͐������O���o��
#if _DEBUG
    DEBUGGER::LOG::C_Log_System::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::E_LOG_COLOR::e_GREEN, DEBUGGER::LOG::E_LOG_COLOR::e_BLACK);
    DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT, "�����_�����O�ݒ�̐����ɐ���");
#endif // _DEBUG

    return true;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�t�H���g���t�H���g�������Ƀ��[�h����
// ����   �Funique_ptr<C_Rendering_Font_Inform_Base> & �ݒ��̃t�H���g���p�����[�^, const C_Create_Font_Data_Inform & �����p�̏��(const)
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_DX12_System::M_Create_Font_Data(std::unique_ptr<INSTANCE::C_Rendering_Font_Inform_Base> & in_font_data, const CREATE::C_Create_Font_Data_Inform & in_create_inform)
{
    // �� �ϐ��錾 �� //
    HFONT handle_font = NULL;   // �t�H���g�̃n���h��

    LOGFONT log_font_data =  // �t�H���g�ݒ�p�̃f�[�^
    {
        //-��- �T�C�Y��`��̐ݒ� -��-// 
        in_create_inform.m_height,   // �t�H���g�̃Z���╶���̍���
        0,                          // �t�H���g�̕����̕�
        0,                          // �������X�������
        0,                          // ��{���Ɣ�ׂ��Ƃ��̂����ł̊p�x
        0,                          // �t�H���g�̑����̐ݒ�i�O�Ńf�t�H���g�j

        //-��- ���̂̐ݒ� -��-//
        FALSE,              // �Α̃t�H���g���ǂ����̃t���O
        FALSE,              // �����t���t�H���g���ǂ����̃t���O
        FALSE,              // ���������t���t�H���g���ǂ����̃t���O
        SHIFTJIS_CHARSET,   // �����Z�b�g�̎��

        //-��- ���x�̐ݒ� -��-//
        OUT_TT_ONLY_PRECIS,         // �t�H���g�̐��x�i���܂ł̐ݒ�ɂǂꂾ�������Ȍ��ʂɂȂ邩�j
        CLIP_DEFAULT_PRECIS,        // �N���b�s���O�̐��x
        PROOF_QUALITY,              // �o�͎��̕i��
        DEFAULT_PITCH | FF_MODERN,  // �t�H���g�̃s�b�`�ƃt�@�~��(�t�H���g�̃f�U�C�����@�̒�`)

        // �t�H���g��
        (WCHAR)in_create_inform.m_font_name.data()
    };

    // �t�H���g�̃n���h����ǂݍ���
    handle_font = CreateFontIndirectW(&log_font_data);
    

    // �t�H���g�n���h���̎擾�Ɏ��s������G���[�������Ĕ�����
    if (handle_font == NULL)
    {
#ifdef _DEBUG

        DEBUGGER::LOG::C_Log_System::M_Set_Console_Text_Color(DEBUGGER::LOG::E_LOG_COLOR::e_RED);
        DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, "�t�H���g�n���h���̐����Ɏ��s", "DX12_FONT_SYSTEM");

#endif // _DEBUG

        return false;
    }


    // �e�X�g�͊��������̂Ō���ŕK�v�̂Ȃ��f�[�^�͍폜
    DeleteObject(handle_font);
    handle_font = NULL;


    //-��- �������Ă�����o�^ -��-//

    // �� �ϐ��錾 �� //
    DX12INSTANCE::C_DX12_Font_Data_Set * new_font_data_handler = new DX12INSTANCE::C_DX12_Font_Data_Set();   // �V�����t�H���g�f�[�^�p�̐ݒ�


    // �t�H���g��
    new_font_data_handler->m_log_font = log_font_data;


    //--�� �o�^ ��--//
    in_font_data.reset(new_font_data_handler);

    return true;
}


//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�n���ꂽ�������ɕ������}�b�v�ɃZ�b�g����
// ����   �FS_Make_Font_To_Graph_Package & �t�H���g����摜����邽�߂̃p�b�P�[�W���
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_DX12_System::M_Set_Font_To_Texture_Map(PAKAGE::FONT::S_Make_Font_To_Graph_Package & in_set_inform)
{
    // �� �萔 �� //
    const MAT2 texture_uv_setting_mat = { {0,1},{0,0},{0,0},{0,1} };   // �e�N�X�`�����W�w��p�̓񎟌��z��R�[�h


    // �� �ϐ��錾 �� //
    DX12INSTANCE::C_DX12_Font_Data_Set * dx12_font_data = reinterpret_cast<DX12INSTANCE::C_DX12_Font_Data_Set * >(in_set_inform.attach_font_data->get());   // �c�w�P�Q�p�t�H���g�f�[�^�ւ̕ϊ�

    HFONT handle_font = NULL;   // �t�H���g�̃n���h��


    // �t�H���g�̃n���h����ǂݍ���
    handle_font = CreateFontIndirectW(&dx12_font_data->m_log_font);


    // �t�H���g�n���h���̎擾�Ɏ��s������G���[�������Ĕ�����
    if (handle_font == NULL)
    {
#ifdef _DEBUG
        DEBUGGER::LOG::C_Log_System::M_Set_Console_Text_Color(DEBUGGER::LOG::E_LOG_COLOR::e_RED);
        DEBUGGER::LOG::C_Log_System::M_Print_Log(DEBUGGER::LOG::E_LOG_TAGS::e_SET_UP, "DX12_FONT_SYSTEM", "�t�H���g�̐����Ɏ��s�A�������̓t�H���g��񂪐ݒ肳��Ă��Ȃ����߁A���̃t�H���g�����g�p���鎖�͂ł��܂���ł���");

#endif // _DEBUG

        return false;
    }


    // �� �ϐ��錾 �� //
    HDC handle_device_context = GetDC(NULL);   // �E�B���h�E�̃f�o�C�X�R���e�L�X�g

    TEXTMETRIC txt_met;  // �e�L�X�g�̐ݒ�

    HFONT old_font_handle = NULL;  // ���̃t�H���g�f�[�^��K�p����O�ɐݒ肳��Ă����n���h��

    int FLG_GRAY_SETTING = GGO_GRAY4_BITMAP;  // �r�b�g�}�b�v���~���w��p�̃t���O

    int num_grad = 0;   // �K���̍ő�l


    // �t�H���g�̎擾
    old_font_handle = (HFONT)SelectObject(handle_device_context, handle_font);


    // �� �r�b�g�}�b�v���~���̃��x�����w�� �� //
    switch (in_set_inform.bit_map_level)
    {
        // 0~4
    case PAKAGE::FONT::E_FONTBIT_MAP_LEVEL::e_4:
        FLG_GRAY_SETTING = GGO_GRAY2_BITMAP;
        num_grad = 4;
        break;

        // 0~16
    case PAKAGE::FONT::E_FONTBIT_MAP_LEVEL::e_16:
        FLG_GRAY_SETTING = GGO_GRAY4_BITMAP;
        num_grad = 16;
        break;

        // 0~64
    case PAKAGE::FONT::E_FONTBIT_MAP_LEVEL::e_64:
        FLG_GRAY_SETTING = GGO_GRAY8_BITMAP;
        num_grad = 64;
        break;
    }   // * 0�`num_grad�Ɏw�肵���l�̊ԂŐF�̏����擾�ł���
    
    // �e�L�X�g�ݒ���E�B���h�E�̃R���e�L�X�g����擾
    GetTextMetrics(handle_device_context, &txt_met);

    
    // �� �ϐ��錾 �� //
    GLYPHMETRICS glyph_met;    // �t�H���g�p�̐ݒ�
    
    DWORD font_map_size = 0; // �r�b�g�}�b�v�̃T�C�Y
    
    // �r�b�g�}�b�v�T�C�Y���擾
    font_map_size = GetGlyphOutlineW(handle_device_context, (UINT)in_set_inform.text_code, FLG_GRAY_SETTING, &glyph_met, 0, NULL, &texture_uv_setting_mat);

    std::vector<DWORD> font_texture_data;    // �t�H���g����擾�����摜���


    // �}�b�v�̎擾
    font_texture_data.resize(font_map_size);
    GetGlyphOutlineW(handle_device_context, (UINT)in_set_inform.text_code, FLG_GRAY_SETTING, &glyph_met, font_map_size, &font_texture_data[0], &texture_uv_setting_mat);
    

    // �� �ϐ��錾 �� //
    DATA::COLOR::C_Color set_color(1.0f, 1.0f, 1.0f, 0.0f); // �ݒ肷��F
    
    int font_map_start_x = glyph_met.gmptGlyphOrigin.x; // �������ł̃t�H���g�̊J�n�r�b�g�ԍ�
    int font_map_start_y = txt_met.tmAscent - glyph_met.gmptGlyphOrigin.y;  // �������ł̃t�H���g�̊J�n�r�b�g�ԍ�

    int font_size_x = (glyph_met.gmBlackBoxX + (4 - (glyph_met.gmBlackBoxX % 4)) % 4);    // �������ł̃t�H���g�̃r�b�g���i�S�Ŋ����Ă�͎̂l���ɕ��ׂēn����邽�߁j
    int font_size_y = glyph_met.gmBlackBoxY;    // �������ł̃t�H���g�̃r�b�g��

    int map_x_size = in_set_inform.draw_rect.right_x - in_set_inform.draw_rect.left_x + 1; // �������ł̃}�b�v�ɏ������ޑ傫��
    int map_y_size = in_set_inform.draw_rect.top_y - in_set_inform.draw_rect.bottom_y + 1; // �c�����ł̃}�b�v�ɏ������ޑ傫��


    int map_write_start_x = (int)(((float)font_map_start_x / ((float)font_size_x + (float)font_map_start_x)) * (float)map_x_size); // �}�b�v�ɏ������ނƂ��̂��ł̊J�n���W
    int map_write_start_y = (int)(((float)font_map_start_y / ((float)font_size_y + (float)font_map_start_y)) * (float)map_y_size); // �}�b�v�ɏ������ނƂ��̂��ł̊J�n���W


    // �����Ă���摜���}�b�v�ɍ��킹�邽�߂̒���
    font_size_x /= 4;
    map_x_size -= map_write_start_x;
    map_y_size -= map_write_start_y;


    float font_size_x_by_map_x_size = (float)font_size_x / (float)map_x_size;   // ���ł̃t�H���g�}�b�v�ɓK�p���邽�߂̔{��
    float font_size_y_by_map_y_size = (float)font_size_y / (float)map_y_size;   // ���ł̃t�H���g�}�b�v�ɓK�p���邽�߂̔{��


    // �e�N�X�`���p�̃}�b�v���m�ۂ���
    in_set_inform.tex_map_data->M_Map_Variable_Size_Change(in_set_inform.draw_rect.right_x, in_set_inform.draw_rect.top_y);


    // �C�����K�v�ȕ����͏C����������i�L���Ȃǁj
    switch (in_set_inform.text_code)
    {
        // �n�C�t���͉��ɕ��ׂ���̂ŏ�ɂ�����A�T�C�Y����������
    case L'-':
        map_write_start_y /= 2;
        map_x_size /= 2;
        map_write_start_x = (in_set_inform.draw_rect.right_x - in_set_inform.draw_rect.left_x) / 3;
        break;

        // �L�΂��_�͉��ɕ��ׂ���̂ŏ�ɂ�����
    case L'�[':
        map_write_start_y /= 2;
        break;
    }


    // �c�̃s�N�Z�����̃��[�v
    for (int l_y_now_pix = 0; l_y_now_pix < map_y_size; l_y_now_pix++)
    {
        // �� �ϐ��錾 �� //
        int now_data_y_element = (int)(l_y_now_pix * font_size_y_by_map_y_size);  // ���ݎ��o���f�[�^�̂����W���̗v�f��
        
        now_data_y_element =
            (now_data_y_element >= (font_size_y - 1)) * (font_size_y - 1)
            +
            (now_data_y_element < (font_size_y - 1)) * now_data_y_element;

        now_data_y_element *= font_size_x;

        
        // ���̃s�N�Z�����̃��[�v
        for (int l_x_now_pix = 0; l_x_now_pix < map_x_size; l_x_now_pix++)
        {
            // �� �ϐ��錾 �� //
            int now_data_element = (int)(l_x_now_pix * font_size_x_by_map_x_size);  // ���ݎ��o���f�[�^�̗v�f�ԍ�

            now_data_element =
                (now_data_element >= (font_size_x - 1)) * (font_size_x - 1)
                +
                (now_data_element < (font_size_x - 1)) * now_data_element;

            now_data_element += now_data_y_element;

            WORD now_color_data = (WORD)((font_texture_data[now_data_element] * 255) / num_grad);    // ���o�����J���[�f�[�^


            // �F�̔Z�����n����邾���Ȃ̂œ����x�̂ݐݒ肷��
            set_color.a = (float)(now_color_data & 0x000000ff) / 255;
            in_set_inform.tex_map_data->M_Set_Color_At_Point(set_color, l_x_now_pix + in_set_inform.draw_rect.left_x + map_write_start_x, l_y_now_pix + in_set_inform.draw_rect.bottom_y + map_write_start_y);
        }
    }


    // �g�p�ς݂̃}�b�v�f�[�^�����
    font_texture_data.clear();
    font_texture_data.shrink_to_fit();


    // ���X�ݒ肳��Ă����t�H���g�ɖ߂�
    SelectObject(handle_device_context, old_font_handle);

    // �����̉��
    DeleteObject(handle_font);
    ReleaseDC(NULL, handle_device_context);

    return true;
}


//-��- �Z�b�^ -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�F�f�[�^���Z�b�g����
// ����   �Fconst C_Color & �Z�b�g����F�f�[�^(const)
// �߂�l �Fvoid
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
void C_DX12_System::M_Set_Clear_Color(const DATA::COLOR::C_Color & in_set_color)
{
    mpr_variable->s_frame_work.clear_color[(int)E_DX12_PARAMATOR::e_RED] = in_set_color.r;
    mpr_variable->s_frame_work.clear_color[(int)E_DX12_PARAMATOR::e_GREEN] = in_set_color.g;
    mpr_variable->s_frame_work.clear_color[(int)E_DX12_PARAMATOR::e_BLUE] = in_set_color.b;
    mpr_variable->s_frame_work.clear_color[(int)E_DX12_PARAMATOR::e_ALPHA] = in_set_color.a;

    return;
}


//-��- ���[�h -��-//

//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
// �ڍ�   �F�e�N�X�`�������[�h����
// ����   �Fstring �t�@�C���̃p�X, C_Texture_Map & �e�N�X�`���}�b�v�̎Q��
// �߂�l �Fbool �������̂�true
//��=��=��=��=��=��=��=��=��=��=��=��=��=��=��=��//
bool C_DX12_System::M_Load_Texture(std::string in_file_path, ASSET::TEXTURE::C_Texture_Map & in_tex_map)
{
    // �� �ϐ��錾 �� //
    DirectX::TexMetadata file_metadata = {};     // �e�N�X�`���̃��^�f�[�^���擾����

    DirectX::ScratchImage scratch_img = {};  // �摜�t�@�C���̓ǂݎ�茋��

    std::vector<wchar_t> w_file_path;  // �t�@�C���p�X��wchar�ɕϊ���������

    int file_path_size = (int)in_file_path.size();   // �t�@�C���p�X������


    // ���C�h�L�����ɕϊ�����
    w_file_path.resize(file_path_size + 1);
    for (int loop_x = 0; loop_x < file_path_size; loop_x++)
    {
        w_file_path[loop_x] = (wchar_t)in_file_path[loop_x];
    }
    w_file_path[file_path_size] = '\0';


    // �t�@�C���̓ǂݍ���    // ���s������G���[�Ŕ�����
    if (FAILED(DirectX::LoadFromWICFile(&w_file_path[0], DirectX::WIC_FLAGS_NONE, &file_metadata, scratch_img)))
    {
        HRESULT result_error = DirectX::LoadFromWICFile(&w_file_path[0], DirectX::WIC_FLAGS_NONE, &file_metadata, scratch_img);

        w_file_path.clear();
        w_file_path.shrink_to_fit();
        return false;
    }
    w_file_path.clear();
    w_file_path.shrink_to_fit();


    // �� �ϐ��錾 �� //
    const DirectX::Image * add_image = scratch_img.GetImage(0, 0, 0);   // �摜�f�[�^�̃A�h���X
    

    // �������̊m��
    in_tex_map.M_Delete_Map();
    in_tex_map.M_Map_Variable_Size_Change((int)add_image->width, (int)add_image->height);


    // �s�N�Z���f�[�^�̃Z�b�g
    for (int l_tex_y = 0; l_tex_y < (int)add_image->height; l_tex_y++)
    {
        // �� �ϐ��錾 �� //
        int row_plus = l_tex_y * (int)add_image->width;	// �ݒ�ʒu�̏c�񕪂ł��炷��
        int image_plus = row_plus * 4;	// �C���[�W���W�̐ݒ�ʒu�̏c�񕪂ł��炷��


        for (int l_tex_x = 0; l_tex_x < (int)add_image->width; l_tex_x++)
        {
            // �� �ϐ��錾 �� //
            DATA::COLOR::C_Color set_color; // �ݒ肷��F


            set_color.r = add_image->pixels[image_plus + l_tex_x * 4 + 0];
            set_color.g = add_image->pixels[image_plus + l_tex_x * 4 + 1];
            set_color.b = add_image->pixels[image_plus + l_tex_x * 4 + 2];
            set_color.a = add_image->pixels[image_plus + l_tex_x * 4 + 3];
            in_tex_map.M_Set_Color_At_Point(set_color, l_tex_x, l_tex_y);
        }
    }

    // ����
    return true;
}


#endif // OS_IS_WINDOWS



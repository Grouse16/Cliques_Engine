////
// Ú×   FVF[_[ÌoCgR[hpÌNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include <string>

#include "C_Shader_Code.h"
#include "C_Platform_Detection_System.h"

#include "C_Console_Log_Interface.h"


//  l[Xy[XÌÈª  //
using namespace ASSET::SHADER;


//  Ö  //

//== pubN ==//

//-- ú»ÆI¹ --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Shader_Code::C_Shader_Code(void)
{
	return;
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_Shader_Code::~C_Shader_Code(void)
{
	M_Release();

	return;
}


//===============//
// Ú×   FoCgR[hÌððúµú»·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_Shader_Code::M_Release(void)
{
	// R[hÌîñpððú
	mpr_variable.binary_ptr.reset();

	// TCYðú»
	mpr_variable.size = 0;

	return;
}


//-- [h --//

//===============//
// Ú×   FVF[_[Ìú»
// ø   Fstring VF[_[ÌÝè
// ßèl Fbool VF[_[ª³©Á½çtrue
//===============//
bool C_Shader_Code::M_Load_Shader_File(std::string in_shader_file_name)
{
	//  Ïé¾  //
	FILE * file_address = nullptr;	// RpCÏÝVF[_[Ìt@Cðüè

	std::string file_name = in_shader_file_name;	// t@C¼


	// RpCÏÝVF[_[Ìt@CðJ­
	fopen_s(&file_address, file_name.c_str(), "rb");


	// t@CªÈ©Á½çfalseÅ²¯é
	if (file_address == nullptr)
	{
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_RED, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_SHADER_ERROR, (file_name + "VF[_[ÌÇÝæèÉ¸sµÜµ½").c_str());
		DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Stop_Update_And_Log_Present();

		return false;
	}


	// VF[_[ÌÇÝæèÌ¬÷ðm
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Set_Console_Color_Text_And_Back(DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_GREEN, DEBUGGER::LOG::CONSOLE::COLOR::E_CONSOLE_LOG_COLOR::e_BLACK);
	DEBUGGER::LOG::CONSOLE::C_Console_Log_Interface::M_Print_Log(DEBUGGER::LOG::CONSOLE::TAGS::E_CONSOLE_LOG_TAGS::e_SET_UP, DEBUGGER::LOG::CONSOLE::ALL_LOG_NAME::GAME_SYSTEM::con_GAME_INIT, (file_name + "VF[_[ÌÇÝæèÉ¬÷µÜµ½").c_str());


	// oCgR[hÌrbgÌüè
	fseek(file_address, 0, SEEK_END);
	mpr_variable.size = ftell(file_address);
	rewind(file_address);


	// oCgR[hð[h·é
	mpr_variable.binary_ptr.reset(new(void * [mpr_variable.size]));
	fread(mpr_variable.binary_ptr.get(), 1, mpr_variable.size, file_address);


	// t@CðÂ¶é
	fclose(file_address);
	file_address = nullptr;

	return true;
}


//-- Qb^ --//

//===============//
// Ú×   FRpCÏÝR[hÌQÆðÔ·
// ø   Fvoid
// ßèl Fconst unique_ptr<void * > & RpCÏÝR[h
//===============//
const std::unique_ptr<void * > & C_Shader_Code::M_Get_Compiled_Cord(void) const
{
	return mpr_variable.binary_ptr;
}


//===============//
// Ú×   FR[hÌoCgTCYðÔ·
// ø   Fvoid
// ßèl Fint R[hÌoCgTCY
//===============//
int C_Shader_Code::M_Get_Cord_Size(void) const
{
	return mpr_variable.size;
}




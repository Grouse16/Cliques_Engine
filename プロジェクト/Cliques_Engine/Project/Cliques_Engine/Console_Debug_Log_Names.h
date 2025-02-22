////
// Ú×   FR\[OpÌev[gÆÈé¶ñpÌt@C
// àŸ   F
// ì¬Ò FûüâŽœ
////


//  œdCN[hK[h  //
#ifndef D_INCLUDE_GUARD_CONSOLE_DEBUG_LOG_NAMES_H_FILE
#define D_INCLUDE_GUARD_CONSOLE_DEBUG_LOG_NAMES_H_FILE


//  l[Xy[X  //

// R\[OpÌVXeðÄÑo·œßÌŒO
namespace DEBUGGER::LOG::CONSOLE
{
	//  è  //

	// OÉgp·é¶ñðÜÆßœ\¢Ì
	namespace ALL_LOG_NAME
	{
		// CVXepÌO¶ñ
		namespace MAIN_SYSTEM
		{
			constexpr char con_CONSOLE_CREATED[] = "Console_Created";		// R\[Ì¶¬¬÷ÌO^Cg
			constexpr char con_SET_UP_SUCCEEDED[] = "WIN_DX12_SET_UP_SUCCEEDED";	// EBhEYÆDX12ÌVXeÌZbgAbv¬÷ÌO^Cg
			constexpr char con_ALL_SET_UP_SUCCEEDED[] = "ALL_SET_UP_CLEAR";	// SÄÌZbgAbvÉ¬÷µœÆ«ÌO
			constexpr char con_END[] = "APK_END";	// AvP[VI¹ÌO^Cg
		};

		// Q[pÌO¶ñ
		namespace GAME_SYSTEM
		{
			constexpr char con_GAME_INIT[] = "GAME_INIT";					// §¿ã°O
			constexpr char con_GAME_INIT_ERROR[] = "GAME_INIT_ERROR";		// §¿ã°žsÌO
			constexpr char con_GAME_SHADER_ERROR[] = "SHADER_ERROR";		// VF[_[Ì¶¬žs
			constexpr char con_GAME_CREATE_FUNCTION[] = "CREATE_FUNCTION";	// @\Ì¶¬
		};

		// Q[Ì`æVXepÌO¶ñ
		namespace GAME_RENDERING
		{
			constexpr char con_INIT[] = "GAME_RENDERING_INIT";		// §¿ã°O
			constexpr char con_RENDERING_ERROR[] = "GAME_RENDERING";		// _OnÌÅÌG[
			constexpr char con_ERROR[] = "GAME_RENDERING_ERROR";	// G[O
		};

		// AvP[VÌG[O
		namespace APK_LOG
		{
			constexpr char con_MANAGERS_ERROR[] = "MANAGER-ERRORS";	// EBhEYÌZbgAbv¬÷ÌO^Cg
		};

		// EBhEYpÌO¶ñ
		namespace WINDOWS
		{
			constexpr char con_SET_UP_SUCCEEDED[] = "Windows_Set_Up_Succeeded";	// EBhEYÌZbgAbv¬÷ÌO^Cg
		};

		// DX12pÌO¶ñ
		namespace DX12
		{
			constexpr char con_SET_UP_SUCCEEDED[] = "DX12_Set_Up_Succeeded";	// EBhEYÌZbgAbv¬÷ÌO^Cg
			constexpr char con_SET_UP_FAILED[] = "DX12_Set_Up_Failed";		// EBhEYÌZbgAbvžsÌO^Cg

			constexpr char con_DEVICE_DELETED[] = "DX12_Device_Deleted";	// foCXªí³êœÌO^Cg

			constexpr char con_ERROR_CHECKING[] = "DX12_ERROR_CHECKING";	// G[oÌO^Cg
		};
	};
}


#endif //!D_INCLUDE_GUARD_CONSOLE_DEBUG_LOG_NAMES_H_FILE


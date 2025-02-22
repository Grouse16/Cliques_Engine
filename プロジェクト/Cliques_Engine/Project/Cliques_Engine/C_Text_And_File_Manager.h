////
// Ú×   Ft@C§äpVXeÌNX
// à¾   Ft@Cð¶¬µAf[^ðL^Å«é
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_FILE_USER_H_FILE
#define D_INCLUDE_GUARD_FILE_USER_H_FILE


//  t@CÐç«  //
#include <vector>
#include <string>


//  l[Xy[X  //

// eLXgð§ä·éVXeðÄÑo·½ßÌ¼O
namespace SYSTEM::TEXT
{
	//  è  //

	// ÒW[hðwè·é½ßÌñ
	enum class E_EDIT_MODE
	{
		e_TEXT,		// eLXg`®
		e_BINARY,	// oCi`®
	};


	//  NX  //

	// ¶Íð§ä·é½ßÌNXAt@CÌÇÝ«às¤
	class C_Text_And_File_Manager
	{
		//== vCx[g ==//
	private:

		//  Ïé¾  //

		// vCx[gÏðÜÆß½\¢Ì
		struct SPr_Variable
		{
			const std::string con_default_name = "default_file_name";	// ftHgÌt@C¼

			E_EDIT_MODE mode_setting = E_EDIT_MODE::e_TEXT;	// ÒW[hÝè

			std::vector<std::string> sentence_data;	// ¶ÍÌf[^iæêzñs,@æñzññ¨æÑ¶j

			std::string file_path = con_default_name;	// t@CÜÅÌpX

			int row_number = 0;		// sÌÔ
			int column_number = 0;	// ñÌÔ

		} mpr_variable;	// vCx[gÏðÄÑo·½ßÌ¼O


		//-- f[^Ø --//

		// üÍ³ê½pX¼ªoOðø«N±³È¢àÌ©Ç¤©ð»è·é@øFpX¼@ßèlFpX¼ª³µ¯êÎtrue
		bool M_Is_File_Path_Succeed(std::string & );

		// üÍ³ê½pX¼Ì¤¿tH_ÌªªoOðø«N±³È¢àÌ©Ç¤©ð»è·é@øFpX¼@ßèlFpX¼ª³µ¯êÎtrue
		bool M_Is_Folder_Path_Is_Succeed(std::string & );

		// t@Cªwè³êÄ¢é©Ç¤©ð»è@øFpX¼@ßèlFt@CÜÅÌpXÈçtrue tH_ÈÇÜÅÈçfalse
		bool M_Is_File(std::string & );

		// wè³ê½¶ªüs¶Å é©Ç¤©ð»è·é@øF¶f[^@ßèlFtrueÈçüsR[h
		bool M_Is_CR(const char &);


		//==  pubN  ==//
	public:

		//-- ú»ÆI¹ --//

		// RXgN^
		C_Text_And_File_Manager(void);

		// f[^ú»
		void M_Reset_Data(void);

		// fXgN^
		~C_Text_And_File_Manager(void);


		//-- f[^Ï· --//

		// ¶ñð10iÌINT^ÉÏ··é@øFÏ··éf[^@ßèlFÏ·Ê
		static int M_Convert_Data_Char_To_X16INT(std::string);


		//-- ¶¬ --//

		// n³ê½pXÌt@Cª¶ÝµÄ¢È¯êÎ¶¬·éipX¼+üs¶ðtH_Æ·éj@øFt@CÜÅÌpX
		bool M_Create_Path_Of_Folder(std::string);

		// pXÜÅÌt@CÆtH_ªÈ¯êÎ¶¬·éipX¼+üs¶ðtH_Æ·éj@øFt@CÜÅÌpX
		bool M_Create_File_And_Folder_If_File_Not_Exist(std::string);


		//-- Zb^ --//

		// ±ê©çÒW·ét@CÌpXðwè·éiÈ¯êÎ¶¬³êéj@øFt@CÌpX@ßèlF¬÷ÌÝtrue
		bool M_Set_File_Path(std::string);

		// ÒW[hðwè·é@øFÒW[hðwè·éÔ
		void M_Set_Edit_Mode(E_EDIT_MODE);


		//-- Qb^ --//

		// »ÝÌf[^ÌQÆðn·@ßèlFt@Cf[^Ì¶ñ
		const std::vector<std::string> & M_Get_File_Data_Refer(void) const;

		// »ÝÒWÌt@CÌpXðÔ·@ßèlFt@CpXÌ¶ñ
		const std::string & M_Get_File_Path_Refer(void) const;

		// »ÝÌsÌÔðÔ·@ßèlF»ÝÌsÔ
		int M_Get_Now_Row(void) const;

		// »ÝÌñÌÔðÔ·@ßèlF»ÝÌñÔ
		int M_Get_Now_Column(void) const;

		// ¶ÍÌsðÔ·@ßèlFSÌÌs
		int M_Get_Text_Row_Sum(void) const;

		// ¡IðÌsÌ¶ðÔ·@ßèlF¡ÌsÌ¶
		int M_Get_Column_Sum_In_Now_Row(void);

		// »ÝÌ¶ÍSÌÌ¶ðÔ·@ßèlF¶ÍÌ¶
		int M_Get_Sentence_Text_Size(void);

		// »ÝÌêÌ¶ðÔ·@ßèlF»ÝÌêÌ¶
		char M_Get_Text_Of_Now_Position(void);


		//-- Z[u --//

		// ìÌt@CÉ»ÝÌf[^ðã«ÅZ[u·é@ßèlF¬÷ÌÝtrue
		bool M_Save_Data_To_Now_File(void);

		// wè³ê½t@CÉ»ÝÌf[^ðã«ÅZ[u·é@øFt@CÌpX@ßèlF¬÷ÌÝtrue
		bool M_Save_Data_To_Select_File(std::string);

		// ìÌt@CÉ»ÝÌf[^ðÇÁÅZ[u·é@ßèlF¬÷ÌÝtrue
		bool M_Add_Data_To_Now_File(void);

		// wè³ê½t@CÉ»ÝÌf[^ðÇÁÅZ[u·é@øFt@CÌpX@ßèlF¬÷ÌÝtrue
		bool M_Add_Data_To_Select_File(std::string);


		//-- [h --//

		// ìÌt@C©çf[^ðÇÝÞ@ßèlF¬÷ÌÝture
		bool M_Load_Now_File(void);

		// ìÌt@C©çwè³ê½sÔ¾¯f[^ðÇÝÞ@øFÇÝnÜèÌs, ÇÝIíèÌs@ßèlF¬÷ÌÝture
		bool M_Load_Now_File_Only_Select_Raw(int, int);

		// wè³ê½t@C©çf[^ðÇÝÞ@øFt@CÌpX@ßèlF¬÷ÌÝture
		bool M_Load_Select_File(std::string);

		// wè³ê½t@C©çwè³ê½sÔ¾¯f[^ðÇÝÞ@øFt@CÌpX, ÇÝnÜèÌs, ÇÝIíèÌs@ßèlF¬÷ÌÝture
		bool M_Load_Select_File_Only_Select_Raw(std::string, int, int);


		//-- üÍ --//

		// wè³ê½f[^ð»ÝÌìÊu©çüÍ·é@øFüÍ·éf[^
		void M_Input_This_Data(short);

		// wè³ê½f[^ð»ÝÌìÊu©çüÍ·é@øFüÍ·éf[^
		void M_Input_This_Data(unsigned short);

		// wè³ê½f[^ð»ÝÌìÊu©çüÍ·é@øFüÍ·éf[^
		void M_Input_This_Data(int);

		// wè³ê½f[^ð»ÝÌìÊu©çüÍ·é@øFüÍ·éf[^
		void M_Input_This_Data(unsigned int);

		// wè³ê½f[^ð»ÝÌìÊu©çüÍ·é@øFüÍ·éf[^
		void M_Input_This_Data(long long);

		// wè³ê½f[^ð»ÝÌìÊu©çüÍ·é@øFüÍ·éf[^
		void M_Input_This_Data(unsigned long long);

		// wè³ê½f[^ð»ÝÌìÊu©çüÍ·é@øFüÍ·éf[^
		void M_Input_This_Data(std::string);

		// wè³ê½f[^ð»ÝÌìÊu©çüÍ·é@øFüÍ·éf[^
		void M_Input_This_Data(double);


		//-- í --//

		// wè³ê½f[^ð¶Íà©çwè³ê½ñª¾¯í·é@øFíñiOÅSÄíj, í·é¶
		void M_Delete_Data_Equal_This_Text_In_Sentence(int, std::string);

		// wè³ê½f[^ðIðÌsà©çwè³ê½ñª¾¯í·é@øFíñiOÅSÄíj, í·é¶
		void M_Delete_Data_Equal_This_Text_In_Now_Row(int, std::string);

		// wè³ê½f[^ðIðÊuÌE¤Ìsà©çwè³ê½ñª¾¯í·é@øFíñiOÅSÄíj, í·é¶
		void M_Delete_Data_Equal_This_Text_In_Now_Row_For_Right(int, std::string);

		// wè³ê½f[^ðIðÊuÌ¶¤Ìsà©çwè³ê½ñª¾¯í·é@øFíñiOÅSÄíj, í·é¶
		void M_Delete_Data_Equal_This_Text_In_Now_Row_For_Left(int, std::string);

		// wè³ê½sðí·é@øFí·és
		void M_Delete_Row(int);

		// ¡Ìê©çwè³ê½¶ª¾¯¶ðí·éisÍ±¦È¢j@øFí·é¶
		void M_Delete_Column(int);

		// IðÌt@Cðí·é@ßèlFí·ét@Cª©Â©çÈ©Á½Aàµ­Íwè³ê½pXªfBNgð³·Èçfalse
		bool M_Delete_Now_File(void);

		// wè³ê½t@Cðí·é@øFí·ét@CÜÅÌpX@ßèlFí·ét@Cª©Â©çÈ©Á½Aàµ­Íwè³ê½pXªfBNgð³·Èçfalse
		bool M_Delete_Select_File(std::string);

		// wè³ê½tH_ðí·é@øFí·étH_ÜÅÌpX@ßèlFí·étH_ª©Â©çÈ©Á½çfalse
		bool M_Delete_Select_Folder(std::string);


		//-- ÏX --//

		// »ÝÒWÌt@CÌt@C¼ðÏX·é@øFÏXãÌt@C¼@ßèlFÏXÉ¬÷µ½çtrue
		bool M_Rename_Now_File(std::string);

		// wè³ê½t@CÌt@C¼ðÏX·é@øFÏXOÌt@C¼, ÏXãÌt@C¼@ßèlFÏXÉ¬÷µ½çtrue
		bool M_Rename_Select_File(std::string, std::string);

		// wè³ê½tH_ÌtH_¼ðÏX·é@øFÏXOÌtH_¼, ÏXãÌtH_¼@ßèlFÏXÉ¬÷µ½çtrue
		bool M_Rename_Select_Folder(std::string, std::string);


		//-- oÍ --//

		// ¡ÌêÌEÉª éêÍ»ÌðÔ·@ßèlF®^
		long long M_Get_Number(void);

		// ¡ÌêÌEÉª éêÍ»Ì­ èÌðÔ·@ßèlF®¬
		double M_Get_Float_Double_Number(void);

		// ¡Ìê©çwè³ê½¶ªÔ·@øF¶@ßèlF¶ñ
		std::string M_Get_Data_By_Number(int);

		// ¡Ìê©çwè³ê½¶ÜÅðÔ·Awè³ê½¶ªÈ©Á½ç___Not_Founds___ðÔ·@øFTõ·é¶ñ@ßèlF¶ñ
		std::string M_Get_Data_By_Text(std::string);

		// sÌnÜè©çIðÌêÜÅðÔ·@ßèlF¶ñ
		std::string M_Get_Data_Left_In_Row(void);

		// IðÌê©çsÜÅðÔ·@ßèlF¶ñ
		std::string M_Get_Data_Right_In_Row(void);

		// ¡ÌIðÌsÌnÜè©çIíèÜÅðÆé@ßèlF¶ñ
		std::string M_Get_Data_Now_Row(void);


		//-- ÒWÊu --//

		//= ¼ÚÚ®n =//

		// ¶ÌnÜèÉÚ®·é
		void M_Goto_Sentence_Start(void);

		// ¶ÌIíèÉÚ®·é
		void M_Goto_Sentence_End(void);

		// IðÌsÌnÜèÉÚ®·é
		void M_Goto_Column_In_Row_Start(void);

		// IðÌsÌIíèÉÚ®·é
		void M_Goto_Column_In_Row_End(void);

		// nÜèÌsÉÚ®·é
		void M_Goto_Start_Row(void);

		// IíèÌsÉÚ®·é
		void M_Goto_End_Row(void);

		// wè³ê½sÉÚ®·é@øFsÌÔ
		void M_Goto_Row_By_Set_Number(unsigned int);

		// wè³ê½ñÉÚ®·é@øFñÌÔ
		void M_Goto_Column_By_Set_Number(unsigned int);


		//= ÔÚÚ®n ==//

		// wè³ê½ªAÚ®·é@øFÚ®Ê
		void M_Move_Position_By_Number(int);

		// wè³ê½ªAsðÚ®·é@øFÚ®ª
		void M_Move_Raw_By_Number(int);

		// ÌsÖÚ®·é
		void M_Move_Next_Raw(void);


		//= TõÚ®n =//

		// wè³ê½¶Æ¯¶¶Ì¤¿¡ÌêÈ~ÅêÔß¢àÌð¶Í²Æ(üsàÜßÄ)TõµÄA»Ì¶ÌEÉÚ®·é@øFTõ·é¶@ßèlFÝÂ©Á½çtrue
		bool M_Goto_Right_By_Text_In_Front_Sentence(std::string);

		// wè³ê½¶Æ¯¶¶Ì¤¿¡ÌêÈOÅêÔß¢àÌð¶Í²Æ(üsàÜßÄ)TõµÄA»Ì¶ÌEÉÚ®·é@øFTõ·é¶@ßèlFÝÂ©Á½çtrue
		bool M_Goto_Right_By_Text_In_Back_Sentence(std::string);

		// wè³ê½¶Æ¯¶¶Ì¤¿¡ÌêÈ~ÅêÔß¢àÌðs²ÆÉiüsÍÜß¸ÉjTõµÄA»Ì¶ÌEÉÚ®·é@øFTõ·é¶@ßèlFÝÂ©Á½çtrue
		bool M_Goto_Right_By_Text_In_Front_Row(std::string);

		// wè³ê½¶Æ¯¶¶Ì¤¿¡ÌêÈOÅêÔß¢àÌðs²ÆÉiüsÍÜß¸ÉjTõµÄA»Ì¶ÌEÉÚ®·é@øFTõ·é¶@ßèlFÝÂ©Á½çtrue
		bool M_Goto_Right_By_Text_In_Back_Row(std::string);

		// wè³ê½¶Æ¯¶¶Ì¤¿¡ÌêÈ~ÅêÔß¢àÌðIðÌsàÅTõµÄA»Ì¶ÌEÉÚ®·é@øFTõ·é¶@ßèlFÝÂ©Á½çtrue
		bool M_Goto_Right_By_Text_In_Front_Column(std::string);

		// wè³ê½¶Æ¯¶¶Ì¤¿¡ÌêÈOÅêÔß¢àÌðIðÌsàÅTõµÄA»Ì¶ÌEÉÚ®·é@øFTõ·é¶@ßèlFÝÂ©Á½çtrue
		bool M_Goto_Right_By_Text_In_Back_Column(std::string);


		// wè³ê½¶Æ¯¶¶Ì¤¿¡ÌêÈ~ÅêÔß¢àÌð¶Í²Æ(üsàÜßÄ)TõµÄA»Ì¶Ì¶ÉÚ®·é@øFTõ·é¶@ßèlFÝÂ©Á½çtrue
		bool M_Goto_Left_By_Text_In_Front_Sentence(std::string);

		// wè³ê½¶Æ¯¶¶Ì¤¿¡ÌêÈOÅêÔß¢àÌð¶Í²Æ(üsàÜßÄ)TõµÄA»Ì¶Ì¶ÉÚ®·é@øFTõ·é¶@ßèlFÝÂ©Á½çtrue
		bool M_Goto_Left_By_Text_In_Back_Sentence(std::string);

		// wè³ê½¶Æ¯¶¶Ì¤¿¡ÌêÈ~ÅêÔß¢àÌðs²ÆÉiüsÍÜß¸ÉjTõµÄA»Ì¶Ì¶ÉÚ®·é@øFTõ·é¶@ßèlFÝÂ©Á½çtrue
		bool M_Goto_Left_By_Text_In_Front_Row(std::string);

		// wè³ê½¶Æ¯¶¶Ì¤¿¡ÌêÈOÅêÔß¢àÌðs²ÆÉiüsÍÜß¸ÉjTõµÄA»Ì¶Ì¶ÉÚ®·é@øFTõ·é¶@ßèlFÝÂ©Á½çtrue
		bool M_Goto_Left_By_Text_In_Back_Row(std::string);

		// wè³ê½¶Æ¯¶¶Ì¤¿¡ÌêÈ~ÅêÔß¢àÌðIðÌsàÅTõµÄA»Ì¶Ì¶ÉÚ®·é@øFTõ·é¶@ßèlFÝÂ©Á½çtrue
		bool M_Goto_Left_By_Text_In_Front_Column(std::string);

		// wè³ê½¶Æ¯¶¶Ì¤¿¡ÌêÈOÅêÔß¢àÌðIðÌsàÅTõµÄA»Ì¶Ì¶ÉÚ®·é@øFTõ·é¶@ßèlFÝÂ©Á½çtrue
		bool M_Goto_Left_By_Text_In_Back_Column(std::string);


		//-- ¶Tõ --//

		// wè³ê½¶ª¶ÍàÉ é©Ç¤©ðÔ·@øFTõ·é¶@ßèlFÝÂ©Á½çtrue
		bool M_Search_Text_In_Sentence(std::string);

		// wè³ê½¶ªIðÌñà é©Ç¤©ðÔ·@øFTõ·é¶@ßèlFÝÂ©Á½çtrue
		bool M_Search_Text_In_Now_Row(std::string);

		// wè³ê½¶ªwè³ê½ñà é©Ç¤©ðÔ·@øFTõ·és, Tõ·é¶@ßèlFÝÂ©Á½çtrue
		bool M_Search_Text_In_Select_Row(int, std::string);


		//-- »è --//

		// ¡IðÌê©ç¶ªêvµÄ¢é©ð²×é@ßèlFêvµ½Æ«ÌÝtrue
		bool M_Check_Text_Is_Equal_Now_Position(std::string);

		// t@Cª¶Ý·é©Ç¤©ðÔ·@øFt@CÜÅÌpX@ßèlFÝÂ©Á½çtrue
		bool M_Is_File_Exist(std::string);
	};
}


#endif // !D_INCLUDE_GUARD_FILE_USER_H_FILE



/* -- Ql --
	
	// t@CðJ­ÛÌÝè
	app	e«ÝioÍjÌOÉAXg[ÌÅãÉV[N·éBiappend Ìªj
	ate	Xg[ÌI[v¼ãÉAXg[ÌÅãÉV[N·éBiat end Ìªj
	binary	üoÍðoCiÅs¤BieLXg[hÌ½Îj
	in	üÍÌ½ßÉI[v·éB
	out	oÍÌ½ßÉI[v·éB
	trunc	ù¶ÌXg[ðI[v·éÛÉAXg[ÌàeðØèlßéBitruncate Ìªj
*/


//======================================================================
// Copyright 2023 ûüâ´½
// 
// àµà±ÌR[hð©ªÌvWFNgÉpµ½¢ÌÅ êÎA
// [AhXFtakasaka.ryusei1116@gmail.com
// Ü½ÍAûüâ´½ÜÅ²A­¾³¢B
// R[hÌs¾ªÌðàâAÅVÌóÔÌñÈÇÉÎ¢½µÜ·B
//======================================================================


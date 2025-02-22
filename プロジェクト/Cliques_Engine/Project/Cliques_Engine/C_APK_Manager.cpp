////
// Ú×   FAvP[V§äpÌNX
// à¾   F
// ì¬Ò Fûüâ´½
////


//  t@CÐç«  //
#include "C_APK_Manager.h"
#include "C_Scene_Manager.h"
#include "C_Game_Instance_Manager.h"


//  l[Xy[XÌÈª  //
using namespace GAME::APPLICATION;


//  Ïé¾  //
std::unique_ptr<C_APK_Manager> C_APK_Manager::m_this;	// ©NXÖÌANZXpÌÏ


//  Ö  //

//== vCx[g ==//

//-- ú» --//

//===============//
// Ú×   FRXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_APK_Manager::C_APK_Manager(void)
{
	return;
}


//== pubN ==//

//-- ú»ÆI¹ --//

//===============//
// Ú×   F ú»µÄgpÂ\É·é
// ø   Fvoid
// ßèl Fbool ¬÷ÌÝtrue
//===============//
bool C_APK_Manager::M_Init(void)
{
	m_this.reset(new C_APK_Manager);

	// úV[ð[h@¸sÅfalseªÔé
	return GAME::SCENE::MANAGER::C_Scene_Manager::M_Scene_Load(con_INITIALIZED_SCENE_NAME);
}


//===============//
// Ú×   FfXgN^
// ø   Fvoid
// ßèl FÈµ
//===============//
C_APK_Manager::~C_APK_Manager(void)
{
	M_Release();

	return;
}


//===============//
// Ú×   Fðú
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_APK_Manager::M_Release(void)
{
	GAME::SCENE::MANAGER::C_Scene_Manager::M_Release();
	GAME::INSTANCE::C_Game_Instance_Manager::M_All_Instance_Destroy_Update();
	m_this.reset();

	return;
}


//-- üÍ --//

//===============//
// Ú×   FAvP[VÌüÍðs¤
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_APK_Manager::M_APK_Input(void)
{
	// AvP[VªANeBuÅÈ¯êÎX[
	if (m_this == nullptr)
	{
		return;
	}


	//-- üÍ --//



	return;
}


//-- XV --//

//===============//
// Ú×   FAvP[VÌXVðs¤
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_APK_Manager::M_APK_Update(void)
{
	// AvP[VªANeBuÅÈ¯êÎX[
	if (m_this == nullptr)
	{
		return;
	}


	//-- XV --//

	// V[ÉæéQ[XVOÌXVðs¤
	GAME::SCENE::MANAGER::C_Scene_Manager::M_Get_Scene()->M_Scene_Before_Update();

	// AN^[ÌXVðs¤
	GAME::INSTANCE::C_Game_Instance_Manager::M_Update_Actor();

	// UIÌXVðs¤
	GAME::INSTANCE::C_Game_Instance_Manager::M_Update_UI();

	// |XgGtFNgÌXVðs¤
	GAME::INSTANCE::C_Game_Instance_Manager::M_Update_Post_Effect();

	// TEhÌXVðs¤
	GAME::INSTANCE::C_Game_Instance_Manager::M_Update_Sound();

	// Q[VXeÌXVðs¤
	GAME::INSTANCE::C_Game_Instance_Manager::M_Update_Game_System();

	// V[ÉæéQ[XVãÌXVðs¤
	GAME::SCENE::MANAGER::C_Scene_Manager::M_Get_Scene()->M_Scene_After_Update();

	return;
}


//-- `æ --//

//===============//
// Ú×   FAvP[VÌ`æðs¤
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_APK_Manager::M_APK_Draw(void)
{
	// AvP[VªANeBuÅÈ¯êÎX[
	if (m_this == nullptr)
	{
		return;
	}


	//-- `æ --//

	// AN^[Ì`æðs¤
	GAME::INSTANCE::C_Game_Instance_Manager::M_Draw_Actor();

	// |XgGtFNg`æXgðXV
	GAME::INSTANCE::C_Game_Instance_Manager::M_Set_Post_Effect_To_Draw_List();

	// |XgGtFNgÌUI`æOÌ`æðs¤
	GAME::INSTANCE::C_Game_Instance_Manager::M_Draw_Post_Effect_Before_UI();

	// UIÌ`æðs¤
	GAME::INSTANCE::C_Game_Instance_Manager::M_Draw_UI();

	// |XgGtFNgÌUI`æãÌ`æðs¤
	GAME::INSTANCE::C_Game_Instance_Manager::M_Draw_Post_Effect_After_UI();

	// V[Éæé`æãÌXVðs¤
	GAME::SCENE::MANAGER::C_Scene_Manager::M_Get_Scene()->M_Scene_Update_After_Draw();

	return;
}


//-- í --//

//===============//
// Ú×   FíÌtOª§ÁÄ¢éCX^Xðí·é
// ø   Fvoid
// ßèl Fvoid
//===============//
void C_APK_Manager::M_Instance_Destroy_Update(void)
{
	GAME::INSTANCE::C_Game_Instance_Manager::M_All_Instance_Destroy_Update();

	return;
}

////
// Ú×   FAj[VÌXe[^Xè`pÌ\¢Ì
// à¾   F»ÝÌÔAuh¦ÈÇAAj[VvZÉ¤ÊµÄKvÈîñðÝè
// ì¬Ò Fûüâ´½
////


//  ½dCN[hK[h  //
#ifndef D_INCLUDE_GUARD_S_ANIMATION_STATUS_H_FILE
#define D_INCLUDE_GUARD_S_ANIMATION_STATUS_H_FILE


//  l[Xy[X  //

// Aj[VpÌVXeðÄÑo·½ßÌ¼O
namespace ASSET::ANIMATION
{
	//  \¢Ì  //

	// Aj[VÌXe[^Xè`pÌ\¢Ì
	struct S_Animation_Status
	{
		float animation_time = 0.0f;	// Aj[VÔ
		float animation_blend_percent = 0.0f;	// Aj[Vuh¦
		float need_blend_time = 0.1f;	// Aj[Vuh®¹ÜÅÌÔ
		float animation_speed = 1.0f;	// Aj[V¬x
		float passed_time = 0.0f;		// oßÔ

		const int bone_sum = 0;	// {[

		bool flg_animation_end = false;		// Aj[VÌI¹
		bool flg_animation_reverse = false;	// Aj[VðtÄ¶·é©Ç¤©


		//  Ö  //

		//-- ú» --//

		// ÊíÌRXgN^ð³ø»
		S_Animation_Status(void) = delete;

		//===============//
		// Ú×   F{[ú»pÌRXgN^
		// ø   Fint {[
		// ßèl FÈµ
		//===============//
		S_Animation_Status(int in_bone_sum) : bone_sum(in_bone_sum)
		{
			return;
		}
	};
}


#endif // !D_INCLUDE_GUARD_S_ANIMATION_STATUS_H_FILE


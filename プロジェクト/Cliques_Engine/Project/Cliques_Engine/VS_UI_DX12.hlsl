////
// Ú×   FJ[ÆeNX`ðKvÆ·éUIÌeNX`p¸_VF[_[
// à¾   F
// ì¬Ò Fûüâ´½
////


//  \¢Ì  //

// ¸_VF[_[ÉüÁÄ­éîñ
struct S_VS_IN
{
	float2 position : CLIQUES0; // ÊuÀW
	float4 color : CLIQUES1; // F
	float2 uv : CLIQUES2; // eNX`
};

// ¸_VF[_[©çoÍ·éîñ
struct S_VS_OUT
{
	float4 position : SV_POSITION;  // ÊuÀW
	float4 color : COLOR0;          // F
	float2 uv : TEXCOORD0;          // UVÀW
};


//  CÖ  //
S_VS_OUT vs_main(S_VS_IN in_vs)
{
	//  Ïé¾  //
	S_VS_OUT out_vs; // ¸_VF[_[©çn·îñ
	
	
	// n³ê½îñÌZbg
	out_vs.position = float4(in_vs.position, 0.0f, 1.0f);
	out_vs.color = in_vs.color;
	out_vs.uv = in_vs.uv;
	

	// oÍÊðé
	return out_vs;
}


//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：なんらかの挑戦を行うときのみ有効にするマクロ
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_CHALLENGE_MODE_MACRO
#define D_INCLUDE_GUARD_CHALLENGE_MODE_MACRO


#if 0

// テクスチャのロードを自分で行うときのマクロ
#define D_TEXTURE_CHALLEGE true
#endif

#if 0

// アセンブラチャレンジをやるときに使うマクロ
#define D_ASM_CHALLENGE true
#endif


#endif // !D_INCLUDE_GUARD_CHALLENGE_MODE_MACRO


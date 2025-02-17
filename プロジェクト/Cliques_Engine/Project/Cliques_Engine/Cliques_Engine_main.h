//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：Cliques Engineのメイン関数の定義設定用のファイル
// 説明   ：
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_CLIQUES_ENGINE_MAIN_H_FILE
#define D_INCLUDE_GUARD_CLIQUES_ENGINE_MAIN_H_FILE


// ☆ 関数 ☆ //

//-☆- 初期化と終了時 -☆-//

// OSシステムの生成を行う
void M_OS_Create_System(void);

// レンダリングAPIの初期化を行う
void M_Rendering_API_Init(void);

// ゲームシステムの初期化を行う
void M_Game_Set_Up(void);

// ゲームの終了処理
void M_Game_End(void);


//-☆- デバッグログ -☆-//

// 初期化の成功を表示する
void M_Print_Log_Of_Succeeded_Init(void);


#endif // !D_INCLUDE_GUARD_CLIQUES_ENGINE_MAIN_H_FILE


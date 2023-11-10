//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：オブジェクトの頂点情報を円滑に設定し、レンダリングするためのシステム
// 説明   ：頂点データのレンダリングをカプセル化する
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_OBJECT_VERTEX_SETTING_H_FILE
#define D_INCLUDE_GUARD_C_OBJECT_VERTEX_SETTING_H_FILE


// ☆ ファイルひらき ☆ //
#include <memory>
#include <vector>

#include "C_Vertex_Buffer_Setting_Inform_Base.h"
#include "C_Rendering_Graphics_API_Base.h"


// ☆ ネームスペース ☆ //

// 描画に使用するシステムを呼び出すための名前
namespace RENDERING::CAPSULE
{
	// ☆ クラス ☆ //

	// オブジェクトの頂点情報を円滑に設定し、レンダリングするためのシステム
	template <class _My_Vertex_Type> class C_Object_Vertex_System
	{
	//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			std::unique_ptr<RENDERING::GRAPHICS::INSTANCE::C_Vertex_Buffer_Setting_Inform_Base> m_setting_inform;	// 頂点バッファ設定用情報

			std::vector <_My_Vertex_Type> m_vertex_data;	// 頂点データ

			std::vector <unsigned __int32> m_index_data;	// インデックスデータ

		} mpr_variable;	// プライベート変数を呼び出すための名前


	//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 初期化と終了時 -☆-//

		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：コンストラクタ
		// 引数   ：void
		// 戻り値 ：なし
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		C_Object_Vertex_System(void)
		{
			return;
		}


		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：デストラクタ、メモリ解放を行う
		// 引数   ：void
		// 戻り値 ：なし
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		~C_Object_Vertex_System(void)
		{
			mpr_variable.m_setting_inform.reset();

			mpr_variable.m_vertex_data.clear();
			mpr_variable.m_vertex_data.shrink_to_fit();

			mpr_variable.m_index_data.clear();
			mpr_variable.m_index_data.shrink_to_fit();

			return;
		}


		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：メモリ解放を行う
		// 引数   ：void
		// 戻り値 ：void
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		void M_Release(void)
		{
			mpr_variable.m_setting_inform.reset();

			mpr_variable.m_vertex_data.clear();
			mpr_variable.m_vertex_data.shrink_to_fit();

			mpr_variable.m_index_data.clear();
			mpr_variable.m_index_data.shrink_to_fit();

			return;
		}


		//-☆- 生成 -☆-//

		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：頂点情報を生成する
		// 引数   ：int 生成する頂点数, int 生成するインデックス情報数
		// 戻り値 ：void
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		void M_Create_Vertex_And_Index_Data_And_Buffer(int in_creat_vertex_sum, int in_creat_index_sum)
		{
			// ☆ 変数宣言 ☆ //
			RENDERING::GRAPHICS::CREATE::C_Create_Vertex_Buffer_Inform creat_vertex_inform;	// 頂点情報生成用情報


			// 初期化して、必要な分だけ配列を生成しなおす
			M_Release();
			mpr_variable.m_vertex_data.resize(in_creat_vertex_sum);
			mpr_variable.m_index_data.resize(in_creat_index_sum);


			// ☆ 頂点生成用情報の設定 ☆ //
			creat_vertex_inform.size_of_vertex = sizeof(_My_Vertex_Type);	// 頂点一つ分のバイト数
			creat_vertex_inform.vertex_sum = (int)mpr_variable.m_vertex_data.size();	// 頂点数
			creat_vertex_inform.index_sum = (int)mpr_variable.m_index_data.size();		// インデックス情報


			// ☆ レンダリング用頂点情報の生成 ☆ //
			RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Create_Vertex_Inform(mpr_variable.m_setting_inform, creat_vertex_inform);

			return;
		}


		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：現在の頂点とインデックスの数に合わせてバッファを生成する
		// 引数   ：void
		// 戻り値 ：void
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		void M_Create_Vertex_And_Index_Buffer_By_Now_Parameter(void)
		{
			// ☆ 変数宣言 ☆ //
			RENDERING::GRAPHICS::CREATE::C_Create_Vertex_Buffer_Inform creat_vertex_inform;	// 頂点情報生成用情報


			// ☆ 頂点生成用情報の設定 ☆ //
			creat_vertex_inform.size_of_vertex = sizeof(_My_Vertex_Type);	// 頂点一つ分のバイト数
			creat_vertex_inform.vertex_sum = (int)mpr_variable.m_vertex_data.size();	// 頂点数
			creat_vertex_inform.index_sum = (int)mpr_variable.m_index_data.size();		// インデックス情報


			// ☆ レンダリング用頂点情報の生成 ☆ //
			mpr_variable.m_setting_inform.reset();
			RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Create_Vertex_Inform(mpr_variable.m_setting_inform, creat_vertex_inform);

			return;
		}


		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：指定された数分頂点データを生成する
		// 引数   ：int 頂点データの生成数
		// 戻り値 ：void
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		void M_Creat_Vertex_Data_By_Number(int in_vertex_sum)
		{
			mpr_variable.m_vertex_data.clear();
			mpr_variable.m_vertex_data.shrink_to_fit();

			mpr_variable.m_vertex_data.resize(in_vertex_sum);
		}


		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：指定された数分頂点インデックスデータを生成する
		// 引数   ：int 頂点インデックスデータの生成数
		// 戻り値 ：void
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		void M_Creat_Index_Data_By_Number(int in_index_sum)
		{
			mpr_variable.m_index_data.clear();
			mpr_variable.m_index_data.shrink_to_fit();

			mpr_variable.m_index_data.resize(in_vertex_sum);
		}


		//-☆- 削除 -☆-//

		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：頂点データを削除する　＊頂点バッファは削除されない
		// 引数   ：void
		// 戻り値 ：void
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		void M_Delete_Vertex_Data(void)
		{
			mpr_variable.m_vertex_data.clear();
			mpr_variable.m_vertex_data.shrink_to_fit();

			return;
		}


		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：頂点インデックスデータを削除する　＊頂点インデックスバッファは削除されない
		// 引数   ：void
		// 戻り値 ：void
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		void M_Delete_Index_Data(void)
		{
			mpr_variable.m_index_data.clear();
			mpr_variable.m_index_data.shrink_to_fit();

			return;
		}


		//-☆- ゲッタ -☆-//
		
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：頂点データへの参照を返す
		// 引数   ：void
		// 戻り値 ：std::vector<_My_Vertex_Type> & 頂点データへの参照
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		std::vector<_My_Vertex_Type> & M_Get_Vertex_Data(void)
		{
			return mpr_variable.m_vertex_data;
		}


		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：頂点バッファの情報を描画するインデックスを指定して描画する
		// 引数   ：void
		// 戻り値 ：std::vector<uint32_t> & インデックスデータへの参照
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		std::vector<uint32_t> & M_Get_Index_Data(void)
		{
			return mpr_variable.m_index_data;
		}

		
		//-☆- 描画 -☆-//
		
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：頂点バッファに頂点データをセットする
		// 引数   ：void
		// 戻り値 ：void
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		void M_Vertex_Data_To_Buffer(void)
		{
			mpr_variable.m_setting_inform->M_Set_Vertex_Setting(&mpr_variable.m_vertex_data[0]);

			return;
		}


		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：インデックスバッファにインデックスデータをセットする
		// 引数   ：void
		// 戻り値 ：void
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		void M_Index_Data_To_Buffer(void)
		{
			mpr_variable.m_setting_inform->M_Set_Index_Setting(&mpr_variable.m_index_data[0]);

			return;
		}


		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：頂点バッファの情報を全て描画する
		// 引数   ：void
		// 戻り値 ：void
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		void M_Draw_All_Vertex(void)
		{
			RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Draw_All_Vertex_By_Index(mpr_variable.m_setting_inform);

			return;
		}


		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：頂点バッファの情報を描画するインデックスを指定して描画する
		// 引数   ：int 描画するインデックス情報の始まりの番地, int 描画するインデックス情報の終わりの番地
		// 戻り値 ：void
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		void M_Draw_Select_Vertex(int in_start_point, int in_end_point)
		{
			RENDERING::GRAPHICS::C_Rendering_Graphics_API_Base::M_Get_Instance()->M_Draw_Select_Vertex_By_Index(mpr_variable.m_setting_inform, in_start_point, in_end_point);

			return;
		}
	};
}


#endif // !D_INCLUDE_GUARD_C_OBJECT_VERTEX_SETTING_H_FILE

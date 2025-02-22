//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：クラスごとに分離したリストを管理するシステムの基底クラス
// 説明   ：C_Instance_List_Overall_Baseの派生クラスにある程度共通して必要な機能をまとめたクラス
// 作成者 ：��坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_C_INSTANCE_LIST_BASE_H_FILE
#define D_INCLUDE_GUARD_C_INSTANCE_LIST_BASE_H_FILE


// ☆ 注意書き ☆ //

// 派生クラスでは管理範囲に応じて、conceptを使うこと

// **** C++ 20 以降の機能 **** //
// テンプレート引数に制限をかけれる
// 下の例では、テンプレート引数の基底クラスがTEST_CLASSでなければエラーが出るようになるコードを書いている（記録用）
#ifdef false
template<typename C_Class>
concept CONCEPT_CLASS = std::is_base_of<TEST_CLASS, C_Class>::value;

template <CONCEPT_CLASS TEMPLATE>
class C_INS1 : public C_TEST_TEMPLATE_CLASS<C_INS1, CONCEPT_CLASS> { };
#endif // false


// ☆ ファイルひらき ☆ //
#include <algorithm>
#include <functional>
#include <vector>
#include <string>

#include "C_List_Divided_By_Class_Overall_Base.h"


// ☆ マクロ ☆ //
#define D_DIVIDED_LIST_TEMPLATE template <template <typename> class C_List, class C_Instance>	// テンプレート型定義用マクロ
// * template <typename> class はテンプレート引数にテンプレート型のクラスを要求するということ


// ☆ ネームスペース ☆ //

// リストの基底となるシステムを呼び出すための名前
namespace SYSTEM::LIST::BASE
{
	// ☆ クラス ☆ //

	// クラスごとに分離したリストを管理するシステムの基底クラス
	D_DIVIDED_LIST_TEMPLATE class C_List_Divided_By_Class_Base : public SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base
	{
		//==☆ プロテクト ☆==//
	protected:

		// ☆ 変数宣言 ☆ //
		static inline std::vector <C_Instance> m_instance_list;	// インスタンスの管理用リスト

		SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * m_list_instance_address = nullptr;	// このリストへのアドレス


		// ☆ 関数 ☆ //

		//-☆- 初期化 -☆-//

		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：コンストラクタ　シングルトン化する
		// 引数   ：void
		// 戻り値 ：なし
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		C_List_Divided_By_Class_Base(void)
		{
			return;
		}


		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：リストのインスタンスへのアドレスをセットする
		// 引数   ：C_List_All_Base * リストのインスタンスへのアドレス
		// 戻り値 ：void
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		void M_Set_My_Instance_Address(SYSTEM::LIST::BASE::ALL_LIST_BASE::C_List_All_Base * in_set_list_address)
		{
			m_list_instance_address = in_set_list_address;

			return;
		}


		//-☆- 生成 -☆-//

		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：インスタンスの生成を行う
		// 引数   ：void
		// 戻り値 ：C_Instance & 生成したインスタンスの参照
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		static C_Instance & M_Create_Instance(void)
		{
			// このリストがまだインスタンスを持っていない状態であったら、管理用配列にリストを登録
			if (m_instance_list.size() <= 0)
			{
				// このリストがまだインスタンスを持っていない状態であったら、管理用配列にリストを登録
				C_List_Divided_By_Class_Overall_Base<C_List>::M_Add_To_List_Of_All_Instance_List(m_list_instance_address);
			}

			// インスタンスを生成する
			m_instance_list.resize(m_instance_list.size() + 1);
			return m_instance_list[m_instance_list.size() - 1];
		}


		//-☆- 削除 -☆-//

		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：管理している全てのインスタンスを削除する
		// 引数   ：void
		// 戻り値 ：void
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		static void M_Delete_All_Instance(void)
		{
			// 配列データを削除
			m_instance_list.clear();
			m_instance_list.shrink_to_fit();

			// データを持っていないのでリストから登録解除
			C_List_Divided_By_Class_Overall_Base<C_List>::M_Delete_By_List_Of_All_Instance_List(m_list_instance_address);

			return;
		}


		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：渡されたラムダ式の条件に当てはまるインスタンスを消す
		// 引数   ：function<bool(C_Instance &)> 削除インスタンスのチェック用のラムダ式
		// 戻り値 ：bool リストの中の全ての要素が削除されたらtrue
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		static bool M_Delete_Instance_By_Lambda(std::function<bool(C_Instance & )> in_delete_lambda, C_List<C_Instance> * list_instance)
		{
			// 指定された条件通りのインスタンスを削除する
			m_instance_list.before_func_update_list.erase
			(
				std::remove_if
				(
					m_instance_list.begin(), 
					m_instance_list.end(), 
					in_delete_lambda
				), 
				m_instance_list.end()
			);


			// リストのデータを全て削除したのなら、リストを登録解除する
			if (m_instance_list.size() <= 0)
			{
				C_List_Divided_By_Class_Overall_Base<C_List>::M_Delete_By_List_Of_All_Instance_List(m_list_instance_address);

				return true;
			}

			return false;
		}
		

		//==☆ パブリック ☆==//
	public:

		// ☆ 関数 ☆ //

		//-☆- 終了時 -☆-//

		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：デストラクタ
		// 引数   ：void
		// 戻り値 ：なし
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		virtual ~C_List_Divided_By_Class_Base(void) override
		{
			return;
		}


		//-☆- ゲッタ -☆-//

		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		// 詳細   ：インスタンスのリストの参照を返す
		// 引数   ：void
		// 戻り値 ：vector <C_Instance> & リストの参照
		//☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆=☆//
		static std::vector<C_Instance> & M_Get_List(void)
		{
			return m_instance_list;
		}


		//-☆- 更新 -☆-//

		// リスト内のインスタンスの更新を行う
		virtual void M_Instance_Update(void) = 0;


		//-☆- 描画 -☆-//

		// リスト内のインスタンスの描画を行う
		virtual void M_Instance_Draw(void) = 0;


		//-☆- 削除 -☆-//

		// 一部のインスタンスの削除を行う
		virtual void M_Delete_Instance_Execute(void) override = 0;

		// 大部分のインスタンスの削除を行う
		virtual void M_Delete_Most_OF_Instance_Execute(void) = 0;

		// 全てのインスタンスの削除を行う
		virtual void M_Delete_All_Instance_Execute(void) override = 0;
	};
}


// ☆ マクロ削除 ☆ //
#undef D_DIVIDED_LIST_TEMPLATE


#endif // !D_INCLUDE_GUARD_C_INSTANCE_LIST_BASE_H_FILE


//☆======================================================================☆
// Copyright 2023 ��坂龍誠
// 
// もしもこのコードを自分のプロジェクトに利用したいのであれば、
// メールアドレス：takasaka.ryusei1116@gmail.com
// または、��坂龍誠までご連絡ください。
// コードの不明部分の解説や、最新の状態の提供などに対応いたします。
//☆======================================================================☆




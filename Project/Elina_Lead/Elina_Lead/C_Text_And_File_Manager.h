//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//
// 詳細   ：ファイル制御用システムのクラス
// 説明   ：ファイルを生成し、データを記録できる
// 作成者 ：髙坂龍誠
//☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆//


// ☆ 多重インクルードガード ☆ //
#ifndef D_INCLUDE_GUARD_FILE_USER_H_FILE
#define D_INCLUDE_GUARD_FILE_USER_H_FILE


// ☆ ファイルひらき ☆ //
#include <vector>
#include <string>


// ☆ ネームスペース ☆ //

// テキストを制御するシステムを呼び出すための名前
namespace SYSTEM::TEXT
{
	// ☆ 定数 ☆ //

	// 編集モードを指定するための列挙
	enum class E_EDIT_MODE
	{
		e_TEXT,		// テキスト形式
		e_BINARY,	// バイナリ形式
	};


	// ☆ クラス ☆ //

	// 文章を制御するためのクラス、ファイルの読み書きも行う
	class C_Text_And_File_Manager
	{
		//==☆ プライベート ☆==//
	private:

		// ☆ 変数宣言 ☆ //

		// プライベート変数をまとめた構造体
		struct SPr_Variable
		{
			const std::string con_default_name = "default_file_name";	// デフォルトのファイル名

			E_EDIT_MODE mode_setting = E_EDIT_MODE::e_TEXT;	// 編集モード設定

			std::vector<std::string> stack_data;	// 文章のデータ（第一配列＝行,　第二配列＝列および文字）

			std::string file_path = con_default_name;	// ファイルまでのパス

			int row_number = 0;		// 行の番号
			int column_number = 0;	// 列の番号

		} mpr_variable;	// プライベート変数を呼び出すための名前


		//-☆- データ検証 -☆-//

		// 入力されたパス名がバグを引き起こさないものかどうかを判定する　引数：パス名　戻り値：パス名が正しければtrue
		bool M_Is_File_Path_Succeed(std::string & );

		// 入力されたパス名のうちフォルダの部分がバグを引き起こさないものかどうかを判定する　引数：パス名　戻り値：パス名が正しければtrue
		bool M_Is_Folder_Path_Is_Succeed(std::string & );

		// ファイルが指定されているかどうかを判定　引数：パス名　戻り値：ファイルまでのパスならtrue フォルダなどまでならfalse
		bool M_Is_File(std::string & );

		// 指定された文字が改行文字であるかどうかを判定する　引数：文字データ　戻り値：trueなら改行コード
		bool M_Is_CR(const char &);


		//==☆  パブリック  ☆==//
	public:

		//-☆- 初期化と終了時 -☆-//

		// コンストラクタ
		C_Text_And_File_Manager(void);

		// データ初期化
		void M_Reset_Data(void);

		// デストラクタ
		~C_Text_And_File_Manager(void);


		//-☆- データ変換 -☆-//

		// 文字列を10進数のINT型に変換する　引数：変換するデータ　戻り値：変換結果
		static int M_Convert_Data_Char_To_X16INT(std::string);


		//-☆- 生成 -☆-//

		// 渡されたパスのファイルが存在していなければ生成する（パス名+改行文字をフォルダとする）　引数：ファイルまでのパス
		bool M_Creat_Path_Of_Folder(std::string);

		// パスまでのファイルとフォルダがなければ生成する（パス名+改行文字をフォルダとする）　引数：ファイルまでのパス
		bool M_Creat_File_And_Folder_If_File_Not_Exist(std::string);


		//-☆- セッタ -☆-//

		// これから編集するファイルのパスを指定する（なければ生成される）　引数：ファイルのパス　戻り値：成功時のみtrue
		bool M_Set_File_Path(std::string);

		// 編集モードを指定する　引数：編集モードを指定する番号
		void M_Set_Edit_Mode(E_EDIT_MODE);


		//-☆- ゲッタ -☆-//

		// 現在のデータの参照を渡す　戻り値：ファイルデータの文字列
		const std::vector<std::string> & M_Get_File_Data_Refer(void);

		// 現在編集中のファイルのパスを返す　戻り値：ファイルパスの文字列
		const std::string & M_Get_File_Path_Refer(void);

		// 現在の行の番号を返す
		int M_Get_Now_Row(void);

		// 文章の行数を返す
		int M_Get_Text_Row_Sum(void);

		// 現在の列の番号を返す
		int M_Get_Now_Column(void);

		// 今選択中の行の文字数を返す
		int M_Get_Column_Sum_In_Now_Row(void);

		// 現在の文章全体の文字数を返す
		int M_Get_Sentence_Text_Size(void);


		//-☆- セーブ -☆-//

		// 操作中のファイルに現在のデータを上書きでセーブする　戻り値：成功時のみtrue
		bool M_Save_Data_To_Now_File(void);

		// 指定されたファイルに現在のデータを上書きでセーブする　引数：ファイルのパス　戻り値：成功時のみtrue
		bool M_Save_Data_To_Select_File(std::string);

		// 操作中のファイルに現在のデータを追加でセーブする　戻り値：成功時のみtrue
		bool M_Add_Data_To_Now_File(void);

		// 指定されたファイルに現在のデータを追加でセーブする　引数：ファイルのパス　戻り値：成功時のみtrue
		bool M_Add_Data_To_Select_File(std::string);


		//-☆- ロード -☆-//

		// 操作中のファイルからデータを読み込む　戻り値：成功時のみture
		bool M_Load_Now_File(void);

		// 操作中のファイルから指定された行間だけデータを読み込む　引数：読み始まりの行, 読み終わりの行　戻り値：成功時のみture
		bool M_Load_Now_File_Only_Select_Raw(int, int);

		// 指定されたファイルからデータを読み込む　引数：ファイルのパス　戻り値：成功時のみture
		bool M_Load_Select_File(std::string);

		// 指定されたファイルから指定された行間だけデータを読み込む　引数：ファイルのパス, 読み始まりの行, 読み終わりの行　戻り値：成功時のみture
		bool M_Load_Select_File_Only_Select_Raw(std::string, int, int);


		//-☆- 入力 -☆-//

		// 指定されたデータを現在の操作位置から入力する　引数：入力するデータ
		void M_Input_This_Data(short);

		// 指定されたデータを現在の操作位置から入力する　引数：入力するデータ
		void M_Input_This_Data(unsigned short);

		// 指定されたデータを現在の操作位置から入力する　引数：入力するデータ
		void M_Input_This_Data(int);

		// 指定されたデータを現在の操作位置から入力する　引数：入力するデータ
		void M_Input_This_Data(unsigned int);

		// 指定されたデータを現在の操作位置から入力する　引数：入力するデータ
		void M_Input_This_Data(long long);

		// 指定されたデータを現在の操作位置から入力する　引数：入力するデータ
		void M_Input_This_Data(unsigned long long);

		// 指定されたデータを現在の操作位置から入力する　引数：入力するデータ
		void M_Input_This_Data(std::string);

		// 指定されたデータを現在の操作位置から入力する　引数：入力するデータ
		void M_Input_This_Data(double);


		//-☆- 削除 -☆-//

		// 指定されたデータを文章内から指定された回数分だけ削除する　引数：削除回数（０で全て削除）, 削除する文字
		void M_Delete_Data_Equal_This_Text_In_Sentence(int, std::string);

		// 指定されたデータを選択中の行内から指定された回数分だけ削除する　引数：削除回数（０で全て削除）, 削除する文字
		void M_Delete_Data_Eqaul_This_Text_In_Now_Row(int, std::string);

		// 指定されたデータを選択中位置の右側の行内から指定された回数分だけ削除する　引数：削除回数（０で全て削除）, 削除する文字
		void M_Delete_Data_Eqaul_This_Text_In_Now_Row_For_Right(int, std::string);

		// 指定されたデータを選択中位置の左側の行内から指定された回数分だけ削除する　引数：削除回数（０で全て削除）, 削除する文字
		void M_Delete_Data_Eqaul_This_Text_In_Now_Row_For_Left(int, std::string);

		// 指定された行を削除する　引数：削除する行
		void M_Delete_Row(int);

		// 今の場所から指定された文字数分だけ文字を削除する（行はこえない）　引数：削除する文字数
		void M_Delete_Column(int);

		// 選択中のファイルを削除する　戻り値：削除するファイルが見つからなかった、もしくは指定されたパスがディレクトリをさすならfalse
		bool M_Delete_Now_File(void);

		// 指定されたファイルを削除する　引数：削除するファイルまでのパス　戻り値：削除するファイルが見つからなかった、もしくは指定されたパスがディレクトリをさすならfalse
		bool M_Delete_Select_File(std::string);

		// 指定されたフォルダを削除する　引数：削除するフォルダまでのパス　戻り値：削除するフォルダが見つからなかったらfalse
		bool M_Delete_Select_Folder(std::string);


		//-☆- 変更 -☆-//

		// 現在編集中のファイルのファイル名を変更する　引数：変更後のファイル名　戻り値：変更に成功したらtrue
		bool M_Rename_Now_File(std::string);

		// 指定されたファイルのファイル名を変更する　引数：変更前のファイル名, 変更後のファイル名　戻り値：変更に成功したらtrue
		bool M_Rename_Select_File(std::string, std::string);

		// 指定されたフォルダのフォルダ名を変更する　引数：変更前のフォルダ名, 変更後のフォルダ名　戻り値：変更に成功したらtrue
		bool M_Rename_Select_Folder(std::string, std::string);


		//-☆- 出力 -☆-//

		// 今の場所の右に数字がある場合はその数字を返す　戻り値：整数型
		long long M_Get_Number(void);

		// 今の場所の右に数字がある場合はその少数ありの数字を返す　戻り値：浮動小数
		double M_Get_Float_Double_Number(void);

		// 今の場所から指定された文字分返す　引数：文字数　戻り値：文字列
		std::string M_Get_Data_By_Number(int);

		// 今の場所から指定された文字までを返す、指定された文字がなかったら___Not_Founds___を返す　引数：探索する文字列　戻り値：文字列
		std::string M_Get_Data_By_Text(std::string);

		// 行の始まりから選択中の場所までを返す　戻り値：文字列
		std::string M_Get_Data_Left_In_Row(void);

		// 選択中の場所から行末までを返す　戻り値：文字列
		std::string M_Get_Data_Right_In_Row(void);

		// 今の選択中の行の始まりから終わりまでをとる　戻り値：文字列
		std::string M_Get_Data_Now_Row(void);


		//-☆- 編集位置 -☆-//

		//=☆ 直接移動系 ☆=//

		// 文の始まりに移動する
		void M_Goto_Sentence_Start(void);

		// 文の終わりに移動する
		void M_Goto_Sentence_End(void);

		// 選択中の行の始まりに移動する
		void M_Goto_Column_In_Row_Start(void);

		// 選択中の行の終わりに移動する
		void M_Goto_Column_In_Row_End(void);

		// 始まりの行に移動する
		void M_Goto_Start_Row(void);

		// 終わりの行に移動する
		void M_Goto_End_Row(void);

		// 指定された行に移動する　引数：行の番号
		void M_Goto_Row_By_Set_Number(unsigned int);

		// 指定された列に移動する　引数：列の番号
		void M_Goto_Column_By_Set_Number(unsigned int);


		//=☆ 間接移動系 ☆==//

		// 指定された数分、移動する　引数：移動量
		void M_Move_Position_By_Number(int);

		// 指定された数分、行を移動する　引数：移動分
		void M_Move_Raw_By_Number(int);

		// 次の行へ移動する
		void M_Move_Next_Raw(void);


		//=☆ 探索移動系 ☆=//

		// 指定された文字と同じ文字のうち今の場所以降で一番近いものを文章ごと(改行も含めて)探索して、その文字の右に移動する　引数：探索する文字　戻り値：みつかったらtrue
		bool M_Goto_Right_By_Text_In_Front_Sentence(std::string);

		// 指定された文字と同じ文字のうち今の場所以前で一番近いものを文章ごと(改行も含めて)探索して、その文字の右に移動する　引数：探索する文字　戻り値：みつかったらtrue
		bool M_Goto_Right_By_Text_In_Back_Sentence(std::string);

		// 指定された文字と同じ文字のうち今の場所以降で一番近いものを行ごとに（改行は含めずに）探索して、その文字の右に移動する　引数：探索する文字　戻り値：みつかったらtrue
		bool M_Goto_Right_By_Text_In_Front_Row(std::string);

		// 指定された文字と同じ文字のうち今の場所以前で一番近いものを行ごとに（改行は含めずに）探索して、その文字の右に移動する　引数：探索する文字　戻り値：みつかったらtrue
		bool M_Goto_Right_By_Text_In_Back_Row(std::string);

		// 指定された文字と同じ文字のうち今の場所以降で一番近いものを選択中の行内で探索して、その文字の右に移動する　引数：探索する文字　戻り値：みつかったらtrue
		bool M_Goto_Right_By_Text_In_Front_Column(std::string);

		// 指定された文字と同じ文字のうち今の場所以前で一番近いものを選択中の行内で探索して、その文字の右に移動する　引数：探索する文字　戻り値：みつかったらtrue
		bool M_Goto_Right_By_Text_In_Back_Column(std::string);


		// 指定された文字と同じ文字のうち今の場所以降で一番近いものを文章ごと(改行も含めて)探索して、その文字の左に移動する　引数：探索する文字　戻り値：みつかったらtrue
		bool M_Goto_Left_By_Text_In_Front_Sentence(std::string);

		// 指定された文字と同じ文字のうち今の場所以前で一番近いものを文章ごと(改行も含めて)探索して、その文字の左に移動する　引数：探索する文字　戻り値：みつかったらtrue
		bool M_Goto_Left_By_Text_In_Back_Sentence(std::string);

		// 指定された文字と同じ文字のうち今の場所以降で一番近いものを行ごとに（改行は含めずに）探索して、その文字の左に移動する　引数：探索する文字　戻り値：みつかったらtrue
		bool M_Goto_Left_By_Text_In_Front_Row(std::string);

		// 指定された文字と同じ文字のうち今の場所以前で一番近いものを行ごとに（改行は含めずに）探索して、その文字の左に移動する　引数：探索する文字　戻り値：みつかったらtrue
		bool M_Goto_Left_By_Text_In_Back_Row(std::string);

		// 指定された文字と同じ文字のうち今の場所以降で一番近いものを選択中の行内で探索して、その文字の左に移動する　引数：探索する文字　戻り値：みつかったらtrue
		bool M_Goto_Left_By_Text_In_Front_Column(std::string);

		// 指定された文字と同じ文字のうち今の場所以前で一番近いものを選択中の行内で探索して、その文字の左に移動する　引数：探索する文字　戻り値：みつかったらtrue
		bool M_Goto_Left_By_Text_In_Back_Column(std::string);


		//-☆- 文字探索 -☆-//

		// 指定された文字が文章内にあるかどうかを返す　引数：探索する文字　戻り値：みつかったらtrue
		bool M_Serch_Text_In_Sentence(std::string);

		// 指定された文字が選択中の列内あるかどうかを返す　引数：探索する文字　戻り値：みつかったらtrue
		bool M_Serch_Text_In_Now_Row(std::string);

		// 指定された文字が指定された列内あるかどうかを返す　引数：探索する行, 探索する文字　戻り値：みつかったらtrue
		bool M_Serch_Text_In_Select_Row(int, std::string);


		//-☆- 判定 -☆-//

		// 今選択中の場所から文字が一致しているかを調べる　戻り値：一致したときのみtrue
		bool M_Check_Text_Is_Eqaul_Now_Position(std::string);

		// ファイルが存在するかどうかを返す　引数：ファイルまでのパス　戻り値：みつかったらtrue
		bool M_Is_File_Exist(std::string);
	};
}


#endif // !D_INCLUDE_GUARD_FILE_USER_H_FILE



/* -☆- 参考 -☆-
	
	// ファイルを開く際の設定
	app	各書き込み（出力）の前に、ストリームの最後にシークする。（append の略）
	ate	ストリームのオープン直後に、ストリームの最後にシークする。（at end の略）
	binary	入出力をバイナリで行う。（テキストモードの反対）
	in	入力のためにオープンする。
	out	出力のためにオープンする。
	trunc	既存のストリームをオープンする際に、ストリームの内容を切り詰める。（truncate の略）
*/


//☆======================================================================☆
// Copyright 2023 髙坂龍誠
// 
// もしもこのコードを自分のプロジェクトに利用したいのであれば、
// メールアドレス：takasaka.ryusei1116@gmail.com
// または、髙坂龍誠までご連絡ください。
// コードの不明部分の解説や、最新の状態の提供などに対応いたします。
//☆======================================================================☆


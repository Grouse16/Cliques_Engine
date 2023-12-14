using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace _3D_Model_Converter_And_Drawer
{
    // ☆ 構造体 ☆ //

    // 現在のファイルの場所情報の構造体
    public struct S_Now_File_Data_Position
    {
        // ☆ 変数宣言 ☆ //
        private int m_now_line;   // 現在の行
        private int m_now_column;   // 現在の列


        // ☆ プロパティ ☆ //

        // 現在の行番号
        public int mp_now_line
        {
            // ゲッタ
            get
            {
                return m_now_line;
            }

            // セッタ
            set
            {
                m_now_line = value;

                return;
            }
        }

        // 現在の列番号
        public int mp_now_column
        {
            // ゲッタ
            get
            {
                return m_now_column;
            }


            // セッタ
            set
            {
                m_now_column = value;

                return;
            }
        }


        // ☆ 関数 ☆ //

        //-☆- 初期化 -☆-//

        // コンストラクタ　引数：初期の行番号, 初期の列番号
        public S_Now_File_Data_Position(int in_line, int in_column)
        {
            m_now_line = in_line;
            m_now_column = in_column;

            return;
        }
    }


    // ☆ クラス ☆ //

    // 計算システムをまとめたクラス
    internal class CS_My_Math_System
    {
        // ☆ 関数 ☆ //

        //-☆- ファイル -☆-//

        // 渡された絶対パスを、自ファイルからの相対パスに変換する
        static public string M_Get_Relative_Path(string in_path)
        {
            // ☆ 変数宣言 ☆ //
            Uri uri_base_path = new Uri(System.Reflection.Assembly.GetExecutingAssembly().Location);    // 基本となる相対元のパス
            Uri uri_relative_check_path = new Uri(in_path);                                             // 相対パスに変換したいシステムのパス
            Uri uri_relative_path = uri_base_path.MakeRelativeUri(uri_relative_check_path);             // 絶対Uriから相対Uriを取得する

            return uri_relative_path.ToString();   // 相対パス
        }


        //-☆- 文字列 -☆-//

        // 指定された行から文字を探索し、その右の番号を示す　引数：探索元の文字列, 探索するワード, 探索開始位置　戻り値：指定されたワードから一つ右の文字の番号、なければ(0,0)
        static public S_Now_File_Data_Position M_Search_Word_And_Go_To_Right(List<string> in_searched_by, string in_search_word, int start_line)
        {
            for (int l_now_line = start_line; l_now_line < in_searched_by.Count; l_now_line++)
            {
                for (int l_now_column = 0; l_now_line + in_search_word.Length < in_searched_by[l_now_line].Length; l_now_line++)
                {
                    // ☆ 変数宣言 ☆ //
                    bool flg_found = true; // 見つかった時のみtrueになるフラグ


                    // 探索し、一致した時のみtrueとなるようにする
                    for (int l_now_search_word = 0; l_now_search_word < in_search_word.Length; l_now_search_word++)
                    {
                        // 一致しないならfalseをセットして探索をやめる
                        if (in_searched_by[l_now_line][l_now_column + l_now_search_word] != in_search_word[l_now_search_word])
                        {
                            flg_found = false;
                        }
                    }


                    // 見つかったらその場所の右の一文字の番号を返す
                    if (flg_found)
                    {
                        return new S_Now_File_Data_Position(l_now_line, l_now_column + in_search_word.Length);
                    }
                }
            }

            // 見つからなかったら初期値を返す
            return new S_Now_File_Data_Position(0, 0);
        }
    }
}

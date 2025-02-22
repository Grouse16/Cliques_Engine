﻿using System;
using System.Collections.Generic;

namespace CS_MY_MATH
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


        //-☆- 移動 -☆-//

        // 次の行へ移動する、次の行がなければfalseを返す　引数：ファイルのデータ　戻り値：次の行があるときはtrue、ないときはfalse
        public bool M_Goto_Next_Data(in List<string> in_file_data)
        {
            // 次の行番号を指定
            m_now_line += 1;
            m_now_column = 0;

            // 次の行が無ければfalseを返す
            if (in_file_data.Count <= m_now_line)
            {
                return false;
            }

            // 次の行があればtrueを返す
            return true;
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
        static public S_Now_File_Data_Position M_Search_Word_And_Go_To_Right(List<string> in_searched_by, string in_search_word, S_Now_File_Data_Position in_start_position)
        {
            // ☆ 変数宣言 ☆ //
            int start_loop_column = in_start_position.mp_now_column;  // 探索開始位置の列番号


            // 指定された場所から一行づつ探索する
            for (int l_now_line = in_start_position.mp_now_line; l_now_line < in_searched_by.Count; l_now_line++)
            {
                // ☆ 変数宣言 ☆ //
                int can_search_column = in_searched_by[l_now_line].Length - in_search_word.Length;   // 探索できる最大の列番号


                // 探索できる範囲内で探索を行う
                for (int l_now_column = start_loop_column; l_now_column <= can_search_column; l_now_column++)
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

                            break;
                        }
                    }


                    // 見つかったらその場所の右の一文字の番号を返す
                    if (flg_found)
                    {
                        return new S_Now_File_Data_Position(l_now_line, l_now_column + in_search_word.Length);
                    }
                }


                // 二回目以降は行の先頭から探索する
                start_loop_column = 0;
            }

            // 見つからなかったら初期値を返す
            return new S_Now_File_Data_Position(0, 0);
        }


        // 指定された行から文字を探索し、その右の番号を示す　引数：探索元の文字列, 探索するワード, 探索開始位置　戻り値：指定されたワードから一つ右の文字の番号、なければ(0,0)
        static public int M_Search_Word_And_Go_To_Right(string in_searched_by, string in_search_word, int in_start_position)
        {
            // ☆ 変数宣言 ☆ //
            int can_search_column = in_searched_by.Length - in_search_word.Length;   // 探索できる最大の列番号


            // 探索できる範囲内で探索を行う
            for (int l_now_column = in_start_position; l_now_column < can_search_column; l_now_column++)
            {
                // ☆ 変数宣言 ☆ //
                bool flg_found = true; // 見つかった時のみtrueになるフラグ


                // 探索し、一致した時のみtrueとなるようにする
                for (int l_now_search_word = 0; l_now_search_word < in_search_word.Length; l_now_search_word++)
                {
                    // 一致しないならfalseをセットして探索をやめる
                    if (in_searched_by[l_now_column + l_now_search_word] != in_search_word[l_now_search_word])
                    {
                        flg_found = false;

                        break;
                    }
                }


                // 見つかったらその場所の右の一文字の番号を返す
                if (flg_found)
                {
                    return l_now_column + in_search_word.Length;
                }
            }

            // 見つからなかったら初期値を返す
            return 0;
        }


        // 指定された文字までを切り取る　引数：切り取りの開始位置, 切り取り元の文字, 切り取る文字　戻り値：切り取った文字列
        static public string M_Get_String_Until_This_Word(int in_start_point, string in_string_data, char in_word)
        {
            // ☆ 変数宣言 ☆ //
            int index = in_string_data.Substring(in_start_point).IndexOf(in_word);  // 切り取る文字がある文字番号


            // 指定した文字が見つかった場合は、その位置までの部分文字列を取得
            if (index >= 0)
            {
                return in_string_data.Substring(in_start_point, index);
            }

            // 指定した文字が見つからなかった場合は、--NOT_FOUND--を返す
            return "--NOT_FOUND--";
        }
    }
}

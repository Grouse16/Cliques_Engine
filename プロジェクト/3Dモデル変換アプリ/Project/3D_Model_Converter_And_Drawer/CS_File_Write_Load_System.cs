using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _3D_Model_Converter_And_Drawer
{
    // ☆ クラス ☆ //

    // ファイル書き込みシステム
    public class CS_File_Write_Load_System
    {
        // ☆ 関数 ☆ //

        //-☆- 書き込み -☆-//

        // ファイルにデータを書き込む　引数：書き込むファイルのパス, 書き込むデータ
        static public void M_Write_Data_To_File(string in_file_path, List<string> in_write_data)
        {
            // 書き込むデータが存在しない時は終了
            if (in_write_data.Count <= 0)
            {
                return;
            }


            // 書き込み
            System.IO.File.WriteAllText(in_file_path, in_write_data[0] + Environment.NewLine);
            for (int now_write_raw = 1; now_write_raw < in_write_data.Count; now_write_raw++)
            {
                System.IO.File.AppendAllText(in_file_path, in_write_data[now_write_raw] + Environment.NewLine);
            }

            return;
        }


        //-☆- 読み込み -☆-//

        // ファイルからデータを読み込む　引数：読み込むファイルのパス, 読み込んだデータ　戻り値：読み込みに成功したらtrue
        static public void M_Read_Data_From_File(string in_file_path, out List<string> out_read_data)
        {
            // ☆　変数宣言 ☆ //
            StreamReader file_data = new StreamReader(in_file_path); // 指定されたファイルのデータ

            bool is_file_end = false;   // ファイルの終わりに来たかどうか


            // 読み込んだデータを初期化
            out_read_data = new List<string>();


            // ファイルの終わりに来るまで読み取る
            while (is_file_end == false)
            {
                // ☆ 変数宣言 ☆ //
                string new_line = file_data.ReadLine();  // 新しい行のデータ


                // もうデータがないなら終了
                if (new_line == null)
                {
                    is_file_end = true;
                }

                // データがあるなら読み取ったデータのリストに追加
                else
                {
                    out_read_data.Add(new_line);
                }
            }

            // ファイルを閉じる
            file_data.Close();

            return;
        }


        //-☆- ファイル選択 -☆-//

        // ファイル選択ダイアログを表示し、選択されたファイルのパスを返す　引数：結果のファイルパス, タイトル, ファイル名, 拡張子　戻り値：ダイアログでOKの操作が行われたらtrue
        static public bool M_Get_File_Path(out string out_file_path, string in_write_title, string in_file_name, string in_file_extension)
        {
            // ☆ 変数宣言 ☆ //
            SaveFileDialog save_fle_dialog = new SaveFileDialog();  // ファイルセーブ用システム


            // ファイルパスを初期化
            out_file_path = "";

            // 初期のファイル名
            save_fle_dialog.FileName = in_file_name + "." + in_file_extension;

            // 初期表示するディレクトリを設定
            save_fle_dialog.InitialDirectory = System.IO.Path.GetDirectoryName(System.Reflection.Assembly.GetExecutingAssembly().Location);

            // ファイルの種類を設定
            save_fle_dialog.Filter = in_file_extension + "ファイル(*." + in_file_extension + ";*." + in_file_extension + ")| *." + in_file_extension + "; *." + in_file_extension + "| すべてのファイル(*.*)|*.*";

            // ファイルの種類の初期表示を設定
            save_fle_dialog.FilterIndex = 1;

            // タイトルを設定
            save_fle_dialog.Title = in_write_title;

            // ダイアログボックスを閉じる前に現在のディレクトリを復元するようにする
            save_fle_dialog.RestoreDirectory = true;

            // 既に存在するファイル名を指定したとき警告する
            save_fle_dialog.OverwritePrompt = true;

            // 存在しないパスが指定されたとき警告を表示する
            save_fle_dialog.CheckPathExists = true;


            // ダイアログを表示し、OKボタンが押されたらtrueを返す
            if (save_fle_dialog.ShowDialog() == DialogResult.OK)
            {
                out_file_path = save_fle_dialog.FileName;
                return true;
            }

            // キャンセルされたらfalseを返す
            return false;
        }

        
        // フォルダを選択するダイアログを表示し、選択されたフォルダのパスを返す　引数：結果のフォルダパス　戻り値：ダイアログでOKの操作が行われたらtrue
        static public bool M_Get_Folder_Path(out string out_folder_path)
        {
            // フォルダパスを初期化
            out_folder_path = "";


            // フォルダ選択ダイアログを表示
            using (var open_file_data = new OpenFileDialog() { FileName = "SelectFolder", Filter = "Folder|.", CheckFileExists = false })
            {
                // フォルダが選択された時はそこまでのパスをセット
                if (open_file_data.ShowDialog() == DialogResult.OK)
                {
                    out_folder_path = Path.GetDirectoryName(open_file_data.FileName) + "\\";

                    return true;
                }

                // フォルダが選択されていない時は終了
                else
                {
                    return false;
                }
            }
        }


        //-☆- 読み取り -☆-//

        // 指定された文字までの文字列を数値に変換して返し、指定された文字の次まで移動する　引数：変換する文字列, 現在のファイルデータの位置, 読み取り終了までの文字　戻り値：変換した数値
        static public TYPE_Selected M_Convert_String_To_Select_Type_And_Go_To_Right<TYPE_Selected>(List<string> in_text, ref S_Now_File_Data_Position out_now_position, char in_stop_word) where TYPE_Selected : IComparable, IConvertible, IFormattable
        {
            // ☆ 変数宣言 ☆ //
            TYPE_Selected result = default(TYPE_Selected); // 変換した数値


            // 変換した数値を返し、その末尾まで移動する
            result = (TYPE_Selected)Convert.ChangeType(CS_My_Math_System.M_Get_String_Until_This_Word(out_now_position.mp_now_column, in_text[out_now_position.mp_now_line], in_stop_word), typeof(TYPE_Selected));
            out_now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(in_text, in_stop_word.ToString(), out_now_position);

            return result;
        }
    }
}

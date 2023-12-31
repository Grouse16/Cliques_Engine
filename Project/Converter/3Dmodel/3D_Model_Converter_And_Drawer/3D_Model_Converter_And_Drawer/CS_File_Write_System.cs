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
    public class CS_File_Write_System
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
    }
}

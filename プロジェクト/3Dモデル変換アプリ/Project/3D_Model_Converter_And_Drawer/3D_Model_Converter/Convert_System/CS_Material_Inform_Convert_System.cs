using _3D_Model_Converter_And_Drawer.UI;
using _3D_Model_Converter_And_Drawer.UI.Announce_Bord;
using Assimp;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _3D_Model_Converter_And_Drawer._3D_model_Convert
{
    // ☆ クラス ☆ //

    // マテリアル情報変換システム
    public class CS_Material_Inform_Convert_System
    {
        // ☆ 構造体 ☆ //

        // マテリアルとして書き込むファイルのデータの構造体
        struct S_Write_Material_File_Data
        {
            // ☆ 変数宣言 ☆ //
            public string m_file_name;   // ファイル名

            public List<string> m_write_data; // 書き込むデータ


            // ☆ プロパティ ☆ //

            // ファイル名のプロパティ
            public string mp_file_name
            {
                // ゲッタ
                get
                {
                    return m_file_name;
                }

                // セッタ
                set
                {
                    m_file_name = value;

                    return;
                }
            }

            // 書き込むデータのプロパティ
            public List<string> mp_write_data
            {
                // ゲッタ
                get
                {
                    return m_write_data;
                }

                // セッタ
                set
                {
                    m_write_data = value;

                    return;
                }
            }


            //-☆- 関数 -☆-//

            // コンストラクタ
            public S_Write_Material_File_Data(string in_file_name, List<string> in_write_data)
            {
                m_file_name = in_file_name;
                m_write_data = in_write_data;

                return;
            }
        }


        // ☆ 関数 ☆ //

        //-☆- 変換 -☆-//

        // マテリアルの質感情報の変換　引数：シーンデータ, 書き込み中を示すボードの参照
        public static void M_Convert_Material_Inform(Scene in_scene, ref Form_Announce_Bord in_present_writing_anounce_bord)
        {
            // ☆ 定数 ☆ //
            const string con_EXTENSION = ".elmatinform";   // 拡張子


            // ☆ 変数宣言 ☆ //
            List<S_Write_Material_File_Data> write_file_list = new List<S_Write_Material_File_Data>();   // 書き込むファイルのリスト

            string selected_folder_path = "";   // 選択されたフォルダのパス

            int now_material_num = 0;   // 現在のマテリアル番号


            // フォルダ選択ダイアログを表示して、選択されたフォルダのパスを取得、取得できなかったら終了
            if (CS_File_Write_Load_System.M_Get_Folder_Path(out selected_folder_path) == false)
            {
                return;
            }


            // 質感情報であることを示す
            foreach (var now_material_data in in_scene.Materials)
            {
                // ☆ 変数宣言 ☆ //
                List<string> file_mat_write_data = new List<string>(); // 書き込むマテリアルの質感用ファイルのデータ

                string write_file_name = selected_folder_path + Form_3D_Model_Convert_Setting.mp_mesh_name_list[now_material_num] + con_EXTENSION;   // 書き込むファイルの名前


                // 質感情報であることを示す
                file_mat_write_data.Add("This-Is-ELMATINFORM");


                // アンビエント
                file_mat_write_data.Add
                    (
                        "AMBIENT:"
                         + now_material_data.ColorAmbient.R.ToString() + ","
                         + now_material_data.ColorAmbient.G.ToString() + ","
                         + now_material_data.ColorAmbient.B.ToString() + ","
                         + now_material_data.ColorAmbient.A.ToString() + ","
                    );

                // ディフューズ
                file_mat_write_data.Add
                    (
                        "DIFFUSE:"
                         + now_material_data.ColorDiffuse.R.ToString() + ","
                         + now_material_data.ColorDiffuse.G.ToString() + ","
                         + now_material_data.ColorDiffuse.B.ToString() + ","
                         + now_material_data.ColorDiffuse.A.ToString() + ","
                    );

                // エミッション
                file_mat_write_data.Add
                    (
                        "EMISSION:"
                         + now_material_data.ColorEmissive.R.ToString() + ","
                         + now_material_data.ColorEmissive.G.ToString() + ","
                         + now_material_data.ColorEmissive.B.ToString() + ","
                         + now_material_data.ColorEmissive.A.ToString() + ","
                    );

                // リフレクション
                file_mat_write_data.Add
                    (
                        "REFLECTION:"
                         + now_material_data.ColorReflective.R.ToString() + ","
                         + now_material_data.ColorReflective.G.ToString() + ","
                         + now_material_data.ColorReflective.B.ToString() + ","
                         + now_material_data.ColorReflective.A.ToString() + ","
                    );

                // スペキュラー
                file_mat_write_data.Add
                    (
                        "SPECULAR:"
                         + now_material_data.ColorSpecular.R.ToString() + ","
                         + now_material_data.ColorSpecular.G.ToString() + ","
                         + now_material_data.ColorSpecular.B.ToString() + ","
                         + now_material_data.ColorSpecular.A.ToString() + ","
                    );

                // トランスペアレント
                file_mat_write_data.Add
                    (
                        "TRANSPARENT:"
                         + now_material_data.ColorTransparent.R.ToString() + ","
                         + now_material_data.ColorTransparent.G.ToString() + ","
                         + now_material_data.ColorTransparent.B.ToString() + ","
                         + now_material_data.ColorTransparent.A.ToString() + ","
                    );


                // 書き込むファイルのデータをリストに追加
                write_file_list.Add(new S_Write_Material_File_Data(write_file_name, file_mat_write_data));

                // 次のマテリアル番号を指定
                now_material_num += 1;
            }


            // ファイルの書き込みを告知する
            in_present_writing_anounce_bord.M_Set_Announce_Text("ファイル書き込み中です");


            // 新しいファイルの書き込みを行う
            foreach (S_Write_Material_File_Data l_now_write_file_data in write_file_list)
            {
                System.IO.File.WriteAllText(l_now_write_file_data.mp_file_name, l_now_write_file_data.mp_write_data[0]);
                foreach (string l_now_write_data in l_now_write_file_data.m_write_data)
                {
                    System.IO.File.AppendAllText(l_now_write_file_data.mp_file_name, Environment.NewLine + l_now_write_data);
                }
            }


            // ファイルの書き込みを告知する
            in_present_writing_anounce_bord.M_Set_Announce_Text("書き込み終了しました");

            return;
        }
    }
}

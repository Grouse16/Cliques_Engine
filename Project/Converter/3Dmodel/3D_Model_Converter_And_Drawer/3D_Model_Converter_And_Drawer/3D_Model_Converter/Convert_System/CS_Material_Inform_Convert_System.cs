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
        // ☆ 関数 ☆ //

        //-☆- 変換 -☆-//

        // マテリアルの質感情報の変換　引数：シーンデータ
        public static void M_Convert_Material_Inform(Scene in_scene)
        {
            // ☆ 定数 ☆ //
            const string con_EXTENSION = ".elmatinform";   // 拡張子


            // ☆ 変数宣言 ☆ //
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
                        "SPECLAR:"
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


                // 新しいファイルの書き込みを行う
                System.IO.File.WriteAllText(write_file_name, file_mat_write_data[0]);
                for (int now_write_raw = 1; now_write_raw < file_mat_write_data.Count; now_write_raw++)
                {
                    System.IO.File.AppendAllText(write_file_name, Environment.NewLine + file_mat_write_data[now_write_raw]);
                }

                // 次のマテリアル番号を指定
                now_material_num += 1;
            }

            return;
        }
    }
}

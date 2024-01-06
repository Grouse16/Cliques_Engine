using _3D_Model_Converter_And_Drawer._3DModel;
using _3D_Model_Converter_And_Drawer._3DModel.Animation;
using _3D_Model_Converter_And_Drawer._3DModel.Static;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3D_Model_Converter_And_Drawer._3D_Model_Importer.Import_System
{
    // ☆ クラス ☆ //

    // アニメーションモデルインポートシステム
    public class CS_Animation_Model_Import_System
    {
        // ☆ 関数 ☆ //

        //-☆- インポート -☆-//

        // アニメーションモデルをインポートする　引数：ロードするファイルのパス, ロードしたモデルの設定先
        public static void M_Import_Animation_Model(string in_load_file_path, out CS_Animation_Model_Data in_animation_model)
        {
            // ☆ 変数宣言 ☆ //
            List<string> read_data_list = new List<string>();   // 読み取ったデータのリスト

            S_Now_File_Data_Position now_position = new S_Now_File_Data_Position(0, 0); // 現在のファイル操作中の場所


            // 設定先モデルデータを初期化
            in_animation_model = new CS_Animation_Model_Data();


            // ファイルのデータを読み取る
            CS_File_Write_Load_System.M_Read_Data_From_File(in_load_file_path, out read_data_list);
            
            // ファイル名をセット
            in_animation_model.mp_name = Path.GetFileNameWithoutExtension(in_load_file_path);


            // 頂点データのロード
            M_Load_Vertex_Data(ref in_animation_model, read_data_list, ref now_position);

            // ボーンデータのロード
            M_Load_Bone_Data(ref in_animation_model, read_data_list, ref now_position);

            // メッシュデータのロード
            M_Load_Mesh_Data(ref in_animation_model, read_data_list, ref now_position);

            return;
        }


        //-☆- ロード -☆-//

        // 頂点データのロード　引数：設定先のアニメーションモデル, ロードした文字列, 現在の操作位置
        static private void M_Load_Vertex_Data(ref CS_Animation_Model_Data in_set_model, List<string> in_load_data, ref S_Now_File_Data_Position in_now_position)
        {
            // ☆ 変数宣言 ☆ //
            int vertex_sum = 0; // 頂点数


            // 頂点数を取得
            in_now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(in_load_data, "VERTSUM:", new S_Now_File_Data_Position(0, 0));
            vertex_sum = int.Parse(in_load_data[in_now_position.mp_now_line].Substring(in_now_position.mp_now_column));


            // 頂点数分メモリを確保
            for (int l_now_vertex = 0; l_now_vertex < vertex_sum; l_now_vertex++)
            {
                in_set_model.mp_vertex_list.Add(new S_Animation_Vertex_Data());
            }


            // 頂点分だけデータをロード
            for (int l_now_vertex_number = 0; l_now_vertex_number < in_set_model.mp_vertex_list.Count; l_now_vertex_number++)
            {
                // ☆ 変数宣言 ☆ //
                S_Animation_Vertex_Data new_vertex_data = new S_Animation_Vertex_Data(); // 新しい頂点データ


                // 現在の頂点データの開始位置へ移動
                in_now_position.M_Goto_Next_Line(in_load_data);

                // 位置座標をロード
                {
                    // ☆ 変数宣言 ☆ //
                    float position_x = 0.0f;    // X座標
                    float position_y = 0.0f;    // Y座標
                    float position_z = 0.0f;    // Z座標


                    // データをロード
                    position_x = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_load_data, ref in_now_position, ',');
                    position_y = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_load_data, ref in_now_position, ',');
                    position_z = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_load_data, ref in_now_position, ':');

                    // 位置座標をセット
                    new_vertex_data.mp_position = new SharpDX.Vector3(position_x, position_y, position_z);
                }

                // UVをロード
                {
                    // ☆ 変数宣言 ☆ //
                    float set_u = 0.0f; // U座標
                    float set_v = 0.0f; // V座標


                    // データをロード
                    set_u = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_load_data, ref in_now_position, ',');
                    set_v = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_load_data, ref in_now_position, ':');

                    // UV座標をセット
                    new_vertex_data.mp_uv = new SharpDX.Vector2(set_u, set_v);
                }

                // 色をロードする
                {
                    // ☆ 変数宣言 ☆ //
                    float set_r = 0.0f; // R
                    float set_g = 0.0f; // G
                    float set_b = 0.0f; // B
                    float set_a = 0.0f; // A


                    // データをロード
                    set_r = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_load_data, ref in_now_position, ',');
                    set_g = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_load_data, ref in_now_position, ',');
                    set_b = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_load_data, ref in_now_position, ',');
                    set_a = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_load_data, ref in_now_position, ':');

                    // 色をセット
                    new_vertex_data.mp_color = new SharpDX.Vector4(set_r, set_g, set_b, set_a);
                }

                // 法線ベクトルをロード
                {
                    // ☆ 変数宣言 ☆ //
                    float normal_x = 0.0f;  // 法線ベクトルX
                    float normal_y = 0.0f;  // 法線ベクトルY
                    float normal_z = 0.0f;  // 法線ベクトルZ


                    // データをロード
                    normal_x = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_load_data, ref in_now_position, ',');
                    normal_y = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_load_data, ref in_now_position, ',');
                    normal_z = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_load_data, ref in_now_position, ':');

                    // 法線ベクトルをセット
                    new_vertex_data.mp_normal = new SharpDX.Vector3(normal_x, normal_y, normal_z);
                }

                // タンジェントをロード
                {
                    // ☆ 変数宣言 ☆ //
                    float tangent_x = 0.0f; // タンジェントX
                    float tangent_y = 0.0f; // タンジェントY
                    float tangent_z = 0.0f; // タンジェントZ


                    // データをロード
                    tangent_x = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_load_data, ref in_now_position, ',');
                    tangent_y = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_load_data, ref in_now_position, ',');
                    tangent_z = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_load_data, ref in_now_position, ':');

                    // タンジェントベクトルをセット
                    new_vertex_data.mp_tangent = new SharpDX.Vector3(tangent_x, tangent_y, tangent_z);
                }

                // 従法線ベクトルをロード
                {
                    // ☆ 変数宣言 ☆ //
                    float bi_normal_tangent_x = 0.0f;   // 従法線X
                    float bi_normal_tangent_y = 0.0f;   // 従法線Y
                    float bi_normal_tangent_z = 0.0f;   // 従法線Z


                    // データをロード
                    bi_normal_tangent_x = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_load_data, ref in_now_position, ',');
                    bi_normal_tangent_y = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_load_data, ref in_now_position, ',');
                    bi_normal_tangent_z = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_load_data, ref in_now_position, ':');

                    // 従法線ベクトルをセット
                    new_vertex_data.mp_bi_normal_tangent = new SharpDX.Vector3(bi_normal_tangent_x, bi_normal_tangent_y, bi_normal_tangent_z);
                }

                // ボーンウェイト情報をロード
                {
                    // ☆ 変数宣言 ☆ //
                    bool is_bone_data_end = false;    // ボーンデータの終了位置に到達したらtrueになる


                    // ボーンウェイト用のリストを初期化
                    new_vertex_data.mp_bone_weight = new List<CS_Bone_Weight_Data>();

                    // ボーンデータの終了位置、または４つのボーンウェイト情報を取得するまでボーンウェイト情報をロード
                    for (int l_now_bone_number = 0; l_now_bone_number < 4 && is_bone_data_end == false; l_now_bone_number++)
                    {
                        // ☆ 変数宣言 ☆ //
                        int bone_index = 0;         // ボーン番号
                        float bone_weight = 0.0f;   // ウェイト値


                        // ボーン番号を取得
                        bone_index = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<int>(in_load_data, ref in_now_position, '/');

                        // ボーンウェイト値を取得
                        bone_weight = float.Parse(CS_My_Math_System.M_Get_String_Until_This_Word(in_now_position.mp_now_column, in_load_data[in_now_position.mp_now_line], ','));
                        in_now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(in_load_data, ",", in_now_position);

                        // ボーンウェイト情報をセット
                        new_vertex_data.mp_bone_weight.Add(new CS_Bone_Weight_Data(bone_index, bone_weight));


                        // ボーンデータの終了位置に到達したかどうかを判定する
                        is_bone_data_end = (in_load_data[in_now_position.mp_now_line][in_now_position.mp_now_column] == ':');
                    }
                }

                // 新しい頂点データをセット
                in_set_model.mp_vertex_list[l_now_vertex_number] = new_vertex_data;
            }

            return;
        }


        // ボーンデータのロード　引数：設定先のアニメーションモデル, ロードした文字列, 現在の操作位置
        static private void M_Load_Bone_Data(ref CS_Animation_Model_Data in_set_model, List<string> in_load_data, ref S_Now_File_Data_Position in_now_position)
        {
            // ☆ 変数宣言 ☆ //
            int bone_sum = 0;   // ボーン数


            // ボーン数を取得
            in_now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(in_load_data, "BONESUM:", new S_Now_File_Data_Position(0, 0));
            bone_sum = int.Parse(in_load_data[in_now_position.mp_now_line].Substring(in_now_position.mp_now_column));


            // ボーン数分メモリを確保
            for (int l_now_bone = 0; l_now_bone < bone_sum; l_now_bone++)
            {
                in_set_model.mp_bone_data_list.Add(new CS_Model_Bone_Data());
            }


            // ボーン数分だけボーンデータをロード
            foreach (var l_now_bone_data in in_set_model.mp_bone_data_list)
            {
                // ☆ 変数宣言 ☆ //
                float offset_matrix_11 = 0.0f;  // オフセットマトリクス行列11
                float offset_matrix_12 = 0.0f;  // オフセットマトリクス行列12
                float offset_matrix_13 = 0.0f;  // オフセットマトリクス行列13
                float offset_matrix_14 = 0.0f;  // オフセットマトリクス行列14
                float offset_matrix_21 = 0.0f;  // オフセットマトリクス行列21
                float offset_matrix_22 = 0.0f;  // オフセットマトリクス行列22
                float offset_matrix_23 = 0.0f;  // オフセットマトリクス行列23
                float offset_matrix_24 = 0.0f;  // オフセットマトリクス行列24
                float offset_matrix_31 = 0.0f;  // オフセットマトリクス行列31
                float offset_matrix_32 = 0.0f;  // オフセットマトリクス行列32
                float offset_matrix_33 = 0.0f;  // オフセットマトリクス行列33
                float offset_matrix_34 = 0.0f;  // オフセットマトリクス行列34
                float offset_matrix_41 = 0.0f;  // オフセットマトリクス行列41
                float offset_matrix_42 = 0.0f;  // オフセットマトリクス行列42
                float offset_matrix_43 = 0.0f;  // オフセットマトリクス行列43
                float offset_matrix_44 = 0.0f;  // オフセットマトリクス行列44


                // ボーンデータの開始位置へ移動
                in_now_position.M_Goto_Next_Line(in_load_data);


                // 親ボーンの番号を取得
                l_now_bone_data.mp_parent_bone_index = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<int>(in_load_data, ref in_now_position, '/');

                // ボーン名のロード
                l_now_bone_data.mp_name = CS_My_Math_System.M_Get_String_Until_This_Word(in_now_position.mp_now_column, in_load_data[in_now_position.mp_now_line], '/');
                in_now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(in_load_data, "/", in_now_position);


                // オフセットマトリクス行列をロード
                offset_matrix_11 = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_load_data, ref in_now_position, ',');
                offset_matrix_12 = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_load_data, ref in_now_position, ',');
                offset_matrix_13 = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_load_data, ref in_now_position, ',');
                offset_matrix_14 = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_load_data, ref in_now_position, ',');
                offset_matrix_21 = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_load_data, ref in_now_position, ',');
                offset_matrix_22 = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_load_data, ref in_now_position, ',');
                offset_matrix_23 = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_load_data, ref in_now_position, ',');
                offset_matrix_24 = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_load_data, ref in_now_position, ',');
                offset_matrix_31 = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_load_data, ref in_now_position, ',');
                offset_matrix_32 = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_load_data, ref in_now_position, ',');
                offset_matrix_33 = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_load_data, ref in_now_position, ',');
                offset_matrix_34 = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_load_data, ref in_now_position, ',');
                offset_matrix_41 = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_load_data, ref in_now_position, ',');
                offset_matrix_42 = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_load_data, ref in_now_position, ',');
                offset_matrix_43 = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_load_data, ref in_now_position, ',');
                offset_matrix_44 = CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<float>(in_load_data, ref in_now_position, '/');


                // オフセットマトリクス行列をセット
                l_now_bone_data.mp_offset_matrix = new SharpDX.Matrix
                    (
                    offset_matrix_11, offset_matrix_12, offset_matrix_13, offset_matrix_14,
                    offset_matrix_21, offset_matrix_22, offset_matrix_23, offset_matrix_24,
                    offset_matrix_31, offset_matrix_32, offset_matrix_33, offset_matrix_34,
                    offset_matrix_41, offset_matrix_42, offset_matrix_43, offset_matrix_44
                    );
            }

            return;
        }


        // メッシュデータのロード　引数：設定先のアニメーションモデル, ロードした文字列, 現在の操作位置
        static private void M_Load_Mesh_Data(ref CS_Animation_Model_Data in_set_model, List<string> in_load_data, ref S_Now_File_Data_Position in_now_position)
        {
            // ☆ 変数宣言 ☆ //
            int mesh_sum = 0;   // メッシュ数


            // メッシュ数を取得
            in_now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(in_load_data, "MESHSUM:", in_now_position);
            mesh_sum = int.Parse(in_load_data[in_now_position.mp_now_line].Substring(in_now_position.mp_now_column));


            // メッシュ数分メモリを確保
            for (int l_now_mesh = 0; l_now_mesh < mesh_sum; l_now_mesh++)
            {
                in_set_model.mp_mesh_list.Add(new CS_Animation_Mesh_Data());
            }


            // メッシュ数分だけメッシュデータをロード
            foreach (var l_now_mesh_data in in_set_model.mp_mesh_list)
            {
                // ☆ 変数宣言 ☆ //
                int index_sum = 0;  // インデックス数


                // メッシュの開始位置へ移動
                in_now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(in_load_data, "MESH:", in_now_position);

                // メッシュ名がある場所に移動し、メッシュ名を取得
                in_now_position.M_Goto_Next_Line(in_load_data);
                l_now_mesh_data.mp_name = in_load_data[in_now_position.mp_now_line];

                // マテリアル名がある場所に移動し、マテリアル名を取得
                in_now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(in_load_data, "MATERIAL:", in_now_position);
                in_now_position.M_Goto_Next_Line(in_load_data);
                l_now_mesh_data.mp_material_name = in_load_data[in_now_position.mp_now_line];

                // インデックス数を取得
                in_now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(in_load_data, "INDEX:", in_now_position);

                // インデックス数分だけロード
                in_now_position.M_Goto_Next_Line(in_load_data);
                for (int l_now_index = 0; l_now_index < index_sum; l_now_index++)
                {
                    l_now_mesh_data.mp_index_data_list.Add(CS_File_Write_Load_System.M_Convert_String_To_Select_Type_And_Go_To_Right<uint>(in_load_data, ref in_now_position, ':'));
                }
            }

            return;
        }
    }
}

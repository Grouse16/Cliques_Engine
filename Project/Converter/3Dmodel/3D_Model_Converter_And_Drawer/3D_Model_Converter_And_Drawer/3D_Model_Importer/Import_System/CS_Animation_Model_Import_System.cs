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
        public static void M_Import_Animation_Model(string in_load_file_path, CS_Animation_Model_Data in_animation_model)
        {
            // ☆ 変数宣言 ☆ //
            List<string> read_data_list = new List<string>();   // 読み取ったデータのリスト

            S_Now_File_Data_Position now_position = new S_Now_File_Data_Position(0, 0); // 現在のファイル操作中の場所


            // 設定先モデルデータを初期化
            in_animation_model = new CS_Animation_Model_Data();


            // ファイルのデータを読み取る
            {
                // ☆　変数宣言 ☆ //
                StreamReader file_data = new StreamReader(in_load_file_path); // 指定されたファイルのデータ

                bool is_file_end = false;   // ファイルの終わりに来たかどうか


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
                        read_data_list.Add(new_line);
                    }
                }

                // ファイルを閉じる
                file_data.Close();


                // ファイル名をセット
                in_animation_model.mp_name = Path.GetFileName(in_load_file_path);
            }


            // ☆ 変数宣言 ☆ //
            int mesh_sum = 0;   // メッシュ数
            int bone_sum = 0;   // ボーン数


            // メッシュ数へ移動
            now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, "MESHSUM:", new S_Now_File_Data_Position(0, 0));

            // メッシュ数を取得し、その数分メモリを確保
            mesh_sum = int.Parse(read_data_list[now_position.mp_now_line].Substring(now_position.mp_now_column));
            for (int l_now_mesh_num = 0; l_now_mesh_num < mesh_sum; l_now_mesh_num++)
            {
                in_animation_model.mp_mesh_list.Add(new _3DModel.Animation.CS_Animation_Mesh_Data());
            }


            // ボーン数へ移動
            now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, "BONESUM:", now_position);

            // ボーン数を取得し、その数分メモリを確保
            bone_sum = int.Parse(read_data_list[now_position.mp_now_line].Substring(now_position.mp_now_column));
            for (int l_now_bone_num = 0; l_now_bone_num < int.Parse(read_data_list[now_position.mp_now_line].Substring(now_position.mp_now_column)); l_now_bone_num++)
            {
                in_animation_model.mp_bone_data_list.Add(new CS_Model_Bone_Data());
            }


            // ボーン数分だけボーンデータをロード
            foreach (var l_now_bone_data in in_animation_model.mp_bone_data_list)
            {
                // ボーンデータの開始位置へ移動
                now_position.M_Goto_Next_Line(read_data_list);


                // ボーン名のロード
                l_now_bone_data.mp_name = CS_My_Math_System.M_Get_String_Until_This_Word(now_position.mp_now_column, read_data_list[now_position.mp_now_line], '/');
                now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, "/", now_position);
                

                // オフセットマトリクス行列11
                float offset_matrix_11 = float.Parse(CS_My_Math_System.M_Get_String_Until_This_Word(now_position.mp_now_column, read_data_list[now_position.mp_now_line], ','));
                now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, ",", now_position);

                // オフセットマトリクス行列12
                float offset_matrix_12 = float.Parse(CS_My_Math_System.M_Get_String_Until_This_Word(now_position.mp_now_column, read_data_list[now_position.mp_now_line], ','));
                now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, ",", now_position);

                // オフセットマトリクス行列13
                float offset_matrix_13 = float.Parse(CS_My_Math_System.M_Get_String_Until_This_Word(now_position.mp_now_column, read_data_list[now_position.mp_now_line], ','));
                now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, ",", now_position);

                // オフセットマトリクス行列14
                float offset_matrix_14 = float.Parse(CS_My_Math_System.M_Get_String_Until_This_Word(now_position.mp_now_column, read_data_list[now_position.mp_now_line], ','));
                now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, ",", now_position);

                // オフセットマトリクス行列21
                float offset_matrix_21 = float.Parse(CS_My_Math_System.M_Get_String_Until_This_Word(now_position.mp_now_column, read_data_list[now_position.mp_now_line], ','));
                now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, ",", now_position);

                // オフセットマトリクス行列22
                float offset_matrix_22 = float.Parse(CS_My_Math_System.M_Get_String_Until_This_Word(now_position.mp_now_column, read_data_list[now_position.mp_now_line], ','));
                now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, ",", now_position);

                // オフセットマトリクス行列23
                float offset_matrix_23 = float.Parse(CS_My_Math_System.M_Get_String_Until_This_Word(now_position.mp_now_column, read_data_list[now_position.mp_now_line], ','));
                now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, ",", now_position);

                // オフセットマトリクス行列24
                float offset_matrix_24 = float.Parse(CS_My_Math_System.M_Get_String_Until_This_Word(now_position.mp_now_column, read_data_list[now_position.mp_now_line], ','));
                now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, ",", now_position);

                // オフセットマトリクス行列31
                float offset_matrix_31 = float.Parse(CS_My_Math_System.M_Get_String_Until_This_Word(now_position.mp_now_column, read_data_list[now_position.mp_now_line], ','));
                now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, ",", now_position);

                // オフセットマトリクス行列32
                float offset_matrix_32 = float.Parse(CS_My_Math_System.M_Get_String_Until_This_Word(now_position.mp_now_column, read_data_list[now_position.mp_now_line], ','));
                now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, ",", now_position);

                // オフセットマトリクス行列33
                float offset_matrix_33 = float.Parse(CS_My_Math_System.M_Get_String_Until_This_Word(now_position.mp_now_column, read_data_list[now_position.mp_now_line], ','));
                now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, ",", now_position);

                // オフセットマトリクス行列34
                float offset_matrix_34 = float.Parse(CS_My_Math_System.M_Get_String_Until_This_Word(now_position.mp_now_column, read_data_list[now_position.mp_now_line], ','));
                now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, ",", now_position);

                // オフセットマトリクス行列41
                float offset_matrix_41 = float.Parse(CS_My_Math_System.M_Get_String_Until_This_Word(now_position.mp_now_column, read_data_list[now_position.mp_now_line], ','));
                now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, ",", now_position);

                // オフセットマトリクス行列42
                float offset_matrix_42 = float.Parse(CS_My_Math_System.M_Get_String_Until_This_Word(now_position.mp_now_column, read_data_list[now_position.mp_now_line], ','));
                now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, ",", now_position);

                // オフセットマトリクス行列43
                float offset_matrix_43 = float.Parse(CS_My_Math_System.M_Get_String_Until_This_Word(now_position.mp_now_column, read_data_list[now_position.mp_now_line], ','));
                now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, ",", now_position);

                // オフセットマトリクス行列44
                float offset_matrix_44 = float.Parse(CS_My_Math_System.M_Get_String_Until_This_Word(now_position.mp_now_column, read_data_list[now_position.mp_now_line], ','));
            }


            // メッシュの情報を取得する
            foreach (var l_now_mesh_data in in_animation_model.mp_mesh_list)
            {
                // ☆ 変数宣言 ☆ //
                int vertex_sum = 0; // 頂点数
                int index_sum = 0;  // インデックス数


                // メッシュの開始位置へ移動
                now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, "MESH:", now_position);


                // メッシュ名がある場所に移動し、メッシュ名を取得
                now_position.M_Goto_Next_Line(read_data_list);
                l_now_mesh_data.mp_name = read_data_list[now_position.mp_now_line];


                // マテリアル名がある場所に移動し、マテリアル名を取得
                now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, "MATERIAL:", now_position);
                now_position.M_Goto_Next_Line(read_data_list);
                l_now_mesh_data.mp_name = read_data_list[now_position.mp_now_line];


                // 頂点の開始へ移動し、頂点数を取得
                now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, "VERT:", now_position);
                vertex_sum = int.Parse(read_data_list[now_position.mp_now_line].Substring(now_position.mp_now_column));


                // 頂点数分メモリを確保
                for (int l_now_vertex = 0; l_now_vertex < vertex_sum; l_now_vertex++)
                {
                    l_now_mesh_data.mp_vertex_data_list.Add(new _3DModel.CS_Animation_Vertex_Data());
                }


                // 頂点分だけデータをロード
                now_position.M_Goto_Next_Line(read_data_list);
                foreach (var vertex_data in l_now_mesh_data.mp_vertex_data_list)
                {
                    // 位置座標をロード
                    {
                        // ☆ 変数宣言 ☆ //
                        float position_x = 0.0f;    // X座標
                        float position_y = 0.0f;    // Y座標
                        float position_z = 0.0f;    // Z座標


                        // X座標を取得
                        position_x = float.Parse(CS_My_Math_System.M_Get_String_Until_This_Word(now_position.mp_now_column, read_data_list[now_position.mp_now_line], ','));
                        now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, ",", now_position);

                        // Y座標を取得
                        position_y = float.Parse(CS_My_Math_System.M_Get_String_Until_This_Word(now_position.mp_now_column, read_data_list[now_position.mp_now_line], ','));
                        now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, ",", now_position);

                        // Z座標を取得
                        position_z = float.Parse(CS_My_Math_System.M_Get_String_Until_This_Word(now_position.mp_now_column, read_data_list[now_position.mp_now_line], ':'));

                        // 位置座標をセット
                        vertex_data.mp_position = new SharpDX.Vector3(position_x, position_y, position_z);
                    }

                    // UVへ移動
                    now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, ":", now_position);

                    // UVをロード
                    {
                        // ☆ 変数宣言 ☆ //
                        float set_u = 0.0f; // U座標
                        float set_v = 0.0f; // V座標


                        // U座標を取得
                        set_u = float.Parse(CS_My_Math_System.M_Get_String_Until_This_Word(now_position.mp_now_column, read_data_list[now_position.mp_now_line], ','));
                        now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, ",", now_position);

                        // V座標を取得
                        set_v = float.Parse(CS_My_Math_System.M_Get_String_Until_This_Word(now_position.mp_now_column, read_data_list[now_position.mp_now_line], ':'));

                        // UV座標をセット
                        vertex_data.mp_uv = new SharpDX.Vector2(set_u, set_v);
                    }

                    // 色へ移動
                    now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, ":", now_position);

                    // 色をロードする
                    {
                        // ☆ 変数宣言 ☆ //
                        float set_r = 0.0f; // R
                        float set_g = 0.0f; // G
                        float set_b = 0.0f; // B
                        float set_a = 0.0f; // A


                        // Rを取得
                        set_r = float.Parse(CS_My_Math_System.M_Get_String_Until_This_Word(now_position.mp_now_column, read_data_list[now_position.mp_now_line], ','));
                        now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, ",", now_position);

                        // Gを取得
                        set_g = float.Parse(CS_My_Math_System.M_Get_String_Until_This_Word(now_position.mp_now_column, read_data_list[now_position.mp_now_line], ','));
                        now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, ",", now_position);

                        // Gを取得
                        set_b = float.Parse(CS_My_Math_System.M_Get_String_Until_This_Word(now_position.mp_now_column, read_data_list[now_position.mp_now_line], ','));
                        now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, ",", now_position);

                        // Aを取得
                        set_a = float.Parse(CS_My_Math_System.M_Get_String_Until_This_Word(now_position.mp_now_column, read_data_list[now_position.mp_now_line], ':'));

                        // 色をセット
                        vertex_data.mp_color = new SharpDX.Vector4(set_a, set_g, set_b, set_a);
                    }

                    // 法線ベクトルへ移動
                    now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, ":", now_position);

                    // 法線ベクトルをロード
                    {
                        // ☆ 変数宣言 ☆ //
                        float normal_x = 0.0f;  // 法線ベクトルX
                        float normal_y = 0.0f;  // 法線ベクトルY
                        float normal_z = 0.0f;  // 法線ベクトルZ


                        // 法線ベクトルXを取得
                        normal_x = float.Parse(CS_My_Math_System.M_Get_String_Until_This_Word(now_position.mp_now_column, read_data_list[now_position.mp_now_line], ','));
                        now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, ",", now_position);

                        // 法線ベクトルYを取得
                        normal_y = float.Parse(CS_My_Math_System.M_Get_String_Until_This_Word(now_position.mp_now_column, read_data_list[now_position.mp_now_line], ','));
                        now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, ",", now_position);

                        // 法線ベクトルZを取得
                        normal_z = float.Parse(CS_My_Math_System.M_Get_String_Until_This_Word(now_position.mp_now_column, read_data_list[now_position.mp_now_line], ':'));

                        // 法線ベクトルをセット
                        vertex_data.mp_normal = new SharpDX.Vector3(normal_x, normal_y, normal_z);
                    }

                    // タンジェントベクトルへ移動
                    now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, ":", now_position);

                    // タンジェントをロード
                    {
                        // ☆ 変数宣言 ☆ //
                        float tangent_x = 0.0f; // タンジェントX
                        float tangent_y = 0.0f; // タンジェントY
                        float tangent_z = 0.0f; // タンジェントZ


                        // タンジェントXを取得
                        tangent_x = float.Parse(CS_My_Math_System.M_Get_String_Until_This_Word(now_position.mp_now_column, read_data_list[now_position.mp_now_line], ','));
                        now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, ",", now_position);

                        // タンジェントYを取得
                        tangent_y = float.Parse(CS_My_Math_System.M_Get_String_Until_This_Word(now_position.mp_now_column, read_data_list[now_position.mp_now_line], ','));
                        now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, ",", now_position);

                        // タンジェントZを取得
                        tangent_z = float.Parse(CS_My_Math_System.M_Get_String_Until_This_Word(now_position.mp_now_column, read_data_list[now_position.mp_now_line], ':'));

                        // タンジェントベクトルをセット
                        vertex_data.mp_tangent = new SharpDX.Vector3(tangent_x, tangent_y, tangent_z);
                    }

                    // 従法線ベクトルへ移動
                    now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, ":", now_position);

                    // 従法線ベクトルをロード
                    {
                        // ☆ 変数宣言 ☆ //
                        float bi_normal_tangent_x = 0.0f;   // 従法線X
                        float bi_normal_tangent_y = 0.0f;   // 従法線Y
                        float bi_normal_tangent_z = 0.0f;   // 従法線Z


                        // 従法線Xを取得
                        bi_normal_tangent_x = float.Parse(CS_My_Math_System.M_Get_String_Until_This_Word(now_position.mp_now_column, read_data_list[now_position.mp_now_line], ','));
                        now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, ",", now_position);

                        // 従法線Yを取得
                        bi_normal_tangent_y = float.Parse(CS_My_Math_System.M_Get_String_Until_This_Word(now_position.mp_now_column, read_data_list[now_position.mp_now_line], ','));
                        now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, ",", now_position);

                        // 従法線Zを取得
                        bi_normal_tangent_z = float.Parse(CS_My_Math_System.M_Get_String_Until_This_Word(now_position.mp_now_column, read_data_list[now_position.mp_now_line], ':'));

                        // 従法線ベクトルをセット
                        vertex_data.mp_bi_normal_tangent = new SharpDX.Vector3(bi_normal_tangent_x, bi_normal_tangent_y, bi_normal_tangent_z);
                    }

                    // ボーンウェイト情報へ移動
                    now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, ":", now_position);

                    // ボーンウェイト情報をロード
                    {
                        // ☆ 変数宣言 ☆ //
                        bool is_bone_data_end = false;    // ボーンデータの終了位置に到達したらtrueになる


                        // ボーンデータの終了位置、または４つのボーンウェイト情報を取得するまでボーンウェイト情報をロード
                        for (int l_now_bone_number = 0; l_now_bone_number < 4 && is_bone_data_end == false; l_now_bone_number++)
                        {
                            // ☆ 変数宣言 ☆ //
                            int bone_index = 0;         // ボーン番号
                            float bone_weight = 0.0f;   // ウェイト値


                            // ボーン番号を取得
                            bone_index = int.Parse(CS_My_Math_System.M_Get_String_Until_This_Word(now_position.mp_now_column, read_data_list[now_position.mp_now_line], '/'));
                            now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, "/", now_position);

                            // ボーンウェイト値を取得
                            bone_weight = float.Parse(CS_My_Math_System.M_Get_String_Until_This_Word(now_position.mp_now_column, read_data_list[now_position.mp_now_line], ','));

                            // ボーンウェイト情報をセット
                            vertex_data.mp_bone_weight.Add(new _3DModel.CS_Bone_Weight_Data(bone_index, bone_weight));

                            // ボーンデータの終了位置に到達したかどうかを判定する
                            now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, ",", now_position);
                            is_bone_data_end = (read_data_list[now_position.mp_now_line][now_position.mp_now_column] == ':');
                        }
                    }

                    // 次の頂点へ移動
                    now_position.M_Goto_Next_Line(read_data_list);
                }


                // インデックス数を取得
                now_position = CS_My_Math_System.M_Search_Word_And_Go_To_Right(read_data_list, "INDEX:", now_position);
                index_sum = int.Parse(read_data_list[now_position.mp_now_line].Substring(now_position.mp_now_column));


                // インデックス数分だけロード
                now_position.M_Goto_Next_Line(read_data_list);
                for (int l_now_index = 0; l_now_index < index_sum; l_now_index++)
                {
                    l_now_mesh_data.mp_index_data_list.Add(uint.Parse(read_data_list[now_position.mp_now_line]));
                    now_position.M_Goto_Next_Line(read_data_list);
                }
            }

            return;
        }
    }
}

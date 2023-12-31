using _3D_Model_Converter_And_Drawer._3DModel;
using Assimp;
using Assimp.Unmanaged;
using SharpDX;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Security.Policy;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.Window;

namespace _3D_Model_Converter_And_Drawer
{
    // ☆ 列挙 ☆ //

    // 変換のモードを設定する
    enum E_CONVERT_MODE
    {
        e_STATIC_MODEL,
        e_ANIMATION_MODEL,
    }


    // ☆ クラス ☆ //

    // 3Dモデルを独自形式に変換するクラス
    internal class CS_3D_Model_Convert_System
    {
        // ☆ 構造体 ☆ //

        // 頂点ウェイト情報の構造体
        struct S_Vertex_Weight_Inform
        {
            // ☆ 変数宣言 ☆ //
            public double value; // ウェイト値
            public int index;   // ボーン番号


            // ☆ 関数 ☆ //

            //-☆- 初期化 -☆-//

            // 値初期化用コンストラクタ
            public S_Vertex_Weight_Inform(double in_value, int in_index)
            {
                value = in_value;
                index = in_index;
            }


            //-☆- セッタ -☆-//

            // ウェイト値をセットする
            public void M_Set_Value(double in_value)
            {
                value = in_value;
            }
        }


        // ☆ 変数宣言 ☆ //
        static private E_CONVERT_MODE m_convert_mode = E_CONVERT_MODE.e_STATIC_MODEL;    // 変換モード


        // ☆ 関数 ☆ //

        //-☆- 生成 -☆-//

        // 3Dモデルを変換用のフォームを生成する　引数：シーンデータ
        public static void M_Create_Form_Of_Convert_Model(Scene in_scene)
        {
            // ☆ 変数宣言 ☆ //
            Form_3D_Model_Convert_Setting new_form = new Form_3D_Model_Convert_Setting();   // 新しいフォームシステム


            // フォームを初期化して画面に表示
            new_form.M_Initialize(in_scene);
            new_form.Show();

            return;
        }


        //-☆- 変換 -☆-//

        // スタティックモデルに変換する
        public static void M_Convert_Static_Model(Scene in_scene)
        {
            m_convert_mode = E_CONVERT_MODE.e_STATIC_MODEL;
            M_Model_Convert(in_scene);

            return;
        }


        // アニメーションモデルに変換する
        public static void M_Convert_Animation_Model(Scene in_scene)
        {
            m_convert_mode = E_CONVERT_MODE.e_ANIMATION_MODEL;
            M_Model_Convert(in_scene);

            return;
        }


        // 3Dモデルのコンバートを実行する
        private static void M_Model_Convert(Scene in_scene)
        {
            // ☆ 変数宣言 ☆ //
            List<string> write_file_data = new List<string>(); // 書き込むデータ

            List<int> vertex_to_shrunk_vertex_number_list = new List<int>();    // 頂点を結合した後の頂点番号のリスト、元の頂点番号に問い合わせて結合後の頂点番号を取得する


            // 今までに書き込まれたデータを初期化
            M_Write_File_Format(ref write_file_data);


            // 静的モデル用の頂点データを書き込む
            if (m_convert_mode == E_CONVERT_MODE.e_STATIC_MODEL)
            {
                M_Write_Static_Model_Vertex_Data(in_scene, ref write_file_data, out vertex_to_shrunk_vertex_number_list);
            }

            // アニメーションモデル用の頂点データを書き込む
            else if (m_convert_mode == E_CONVERT_MODE.e_ANIMATION_MODEL)
            {
                // 頂点情報を書き込む
                M_Write_Animation_Model_Vertex_Data(in_scene, ref write_file_data, out vertex_to_shrunk_vertex_number_list);

                // ボーン情報を書き込む
                M_Write_Bone_Data(ref write_file_data);
            }

            // メッシュ情報を書き込む
            M_Write_Mesh_Data(in_scene, ref write_file_data, vertex_to_shrunk_vertex_number_list);


            // 静的モデルのセーブ
            if (m_convert_mode == E_CONVERT_MODE.e_STATIC_MODEL)
            {
                M_Save_Static_Model_This_File(write_file_data);
            }

            // アニメーションモデルのセーブ
            else if (m_convert_mode == E_CONVERT_MODE.e_ANIMATION_MODEL)
            {
                M_Save_Animation_Model_This_File(write_file_data);
            }

            return;
        }


        // 静的モデル形式でのセーブ　引数：書き込むデータ
        private static void M_Save_Static_Model_This_File(List<string> in_write_file_data)
        {
            // ☆ 変数宣言 ☆ //
            SaveFileDialog sfd = new SaveFileDialog();  // ファイルセーブ用システム

            string extension = "elsttmdl";  // 拡張子


            sfd.FileName = "new_model." + extension;
            sfd.InitialDirectory = System.IO.Path.GetDirectoryName(System.Reflection.Assembly.GetExecutingAssembly().Location);
            sfd.Filter = extension + "ファイル(*." + extension + ";*." + extension + ")| *." + extension + "; *." + extension + "| すべてのファイル(*.*)|*.*";
            sfd.FilterIndex = 1;
            sfd.Title = "スタティックモデルデータの保存先のファイルを選択してください";
            //ダイアログボックスを閉じる前に現在のディレクトリを復元するようにする
            sfd.RestoreDirectory = true;
            //既に存在するファイル名を指定したとき警告する
            sfd.OverwritePrompt = true;
            //存在しないパスが指定されたとき警告を表示する
            sfd.CheckPathExists = true;

            //ダイアログを表示する
            if (sfd.ShowDialog() == DialogResult.OK)
            {
                System.IO.File.WriteAllText(sfd.FileName, in_write_file_data[0] + Environment.NewLine);

                for (int now_write_raw = 1; now_write_raw < in_write_file_data.Count; now_write_raw++)
                {
                    System.IO.File.AppendAllText(sfd.FileName, in_write_file_data[now_write_raw] + Environment.NewLine);
                }
            }

            return;
        }


        // アニメーションモデル形式でのセーブ　引数：書き込むデータ
        private static void M_Save_Animation_Model_This_File(List<string> in_write_file_data)
        {
            // ☆ 変数宣言 ☆ //
            SaveFileDialog sfd = new SaveFileDialog();  // ファイルセーブ用システム

            string extension = "elanmmdl";  // 拡張子


            sfd.FileName = "new_model." + extension;
            sfd.InitialDirectory = System.IO.Path.GetDirectoryName(System.Reflection.Assembly.GetExecutingAssembly().Location);
            sfd.Filter = extension + "ファイル(*." + extension + ";*." + extension + ")| *." + extension + "; *." + extension + "| すべてのファイル(*.*)|*.*";
            sfd.FilterIndex = 1;
            sfd.Title = "アニメーションモデルデータの保存先のファイルを選択してください";
            //ダイアログボックスを閉じる前に現在のディレクトリを復元するようにする
            sfd.RestoreDirectory = true;
            //既に存在するファイル名を指定したとき警告する
            sfd.OverwritePrompt = true;
            //存在しないパスが指定されたとき警告を表示する
            sfd.CheckPathExists = true;

            //ダイアログを表示する
            if (sfd.ShowDialog() == DialogResult.OK)
            {
                System.IO.File.WriteAllText(sfd.FileName, in_write_file_data[0] + Environment.NewLine);

                for (int now_write_raw = 1; now_write_raw < in_write_file_data.Count; now_write_raw++)
                {
                    System.IO.File.AppendAllText(sfd.FileName, in_write_file_data[now_write_raw] + Environment.NewLine);
                }
            }

            return;
        }


        //-☆- 書き込み -☆-//

        // 独自形式であることを示す記述を書き込む　引数：書き込むデータの参照
        private static void M_Write_File_Format(ref List<string> in_write_file_data)
        {
            // 静的モデルに変換するときは、.elsttmdlであることを証明する記述をする
            if (m_convert_mode == E_CONVERT_MODE.e_STATIC_MODEL)
            {
                in_write_file_data.Add("This-Is-ELSTTMDL");
            }

            // アニメーションモデルに変換するときは、.elanmmdlであることを証明する記述をする
            else if (m_convert_mode == E_CONVERT_MODE.e_ANIMATION_MODEL)
            {
                in_write_file_data.Add("This-Is-ELANMMDL");
            }

            return;
        }


        // 静的モデルの頂点データを書き込む　引数：変換するモデルの情報, 書き込むデータの参照, 頂点を結合した後の頂点番号のリスト
        private static void M_Write_Static_Model_Vertex_Data(Scene in_scene, ref List<string> in_write_file_data, out List<int> in_vertex_to_shrink_vertex_number_list)
        {
            // ☆ 変数宣言 ☆ //
            List<S_Static_Vertex_Data> vertex_data_list = new List<S_Static_Vertex_Data>(); // 頂点データのリスト
            List<S_Static_Vertex_Data> shrunk_vertex_data_list = new List<S_Static_Vertex_Data>();    // 頂点を結合した後の頂点データのリスト


            // 頂点結合の情報のリストを初期化
            in_vertex_to_shrink_vertex_number_list = new List<int>();

            // 全頂点を探索し、重なっている頂点を結合する
            foreach (var l_now_mesh in in_scene.Meshes)
            {
                // 頂点ごとの静的モデル用頂点へのデータ変換
                for (int l_now_vertex_number = 0; l_now_vertex_number < l_now_mesh.VertexCount; l_now_vertex_number++)
                {
                    // ☆ 変数宣言 ☆ //
                    S_Static_Vertex_Data new_static_vertex_data = new S_Static_Vertex_Data();   // 新しい頂点データ

                    Vector3 new_position = new Vector3(0, 0, 0);    // 新しい頂点座標

                    Vector2 new_uv = new Vector2(0, 0); // 新しいUV座標

                    Vector4 new_color = new Vector4(0, 0, 0, 0);    // 新しい頂点カラー

                    Vector3 new_normal = new Vector3(0, 0, 0);  // 新しい法線ベクトル

                    Vector3 new_tangent = new Vector3(0, 0, 0); // 新しいタンジェントベクトル

                    Vector3 new_bi_tangent = new Vector3(0, 0, 0);  // 新しいバイノーマルタンジェント（従法線）


                    // 色情報があるなら登録（存在しない場合があるのでチェックする）
                    if (l_now_mesh.VertexColorChannelCount > 0)
                    {
                        new_color.X = l_now_mesh.VertexColorChannels[0][l_now_vertex_number].R;
                        new_color.Y = l_now_mesh.VertexColorChannels[0][l_now_vertex_number].G;
                        new_color.Z = l_now_mesh.VertexColorChannels[0][l_now_vertex_number].B;
                        new_color.W = l_now_mesh.VertexColorChannels[0][l_now_vertex_number].A;
                    }

                    // UV情報があるなら登録（存在しない場合があるのでチェックする）
                    if (l_now_mesh.TextureCoordinateChannelCount > 0)
                    {
                        new_uv.X = l_now_mesh.TextureCoordinateChannels[0][l_now_vertex_number].X;
                        new_uv.Y = l_now_mesh.TextureCoordinateChannels[0][l_now_vertex_number].Y;
                    }

                    // 頂点座標を登録
                    new_position.X = l_now_mesh.Vertices[l_now_vertex_number].X;
                    new_position.Y = l_now_mesh.Vertices[l_now_vertex_number].Y;
                    new_position.Z = l_now_mesh.Vertices[l_now_vertex_number].Z;

                    // 法線ベクトルを登録
                    new_normal.X = l_now_mesh.Normals[l_now_vertex_number].X;
                    new_normal.Y = l_now_mesh.Normals[l_now_vertex_number].Y;
                    new_normal.Z = l_now_mesh.Normals[l_now_vertex_number].Z;

                    // タンジェントベクトルを登録
                    new_tangent.X = l_now_mesh.Tangents[l_now_vertex_number].X;
                    new_tangent.Y = l_now_mesh.Tangents[l_now_vertex_number].Y;
                    new_tangent.Z = l_now_mesh.Tangents[l_now_vertex_number].Z;

                    // バイノーマルタンジェント（従法線）を登録
                    new_bi_tangent.X = l_now_mesh.BiTangents[l_now_vertex_number].X;
                    new_bi_tangent.Y = l_now_mesh.BiTangents[l_now_vertex_number].Y;
                    new_bi_tangent.Z = l_now_mesh.BiTangents[l_now_vertex_number].Z;


                    // 新しい頂点データを生成
                    new_static_vertex_data.mp_position = new_position;
                    new_static_vertex_data.mp_uv = new_uv;
                    new_static_vertex_data.mp_color = new_color;
                    new_static_vertex_data.mp_normal = new_normal;
                    new_static_vertex_data.mp_tangent = new_tangent;
                    new_static_vertex_data.mp_bi_normal_tangent = new_bi_tangent;

                    // この頂点データをリストに登録
                    vertex_data_list.Add(new_static_vertex_data);
                }
            }


            // 重なっている頂点を結合したリストを生成する
            for (int l_now_setting_vertex_number = 0; l_now_setting_vertex_number < vertex_data_list.Count; l_now_setting_vertex_number++)
            {
                // ☆ 変数宣言 ☆ //
                int l_now_searching_vertex_number = 0;  // 探索している頂点番号

                bool is_doubling = false;   // 重なっているかどうか


                // 今までに登録された頂点と重なっているかどうかを調べる
                for (l_now_searching_vertex_number = 0; l_now_searching_vertex_number < l_now_setting_vertex_number && l_now_searching_vertex_number < shrunk_vertex_data_list.Count; l_now_searching_vertex_number++)
                {
                    // 重なっているならフラグを立ててループを抜ける
                    if (shrunk_vertex_data_list[l_now_searching_vertex_number] == vertex_data_list[l_now_setting_vertex_number])
                    {
                        is_doubling = true;

                        break;
                    }
                }


                // 重なっているなら重なっている頂点の番号を記録
                if (is_doubling)
                {
                    in_vertex_to_shrink_vertex_number_list.Add(l_now_searching_vertex_number);
                }

                // 重なっていないなら頂点を結合したリストに登録
                else
                {
                    // 重なっていない頂点の番号を記録
                    in_vertex_to_shrink_vertex_number_list.Add(shrunk_vertex_data_list.Count);

                    // 新しい頂点をリストに登録
                    shrunk_vertex_data_list.Add(vertex_data_list[l_now_setting_vertex_number]);
                }
            }


            // 頂点数を書き込む
            in_write_file_data.Add("VERTSUM:" + shrunk_vertex_data_list.Count.ToString());

            // 頂点データを書き込む
            foreach (var vertex_data in shrunk_vertex_data_list)
            {
                // ☆ 変数宣言 ☆ //
                string vertex_write_text;  // 頂点に書き込むデータ


                // 書き込む頂点情報を設定
                vertex_write_text =

                      //==☆ 頂点座標 ☆==//
                      vertex_data.mp_position.X.ToString() + ","
                    + vertex_data.mp_position.Y.ToString() + ","
                    + vertex_data.mp_position.Z.ToString() + ":"

                    //==☆ UV座標 ☆==//
                    + vertex_data.mp_uv.X.ToString() + ","
                    + vertex_data.mp_uv.Y.ToString() + ":"

                    //==☆ 頂点カラー ☆==//
                    + vertex_data.mp_color.X.ToString() + ","
                    + vertex_data.mp_color.Y.ToString() + ","
                    + vertex_data.mp_color.Z.ToString() + ","
                    + vertex_data.mp_color.W.ToString() + ":"

                    //==☆ 法線ベクトル ☆==//
                    + vertex_data.mp_normal.X.ToString() + ","
                    + vertex_data.mp_normal.Y.ToString() + ","
                    + vertex_data.mp_normal.Z.ToString() + ":"

                    //==☆ タンジェント ☆==//
                    + vertex_data.mp_tangent.X.ToString() + ","
                    + vertex_data.mp_tangent.Y.ToString() + ","
                    + vertex_data.mp_tangent.Z.ToString() + ":"

                    //==☆ バイノーマルタンジェント（従法線） ☆==//
                    + vertex_data.mp_bi_normal_tangent.X.ToString() + ","
                    + vertex_data.mp_bi_normal_tangent.Y.ToString() + ","
                    + vertex_data.mp_bi_normal_tangent.Z.ToString() + ":";


                // 生成した頂点情報を書き込む
                in_write_file_data.Add(vertex_write_text);
            }

            return;
        }


        // アニメーションモデルの頂点データを書き込む　引数：変換するモデルの情報, 書き込むデータの参照, 頂点を結合した後の頂点番号のリスト　戻り値：成功時のみtrue
        private static bool M_Write_Animation_Model_Vertex_Data(Scene in_scene, ref List<string> in_write_file_data, out List<int> in_vertex_to_shrink_vertex_number_list)
        {
            // ☆ 変数宣言 ☆ //
            List<S_Animation_Vertex_Data> vertex_data_list = new List<S_Animation_Vertex_Data>(); // 頂点データのリスト
            List<S_Animation_Vertex_Data> shrunk_vertex_data_list = new List<S_Animation_Vertex_Data>();    // 頂点を結合した後の頂点データのリスト


            // 頂点結合の情報のリストを初期化
            in_vertex_to_shrink_vertex_number_list = new List<int>();

            // 全頂点を探索し、重なっている頂点を結合する
            foreach (var l_now_mesh in in_scene.Meshes)
            {
                // ☆ 変数宣言 ☆ //
                List<List<CS_Bone_Weight_Data>> vertex_weight_list = new List<List<CS_Bone_Weight_Data>>(); // 頂点ウェイト値のリスト


                // ボーンウェイトの配列を生成
                foreach (var l_now_vertex in l_now_mesh.Vertices)
                {
                    vertex_weight_list.Add(new List<CS_Bone_Weight_Data>());
                }

                // ボーンウェイト情報の設定
                foreach (var l_now_bone in l_now_mesh.Bones)
                {
                    // ☆ 定数 ☆ //
                    const int con_WEIGHT_COUNT_MAX = 4;    // １頂点に対するウェイト情報量の上限


                    // ☆ 変数宣言 ☆ //
                    int bone_index = 0; // ボーンID


                    // ボーンIDを取得
                    foreach (var bone_index_data in Form_3D_Model_Convert_Setting.mp_bone_data_list)
                    {
                        if (bone_index_data.name == l_now_bone.Name)
                        {
                            bone_index = bone_index_data.index;

                            break;
                        }
                    }

                    // ボーンウェイト値とボーンIDをセット
                    foreach (var l_now_weight in l_now_bone.VertexWeights)
                    {
                        // ウェイト情報数が4を超えるまではウェイト情報を登録する
                        if (vertex_weight_list[l_now_weight.VertexID].Count < con_WEIGHT_COUNT_MAX)
                        {
                            vertex_weight_list[l_now_weight.VertexID].Add(new CS_Bone_Weight_Data(bone_index, l_now_weight.Weight));
                        }

                        // この形式のウェイトは4つまでだが、5つ以上のボーンのウェイト情報を頂点が持っている時
                        else
                        {
                            //メッセージボックスを表示する
                            DialogResult result = MessageBox.Show
                            (
                                "5つ以上のボーンから影響(Weight)を受ける頂点がありますが、.elanmmdlで指定できるWeightのボーン数は4つまでです。このままでは5つ目以降の情報を削除することになりますが、続行しますか？"
                                    + Environment.NewLine + "ボーン名:" + Form_3D_Model_Convert_Setting.mp_bone_data_list[bone_index].name,
                                "続行確認",
                                MessageBoxButtons.YesNoCancel,
                                MessageBoxIcon.Exclamation,
                                MessageBoxDefaultButton.Button2
                            );

                            // はい選択時は続行
                            if (result == DialogResult.Yes)
                            {
                                break;
                            }

                            // それ以外の時は終了
                            else
                            {
                                return false;
                            }
                        }
                    }
                }

                // ボーンウェイト情報を正規化
                for (int l_now_bone_number = 0; l_now_bone_number < vertex_weight_list.Count; l_now_bone_number++)
                {
                    // ☆ 変数宣言 ☆ //
                    List<CS_Bone_Weight_Data> new_vertex_weight_list = vertex_weight_list[l_now_bone_number];    // 新しいウェイト情報リスト


                    // ウェイト情報を正規化
                    M_Adjust_Vertex_Weight(ref new_vertex_weight_list);
                }


                // 頂点ごとの静的モデル用頂点へのデータ変換
                for (int l_now_vertex_number = 0; l_now_vertex_number < l_now_mesh.VertexCount; l_now_vertex_number++)
                {
                    // ☆ 変数宣言 ☆ //
                    S_Animation_Vertex_Data new_animation_vertex_data = new S_Animation_Vertex_Data();   // 新しい頂点データ

                    Vector3 new_position = new Vector3(0, 0, 0);    // 新しい頂点座標

                    Vector2 new_uv = new Vector2(0, 0); // 新しいUV座標

                    Vector4 new_color = new Vector4(0, 0, 0, 0);    // 新しい頂点カラー

                    Vector3 new_normal = new Vector3(0, 0, 0);  // 新しい法線ベクトル

                    Vector3 new_tangent = new Vector3(0, 0, 0); // 新しいタンジェントベクトル

                    Vector3 new_bi_tangent = new Vector3(0, 0, 0);  // 新しいバイノーマルタンジェント（従法線）


                    // 色情報があるなら登録（存在しない場合があるのでチェックする）
                    if (l_now_mesh.VertexColorChannelCount > 0)
                    {
                        new_color.X = l_now_mesh.VertexColorChannels[0][l_now_vertex_number].R;
                        new_color.Y = l_now_mesh.VertexColorChannels[0][l_now_vertex_number].G;
                        new_color.Z = l_now_mesh.VertexColorChannels[0][l_now_vertex_number].B;
                        new_color.W = l_now_mesh.VertexColorChannels[0][l_now_vertex_number].A;
                    }

                    // UV情報があるなら登録（存在しない場合があるのでチェックする）
                    if (l_now_mesh.TextureCoordinateChannelCount > 0)
                    {
                        new_uv.X = l_now_mesh.TextureCoordinateChannels[0][l_now_vertex_number].X;
                        new_uv.Y = l_now_mesh.TextureCoordinateChannels[0][l_now_vertex_number].Y;
                    }

                    // 頂点座標を登録
                    new_position.X = l_now_mesh.Vertices[l_now_vertex_number].X;
                    new_position.Y = l_now_mesh.Vertices[l_now_vertex_number].Y;
                    new_position.Z = l_now_mesh.Vertices[l_now_vertex_number].Z;

                    // 法線ベクトルを登録
                    new_normal.X = l_now_mesh.Normals[l_now_vertex_number].X;
                    new_normal.Y = l_now_mesh.Normals[l_now_vertex_number].Y;
                    new_normal.Z = l_now_mesh.Normals[l_now_vertex_number].Z;

                    // タンジェントベクトルを登録
                    new_tangent.X = l_now_mesh.Tangents[l_now_vertex_number].X;
                    new_tangent.Y = l_now_mesh.Tangents[l_now_vertex_number].Y;
                    new_tangent.Z = l_now_mesh.Tangents[l_now_vertex_number].Z;

                    // バイノーマルタンジェント（従法線）を登録
                    new_bi_tangent.X = l_now_mesh.BiTangents[l_now_vertex_number].X;
                    new_bi_tangent.Y = l_now_mesh.BiTangents[l_now_vertex_number].Y;
                    new_bi_tangent.Z = l_now_mesh.BiTangents[l_now_vertex_number].Z;


                    // 新しい頂点データを生成
                    new_animation_vertex_data.mp_position = new_position;
                    new_animation_vertex_data.mp_uv = new_uv;
                    new_animation_vertex_data.mp_color = new_color;
                    new_animation_vertex_data.mp_normal = new_normal;
                    new_animation_vertex_data.mp_tangent = new_tangent;
                    new_animation_vertex_data.mp_bi_normal_tangent = new_bi_tangent;
                    new_animation_vertex_data.mp_bone_weight = vertex_weight_list[l_now_vertex_number];

                    // この頂点データをリストに登録
                    vertex_data_list.Add(new_animation_vertex_data);
                }
            }


            // 重なっている頂点を結合したリストを生成する
            for (int l_now_setting_vertex_number = 0; l_now_setting_vertex_number < vertex_data_list.Count; l_now_setting_vertex_number++)
            {
                // ☆ 変数宣言 ☆ //
                int l_now_searching_vertex_number = 0;  // 探索している頂点番号

                bool is_doubling = false;   // 重なっているかどうか


                // 今までに登録された頂点と重なっているかどうかを調べる
                for (l_now_searching_vertex_number = 0; l_now_searching_vertex_number < l_now_setting_vertex_number && l_now_searching_vertex_number < shrunk_vertex_data_list.Count; l_now_searching_vertex_number++)
                {
                    // 重なっているならフラグを立ててループを抜ける
                    if (shrunk_vertex_data_list[l_now_searching_vertex_number] == vertex_data_list[l_now_setting_vertex_number])
                    {
                        is_doubling = true;

                        break;
                    }
                }


                // 重なっているなら重なっている頂点の番号を記録
                if (is_doubling)
                {
                    in_vertex_to_shrink_vertex_number_list.Add(l_now_searching_vertex_number);
                }

                // 重なっていないなら頂点を結合したリストに登録
                else
                {
                    // 重なっていない頂点の番号を記録
                    in_vertex_to_shrink_vertex_number_list.Add(shrunk_vertex_data_list.Count);

                    // 新しい頂点をリストに登録
                    shrunk_vertex_data_list.Add(vertex_data_list[l_now_setting_vertex_number]);
                }
            }


            // 頂点数を書き込む
            in_write_file_data.Add("VERTSUM:" + shrunk_vertex_data_list.Count.ToString());

            // 頂点データを書き込む
            foreach (var vertex_data in shrunk_vertex_data_list)
            {
                // ☆ 変数宣言 ☆ //
                string vertex_write_text;  // 頂点に書き込むデータ


                // 書き込む頂点情報を設定
                vertex_write_text =

                      //==☆ 頂点座標 ☆==//
                      vertex_data.mp_position.X.ToString() + ","
                    + vertex_data.mp_position.Y.ToString() + ","
                    + vertex_data.mp_position.Z.ToString() + ":"

                    //==☆ UV座標 ☆==//
                    + vertex_data.mp_uv.X.ToString() + ","
                    + vertex_data.mp_uv.Y.ToString() + ":"

                    //==☆ 頂点カラー ☆==//
                    + vertex_data.mp_color.X.ToString() + ","
                    + vertex_data.mp_color.Y.ToString() + ","
                    + vertex_data.mp_color.Z.ToString() + ","
                    + vertex_data.mp_color.W.ToString() + ":"

                    //==☆ 法線ベクトル ☆==//
                    + vertex_data.mp_normal.X.ToString() + ","
                    + vertex_data.mp_normal.Y.ToString() + ","
                    + vertex_data.mp_normal.Z.ToString() + ":"

                    //==☆ タンジェント ☆==//
                    + vertex_data.mp_tangent.X.ToString() + ","
                    + vertex_data.mp_tangent.Y.ToString() + ","
                    + vertex_data.mp_tangent.Z.ToString() + ":"

                    //==☆ バイノーマルタンジェント（従法線） ☆==//
                    + vertex_data.mp_bi_normal_tangent.X.ToString() + ","
                    + vertex_data.mp_bi_normal_tangent.Y.ToString() + ","
                    + vertex_data.mp_bi_normal_tangent.Z.ToString() + ":";

                // アニメーションモデル時はボーンウェイト情報を追記
                foreach (var weight_inform in vertex_data.mp_bone_weight)
                {
                    vertex_write_text += weight_inform.mp_index.ToString() + "/" + weight_inform.mp_weight.ToString() + ",";
                }

                // ボーンウェイト情報終了を記録
                vertex_write_text += ":";


                // 生成した頂点情報を書き込む
                in_write_file_data.Add(vertex_write_text);
            }

            return true;
        }


        // ボーンウェイト情報を合計で1.0fになるように調整する　引数：頂点ウェイト情報のリスト
        private static void M_Adjust_Vertex_Weight(ref List<CS_Bone_Weight_Data> in_vertex_weight_list)
        {
            // ☆ 変数宣言 ☆ //
            double weight_sum = 0.0;    // ウェイトの合計値


            // ウェイトの合計値を初期化
            while (weight_sum >= 1.0f)
            {
                // ウェイトの合計値を初期化
                weight_sum = 0.0;

                // ウェイト値の合計を計算
                foreach (var weight_data in in_vertex_weight_list)
                {
                    weight_sum += weight_data.mp_weight;
                }

                // 1.0を超えないなら全体的に修正をかける
                if (weight_sum < 1.0)
                {
                    for (int l_weight_num = 0; l_weight_num < in_vertex_weight_list.Count; l_weight_num++)
                    {
                        in_vertex_weight_list[l_weight_num] = new CS_Bone_Weight_Data(in_vertex_weight_list[l_weight_num].mp_index, in_vertex_weight_list[l_weight_num].mp_weight + (1.0f - (float)weight_sum) / (float)in_vertex_weight_list.Count);
                    }

                    // 修正後のウェイトの合計値を取得
                    weight_sum = 0.0;
                    foreach (var weight_data in in_vertex_weight_list)
                    {
                        weight_sum += weight_data.mp_weight;
                    }
                }
            }

            return;
        }


        // ボーン情報を書き込む　引数：書き込むデータの参照
        private static void M_Write_Bone_Data(ref List<string> in_write_file_data)
        {
            // ☆ 変数宣言 ☆ //
            int now_bone_index = 0; // 現在のボーン番号


            // ボーン数を記録
            in_write_file_data.Add("BONESUM:" + Form_3D_Model_Convert_Setting.mp_bone_data_list.Count.ToString());

            // ボーン名とオフセットマトリクスを記録
            foreach (var bone_index in Form_3D_Model_Convert_Setting.mp_bone_data_list)
            {
                in_write_file_data.Add
                    (
                          bone_index.parent_index.ToString() + "/"
                        + Form_3D_Model_Convert_Setting.mp_born_name_list[now_bone_index] + "/"
                        + bone_index.offset_matrix.A1.ToString() + ","
                        + bone_index.offset_matrix.A2.ToString() + ","
                        + bone_index.offset_matrix.A3.ToString() + ","
                        + bone_index.offset_matrix.A4.ToString() + ","
                        + bone_index.offset_matrix.B1.ToString() + ","
                        + bone_index.offset_matrix.B2.ToString() + ","
                        + bone_index.offset_matrix.B3.ToString() + ","
                        + bone_index.offset_matrix.B4.ToString() + ","
                        + bone_index.offset_matrix.C1.ToString() + ","
                        + bone_index.offset_matrix.C2.ToString() + ","
                        + bone_index.offset_matrix.C3.ToString() + ","
                        + bone_index.offset_matrix.C4.ToString() + ","
                        + bone_index.offset_matrix.D1.ToString() + ","
                        + bone_index.offset_matrix.D2.ToString() + ","
                        + bone_index.offset_matrix.D3.ToString() + ","
                        + bone_index.offset_matrix.D4.ToString() + "/"
                    );

                // 次のボーン番号を指定
                now_bone_index += 1;
            }

            return;
        }


        // メッシュの情報を書き込む　引数：読み込んだモデルの情報, 書き込むデータの参照, 頂点を結合した後の頂点番号のリスト
        private static void M_Write_Mesh_Data(Scene in_scene, ref List<string> in_write_file_data, List<int> vertex_to_shrunk_vertex_number_list)
        {
            // ☆ 変数宣言 ☆ //
            int mesh_num = 0;   // 現在のメッシュ番号
            int now_vertex_slot_offset = 0; // 現在の頂点の開始位置


            // メッシュ数を記録
            in_write_file_data.Add("MESHSUM:" + in_scene.MeshCount.ToString());


            // メッシュ数分繰り返す
            foreach (var mesh in in_scene.Meshes)
            {
                // メッシュ名を記述
                in_write_file_data.Add("MESH:");
                in_write_file_data.Add(_3D_Model_Converter_And_Drawer.Form_3D_Model_Convert_Setting.mp_mesh_name_list[mesh_num]);

                // マテリアル名を記述
                in_write_file_data.Add("MATERIAL:");
                in_write_file_data.Add(_3D_Model_Converter_And_Drawer.Form_3D_Model_Convert_Setting.mp_material_name_list[mesh.MaterialIndex]);

                // メッシュのインデックス開始位置指定
                in_write_file_data.Add("INDEX:" + mesh.FaceCount * 3);

                // インデックスデータを書き込む
                foreach (var face in mesh.Faces)
                {
                    in_write_file_data.Add(vertex_to_shrunk_vertex_number_list[(face.Indices[0] + now_vertex_slot_offset)].ToString());
                    in_write_file_data.Add(vertex_to_shrunk_vertex_number_list[(face.Indices[1] + now_vertex_slot_offset)].ToString());
                    in_write_file_data.Add(vertex_to_shrunk_vertex_number_list[(face.Indices[2] + now_vertex_slot_offset)].ToString());
                }

                // 空白をあける
                in_write_file_data.Add("");

                // 次のメッシュ番号を指定
                mesh_num++;

                // 次の頂点の開始位置を指定
                now_vertex_slot_offset += mesh.VertexCount;
            }

            return;
        }
    }
}








































//☆======================================================================☆
// Copyright 2023 髙坂龍誠
// 
// もしもこのコードを自分のプロジェクトに利用したいのであれば、
// メールアドレス：takasaka.ryusei1116@gmail.com
// または、髙坂龍誠までご連絡ください。
// コードの不明部分の解説や、最新の状態の提供などに対応いたします。
//☆======================================================================☆

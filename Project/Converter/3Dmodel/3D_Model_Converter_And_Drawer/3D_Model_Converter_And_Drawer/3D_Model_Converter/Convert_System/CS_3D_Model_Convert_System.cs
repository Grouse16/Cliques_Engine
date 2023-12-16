using Assimp;
using Assimp.Unmanaged;
using SharpDX;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
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

        // ボーンとインデックスを管理するための構造体
        struct S_Bone_Data_Inform
        {
            public string name; // ボーン名
            public int index;   // ボーンのインデックス番号
            public Matrix4x4 offset_matrix;    // オフセットマトリクス行列   


            // 初期化用コンストラクタ
            public S_Bone_Data_Inform(string in_name, int in_index, Matrix4x4 in_offset_matrix)
            {
                name = in_name;
                index = in_index;
                offset_matrix = in_offset_matrix;
            }
        }

        // 頂点ウェイト情報の構造体
        struct S_Vertex_Weight_Inform
        {
            public double value; // ウェイト値
            public int index;   // ボーン番号
            

            // 値初期化用コンストラクタ
            public S_Vertex_Weight_Inform(double in_value, int in_index)
            {
                value = in_value;
                index = in_index;
            }

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

            List<S_Bone_Data_Inform> bone_index_list = new List<S_Bone_Data_Inform>();   // ボーンとインデックスのリスト

            int mesh_num = 0;   // 現在のメッシュ番号


            // 静的モデルに変換するときは、.elsttmdlであることを証明する記述をする
            if (m_convert_mode == E_CONVERT_MODE.e_STATIC_MODEL)
            {
                write_file_data.Add("This-Is-ELSTTMDL");
            }
            // アニメーションモデルに変換するときは、.elanmmdlであることを証明する記述をする
            else if (m_convert_mode == E_CONVERT_MODE.e_ANIMATION_MODEL)
            {
                write_file_data.Add("This-Is-ELANMMDL");
            }

            // メッシュ数を記録
            write_file_data.Add("MESHSUM:" + in_scene.MeshCount.ToString());


            // アニメーションのあるモデルへ変換するときのみ
            if (m_convert_mode == E_CONVERT_MODE.e_ANIMATION_MODEL)
            {
                // ☆ 変数宣言 ☆ //
                int now_bone_index = 0; // 現在のボーン番号


                // メッシュ数分ボーン名とインデックスの関連付けを行う
                foreach (var l_now_bone in in_scene.RootNode.Children)
                {
                    bone_index_list.Add(new S_Bone_Data_Inform(l_now_bone.Name, bone_index_list.Count, l_now_bone.Transform));
                }


                // ボーン数を記録
                write_file_data.Add("BONESUM:" + bone_index_list.Count.ToString());

                // ボーン名とオフセットマトリクスを記録
                foreach (var bone_index in bone_index_list)
                {
                    write_file_data.Add
                        (
                              Form_3D_Model_Convert_Setting.mp_born_name_list[now_bone_index] + "/"
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
                            + bone_index.offset_matrix.D4.ToString() + ","
                        );
                }
            }


            // メッシュ数分繰り返す
            foreach (var mesh in in_scene.Meshes)
            {
                // ☆ 変数宣言 ☆ //
                List<List<S_Vertex_Weight_Inform>> m_vertex_weight_list = new List<List<S_Vertex_Weight_Inform>>(); // 頂点ウェイト値のリスト


                // アニメーションモデル時のみボーンの情報を取得
                if (m_convert_mode == E_CONVERT_MODE.e_ANIMATION_MODEL)
                {
                    // 現在のメッシュ用の頂点ウェイト情報分のメモリを確保
                    foreach (var vertex in mesh.Vertices)
                    {
                        m_vertex_weight_list.Add(new List<S_Vertex_Weight_Inform>());
                    }

                    // このメッシュのウェイト値を全て頂点ごとに修正
                    foreach (var bone in mesh.Bones)
                    {
                        // ☆ 変数宣言 ☆ //
                        int bone_index = 0; // ボーンのインデックス番号


                        // ボーンのインデックスIDを取得
                        foreach (var bone_index_data in bone_index_list)
                        {
                            if (bone_index_data.name == bone.Name)
                            {
                                bone_index = bone_index_data.index;
                            }
                        }

                        // ウェイト値とボーンIDをリストに登録
                        foreach (var weight_value in bone.VertexWeights)
                        {
                            // ☆ 定数 ☆ //
                            const int con_WEIGHT_COUNT_MAX = 4;    // １頂点に対するウェイト情報量の上限


                            // ウェイト情報数が4を超えるまではウェイト情報を登録する
                            if (m_vertex_weight_list[weight_value.VertexID].Count < con_WEIGHT_COUNT_MAX)
                            {
                                m_vertex_weight_list[weight_value.VertexID].Add(new S_Vertex_Weight_Inform(weight_value.Weight, bone_index));
                            }

                            // この形式のウェイトは4つまでだが、5つ以上のボーンのウェイト情報を頂点が持っている時
                            else
                            {
                                //メッセージボックスを表示する
                                DialogResult result = MessageBox.Show("5つ以上のボーンから影響(Weight)を受ける頂点がありますが、.elanmmdlで指定できるWeightのボーン数は4つまでです。このままでは5つ目以降の情報を削除することになりますが、続行しますか？" + Environment.NewLine + "ボーン名:" + bone.Name,
                                    "続行確認",
                                    MessageBoxButtons.YesNoCancel,
                                    MessageBoxIcon.Exclamation,
                                    MessageBoxDefaultButton.Button2);

                                // はい選択時は続行
                                if (result == DialogResult.Yes)
                                {

                                }

                                // それ以外の時は終了
                                else
                                {
                                    return;
                                }
                            }
                        }
                    }

                    // それぞれの頂点のウェイト値を合計で1.0になるように調整する
                    foreach (var vertex_weight_list in m_vertex_weight_list)
                    {
                        // ☆ 変数宣言 ☆ //
                        double weight_sum = 0.0;    // ウェイトの合計値

                        int weight_slot_sum = vertex_weight_list.Count;    // この頂点のウェイト数

                        double weight_attach_level = 1.0; // ウェイトの修正時の修正力の強さ


                        do
                        {
                            // ウェイトの合計値を初期化
                            weight_sum = 0.0;

                            // ウェイト値の合計を計算
                            foreach (var weight_data in vertex_weight_list)
                            {
                                weight_sum += weight_data.value;
                            }

                            // 1.0を超えないなら全体的に修正をかける
                            if (weight_sum < 1.0)
                            {
                                for (int l_weight_num = 0; l_weight_num < weight_slot_sum; l_weight_num++)
                                {
                                    vertex_weight_list[l_weight_num] = new S_Vertex_Weight_Inform(vertex_weight_list[l_weight_num].value + (1.0 - weight_sum) / (double)weight_slot_sum, vertex_weight_list[l_weight_num].index);
                                }

                                // 修正後のウェイトの合計値を取得
                                weight_sum = 0.0;
                                foreach (var weight_data in vertex_weight_list)
                                {
                                    weight_sum += weight_data.value;
                                }

                                weight_attach_level *= 2.0;
                            }

                            // 超えるなら修正力を初期化
                            if (weight_sum >= 1.0)
                            {
                                weight_attach_level = 2.0;
                            }

                        } while (weight_sum < 1.0);
                    }
                }

                // メッシュ名を記述
                write_file_data.Add("MESH:");
                write_file_data.Add(_3D_Model_Converter_And_Drawer.Form_3D_Model_Convert_Setting.mp_mesh_name_list[mesh_num]);

                // マテリアル名を記述
                write_file_data.Add("MATERIAL:");
                write_file_data.Add(_3D_Model_Converter_And_Drawer.Form_3D_Model_Convert_Setting.mp_material_name_list[mesh.MaterialIndex]);

                // 頂点数を入力
                write_file_data.Add("VERT:" + mesh.VertexCount.ToString());

                // 頂点データを書き込む
                for (int now_vertex = 0; now_vertex < mesh.Vertices.Count; now_vertex++)
                {
                    // ☆ 変数宣言 ☆ //
                    string vertex_write_text;  // 頂点に書き込むデータ

                    Color4D color = new Color4D(0, 0, 0, 0); // 色情報

                    Vector3D uv = new Vector3D(0, 0, 0);


                    // 色情報があるなら登録（存在しない場合があるのでチェックする）
                    if (mesh.VertexColorChannelCount > 0)
                    {
                        color = mesh.VertexColorChannels[0][now_vertex];
                    }

                    // UV情報があるなら登録（存在しない場合があるのでチェックする）
                    if (mesh.TextureCoordinateChannelCount > 0)
                    {
                        uv = mesh.TextureCoordinateChannels[0][now_vertex];
                    }

                    // 書き込む頂点情報を設定
                    vertex_write_text =

                        //==☆ 頂点座標 ☆==//
                          mesh.Vertices[now_vertex].X.ToString() + ","
                        + mesh.Vertices[now_vertex].Y.ToString() + ","
                        + mesh.Vertices[now_vertex].Z.ToString() + ":"

                        //==☆ UV座標 ☆==//
                        + uv.X.ToString() + ","
                        + uv.Y.ToString() + ":"

                        //==☆ 頂点カラー ☆==//
                        + color.R.ToString() + ","
                        + color.G.ToString() + ","
                        + color.B.ToString() + ","
                        + color.A.ToString() + ":"

                        //==☆ 法線ベクトル ☆==//
                        + mesh.Normals[now_vertex].X.ToString() + ","
                        + mesh.Normals[now_vertex].Y.ToString() + ","
                        + mesh.Normals[now_vertex].Z.ToString() + ":"

                        //==☆ タンジェント ☆==//
                        + mesh.Tangents[now_vertex].X.ToString() + ","
                        + mesh.Tangents[now_vertex].Y.ToString() + ","
                        + mesh.Tangents[now_vertex].Z.ToString() + ":"

                        //==☆ バイノーマルタンジェント（従法線） ☆==//
                        + mesh.BiTangents[now_vertex].X.ToString() + ","
                        + mesh.BiTangents[now_vertex].Y.ToString() + ","
                        + mesh.BiTangents[now_vertex].Z.ToString() + ":";


                    // アニメーションモデル時はボーンウェイト情報を追記
                    if (m_convert_mode == E_CONVERT_MODE.e_ANIMATION_MODEL)
                    {
                        foreach (var weight_inform in m_vertex_weight_list[now_vertex])
                        {
                            vertex_write_text += weight_inform.index.ToString() + "/" + weight_inform.value.ToString() + ",";
                        }

                        // ボーンウェイト情報終了を記録
                        vertex_write_text += ":";
                    }

                    // 生成した頂点情報を書き込み
                    write_file_data.Add(vertex_write_text);
                }


                // メッシュのインデックス開始位置指定
                write_file_data.Add("INDEX:" + mesh.FaceCount * 3);

                // インデックスデータを書き込む
                foreach (var face in mesh.Faces)
                {
                    write_file_data.Add(face.Indices[0].ToString());
                    write_file_data.Add(face.Indices[1].ToString());
                    write_file_data.Add(face.Indices[2].ToString());
                }

                // 空白をあける
                write_file_data.Add("");

                // 次のメッシュ番号を指定
                mesh_num++;
            }

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
            sfd.Filter = extension + "ファイル(*." + extension +";*." + extension + ")| *." + extension + "; *." + extension  + "| すべてのファイル(*.*)|*.*";
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

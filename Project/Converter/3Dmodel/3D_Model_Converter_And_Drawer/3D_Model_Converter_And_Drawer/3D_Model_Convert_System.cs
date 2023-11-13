using Assimp;
using Assimp.Unmanaged;
using SharpDX;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

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
    internal class _3D_Model_Convert_System
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
        static List<S_Bone_Data_Inform> m_bone_index_list = new List<S_Bone_Data_Inform>();   // ボーンとインデックスのリスト

        static public Scene m_now_scene = new Scene();  // シーンのデータ

        static public E_CONVERT_MODE m_convert_mode = E_CONVERT_MODE.e_STATIC_MODEL;    // 変換モード

        static List<string> m_file_write_data = new List<string>(); // 書き込むファイルのデータ
        static List<string> m_file_mat_write_data = new List<string>(); // 書き込むマテリアルの質感用ファイルのデータ


        // 3Dモデルを変換する　引数：シーンデータ
        public static void M_Convert_Data_Set(ref Scene in_scene)
        {
            m_now_scene = in_scene;
        }

        public static void M_Input_Form_Create()
        {
            _3D_Model_Converter_And_Drawer.Form1.material_num = m_now_scene.MaterialCount;
            _3D_Model_Converter_And_Drawer.Form1.mesh_num = m_now_scene.MeshCount;

            Form1 new_form = new Form1();
            new_form.Show();
        }

        // 変換の実行
        public static void M_Covert_Execute()
        {
            m_file_write_data.Clear();
            m_bone_index_list.Clear();
            m_file_mat_write_data.Clear();

            // メッシュデータの変換
            if (M_Mesh_Convert() == false)
            {
                return;
            }


            // 静的モデルを指定されているなら静的モデル形式でセーブ
            if (m_convert_mode == E_CONVERT_MODE.e_STATIC_MODEL)
            {
                M_Save_Static_Model_This_File();
            }

            // アニメーションモデルを指定されているならアニメーションモデル形式でセーブ
            else if (m_convert_mode == E_CONVERT_MODE.e_ANIMATION_MODEL)
            {
                M_Save_Animation_Model_This_File();
            }

            // マテリアルの質感情報を取り出す
            M_Convert_Material_Inform();

            // マテリアルの質感情報を抜き出したファイルを保存
            M_Save_Mat_Inform_File();

            return;
        }


        // メッシュデータの変換
        private static bool M_Mesh_Convert()
        {
            // 静的モデルに変換するときは、.elsttmdlであることを証明する記述をする
            if (m_convert_mode == E_CONVERT_MODE.e_STATIC_MODEL)
            {
                m_file_write_data.Add("This-Is-ELSTTMDL");
            }
            else if (m_convert_mode == E_CONVERT_MODE.e_ANIMATION_MODEL)
            {
                m_file_write_data.Add("This-Is-ELANMMDL");
            }

            // メッシュ数を記録
            m_file_write_data.Add("MESHSUM:" + m_now_scene.MeshCount.ToString());


            // アニメーションのあるモデルへ変換するときのみ
            if (m_convert_mode == E_CONVERT_MODE.e_ANIMATION_MODEL)
            {
                // メッシュ数分ボーン名とインデックスの関連付けを行う
                foreach (var mesh in m_now_scene.Meshes)
                {
                    foreach (var bone in mesh.Bones)
                    {
                        // ☆ 変数宣言 ☆ //
                        bool detected = false;  // ボーンがすでに登録されていたかどうかのフラグ　trueで登録済み


                        foreach (var bone_index in m_bone_index_list)
                        {
                            if (bone_index.name == bone.Name)
                            {
                                detected = true;
                            }
                        }

                        // 見つからなかったら新しく登録
                        if (detected == false)
                        {
                            m_bone_index_list.Add(new S_Bone_Data_Inform(bone.Name, m_bone_index_list.Count, bone.OffsetMatrix));
                        }
                    }
                }


                // ボーン数とボーン名、オフセットマトリクスを記録
                m_file_write_data.Add("BONESUM:" + m_bone_index_list.Count.ToString());
                foreach (var bone_index in m_bone_index_list)
                {
                    m_file_write_data.Add
                        (
                              bone_index.name + "/"
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
            int mesh_num = 0;
            foreach (var mesh in m_now_scene.Meshes)
            {
                // ☆ 変数宣言 ☆ //
                List<List<S_Vertex_Weight_Inform>> m_vertex_weight_list = new List<List<S_Vertex_Weight_Inform>>(); // 頂点ウェイト値のリスト


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
                    foreach (var bone_index_data in m_bone_index_list)
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
                            DialogResult result = MessageBox.Show("5つ以上のボーンから影響(Weight)を受ける頂点がありますが、.elanmmdlで指定できるWeight数は4つまでです。このままでは5つ目以降の情報を削除することになりますが、続行しますか？" + Environment.NewLine + "ボーン名:" + bone.Name,
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
                                return false;
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

                // メッシュ名を記述
                m_file_write_data.Add("MESH" + (mesh_num + 1).ToString() + ":");
                m_file_write_data.Add(_3D_Model_Converter_And_Drawer.Form1.mesh_group_name_list[mesh_num]);

                // マテリアル名を記述
                m_file_write_data.Add("MATERIAL" + (mesh_num + 1).ToString() + ":");
                m_file_write_data.Add(_3D_Model_Converter_And_Drawer.Form1.material_name_list[mesh.MaterialIndex]);

                // 頂点数を入力
                m_file_write_data.Add("VERT" + (mesh_num + 1).ToString() + ":" + mesh.VertexCount);

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
                        + mesh.Vertices[now_vertex].Z.ToString() + "," + ":"

                        //==☆ UV座標 ☆==//
                        + uv.X.ToString() + ","
                        + uv.Y.ToString() + "," + ":"

                        //==☆ 頂点カラー ☆==//
                        + color.R.ToString() + ","
                        + color.G.ToString() + ","
                        + color.B.ToString() + ","
                        + color.A.ToString() + "," + ":"

                        //==☆ 法線ベクトル ☆==//
                        + mesh.Normals[now_vertex].X.ToString() + ","
                        + mesh.Normals[now_vertex].Y.ToString() + ","
                        + mesh.Normals[now_vertex].Z.ToString() + "," + ":"

                        //==☆ タンジェント ☆==//
                        + mesh.Tangents[now_vertex].X.ToString() + ","
                        + mesh.Tangents[now_vertex].Y.ToString() + ","
                        + mesh.Tangents[now_vertex].Z.ToString() + "," + ":"

                        //==☆ バイノーマルタンジェント（順法線） ☆==//
                        + mesh.BiTangents[now_vertex].X.ToString() + ","
                        + mesh.BiTangents[now_vertex].Y.ToString() + ","
                        + mesh.BiTangents[now_vertex].Z.ToString() + "," + ":";


                    // アニメーション時はボーンウェイト情報を追記
                    if (m_convert_mode == E_CONVERT_MODE.e_ANIMATION_MODEL)
                    {
                        foreach (var weight_inform in m_vertex_weight_list[now_vertex])
                        {
                            vertex_write_text += weight_inform.index.ToString() + "/" + weight_inform.value.ToString() + ",";
                        }

                        // ボーンウェイト情報終了を記録
                        vertex_write_text += ";";
                    }

                    // 生成した頂点情報を書き込み
                    m_file_write_data.Add(vertex_write_text);
                }


                // メッシュのインデックス開始位置指定
                m_file_write_data.Add("INDEX" + (mesh_num + 1).ToString() + ":" + mesh.FaceCount * 3);

                // インデックスデータを書き込む
                foreach (var face in mesh.Faces)
                {
                    m_file_write_data.Add(face.Indices[0].ToString());
                    m_file_write_data.Add(face.Indices[1].ToString());
                    m_file_write_data.Add(face.Indices[2].ToString());
                }

                // 空白をあける
                m_file_write_data.Add("");

                // 次のメッシュ番号を指定
                mesh_num++;
            }

            return true;
        }


        // 静的モデル形式でのセーブ
        private static void M_Save_Static_Model_This_File()
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
                System.IO.File.WriteAllText(sfd.FileName, m_file_write_data[0] + Environment.NewLine);

                for (int now_write_raw = 1; now_write_raw < m_file_write_data.Count; now_write_raw++)
                {
                    System.IO.File.AppendAllText(sfd.FileName, m_file_write_data[now_write_raw] + Environment.NewLine);
                }
            }
        }


        // アニメーションモデル形式でのセーブ
        private static void M_Save_Animation_Model_This_File()
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
                System.IO.File.WriteAllText(sfd.FileName, m_file_write_data[0] + Environment.NewLine);

                for (int now_write_raw = 1; now_write_raw < m_file_write_data.Count; now_write_raw++)
                {
                    System.IO.File.AppendAllText(sfd.FileName, m_file_write_data[now_write_raw] + Environment.NewLine);
                }
            }
        }

        // マテリアルの質感情報の変換
        private static void M_Convert_Material_Inform()
        {
            for (int now_mat_num = 0; now_mat_num < m_now_scene.MaterialCount; now_mat_num++)
            {
                m_file_mat_write_data.Add(_3D_Model_Converter_And_Drawer.Form1.material_name_list[now_mat_num]);

                // アンビエント
                m_file_mat_write_data.Add
                    (
                        m_now_scene.Materials[now_mat_num].ColorAmbient.R.ToString() + ","
                         + m_now_scene.Materials[now_mat_num].ColorAmbient.G.ToString() + ","
                         + m_now_scene.Materials[now_mat_num].ColorAmbient.B.ToString() + ","
                         + m_now_scene.Materials[now_mat_num].ColorAmbient.A.ToString() + ","
                    );

                // ディフューズ
                m_file_mat_write_data.Add
                    (
                        m_now_scene.Materials[now_mat_num].ColorDiffuse.R.ToString() + ","
                         + m_now_scene.Materials[now_mat_num].ColorDiffuse.G.ToString() + ","
                         + m_now_scene.Materials[now_mat_num].ColorDiffuse.B.ToString() + ","
                         + m_now_scene.Materials[now_mat_num].ColorDiffuse.A.ToString() + ","
                    );

                // エミッション
                m_file_mat_write_data.Add
                    (
                        m_now_scene.Materials[now_mat_num].ColorEmissive.R.ToString() + ","
                         + m_now_scene.Materials[now_mat_num].ColorEmissive.G.ToString() + ","
                         + m_now_scene.Materials[now_mat_num].ColorEmissive.B.ToString() + ","
                         + m_now_scene.Materials[now_mat_num].ColorEmissive.A.ToString() + ","
                    );

                // リフレクション
                m_file_mat_write_data.Add
                    (
                        m_now_scene.Materials[now_mat_num].ColorReflective.R.ToString() + ","
                         + m_now_scene.Materials[now_mat_num].ColorReflective.G.ToString() + ","
                         + m_now_scene.Materials[now_mat_num].ColorReflective.B.ToString() + ","
                         + m_now_scene.Materials[now_mat_num].ColorReflective.A.ToString() + ","
                    );

                // スペキュラー
                m_file_mat_write_data.Add
                    (
                        m_now_scene.Materials[now_mat_num].ColorSpecular.R.ToString() + ","
                         + m_now_scene.Materials[now_mat_num].ColorSpecular.G.ToString() + ","
                         + m_now_scene.Materials[now_mat_num].ColorSpecular.B.ToString() + ","
                         + m_now_scene.Materials[now_mat_num].ColorSpecular.A.ToString() + ","
                    );

                // トランスペアレント
                m_file_mat_write_data.Add
                    (
                        m_now_scene.Materials[now_mat_num].ColorTransparent.R.ToString() + ","
                         + m_now_scene.Materials[now_mat_num].ColorTransparent.G.ToString() + ","
                         + m_now_scene.Materials[now_mat_num].ColorTransparent.B.ToString() + ","
                         + m_now_scene.Materials[now_mat_num].ColorTransparent.A.ToString() + ","
                    );

                // １行あける
                m_file_mat_write_data.Add("");
            }
        }

        // マテリアルの質感ファイルの保存
        private static void M_Save_Mat_Inform_File()
        {
            // ☆ 変数宣言 ☆ //
            SaveFileDialog sfd = new SaveFileDialog();  // ファイルセーブ用システム

            string extension = "elmatinform";   // 拡張子


            sfd.FileName = "new_mat_inform." + extension;
            sfd.InitialDirectory = System.IO.Path.GetDirectoryName(System.Reflection.Assembly.GetExecutingAssembly().Location);
            sfd.Filter = extension + "ファイル(*." + extension + ";*." + extension +")|*." + ";*." + extension +"|すべてのファイル(*.*)|*.*";
            sfd.FilterIndex = 1;
            sfd.Title = "マテリアルの質感情報の保存先のファイルを選択してください";
            //ダイアログボックスを閉じる前に現在のディレクトリを復元するようにする
            sfd.RestoreDirectory = true;
            //既に存在するファイル名を指定したとき警告する
            sfd.OverwritePrompt = true;
            //存在しないパスが指定されたとき警告を表示する
            sfd.CheckPathExists = true;

            //ダイアログを表示する
            if (sfd.ShowDialog() == DialogResult.OK)
            {
                System.IO.File.WriteAllText(sfd.FileName, m_file_mat_write_data[0] + Environment.NewLine);

                for (int now_write_raw = 1; now_write_raw < m_file_mat_write_data.Count; now_write_raw++)
                {
                    System.IO.File.AppendAllText(sfd.FileName, m_file_mat_write_data[now_write_raw] + Environment.NewLine);
                }
            }
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

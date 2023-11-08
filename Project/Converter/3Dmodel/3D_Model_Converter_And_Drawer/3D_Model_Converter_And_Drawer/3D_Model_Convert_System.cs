using Assimp;
using SharpDX;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _3D_Model_Converter_And_Drawer
{
    // ☆ クラス ☆ //

    // 3Dモデルを独自形式に変換するクラス
    internal class _3D_Model_Convert_System
    {
        static public Scene now_scene = new Scene();

        static List<string> file_write_data = new List<string>();
        static List<string> file_mat_write_data = new List<string>();

        // 3Dモデルを変換する　引数：シーンデータ
        public static void M_Convert_Data_Set(ref Scene in_scene)
        {
            now_scene = in_scene;
        }

        public static void M_Input_Form_Create()
        {
            _3D_Model_Converter_And_Drawer.Form1.material_num = now_scene.MaterialCount;
            _3D_Model_Converter_And_Drawer.Form1.mesh_num = now_scene.MeshCount;

            Form1 new_form = new Form1();
            new_form.Show();
        }

        // 変換の実行
        public static void M_Covert_Execute()
        {
            file_write_data.Clear();
            file_mat_write_data.Clear();

            // マテリアルデータの変換
            M_Material_Convert();

            // 空白を作成
            file_write_data.Add("");

            // メッシュデータの変換
            M_Mesh_Convert();

            // 生成したデータをファイルとして保存
            M_Save_This_File();

            // マテリアルの質感情報を取り出す
            M_Convert_Material_Inform();

            // マテリアルの質感情報を抜き出したファイルを保存
            M_Save_Mat_Inform_File();

            return;
        }



        // マテリアル情報の変換
        private static void M_Material_Convert()
        {
            // マテリアル情報の開始位置を設定
            file_write_data.Add("MATERIAL:");

            // マテリアル名を一覧入力
            foreach (string now_mat_name in _3D_Model_Converter_And_Drawer.Form1.material_name_list)
            {
                file_write_data.Add(now_mat_name);
            }
        }


        // メッシュデータの変換
        private static void M_Mesh_Convert()
        {
            // メッシュ数分繰り返す
            for (int mesh_num = 0; mesh_num < now_scene.MeshCount; mesh_num++)
            {
                // メッシュ情報の開始位置を設定
                file_write_data.Add("MESH" + (mesh_num + 1).ToString() + ":");

                // メッシュ名を入力
                file_write_data.Add(_3D_Model_Converter_And_Drawer.Form1.mesh_group_name_list[mesh_num]);

                // 頂点数を入力
                file_write_data.Add("VERT" + (mesh_num + 1).ToString() + ":" + now_scene.Meshes[mesh_num].VertexCount);

                // 頂点データを書き込む
                for (int now_vertex = 0; now_vertex < now_scene.Meshes[mesh_num].Vertices.Count; now_vertex++)
                {
                    file_write_data.Add
                        (
                            //==☆ 頂点座標 ☆==//
                            now_scene.Meshes[mesh_num].Vertices[now_vertex].X.ToString() + ","
                            + now_scene.Meshes[mesh_num].Vertices[now_vertex].Y.ToString() + ","
                            + now_scene.Meshes[mesh_num].Vertices[now_vertex].Z.ToString() + "," + ":"

                            //==☆ UV座標 ☆==//
                            + now_scene.Meshes[mesh_num].TextureCoordinateChannels[0][now_vertex].X.ToString() + ","
                            + now_scene.Meshes[mesh_num].TextureCoordinateChannels[0][now_vertex].Y.ToString() + "," + ":"

                            //==☆ 法線ベクトル ☆==//
                            + now_scene.Meshes[mesh_num].Normals[now_vertex].X.ToString() + ","
                            + now_scene.Meshes[mesh_num].Normals[now_vertex].Y.ToString() + ","
                            + now_scene.Meshes[mesh_num].Normals[now_vertex].Z.ToString() + "," + ":"

                            //==☆ タンジェント ☆==//
                            + now_scene.Meshes[mesh_num].Tangents[now_vertex].X.ToString() + ","
                            + now_scene.Meshes[mesh_num].Tangents[now_vertex].Y.ToString() + ","
                            + now_scene.Meshes[mesh_num].Tangents[now_vertex].Z.ToString() + "," + ":"

                            //==☆ バイノーマルタンジェント（順法線） ☆==//
                            + now_scene.Meshes[mesh_num].BiTangents[now_vertex].X.ToString() + ","
                            + now_scene.Meshes[mesh_num].BiTangents[now_vertex].Y.ToString() + ","
                            + now_scene.Meshes[mesh_num].BiTangents[now_vertex].Z.ToString() + ","
                        );
                }


                // メッシュのインデックス開始位置指定
                file_write_data.Add("INDEX" + (mesh_num + 1).ToString() + ":" + now_scene.Meshes[mesh_num].FaceCount);

                // インデックスデータを書き込む
                for (int now_face_num = 0; now_face_num < now_scene.Meshes[mesh_num].FaceCount; now_face_num++)
                {
                    file_write_data.Add
                        (
                            now_scene.Meshes[mesh_num].Faces[now_face_num].Indices[0].ToString() + "," + 
                            now_scene.Meshes[mesh_num].Faces[now_face_num].Indices[1].ToString() + "," + 
                            now_scene.Meshes[mesh_num].Faces[now_face_num].Indices[2].ToString() + ","
                        );
                }

                // 空白をあける
                file_write_data.Add("");
            }
        }
        

        // ファイルのセーブ
        private static void M_Save_This_File()
        {
            // ☆ 変数宣言 ☆ //
            SaveFileDialog sfd = new SaveFileDialog();  // ファイルセーブ用システム


            sfd.FileName = "new_model.elmdl";
            sfd.InitialDirectory = System.IO.Path.GetDirectoryName(System.Reflection.Assembly.GetExecutingAssembly().Location);
            sfd.Filter = "elmdlファイル(*.elmdl;*.elmdl)|*.elmdl;*.elmdl|すべてのファイル(*.*)|*.*";
            sfd.FilterIndex = 1;
            sfd.Title = "モデルデータの保存先のファイルを選択してください";
            //ダイアログボックスを閉じる前に現在のディレクトリを復元するようにする
            sfd.RestoreDirectory = true;
            //既に存在するファイル名を指定したとき警告する
            sfd.OverwritePrompt = true;
            //存在しないパスが指定されたとき警告を表示する
            sfd.CheckPathExists = true;

            //ダイアログを表示する
            if (sfd.ShowDialog() == DialogResult.OK)
            {
                System.IO.File.WriteAllText(sfd.FileName, file_write_data[0] + Environment.NewLine);

                for (int now_write_raw = 1; now_write_raw < file_write_data.Count; now_write_raw++)
                {
                    System.IO.File.AppendAllText(sfd.FileName, file_write_data[now_write_raw] + Environment.NewLine);
                }
            }
        }

        // マテリアルの質感情報の変換
        private static void M_Convert_Material_Inform()
        {
            for (int now_mat_num = 0; now_mat_num < now_scene.MaterialCount; now_mat_num++)
            {
                file_mat_write_data.Add(_3D_Model_Converter_And_Drawer.Form1.material_name_list[now_mat_num]);

                // アンビエント
                file_mat_write_data.Add
                    (
                        now_scene.Materials[now_mat_num].ColorAmbient.R.ToString() 
                         + now_scene.Materials[now_mat_num].ColorAmbient.G.ToString()
                         + now_scene.Materials[now_mat_num].ColorAmbient.B.ToString()
                         + now_scene.Materials[now_mat_num].ColorAmbient.A.ToString()
                    );

                // ディフューズ
                file_mat_write_data.Add
                    (
                        now_scene.Materials[now_mat_num].ColorDiffuse.R.ToString()
                         + now_scene.Materials[now_mat_num].ColorDiffuse.G.ToString()
                         + now_scene.Materials[now_mat_num].ColorDiffuse.B.ToString()
                         + now_scene.Materials[now_mat_num].ColorDiffuse.A.ToString()
                    );

                // エミッション
                file_mat_write_data.Add
                    (
                        now_scene.Materials[now_mat_num].ColorEmissive.R.ToString()
                         + now_scene.Materials[now_mat_num].ColorEmissive.G.ToString()
                         + now_scene.Materials[now_mat_num].ColorEmissive.B.ToString()
                         + now_scene.Materials[now_mat_num].ColorEmissive.A.ToString()
                    );

                // リフレクション
                file_mat_write_data.Add
                    (
                        now_scene.Materials[now_mat_num].ColorReflective.R.ToString()
                         + now_scene.Materials[now_mat_num].ColorReflective.G.ToString()
                         + now_scene.Materials[now_mat_num].ColorReflective.B.ToString()
                         + now_scene.Materials[now_mat_num].ColorReflective.A.ToString()
                    );

                // スペキュラー
                file_mat_write_data.Add
                    (
                        now_scene.Materials[now_mat_num].ColorSpecular.R.ToString()
                         + now_scene.Materials[now_mat_num].ColorSpecular.G.ToString()
                         + now_scene.Materials[now_mat_num].ColorSpecular.B.ToString()
                         + now_scene.Materials[now_mat_num].ColorSpecular.A.ToString()
                    );

                // トランスペアレント
                file_mat_write_data.Add
                    (
                        now_scene.Materials[now_mat_num].ColorTransparent.R.ToString()
                         + now_scene.Materials[now_mat_num].ColorTransparent.G.ToString()
                         + now_scene.Materials[now_mat_num].ColorTransparent.B.ToString()
                         + now_scene.Materials[now_mat_num].ColorTransparent.A.ToString()
                    );

                // １行あける
                file_mat_write_data.Add("");
            }
        }

        // マテリアルの質感ファイルの保存
        private static void M_Save_Mat_Inform_File()
        {
            // ☆ 変数宣言 ☆ //
            SaveFileDialog sfd = new SaveFileDialog();  // ファイルセーブ用システム


            sfd.FileName = "new_mat_inform.elmatinform";
            sfd.InitialDirectory = System.IO.Path.GetDirectoryName(System.Reflection.Assembly.GetExecutingAssembly().Location);
            sfd.Filter = "elmatinformファイル(*.elmatinform;*.elmatinform)|*.elmatinform;*.elmatinform|すべてのファイル(*.*)|*.*";
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
                System.IO.File.WriteAllText(sfd.FileName, file_mat_write_data[0] + Environment.NewLine);

                for (int now_write_raw = 1; now_write_raw < file_mat_write_data.Count; now_write_raw++)
                {
                    System.IO.File.AppendAllText(sfd.FileName, file_mat_write_data[now_write_raw] + Environment.NewLine);
                }
            }
        }
    }
}


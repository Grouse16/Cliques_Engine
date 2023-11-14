using System;
using System.Collections.Generic;
using System.Drawing.Text;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Assimp;


namespace _3D_Model_Converter_And_Drawer.Animation_Convert
{
    // ☆ クラス ☆ //

    // アニメーション変換システム
    internal class CS_Animation_Convert_System
    {
        // ☆ 変数宣言 ☆ //
        static List<Animation> m_animation_list = new List<Animation>();  // アニメーションのリスト

        static List<string> m_write_data_to_file = new List<string>();  // ファイルに書き込むデータ


        // ☆ 関数 ☆ //

        //-☆- セッタ -☆-//

        // アニメーションを独自形式に変換するアニメーションの情報をセットする
        static public void M_Set_Convert_Animation_Scene(Scene in_scene)
        {
            m_animation_list = in_scene.Animations;
        }


        //-☆- 変換 -☆-//

        // アニメーションの独自形式への変換を実行する
        static public void M_Animation_Convert_Execute()
        {
            // アニメーションを独自形式に変換する
            M_Convert();

            // 現在のデータをファイルとして書き込む
            M_Write_Animation_Data_File();
        }


        // アニメーションデータの変換をする
        static private void M_Convert()
        {
            // 今までに書き込まれたデータを初期化
            m_write_data_to_file.Clear();


            // アニメーションのファイルであることを示す文字列を記録
            m_write_data_to_file.Add("This-Is-ELANMDT");


            // アニメーション数分変換を行う
            foreach (var now_animation in m_animation_list)
            {
                // ☆ 変数宣言 ☆ //
                double one_frame_time = 1.0 / now_animation.TicksPerSecond;    // １フレームの時間


                // アニメーションの開始位置を書き込む
                m_write_data_to_file.Add("ANIMATION:");

                // アニメーションの１秒間でのフレームレートを書き込む
                m_write_data_to_file.Add("FRAMERATE:" + now_animation.TicksPerSecond.ToString());

                // アニメーションするボーン数を書き込む
                m_write_data_to_file.Add("BONESUM:" + now_animation.NodeAnimationChannelCount.ToString());


                // ボーンごとに動作を書き込む
                foreach (var bone_frame in now_animation.NodeAnimationChannels)
                {
                    // ボーン情報開始位置とボーン名を書き込む
                    m_write_data_to_file.Add("BONE:" + bone_frame.NodeName);


                    // 座標のキー情報の開始位置と座標キー数を書き込む
                    m_write_data_to_file.Add("POS:" + bone_frame.PositionKeyCount.ToString());

                    // 座標のキーを全て書き込む
                    foreach (var position_key in bone_frame.PositionKeys)
                    {
                        // このキーになる時間と座標情報を書き込む
                        m_write_data_to_file.Add
                            (
                                  (position_key.Time * one_frame_time).ToString() + ","
                                + position_key.Value.X.ToString() + ","
                                + position_key.Value.Y.ToString() + ","
                                + position_key.Value.Z.ToString()
                            );
                    }


                    // 回転のキー情報の開始位置と回転キー数を書き込む
                    m_write_data_to_file.Add("ROT:" + bone_frame.RotationKeyCount.ToString());

                    // 回転のキーを全て書き込む
                    foreach (var rotation_key in bone_frame.RotationKeys)
                    {
                        // このキーになる時間と座標情報を書き込む
                        m_write_data_to_file.Add
                            (
                                  (rotation_key.Time * one_frame_time).ToString() + ","
                                + rotation_key.Value.X.ToString() + ","
                                + rotation_key.Value.Y.ToString() + ","
                                + rotation_key.Value.Z.ToString() + ","
                                + rotation_key.Value.W.ToString()
                            );
                    }


                    // スケールのキー情報の開始位置とスケールキー数を書き込む
                    m_write_data_to_file.Add("SCL:" + bone_frame.ScalingKeyCount.ToString());

                    // スケールのキーを全て書き込む
                    foreach (var scale_key in bone_frame.ScalingKeys)
                    {
                        // このキーになる時間と座標情報を書き込む
                        m_write_data_to_file.Add
                            (
                                  (scale_key.Time * one_frame_time).ToString() + ","
                                + scale_key.Value.X.ToString() + ","
                                + scale_key.Value.Y.ToString() + ","
                                + scale_key.Value.Z.ToString()
                            );
                    }
                }
            }

            return;
        }

        // ファイルを書き込む
        static void M_Write_Animation_Data_File()
        {
            // ☆ 変数宣言 ☆ //
            SaveFileDialog sfd = new SaveFileDialog();  // ファイルセーブ用システム

            string extension = "elanmdt";  // 拡張子


            sfd.FileName = "new_model." + extension;
            sfd.InitialDirectory = System.IO.Path.GetDirectoryName(System.Reflection.Assembly.GetExecutingAssembly().Location);
            sfd.Filter = extension + "ファイル(*." + extension + ";*." + extension + ")| *." + extension + "; *." + extension + "| すべてのファイル(*.*)|*.*";
            sfd.FilterIndex = 1;
            sfd.Title = "アニメーションデータの保存先のファイルを選択してください";
            //ダイアログボックスを閉じる前に現在のディレクトリを復元するようにする
            sfd.RestoreDirectory = true;
            //既に存在するファイル名を指定したとき警告する
            sfd.OverwritePrompt = true;
            //存在しないパスが指定されたとき警告を表示する
            sfd.CheckPathExists = true;

            //ダイアログを表示する
            if (sfd.ShowDialog() == DialogResult.OK)
            {
                System.IO.File.WriteAllText(sfd.FileName, m_write_data_to_file[0] + Environment.NewLine);

                for (int now_write_raw = 1; now_write_raw < m_write_data_to_file.Count; now_write_raw++)
                {
                    System.IO.File.AppendAllText(sfd.FileName, m_write_data_to_file[now_write_raw] + Environment.NewLine);
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


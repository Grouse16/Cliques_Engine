using System;
using System.Collections.Generic;
using System.Drawing.Text;
using System.IO;
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
        // ☆ 関数 ☆ //

        //-☆- 変換 -☆-//

        // アニメーションデータの変換をする
        static public void M_Convert_Animation_Data(Scene in_scene)
        {
            // ☆ 定数 ☆ //
            const string con_EXTENSION = ".elanmdt";   // 拡張子


            // ☆ 変数宣言 ☆ //
            string selected_folder_path = "";   // 選択されたフォルダのパス

            int now_animation_data_num = 0;   // 現在のアニメーションデータ番号


            // フォルダ選択ダイアログを表示して、選択されたフォルダのパスを取得、取得できなかったら終了
            if (CS_File_Write_System.M_Get_Folder_Path(out selected_folder_path) == false)
            {
                return;
            }


            // アニメーション数分変換を行う
            foreach (var now_animation in in_scene.Animations)
            {
                // ☆ 変数宣言 ☆ //
                List<string> write_data_to_file = new List<string>();  // ファイルに書き込むデータ

                string write_file_path = selected_folder_path + Form_3D_Model_Convert_Setting.mp_animation_data_name_list[now_animation_data_num] + con_EXTENSION;  // 書き込むファイルのパス

                double one_frame_time = 1.0 / now_animation.TicksPerSecond;    // １フレームの時間


                // 今までに書き込まれたデータを初期化
                write_data_to_file.Clear();

                // アニメーションのファイルであることを示す文字列を記録
                write_data_to_file.Add("This-Is-ELANMDT");


                // アニメーションの開始位置を書き込む
                write_data_to_file.Add("ANIMATION:");

                // アニメーションの１秒間でのフレームレートを書き込む
                write_data_to_file.Add("FRAMERATE:" + now_animation.TicksPerSecond.ToString());

                // アニメーションの終了までの時間を書き込む
                write_data_to_file.Add("ENDTIME:" + now_animation.DurationInTicks);

                // アニメーションするボーン数を書き込む
                write_data_to_file.Add("BONESUM:" + now_animation.NodeAnimationChannelCount.ToString());


                // ボーンごとに動作を書き込む
                for (int l_now_bone_number = 0; l_now_bone_number < now_animation.NodeAnimationChannels.Count; l_now_bone_number++)
                {
                    // ボーン情報開始位置とボーン名を書き込む
                    write_data_to_file.Add("BONE:" + now_animation.NodeAnimationChannels[l_now_bone_number].NodeName);
                    

                    // 座標のキー情報の開始位置と座標キー数を書き込む
                    write_data_to_file.Add("POS:" + now_animation.NodeAnimationChannels[l_now_bone_number].PositionKeyCount.ToString());

                    // 座標のキーを全て書き込む
                    foreach (var position_key in now_animation.NodeAnimationChannels[l_now_bone_number].PositionKeys)
                    {
                        // このキーになる時間と座標情報を書き込む
                        write_data_to_file.Add
                            (
                                  (position_key.Time * one_frame_time).ToString() + ","
                                + position_key.Value.X.ToString() + ","
                                + position_key.Value.Y.ToString() + ","
                                + position_key.Value.Z.ToString()
                            );
                    }


                    // 回転のキー情報の開始位置と回転キー数を書き込む
                    write_data_to_file.Add("ROT:" + now_animation.NodeAnimationChannels[l_now_bone_number].RotationKeyCount.ToString());

                    // 回転のキーを全て書き込む
                    foreach (var rotation_key in now_animation.NodeAnimationChannels[l_now_bone_number].RotationKeys)
                    {
                        // このキーになる時間と座標情報を書き込む
                        write_data_to_file.Add
                            (
                                  (rotation_key.Time * one_frame_time).ToString() + ","
                                + rotation_key.Value.X.ToString() + ","
                                + rotation_key.Value.Y.ToString() + ","
                                + rotation_key.Value.Z.ToString() + ","
                                + rotation_key.Value.W.ToString()
                            );
                    }


                    // スケールのキー情報の開始位置とスケールキー数を書き込む
                    write_data_to_file.Add("SCL:" + now_animation.NodeAnimationChannels[l_now_bone_number].ScalingKeyCount.ToString());

                    // スケールのキーを全て書き込む
                    foreach (var scale_key in now_animation.NodeAnimationChannels[l_now_bone_number].ScalingKeys)
                    {
                        // このキーになる時間と座標情報を書き込む
                        write_data_to_file.Add
                            (
                                  (scale_key.Time * one_frame_time).ToString() + ","
                                + scale_key.Value.X.ToString() + ","
                                + scale_key.Value.Y.ToString() + ","
                                + scale_key.Value.Z.ToString()
                            );
                    }
                }


                // 新しいファイルの書き込みを行う
                File.WriteAllText(write_file_path, write_data_to_file[0]);
                for (int now_write_raw = 1; now_write_raw < write_data_to_file.Count; now_write_raw++)
                {
                    File.AppendAllText(write_file_path, Environment.NewLine + write_data_to_file[now_write_raw]);
                }

                // 次のアニメーションデータを指定
                now_animation_data_num += 1;
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


using SharpDX;
using SharpDXSample;
using System;
using System.IO;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Assimp;
using System.Runtime.InteropServices;
using Assimp.Unmanaged;
using _3D_Model_Converter_And_Drawer.Animation_Convert;
using _3D_Model_Converter_And_Drawer._3D_Model_Importer;
using _3D_Model_Converter_And_Drawer._3D_Model_Importer.Import_System;
using _3D_Model_Converter_And_Drawer._3DModel.Static;
using _3D_Model_Converter_And_Drawer._3DModel.Animation;

namespace _3D_Model_Converter_And_Drawer
{
    // ☆ クラス ☆ //

    // メインフォーム
    public partial class Main_Form : Form
    {
        // ☆ 変数宣言 ☆ //
        private BindingList<S_Vertex> m_vertex_list = new BindingList<S_Vertex>(); // 頂点データ

        private C_Shader_Source m_shader;  // シェーダー

        private CS_Static_Model_Data m_static_model = new CS_Static_Model_Data(); // 静的モデルデータ

        private CS_Animation_Model_Data m_animation_model = new CS_Animation_Model_Data(); // アニメーションモデルデータ

        private string m_shader_path;   // シェーダーファイルのパス


        // ☆ 関数 ☆ //

        //-☆- 初期化 -☆-//

        // コンストラクタ
        public Main_Form()
        {
            // コンポーネントの初期化
            InitializeComponent();

            // シェーダーロード
            m_shader_path = Path.Combine(Path.GetDirectoryName(Application.ExecutablePath), "Asset\\shader.fx");
            m_shader = new C_Shader_Source();
            m_shader.PropertyChanged += M_source_PropertyChanged;
            m_shader.mp_shader = File.ReadAllText(m_shader_path, Encoding.UTF8);

            // シェーダーのパスをセット
            uc_dx_11_panel.mp_shader.mp_shader_path = m_shader.mp_shader;
            uc_dx_11_panel.mp_renderer.M_Create_Renderer(Handle);


            // 頂点リストのファイルウォッチャーの設定
            m_vertex_list.ListChanged += (o, e) =>
              {
                  uc_dx_11_panel.mp_buffer.M_Set_Vertex(m_vertex_list.ToArray());
                  uc_dx_11_panel.Invalidate();
              };

            // 頂点リストの初期化
            m_vertex_list.Add(new S_Vertex(new Vector4(0.0f, 0.5f, 0.5f, 1.0f), new Vector4(1.0f, 0.0f, 0.0f, 1.0f), new Vector4(1.0f, 0.0f, 0.0f, 1.0f)));
            m_vertex_list.Add(new S_Vertex(new Vector4(0.5f, -0.5f, 0.5f, 1.0f), new Vector4(0.0f, 1.0f, 0.0f, 1.0f), new Vector4(1.0f, 0.0f, 0.0f, 1.0f)));
            m_vertex_list.Add(new S_Vertex(new Vector4(-0.5f, -0.5f, 0.5f, 1.0f), new Vector4(0.0f, 0.0f, 1.0f, 1.0f), new Vector4(1.0f, 0.0f, 0.0f, 1.0f)));

            return;
        }


        // フォーム読み込み時
        private void Form1_Load(object sender, EventArgs e)
        {
            tb_print_model_converter.ReadOnly = true;
            tb_print_model_importer.ReadOnly = true;
            tb_print_model_viewer.ReadOnly = true;
            tb_print_camera_setting.ReadOnly = true;
            tb_print_camera_distance.ReadOnly = true;
            tb_print_camera_position.ReadOnly = true;
            tb_print_animation_blend.ReadOnly = true;
            tb_print_animation_01_times.ReadOnly = true;
            tb_print_animation_02_time.ReadOnly = true;
            tb_print_animation_01_name.ReadOnly = true;
            tb_print_animation_02_name.ReadOnly = true;
            tb_print_animation_blend_percent.ReadOnly = true;

            this.MaximumSize = this.Size;
            this.MinimumSize = this.Size;

            return;
        }


        //-☆- 更新 -☆-//

        // ウォッチャー変更時
        private async void Watcher_Changed(object sender, FileSystemEventArgs e)
        {
            // 少し待つ
            await Task.Delay(100);

            // UIスレッドでの実行でないなら、UIスレッドで実行
            if (InvokeRequired)
            {
                // ☆ 変数宣言 ☆ //
                Action call_back = () =>    // コールバック関数
                {
                    Watcher_Changed(sender, e);
                };


                // 別スレッドに投げることでUIスレッドで実行
                Invoke(call_back);

                return;
            }

            // シェーダーの再読み込み
            m_shader.mp_shader = File.ReadAllText(m_shader_path, Encoding.UTF8);

            return;
        }


        // シェーダーのプロパティ変更時
        private void M_source_PropertyChanged(object sender, PropertyChangedEventArgs e)
        {
            // UIスレッドでの実行でないなら、UIスレッドで実行
            if (InvokeRequired)
            {
                // ☆ 変数宣言 ☆ //
                Action call_back = () =>    // コールバック関数
                {
                    M_source_PropertyChanged(sender, e);
                };


                // 別スレッドに投げることでUIスレッドで実行
                Invoke(call_back);
                return;
            }

            // シェーダーのパスをセット
            uc_dx_11_panel.mp_shader.mp_shader_path = m_shader.mp_shader;
            uc_dx_11_panel.Invalidate();

            return;
        }


        //-☆- ロード -☆-//

        // アニメーションモデルのロード　引数：ファイルパス
        private void M_Animation_Model_Load(string in_file_path)
        {
            // ☆ 変数宣言 ☆ //
            Form_Animation_Model_Importer new_form = new Form_Animation_Model_Importer();   // 新しいフォームシステム


            // フォームを初期化して画面に表示
            new_form.M_Initialize(in_file_path, uc_dx_11_panel);
            new_form.Show();

            return;
        }


        //-☆- イベント -☆-//

        // ドラッグがカーソル上にあるとき
        private void B_Drag_Over_File_Checker(object sender, DragEventArgs e)
        {
            // ファイルドロップ時はカーソルをコピーに変更
            if (e.Data.GetDataPresent(DataFormats.FileDrop))
            {
                e.Effect = DragDropEffects.Copy;
            }

            // それ以外の時はなにもしない
            else
            {
                e.Effect = DragDropEffects.None;
            }

            return;
        }


        // 変換する3Dモデルのファイルのドロップを受け取る
        private void B_Model_Converter_DragDrop(object sender, DragEventArgs e)
        {
            // ファイルドロップ時はファイルのプロパティを取得（なければスルー）
            if (e.Data.GetDataPresent(DataFormats.FileDrop) == false)
            {
                return;
            }


            // ☆ 変数宣言 ☆ //
            System.Diagnostics.Stopwatch stop_watch = new System.Diagnostics.Stopwatch();   // タイマーシステム
            
            System.Diagnostics.Process now_process = System.Diagnostics.Process.GetCurrentProcess();   // 現在のプロセスの状況を取得

            long before_working_memory = 0;   // ロード前の物理メモリ
            long before_virtual_memory = 0;   // ロード前の仮想メモリ


            // ロート直前の使用しているメモリ容量を物理と仮想両方取得
            now_process.Refresh();
            before_working_memory = now_process.WorkingSet64;
            before_virtual_memory = now_process.VirtualMemorySize64;

            // 生成時間を記録開始
            stop_watch.Start();


            // ☆ 変数宣言 ☆ //
            string[] file_path = (string[])e.Data.GetData(DataFormats.FileDrop, false); // ファイル名（絶対パス）

            string relative_file_path = CS_My_Math_System.M_Get_Relative_Path(file_path[0]);   // 相対パス

            AssimpContext importer = new AssimpContext(); // インポートシステム

            Scene scene =     // 取得結果のデータ
                importer.ImportFile
                (
                    relative_file_path,
                    PostProcessSteps.CalculateTangentSpace |
                    PostProcessSteps.GenerateSmoothNormals |
                    PostProcessSteps.JoinIdenticalVertices |
                    PostProcessSteps.LimitBoneWeights |
                    PostProcessSteps.RemoveRedundantMaterials |
                    PostProcessSteps.SplitLargeMeshes |
                    PostProcessSteps.GenerateUVCoords |
                    PostProcessSteps.SortByPrimitiveType |
                    PostProcessSteps.FindDegenerates |
                    PostProcessSteps.FindInvalidData |
                    PostProcessSteps.Triangulate |      // 全ての面を三角形に変換
                    PostProcessSteps.FlipWindingOrder | // 時計回り
                    PostProcessSteps.MakeLeftHanded     // 左手系
                );

            // ロード終了、ロードにかかった時間を記録
            stop_watch.Stop();

            // 現在のメモリサイズを取得
            now_process.Refresh();

            // ロード時間と必要なメモリサイズを表示
            uc_load_inform_box.M_Set_Assimp_Load_Inform
                (
                stop_watch.ElapsedMilliseconds,
                now_process.WorkingSet64 - before_working_memory,
                now_process.VirtualMemorySize64 - before_virtual_memory
                );


            // コンバートするデータをセットし、各種設定用のフォームを生成
            CS_3D_Model_Convert_System.M_Create_Form_Of_Convert_Model(scene);

            return;
        }


        // 独自形式モデルの変換にファイルのドロップがあった時
        private void B_Model_Importer_DragDrop(object sender, DragEventArgs e)
        {
            // ☆ 定数 ☆ //
            const string con_IS_ELSSTMDL_TEXT = "This-Is-ELSTTMDL";   // 静的モデル、elsttmdlであることを確認するための文字列
            const string con_IS_ELANMMDL_TEXT = "This-Is-ELANMMDT";   // 動的モデル、elanmmdlであることを確認するための文字列


            // ファイルドロップ時はファイルのプロパティを取得（なければスルー）
            if (e.Data.GetDataPresent(DataFormats.FileDrop) == false)
            {
                return;
            }


            // ☆ 変数宣言 ☆ //
            string[] file_path = (string[])e.Data.GetData(DataFormats.FileDrop, false); // ファイルまでの絶対パス

            string relative_file_path = CS_My_Math_System.M_Get_Relative_Path(file_path[0]);   // ファイルまでの相対パス
            
            StreamReader file_data = new StreamReader(relative_file_path); // ファイルデータ

            string file_data_a_line = file_data.ReadLine(); // ファイルの一行分のデータ


            // 静的モデルである時のロード
            if(file_data_a_line == con_IS_ELSSTMDL_TEXT)
            {
                // ☆ 変数宣言 ☆ //
                System.Diagnostics.Stopwatch stop_watch = new System.Diagnostics.Stopwatch();   // タイマーシステム

                System.Diagnostics.Process now_process = System.Diagnostics.Process.GetCurrentProcess();   // 現在のプロセスの状況を取得

                long before_working_memory = 0;   // ロード前の物理メモリ
                long before_virtual_memory = 0;   // ロード前の仮想メモリ


                // ファイルを閉じる
                file_data.Close();

                // ロート直前の使用しているメモリ容量を物理と仮想両方取得
                now_process.Refresh();
                before_working_memory = now_process.WorkingSet64;
                before_virtual_memory = now_process.VirtualMemorySize64;

                // 生成時間を記録開始
                stop_watch.Start();

                // 静的モデルのロード
                CS_Static_Model_Import_System.M_Static_Model_Load(relative_file_path, m_static_model);

                // ロード終了、ロードにかかった時間を記録
                stop_watch.Stop();

                // 現在のメモリサイズを取得
                now_process.Refresh();

                // ロード時間と必要なメモリサイズを表示
                uc_load_inform_box.M_Set_My_Model_Load_Inform
                    (
                    stop_watch.ElapsedMilliseconds,
                    now_process.WorkingSet64 - before_working_memory,
                    now_process.VirtualMemorySize64 - before_virtual_memory
                    );

                return;
            }


            // アニメーションモデルである時のロード
            if (file_data_a_line == con_IS_ELANMMDL_TEXT)
            {
                file_data.Close();
                M_Animation_Model_Load(relative_file_path);

                return;
            }

            return;
        }

        private void tb_print_animation_blend_percent_TextChanged(object sender, EventArgs e)
        {

        }

        private void trackBar5_Scroll(object sender, EventArgs e)
        {

        }

        private void trackBar4_Scroll(object sender, EventArgs e)
        {

        }

        private void tb_print_animation_02_name_TextChanged(object sender, EventArgs e)
        {

        }

        private void tb_print_animation_02_time_TextChanged(object sender, EventArgs e)
        {

        }

        private void tb_print_animation_01_name_TextChanged(object sender, EventArgs e)
        {

        }

        private void trackBar3_Scroll(object sender, EventArgs e)
        {

        }
    }


    // シェーダー設定用のクラス
    class C_Shader_Source : INotifyPropertyChanged
    {
        // ☆ 変数宣言 ☆ //
        string m_shader_path;   // シェーダーファイルのパス


        // ☆ プロパティ ☆ //

        // シェーダーファイルのパス
        public string mp_shader
        {
            // ゲッタ
            get
            {
                return m_shader_path;
            }

            // セッタ
            set
            {
                if (m_shader_path == value)
                {
                    return;
                }

                m_shader_path = value;
                RaisePropertyChanged(nameof(mp_shader));

                return;
            }
        }


        // ☆ イベント ☆ //
        public event PropertyChangedEventHandler PropertyChanged;   // プロパティ変更時


        // プロパティ変更時
        void RaisePropertyChanged(string prop)
        {
            // ☆ 変数宣言 ☆ //
            var handler = PropertyChanged;  // プロパティ変更イベントのハンドル


            // プロパティ変更イベントが取得できたならプロパティ変更イベントを実行
            if (handler != null)
            {
                handler(this, new PropertyChangedEventArgs(prop));
            }
        }
    }


    // ロード情報表示用のクラス
    static class CS_Color_Extensions
    {
        // SharpDXのカラーをfloat4のカラーに変換
        public static System.Drawing.Color M_SharpDX_Color_To_Float4_Color(this Color4 src)
        {
            return System.Drawing.Color.FromArgb(
                (byte)(src.Alpha * 255),
                (byte)(src.Red * 255),
                (byte)(src.Green * 255),
                (byte)(src.Blue * 255)
                );
        }

        // float4のカラーをSharpDXのカラーに変換
        public static Color4 M_Float4_Color_To_SharpDX_Color(this System.Drawing.Color value)
        {
            return new Color4(
                value.R / 255.0f,
                value.G / 255.0f,
                value.B / 255.0f,
                value.A / 255.0f
                );
        }
    }
}

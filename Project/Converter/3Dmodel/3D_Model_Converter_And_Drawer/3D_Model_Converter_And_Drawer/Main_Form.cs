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

namespace _3D_Model_Converter_And_Drawer
{
    // ☆ クラス ☆ //

    // メインフォーム
    public partial class Main_Form : Form
    {
        // ☆ 変数宣言 ☆ //
        private string m_shader_path;   // シェーダーファイルのパス

        private C_Shader_Source m_shader;  // シェーダー

        private BindingList<S_Vertex> m_vertex_list = new BindingList<S_Vertex>(); // 頂点データ


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
            uC_DX_11_Panel1.mp_shader.mp_shader_path = m_shader.mp_shader;
            uC_DX_11_Panel1.mp_renderer.M_Create_Renderer(Handle);
            

            // 頂点リストのファイルウォッチャーの設定
            m_vertex_list.ListChanged += (o, e) =>
              {
                  uC_DX_11_Panel1.mp_buffer.M_Set_Vertex(m_vertex_list.ToArray());
                  uC_DX_11_Panel1.Invalidate();
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
            textBox1.ReadOnly = true;
            textBox5.ReadOnly = true;
            textBox7.ReadOnly = true;
            textBox8.ReadOnly = true;
            textBox9.ReadOnly = true;
            textBox10.ReadOnly = true;
            textBox11.ReadOnly = true;
            textBox12.ReadOnly = true;
            textBox13.ReadOnly = true;
            textBox14.ReadOnly = true;
            textBox15.ReadOnly = true;
            textBox16.ReadOnly = true;

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
            m_shader.mp_shader=File.ReadAllText(m_shader_path, Encoding.UTF8);

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
            uC_DX_11_Panel1.mp_shader.mp_shader_path = m_shader.mp_shader;
            uC_DX_11_Panel1.Invalidate();

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

            string relative_file_path = My_Math_System.M_Get_Relative_Path(file_path[0]);   // 相対パス

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
            UC_load_inform_box.M_Set_Assimp_Load_Inform
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
            // ファイルドロップ時はファイルのプロパティを取得（なければスルー）
            if (e.Data.GetDataPresent(DataFormats.FileDrop) == false)
            {
                return;
            }


            // ☆ 変数宣言 ☆ //
            System.Diagnostics.Stopwatch stop_watch = new System.Diagnostics.Stopwatch();   // タイマーシステム

            System.Diagnostics.Process now_process = System.Diagnostics.Process.GetCurrentProcess();   // 現在のプロセスの状況を取得


            return;
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

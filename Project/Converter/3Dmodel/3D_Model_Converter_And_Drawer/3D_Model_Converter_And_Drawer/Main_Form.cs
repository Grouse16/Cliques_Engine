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

namespace _3D_Model_Converter_And_Drawer
{
    public partial class Main_Form : Form
    {
        string m_sourcePath;

        ShaderSource m_source;

        BindingList<Vertex> m_vertices = new BindingList<Vertex>();

        public Main_Form()
        {
            InitializeComponent();

            // シェーダーロード
            m_sourcePath = Path.Combine(Path.GetDirectoryName(Application.ExecutablePath), "shader.fx");
            m_source = new ShaderSource();
            m_source.PropertyChanged += M_source_PropertyChanged;               
            m_source.Source = File.ReadAllText(m_sourcePath, Encoding.UTF8);


            // 頂点
            m_vertices.ListChanged += (o, e) =>
              {
                  d3D11Panel1.Buffer.SetVertices(m_vertices.ToArray());
                  d3D11Panel1.Invalidate();
              };

            m_vertices.Add(new Vertex(new Vector4(0.0f, 0.5f, 0.5f, 1.0f), new Vector4(1.0f, 0.0f, 0.0f, 1.0f), new Vector4(1.0f, 0.0f, 0.0f, 1.0f)));
            m_vertices.Add(new Vertex(new Vector4(0.5f, -0.5f, 0.5f, 1.0f), new Vector4(0.0f, 1.0f, 0.0f, 1.0f), new Vector4(1.0f, 0.0f, 0.0f, 1.0f)));
            m_vertices.Add(new Vertex(new Vector4(-0.5f, -0.5f, 0.5f, 1.0f), new Vector4(0.0f, 0.0f, 1.0f, 1.0f), new Vector4(1.0f, 0.0f, 0.0f, 1.0f)));
        }

        private async void Watcher_Changed(object sender, FileSystemEventArgs e)
        {
            await Task.Delay(100);

            if (InvokeRequired)
            {
                Action callback = () =>
                {
                    Watcher_Changed(sender, e);
                };
                Invoke(callback);
                return;
            }
            m_source.Source=File.ReadAllText(m_sourcePath, Encoding.UTF8);
        }

        private void M_source_PropertyChanged(object sender, PropertyChangedEventArgs e)
        {
            if (InvokeRequired)
            {
                Action callback = () =>
                {
                    M_source_PropertyChanged(sender, e);
                };
                Invoke(callback);
                return;
            }

            d3D11Panel1.Shader.Source = m_source.Source;
            d3D11Panel1.Invalidate();
        }


        // フォーム読み込み時
        private void Form1_Load(object sender, EventArgs e)
        {
            textBox1.ReadOnly = true;
            textBox2.ReadOnly = true;
            textBox3.ReadOnly = true;
            textBox4.ReadOnly = true;
            textBox5.ReadOnly = true;
            textBox6.ReadOnly = true;
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
            textBox17.ReadOnly = true;
            TB_after_convert_path.ReadOnly = true;
            TB_before_convert_path.ReadOnly = true;

            this.MaximumSize = this.Size;
            this.MinimumSize = this.Size;
        }


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
        }

        // 3Dモデルのファイルのドラッグアンドドロップを受け取る
        private void B_Model_Converter_DragDrop(object sender, DragEventArgs e)
        {
            // ファイルドロップ時はファイルのプロパティを取得
            if (e.Data.GetDataPresent(DataFormats.FileDrop))
            {
                // ☆ 変数宣言 ☆ //
                System.Diagnostics.Stopwatch stop_watch = new System.Diagnostics.Stopwatch();   // タイマーシステム
                                                                                                // Processインスタンスを取得
                System.Diagnostics.Process proc = System.Diagnostics.Process.GetCurrentProcess();

                long before_working_memory = 0;   // ロード前の物理メモリ
                long before_virtual_memory = 0;   // ロード前の仮想メモリ


                // ロート直前の使用しているメモリ容量を物理と仮想両方取得
                before_working_memory = proc.WorkingSet64;
                before_virtual_memory = proc.VirtualMemorySize64;
                
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
                TB_assimp_load_time.Text = stop_watch.ElapsedMilliseconds.ToString() + "ミリ秒";

                // 物理と仮想メモリの変化量をロードに必要なデータサイズとして記録
                proc.Refresh();
                TB_assimp_load_physics_data_size.Text = (proc.WorkingSet64 - before_working_memory).ToString() + ".byte";
                TB_assimp_load_virtual_data_size.Text = (proc.VirtualMemorySize64 - before_virtual_memory).ToString() + ".byte";


                // コンバートするデータをセットし、各種設定用のフォームを生成
                _3D_Model_Convert_System.m_convert_mode = E_CONVERT_MODE.e_STATIC_MODEL;
                _3D_Model_Convert_System.M_Convert_Data_Set(ref scene);
                _3D_Model_Convert_System.M_Input_Form_Create();

                // ロードしたファイルのパスを表示
                TB_before_convert_path.ResetText();
                TB_before_convert_path.AppendText(file_path[0]);
            }
        }

        private void TB_Anim_Model_Convert_DragDrop(object sender, DragEventArgs e)
        {
            // ファイルドロップ時はファイルのプロパティを取得
            if (e.Data.GetDataPresent(DataFormats.FileDrop))
            {
                // ☆ 変数宣言 ☆ //
                System.Diagnostics.Stopwatch stop_watch = new System.Diagnostics.Stopwatch();   // タイマーシステム
                                                                                                // Processインスタンスを取得
                System.Diagnostics.Process proc = System.Diagnostics.Process.GetCurrentProcess();

                long before_working_memory = 0;   // ロード前の物理メモリ
                long before_virtual_memory = 0;   // ロード前の仮想メモリ


                // ロート直前の使用しているメモリ容量を物理と仮想両方取得
                before_working_memory = proc.WorkingSet64;
                before_virtual_memory = proc.VirtualMemorySize64;

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
                TB_assimp_load_time.Text = stop_watch.ElapsedMilliseconds.ToString() + "ミリ秒";

                // 物理と仮想メモリの変化量をロードに必要なデータサイズとして記録
                proc.Refresh();
                TB_assimp_load_physics_data_size.Text = (proc.WorkingSet64 - before_working_memory).ToString() + ".byte";
                TB_assimp_load_virtual_data_size.Text = (proc.VirtualMemorySize64 - before_virtual_memory).ToString() + ".byte";


                // コンバートするデータをセットし、各種設定用のフォームを生成
                _3D_Model_Convert_System.m_convert_mode = E_CONVERT_MODE.e_ANIMATION_MODEL;
                _3D_Model_Convert_System.M_Convert_Data_Set(ref scene);
                _3D_Model_Convert_System.M_Input_Form_Create();

                // ロードしたファイルのパスを表示
                TB_before_convert_path.ResetText();
                TB_before_convert_path.AppendText(file_path[0]);
            }
        }

        private void textBox24_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox25_TextChanged(object sender, EventArgs e)
        {

        }

        private void B_Model_Converter_Click(object sender, EventArgs e)
        {

        }

        private void textBox19_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox22_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox23_TextChanged(object sender, EventArgs e)
        {

        }

        private void B_Model_Importer_Click(object sender, EventArgs e)
        {

        }
    }
    class ShaderSource : INotifyPropertyChanged
    {
        public event PropertyChangedEventHandler PropertyChanged;
        void RaisePropertyChanged(string prop)
        {
            var handler = PropertyChanged;
            if (handler != null)
            {
                handler(this, new PropertyChangedEventArgs(prop));
            }
        }

        string m_source;
        public string Source
        {
            get { return m_source; }
            set
            {
                if (m_source == value) return;
                m_source = value;
                RaisePropertyChanged(nameof(Source));
            }
        }
    }

    static class ColorExtensions
    {
        public static System.Drawing.Color ToColor(this Color4 src)
        {
            return System.Drawing.Color.FromArgb(
                (byte)(src.Alpha * 255),
                (byte)(src.Red * 255),
                (byte)(src.Green * 255),
                (byte)(src.Blue * 255)
                );
        }

        const float ToF = 1.0f / 255;
        public static Color4 ToSharpDX(this System.Drawing.Color value)
        {
            return new Color4(
                value.R * ToF,
                value.G * ToF,
                value.B * ToF,
                value.A * ToF
                );
        }
    }
}

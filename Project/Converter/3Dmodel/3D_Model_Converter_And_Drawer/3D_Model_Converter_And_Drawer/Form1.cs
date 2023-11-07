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

namespace _3D_Model_Converter_And_Drawer
{
    public partial class Form1 : Form
    {
        string m_sourcePath;

        ShaderSource m_source;

        BindingList<Vertex> m_vertices = new BindingList<Vertex>();

        public Form1()
        {
            InitializeComponent();

            // shader source
            m_sourcePath = Path.Combine(Path.GetDirectoryName(Application.ExecutablePath), "shader.fx");
            m_source = new ShaderSource();
            m_source.PropertyChanged += M_source_PropertyChanged;               
            m_source.Source = File.ReadAllText(m_sourcePath, Encoding.UTF8);

            // watch
            var watcher = new System.IO.FileSystemWatcher();
            watcher.Path = Path.GetDirectoryName(m_sourcePath);
            watcher.NotifyFilter = System.IO.NotifyFilters.LastWrite;
            watcher.Filter = Path.GetFileName(m_sourcePath);
            watcher.Changed += Watcher_Changed;
            watcher.EnableRaisingEvents = true;

            // vertex
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
                string[] file_path = (string[])e.Data.GetData(DataFormats.FileDrop, false); // ファイル名（絶対パス）

                string relative_file_path = My_Math_System.M_Get_Relative_Path(file_path[0]);   // 相対パス

                var importer = new AssimpContext(); // インポートシステム

                var scene =     // 取得結果のデータ
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


                // ロードしたファイルのパスを表示
                TB_before_convert_path.ResetText();
                TB_before_convert_path.AppendText(file_path[0]);
            }
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

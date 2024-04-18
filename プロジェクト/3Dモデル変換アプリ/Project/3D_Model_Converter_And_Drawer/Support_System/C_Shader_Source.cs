using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _3D_Model_Converter_And_Drawer.Support_System
{
    // ☆ クラス ☆ //

    // シェーダー設定用のクラス
    class C_Shader_Source : INotifyPropertyChanged
    {
        // ☆ 変数宣言 ☆ //
        string m_shader_path;   // シェーダーファイルのパス


        // ☆ プロパティ ☆ //

        // シェーダーファイルのパス
        public string mp_shader_path
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
                RaisePropertyChanged(nameof(mp_shader_path));

                return;
            }
        }


        // ☆ イベント ☆ //
        public event PropertyChangedEventHandler PropertyChanged;   // プロパティ変更時


        // ☆ 関数 ☆ //

        //-☆- イベント -☆-//

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

            return;
        }
    }
}

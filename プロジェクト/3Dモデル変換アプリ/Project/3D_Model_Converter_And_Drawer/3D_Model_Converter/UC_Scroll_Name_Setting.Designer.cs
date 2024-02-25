using Assimp;
using System.Collections.Generic;
using System.Drawing;

namespace _3D_Model_Converter_And_Drawer._3Dmodel_Convert
{
    partial class UC_Scroll_Name_Setting
    {
        // ☆ 関数 ☆ //

        //-☆- 削除 -☆-//

        // ネームUIを削除する
        public void M_Delete_Name_UI()
        {
            for (int now_name_num = 0; now_name_num < m_name_list.Count; now_name_num++)
            {
                this.Controls.Remove(m_name_list[now_name_num]);
                m_name_list[now_name_num].Dispose();
                m_name_list[now_name_num] = null;
            }

            m_name_list.Clear();

            return;
        }



        /// <summary> 
        /// 必要なデザイナー変数です。
        /// </summary>
        private System.ComponentModel.IContainer components = null;
        /// <summary> 
        /// 使用中のリソースをすべてクリーンアップします。
        /// </summary>
        /// <param name="disposing">マネージド リソースを破棄する場合は true を指定し、その他の場合は false を指定します。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }


        #region コンポーネント デザイナーで生成されたコード

        /// <summary> 
        /// デザイナー サポートに必要なメソッドです。このメソッドの内容を 
        /// コード エディターで変更しないでください。
        /// </summary>
        private void InitializeComponent()
        {
            this.tb_print_this_names_kind = new System.Windows.Forms.TextBox();
            this.scroll_bar = new System.Windows.Forms.VScrollBar();
            this.SuspendLayout();
            // 
            // tb_print_this_names_kind
            // 
            this.tb_print_this_names_kind.Dock = System.Windows.Forms.DockStyle.Top;
            this.tb_print_this_names_kind.Location = new System.Drawing.Point(0, 0);
            this.tb_print_this_names_kind.Name = "tb_print_this_names_kind";
            this.tb_print_this_names_kind.ReadOnly = true;
            this.tb_print_this_names_kind.Size = new System.Drawing.Size(478, 19);
            this.tb_print_this_names_kind.TabIndex = 0;
            // 
            // scroll_bar
            // 
            this.scroll_bar.Dock = System.Windows.Forms.DockStyle.Right;
            this.scroll_bar.Location = new System.Drawing.Point(455, 19);
            this.scroll_bar.Maximum = 10;
            this.scroll_bar.Name = "scroll_bar";
            this.scroll_bar.Size = new System.Drawing.Size(23, 154);
            this.scroll_bar.TabIndex = 1;
            this.scroll_bar.Scroll += new System.Windows.Forms.ScrollEventHandler(this.vScrollBar1_Scroll);
            // 
            // UC_Scroll_Name_Setting
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.scroll_bar);
            this.Controls.Add(this.tb_print_this_names_kind);
            this.Name = "UC_Scroll_Name_Setting";
            this.Size = new System.Drawing.Size(478, 173);
            this.Load += new System.EventHandler(this.UC_Scroll_Name_Setting_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox tb_print_this_names_kind;
        private System.Windows.Forms.VScrollBar scroll_bar;
    }
}

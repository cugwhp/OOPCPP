namespace RSWinApp
{
    partial class BandSelForm
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.comboBoxBand = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.OK = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // comboBoxBand
            // 
            this.comboBoxBand.FormattingEnabled = true;
            this.comboBoxBand.Location = new System.Drawing.Point(90, 28);
            this.comboBoxBand.Name = "comboBoxBand";
            this.comboBoxBand.Size = new System.Drawing.Size(133, 20);
            this.comboBoxBand.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(31, 31);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(53, 12);
            this.label1.TabIndex = 1;
            this.label1.Text = "显示波段";
            // 
            // OK
            // 
            this.OK.Location = new System.Drawing.Point(90, 66);
            this.OK.Name = "OK";
            this.OK.Size = new System.Drawing.Size(133, 51);
            this.OK.TabIndex = 2;
            this.OK.Text = "OK";
            this.OK.UseVisualStyleBackColor = true;
            this.OK.Click += new System.EventHandler(this.OK_Click);
            // 
            // BandSelForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 159);
            this.Controls.Add(this.OK);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.comboBoxBand);
            this.Name = "BandSelForm";
            this.Text = "BandSelForm";
            this.Load += new System.EventHandler(this.InitForm);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ComboBox comboBoxBand;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button OK;

        private int m_iBandCount;
        public int m_iBandIdx;
    }
}
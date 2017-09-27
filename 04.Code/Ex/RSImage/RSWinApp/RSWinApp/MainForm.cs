using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;


namespace RSWinApp
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }

        protected Dataset m_DS;
        

        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenFileDialog dlg = new OpenFileDialog();
            dlg.Filter = "影像文件|*.tif;*.jpg;*.img|所有文件|*.*";
            if (dlg.ShowDialog() == DialogResult.OK)
            {
                m_strImgFilePath = dlg.FileName;
            }

            BandSelForm dlgBandSel = new BandSelForm(6);
            if (dlgBandSel.ShowDialog() == DialogResult.OK)
            {
                MessageBox.Show(Convert.ToString(dlgBandSel.m_iBandIdx));

                dlgBandSel.m_iRed;
                dlgBandSel.m_iGrn;
                dlgBandSel.m_iBlu;

                DataSet.SetRGB();
            }

            //dlgBandSel.Show()
        }

        private void button1_Click(object sender, EventArgs e)
        {

        }
    }
}

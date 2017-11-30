using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace RSWinApp
{
    public partial class BandSelForm : Form
    {
        protected Dataset m_DS;

        public BandSelForm()
        {
            InitializeComponent();

            m_iBandCount = 0;
        }

        public BandSelForm(int iBandCount)
        {
            InitializeComponent();

            m_iBandCount = Math.Max(0, iBandCount);
        }

        public BandSelForm(Dataset DS)
        {
            InitializeComponent();

            m_iBandCount = Math.Max(0, iBandCount);
        }
           
        private void OK_Click(object sender, EventArgs e)
        {
            m_iBandIdx = int.Parse(comboBoxBand.Text);

            this.DialogResult = DialogResult.OK;
            
            this.Close();
        }

        private void InitForm(object sender, EventArgs e)
        {
            comboBoxBand.Items.Clear();

            for (int i=0; i<m_iBandCount; ++i)
            {
                comboBoxBand.Items.Add(Convert.ToString(i+1));
            }
        }
    }
}
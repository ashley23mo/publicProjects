namespace Ksu.Cis300.TravelingSalesperson
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.uxDrawingPanel = new Ksu.Cis300.Drawing.DrawingPanel();
            this.uxList = new System.Windows.Forms.ListBox();
            this.uxFindTour = new System.Windows.Forms.Button();
            this.uxClear = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // uxDrawingPanel
            // 
            this.uxDrawingPanel.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.uxDrawingPanel.BackColor = System.Drawing.Color.White;
            this.uxDrawingPanel.Location = new System.Drawing.Point(12, 12);
            this.uxDrawingPanel.Name = "uxDrawingPanel";
            this.uxDrawingPanel.Size = new System.Drawing.Size(295, 372);
            this.uxDrawingPanel.TabIndex = 0;
            this.uxDrawingPanel.Load += new System.EventHandler(this.uxDrawingPanel_Load);
            // 
            // uxList
            // 
            this.uxList.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.uxList.FormattingEnabled = true;
            this.uxList.Location = new System.Drawing.Point(313, 107);
            this.uxList.Name = "uxList";
            this.uxList.Size = new System.Drawing.Size(141, 277);
            this.uxList.TabIndex = 1;
            this.uxList.SelectedIndexChanged += new System.EventHandler(this.uxList_SelectedIndexChanged);
            // 
            // uxFindTour
            // 
            this.uxFindTour.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.uxFindTour.Location = new System.Drawing.Point(313, 12);
            this.uxFindTour.Name = "uxFindTour";
            this.uxFindTour.Size = new System.Drawing.Size(129, 38);
            this.uxFindTour.TabIndex = 2;
            this.uxFindTour.Text = "Find Tour";
            this.uxFindTour.UseVisualStyleBackColor = true;
            this.uxFindTour.Click += new System.EventHandler(this.uxFindTour_Click);
            // 
            // uxClear
            // 
            this.uxClear.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.uxClear.Location = new System.Drawing.Point(313, 56);
            this.uxClear.Name = "uxClear";
            this.uxClear.Size = new System.Drawing.Size(129, 36);
            this.uxClear.TabIndex = 3;
            this.uxClear.Text = "Clear";
            this.uxClear.UseVisualStyleBackColor = true;
            this.uxClear.Click += new System.EventHandler(this.uxClear_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(454, 396);
            this.Controls.Add(this.uxClear);
            this.Controls.Add(this.uxFindTour);
            this.Controls.Add(this.uxList);
            this.Controls.Add(this.uxDrawingPanel);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private Drawing.DrawingPanel uxDrawingPanel;
        private System.Windows.Forms.ListBox uxList;
        private System.Windows.Forms.Button uxFindTour;
        private System.Windows.Forms.Button uxClear;
    }
}


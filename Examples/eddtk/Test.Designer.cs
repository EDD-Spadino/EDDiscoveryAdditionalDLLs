﻿namespace eddtk
{
    partial class Test
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
            this.renderer3D1 = new EDDTK.Plot3D.Rendering.View.Renderer3D();
            this.SuspendLayout();
            // 
            // renderer3D1
            // 
            this.renderer3D1.BackColor = System.Drawing.Color.Black;
            this.renderer3D1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.renderer3D1.Location = new System.Drawing.Point(0, 0);
            this.renderer3D1.Name = "renderer3D1";
            this.renderer3D1.Size = new System.Drawing.Size(504, 450);
            this.renderer3D1.TabIndex = 0;
            this.renderer3D1.VSync = false;
            // 
            // Test
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(504, 450);
            this.Controls.Add(this.renderer3D1);
            this.Name = "Test";
            this.Text = "Test";
            this.ResumeLayout(false);

        }

        #endregion

        private EDDTK.Plot3D.Rendering.View.Renderer3D renderer3D1;
    }
}
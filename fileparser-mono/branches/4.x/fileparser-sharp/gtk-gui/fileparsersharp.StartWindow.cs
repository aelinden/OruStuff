// ------------------------------------------------------------------------------
//  <autogenerated>
//      This code was generated by a tool.
//      
// 
//      Changes to this file may cause incorrect behavior and will be lost if 
//      the code is regenerated.
//  </autogenerated>
// ------------------------------------------------------------------------------

namespace fileparsersharp {
    
    
    public partial class StartWindow {
        
        private Gtk.HBox hbox1;
        
        private Gtk.Alignment alignment1;
        
        private Gtk.VBox buttonBox;
        
        private Gtk.Button openFileButton;
        
        private Gtk.Button startCalculationButton;
        
        private Gtk.Button viewResultsButton;
        
        private Gtk.Button quitButton;
        
        private Gtk.Alignment alignment2;
        
        protected virtual void Build() {
            Stetic.Gui.Initialize(this);
            // Widget fileparsersharp.StartWindow
            this.Name = "fileparsersharp.StartWindow";
            this.Title = "The Anders Program";
            this.WindowPosition = ((Gtk.WindowPosition)(4));
            // Container child fileparsersharp.StartWindow.Gtk.Container+ContainerChild
            this.hbox1 = new Gtk.HBox();
            this.hbox1.Name = "hbox1";
            this.hbox1.Spacing = 6;
            // Container child hbox1.Gtk.Box+BoxChild
            this.alignment1 = new Gtk.Alignment(0.5F, 0.5F, 1F, 1F);
            this.alignment1.Name = "alignment1";
            this.hbox1.Add(this.alignment1);
            Gtk.Box.BoxChild w1 = ((Gtk.Box.BoxChild)(this.hbox1[this.alignment1]));
            w1.Position = 0;
            // Container child hbox1.Gtk.Box+BoxChild
            this.buttonBox = new Gtk.VBox();
            this.buttonBox.Name = "buttonBox";
            this.buttonBox.Homogeneous = true;
            this.buttonBox.Spacing = 6;
            // Container child buttonBox.Gtk.Box+BoxChild
            this.openFileButton = new Gtk.Button();
            this.openFileButton.CanFocus = true;
            this.openFileButton.Name = "openFileButton";
            this.openFileButton.UseUnderline = true;
            this.openFileButton.Label = "Open File";
            this.buttonBox.Add(this.openFileButton);
            Gtk.Box.BoxChild w2 = ((Gtk.Box.BoxChild)(this.buttonBox[this.openFileButton]));
            w2.Position = 0;
            w2.Expand = false;
            w2.Fill = false;
            // Container child buttonBox.Gtk.Box+BoxChild
            this.startCalculationButton = new Gtk.Button();
            this.startCalculationButton.CanFocus = true;
            this.startCalculationButton.Name = "startCalculationButton";
            this.startCalculationButton.UseUnderline = true;
            this.startCalculationButton.Label = "Calculate";
            this.buttonBox.Add(this.startCalculationButton);
            Gtk.Box.BoxChild w3 = ((Gtk.Box.BoxChild)(this.buttonBox[this.startCalculationButton]));
            w3.Position = 1;
            w3.Expand = false;
            w3.Fill = false;
            // Container child buttonBox.Gtk.Box+BoxChild
            this.viewResultsButton = new Gtk.Button();
            this.viewResultsButton.CanFocus = true;
            this.viewResultsButton.Name = "viewResultsButton";
            this.viewResultsButton.UseUnderline = true;
            this.viewResultsButton.Label = "View Results";
            this.buttonBox.Add(this.viewResultsButton);
            Gtk.Box.BoxChild w4 = ((Gtk.Box.BoxChild)(this.buttonBox[this.viewResultsButton]));
            w4.Position = 2;
            w4.Expand = false;
            w4.Fill = false;
            // Container child buttonBox.Gtk.Box+BoxChild
            this.quitButton = new Gtk.Button();
            this.quitButton.CanFocus = true;
            this.quitButton.Name = "quitButton";
            this.quitButton.UseUnderline = true;
            this.quitButton.Label = "Quit";
            this.buttonBox.Add(this.quitButton);
            Gtk.Box.BoxChild w5 = ((Gtk.Box.BoxChild)(this.buttonBox[this.quitButton]));
            w5.Position = 3;
            w5.Expand = false;
            w5.Fill = false;
            this.hbox1.Add(this.buttonBox);
            Gtk.Box.BoxChild w6 = ((Gtk.Box.BoxChild)(this.hbox1[this.buttonBox]));
            w6.Position = 1;
            w6.Expand = false;
            w6.Fill = false;
            // Container child hbox1.Gtk.Box+BoxChild
            this.alignment2 = new Gtk.Alignment(0.5F, 0.5F, 1F, 1F);
            this.alignment2.Name = "alignment2";
            this.hbox1.Add(this.alignment2);
            Gtk.Box.BoxChild w7 = ((Gtk.Box.BoxChild)(this.hbox1[this.alignment2]));
            w7.Position = 2;
            this.Add(this.hbox1);
            if ((this.Child != null)) {
                this.Child.ShowAll();
            }
            this.DefaultWidth = 400;
            this.DefaultHeight = 300;
            this.Show();
            this.openFileButton.Clicked += new System.EventHandler(this.openFile);
            this.startCalculationButton.Clicked += new System.EventHandler(this.calculate);
            this.viewResultsButton.Clicked += new System.EventHandler(this.viewResults);
            this.quitButton.Clicked += new System.EventHandler(this.quitProgram);
        }
    }
}
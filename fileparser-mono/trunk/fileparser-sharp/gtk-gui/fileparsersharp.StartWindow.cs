
// This file has been generated by the GUI designer. Do not modify.
namespace fileparsersharp
{
	public partial class StartWindow
	{
		private global::Gtk.HBox hbox1;

		private global::Gtk.Alignment alignment1;

		private global::Gtk.VBox buttonBox;

		private global::Gtk.Button openFileButton;

		private global::Gtk.Button startCalculationButton;

		private global::Gtk.Button viewResultsButton;

		private global::Gtk.Button quitButton;

		private global::Gtk.Alignment alignment2;

		protected virtual void Build ()
		{
			global::Stetic.Gui.Initialize (this);
			// Widget fileparsersharp.StartWindow
			this.Name = "fileparsersharp.StartWindow";
			this.Title = "The Anders Program";
			this.WindowPosition = ((global::Gtk.WindowPosition)(4));
			// Container child fileparsersharp.StartWindow.Gtk.Container+ContainerChild
			this.hbox1 = new global::Gtk.HBox ();
			this.hbox1.Name = "hbox1";
			this.hbox1.Spacing = 6;
			// Container child hbox1.Gtk.Box+BoxChild
			this.alignment1 = new global::Gtk.Alignment (0.5f, 0.5f, 1f, 1f);
			this.alignment1.Name = "alignment1";
			this.hbox1.Add (this.alignment1);
			global::Gtk.Box.BoxChild w1 = ((global::Gtk.Box.BoxChild)(this.hbox1[this.alignment1]));
			w1.Position = 0;
			// Container child hbox1.Gtk.Box+BoxChild
			this.buttonBox = new global::Gtk.VBox ();
			this.buttonBox.Name = "buttonBox";
			this.buttonBox.Homogeneous = true;
			this.buttonBox.Spacing = 6;
			// Container child buttonBox.Gtk.Box+BoxChild
			this.openFileButton = new global::Gtk.Button ();
			this.openFileButton.CanFocus = true;
			this.openFileButton.Name = "openFileButton";
			this.openFileButton.UseUnderline = true;
			this.openFileButton.Label = "Open File";
			this.buttonBox.Add (this.openFileButton);
			global::Gtk.Box.BoxChild w2 = ((global::Gtk.Box.BoxChild)(this.buttonBox[this.openFileButton]));
			w2.Position = 0;
			w2.Expand = false;
			w2.Fill = false;
			// Container child buttonBox.Gtk.Box+BoxChild
			this.startCalculationButton = new global::Gtk.Button ();
			this.startCalculationButton.CanFocus = true;
			this.startCalculationButton.Name = "startCalculationButton";
			this.startCalculationButton.UseUnderline = true;
			this.startCalculationButton.Label = "Calculate";
			this.buttonBox.Add (this.startCalculationButton);
			global::Gtk.Box.BoxChild w3 = ((global::Gtk.Box.BoxChild)(this.buttonBox[this.startCalculationButton]));
			w3.Position = 1;
			w3.Expand = false;
			w3.Fill = false;
			// Container child buttonBox.Gtk.Box+BoxChild
			this.viewResultsButton = new global::Gtk.Button ();
			this.viewResultsButton.CanFocus = true;
			this.viewResultsButton.Name = "viewResultsButton";
			this.viewResultsButton.UseUnderline = true;
			this.viewResultsButton.Label = "View Results";
			this.buttonBox.Add (this.viewResultsButton);
			global::Gtk.Box.BoxChild w4 = ((global::Gtk.Box.BoxChild)(this.buttonBox[this.viewResultsButton]));
			w4.Position = 2;
			w4.Expand = false;
			w4.Fill = false;
			// Container child buttonBox.Gtk.Box+BoxChild
			this.quitButton = new global::Gtk.Button ();
			this.quitButton.CanFocus = true;
			this.quitButton.Name = "quitButton";
			this.quitButton.UseUnderline = true;
			this.quitButton.Label = "Quit";
			this.buttonBox.Add (this.quitButton);
			global::Gtk.Box.BoxChild w5 = ((global::Gtk.Box.BoxChild)(this.buttonBox[this.quitButton]));
			w5.Position = 3;
			w5.Expand = false;
			w5.Fill = false;
			this.hbox1.Add (this.buttonBox);
			global::Gtk.Box.BoxChild w6 = ((global::Gtk.Box.BoxChild)(this.hbox1[this.buttonBox]));
			w6.Position = 1;
			w6.Expand = false;
			w6.Fill = false;
			// Container child hbox1.Gtk.Box+BoxChild
			this.alignment2 = new global::Gtk.Alignment (0.5f, 0.5f, 1f, 1f);
			this.alignment2.Name = "alignment2";
			this.hbox1.Add (this.alignment2);
			global::Gtk.Box.BoxChild w7 = ((global::Gtk.Box.BoxChild)(this.hbox1[this.alignment2]));
			w7.Position = 2;
			this.Add (this.hbox1);
			if ((this.Child != null)) {
				this.Child.ShowAll ();
			}
			this.DefaultWidth = 400;
			this.DefaultHeight = 300;
			this.Show ();
			this.openFileButton.Clicked += new global::System.EventHandler (this.openFile);
			this.startCalculationButton.Clicked += new global::System.EventHandler (this.calculate);
			this.viewResultsButton.Clicked += new global::System.EventHandler (this.viewResults);
			this.quitButton.Clicked += new global::System.EventHandler (this.quitProgram);
		}
	}
}

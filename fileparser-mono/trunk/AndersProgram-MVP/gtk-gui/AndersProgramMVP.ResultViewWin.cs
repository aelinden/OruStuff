
// This file has been generated by the GUI designer. Do not modify.
namespace AndersProgramMVP
{
	public partial class ResultViewWin
	{
		private global::Gtk.ScrolledWindow GtkScrolledWindow;

		private global::Gtk.TreeView resultView;

		private global::Gtk.Button saveButton;

		private global::Gtk.Button buttonOk;

		protected virtual void Build ()
		{
			global::Stetic.Gui.Initialize (this);
			// Widget AndersProgramMVP.ResultViewWin
			this.Name = "AndersProgramMVP.ResultViewWin";
			this.Title = global::Mono.Unix.Catalog.GetString ("View/Save Results");
			this.Icon = global::Gdk.Pixbuf.LoadFromResource ("AndersProgramMVP.fpicon.ico");
			this.WindowPosition = ((global::Gtk.WindowPosition)(4));
			this.Modal = true;
			// Internal child AndersProgramMVP.ResultViewWin.VBox
			global::Gtk.VBox w1 = this.VBox;
			w1.Name = "dialog1_VBox";
			w1.BorderWidth = ((uint)(2));
			// Container child dialog1_VBox.Gtk.Box+BoxChild
			this.GtkScrolledWindow = new global::Gtk.ScrolledWindow ();
			this.GtkScrolledWindow.Name = "GtkScrolledWindow";
			this.GtkScrolledWindow.ShadowType = ((global::Gtk.ShadowType)(1));
			// Container child GtkScrolledWindow.Gtk.Container+ContainerChild
			this.resultView = new global::Gtk.TreeView ();
			this.resultView.CanFocus = true;
			this.resultView.Name = "resultView";
			this.GtkScrolledWindow.Add (this.resultView);
			w1.Add (this.GtkScrolledWindow);
			global::Gtk.Box.BoxChild w3 = ((global::Gtk.Box.BoxChild)(w1[this.GtkScrolledWindow]));
			w3.Position = 0;
			// Internal child AndersProgramMVP.ResultViewWin.ActionArea
			global::Gtk.HButtonBox w4 = this.ActionArea;
			w4.Name = "dialog1_ActionArea";
			w4.Spacing = 10;
			w4.BorderWidth = ((uint)(5));
			w4.LayoutStyle = ((global::Gtk.ButtonBoxStyle)(4));
			// Container child dialog1_ActionArea.Gtk.ButtonBox+ButtonBoxChild
			this.saveButton = new global::Gtk.Button ();
			this.saveButton.CanFocus = true;
			this.saveButton.Name = "saveButton";
			this.saveButton.UseStock = true;
			this.saveButton.UseUnderline = true;
			this.saveButton.Label = "gtk-save";
			this.AddActionWidget (this.saveButton, 0);
			global::Gtk.ButtonBox.ButtonBoxChild w5 = ((global::Gtk.ButtonBox.ButtonBoxChild)(w4[this.saveButton]));
			w5.Expand = false;
			w5.Fill = false;
			// Container child dialog1_ActionArea.Gtk.ButtonBox+ButtonBoxChild
			this.buttonOk = new global::Gtk.Button ();
			this.buttonOk.CanDefault = true;
			this.buttonOk.CanFocus = true;
			this.buttonOk.Name = "buttonOk";
			this.buttonOk.UseStock = true;
			this.buttonOk.UseUnderline = true;
			this.buttonOk.Label = "gtk-ok";
			this.AddActionWidget (this.buttonOk, -5);
			global::Gtk.ButtonBox.ButtonBoxChild w6 = ((global::Gtk.ButtonBox.ButtonBoxChild)(w4[this.buttonOk]));
			w6.Position = 1;
			w6.Expand = false;
			w6.Fill = false;
			if ((this.Child != null)) {
				this.Child.ShowAll ();
			}
			this.DefaultWidth = 400;
			this.DefaultHeight = 300;
			this.Hide ();
			this.saveButton.Clicked += new global::System.EventHandler (this.saveFileHandler);
			this.buttonOk.Clicked += new global::System.EventHandler (this.closeViewWinHandler);
		}
	}
}

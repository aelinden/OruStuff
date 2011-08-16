
// This file has been generated by the GUI designer. Do not modify.

public partial class MainWindow
{
	private global::Gtk.UIManager UIManager;

	private global::Gtk.Action FileAction;

	private global::Gtk.Action OpenAction;

	private global::Gtk.Action ExitAction;

	private global::Gtk.Action AboutAction;

	private global::Gtk.Action OpenAction1;

	private global::Gtk.Action AboutAction1;

	private global::Gtk.VBox vbox1;

	private global::Gtk.MenuBar MenuBar;

	private global::Gtk.ScrolledWindow GtkScrolledWindow;

	private global::Gtk.TextView TextView;

	private global::Gtk.HBox ButtonHBox;

	private global::Gtk.Button OpenButton;

	private global::Gtk.Button ExecButton;

	private global::Gtk.Button ViewButton;

	private global::Gtk.Button ExitButton;

	private global::Gtk.Button SaveButton;

	private global::Gtk.Statusbar SBar;

	protected virtual void Build ()
	{
		global::Stetic.Gui.Initialize (this);
		// Widget MainWindow
		this.UIManager = new global::Gtk.UIManager ();
		global::Gtk.ActionGroup w1 = new global::Gtk.ActionGroup ("Default");
		this.FileAction = new global::Gtk.Action ("FileAction", "_File", null, null);
		this.FileAction.ShortLabel = "_File";
		w1.Add (this.FileAction, "<Control><Mod2>f");
		this.OpenAction = new global::Gtk.Action ("OpenAction", "_Open", null, null);
		this.OpenAction.ShortLabel = "_Open";
		w1.Add (this.OpenAction, "<Control><Mod2>o");
		this.ExitAction = new global::Gtk.Action ("ExitAction", "E_xit", null, null);
		this.ExitAction.ShortLabel = "E_xit";
		w1.Add (this.ExitAction, "<Control><Mod2>x");
		this.AboutAction = new global::Gtk.Action ("AboutAction", "_About", null, null);
		this.AboutAction.ShortLabel = "_About";
		w1.Add (this.AboutAction, "<Control><Mod2>a");
		this.OpenAction1 = new global::Gtk.Action ("OpenAction1", "_Open", null, null);
		this.OpenAction1.ShortLabel = "_Open";
		w1.Add (this.OpenAction1, null);
		this.AboutAction1 = new global::Gtk.Action ("AboutAction1", "_About", null, null);
		this.AboutAction1.ShortLabel = "_About";
		w1.Add (this.AboutAction1, "<Control><Mod2>a");
		this.UIManager.InsertActionGroup (w1, 0);
		this.AddAccelGroup (this.UIManager.AccelGroup);
		this.Name = "MainWindow";
		this.Title = "PnP";
		this.Icon = global::Stetic.IconLoader.LoadIcon (this, "gtk-justify-center", global::Gtk.IconSize.Menu);
		this.WindowPosition = ((global::Gtk.WindowPosition)(4));
		this.DefaultWidth = 640;
		this.DefaultHeight = 480;
		// Container child MainWindow.Gtk.Container+ContainerChild
		this.vbox1 = new global::Gtk.VBox ();
		this.vbox1.Name = "vbox1";
		this.vbox1.Spacing = 6;
		// Container child vbox1.Gtk.Box+BoxChild
		this.UIManager.AddUiFromString ("<ui><menubar name='MenuBar'><menu name='FileAction' action='FileAction'><menuitem name='OpenAction1' action='OpenAction1'/><menuitem name='ExitAction' action='ExitAction'/></menu><menuitem name='AboutAction1' action='AboutAction1'/></menubar></ui>");
		this.MenuBar = ((global::Gtk.MenuBar)(this.UIManager.GetWidget ("/MenuBar")));
		this.MenuBar.Name = "MenuBar";
		this.vbox1.Add (this.MenuBar);
		global::Gtk.Box.BoxChild w2 = ((global::Gtk.Box.BoxChild)(this.vbox1[this.MenuBar]));
		w2.Position = 0;
		w2.Expand = false;
		w2.Fill = false;
		// Container child vbox1.Gtk.Box+BoxChild
		this.GtkScrolledWindow = new global::Gtk.ScrolledWindow ();
		this.GtkScrolledWindow.Name = "GtkScrolledWindow";
		this.GtkScrolledWindow.ShadowType = ((global::Gtk.ShadowType)(1));
		// Container child GtkScrolledWindow.Gtk.Container+ContainerChild
		this.TextView = new global::Gtk.TextView ();
		this.TextView.CanFocus = true;
		this.TextView.Name = "TextView";
		this.TextView.Editable = false;
		this.TextView.CursorVisible = false;
		this.GtkScrolledWindow.Add (this.TextView);
		this.vbox1.Add (this.GtkScrolledWindow);
		global::Gtk.Box.BoxChild w4 = ((global::Gtk.Box.BoxChild)(this.vbox1[this.GtkScrolledWindow]));
		w4.Position = 1;
		// Container child vbox1.Gtk.Box+BoxChild
		this.ButtonHBox = new global::Gtk.HBox ();
		this.ButtonHBox.Name = "ButtonHBox";
		this.ButtonHBox.Homogeneous = true;
		this.ButtonHBox.Spacing = 6;
		// Container child ButtonHBox.Gtk.Box+BoxChild
		this.OpenButton = new global::Gtk.Button ();
		this.OpenButton.CanFocus = true;
		this.OpenButton.Name = "OpenButton";
		this.OpenButton.UseUnderline = true;
		this.OpenButton.Label = "Open";
		this.ButtonHBox.Add (this.OpenButton);
		global::Gtk.Box.BoxChild w5 = ((global::Gtk.Box.BoxChild)(this.ButtonHBox[this.OpenButton]));
		w5.Position = 0;
		w5.Expand = false;
		w5.Fill = false;
		// Container child ButtonHBox.Gtk.Box+BoxChild
		this.ExecButton = new global::Gtk.Button ();
		this.ExecButton.Sensitive = false;
		this.ExecButton.CanFocus = true;
		this.ExecButton.Name = "ExecButton";
		this.ExecButton.UseUnderline = true;
		this.ExecButton.Label = "Parse";
		this.ButtonHBox.Add (this.ExecButton);
		global::Gtk.Box.BoxChild w6 = ((global::Gtk.Box.BoxChild)(this.ButtonHBox[this.ExecButton]));
		w6.Position = 1;
		w6.Expand = false;
		w6.Fill = false;
		// Container child ButtonHBox.Gtk.Box+BoxChild
		this.ViewButton = new global::Gtk.Button ();
		this.ViewButton.Sensitive = false;
		this.ViewButton.CanFocus = true;
		this.ViewButton.Name = "ViewButton";
		this.ViewButton.UseUnderline = true;
		this.ViewButton.Label = "View";
		this.ButtonHBox.Add (this.ViewButton);
		global::Gtk.Box.BoxChild w7 = ((global::Gtk.Box.BoxChild)(this.ButtonHBox[this.ViewButton]));
		w7.Position = 2;
		w7.Expand = false;
		w7.Fill = false;
		// Container child ButtonHBox.Gtk.Box+BoxChild
		this.ExitButton = new global::Gtk.Button ();
		this.ExitButton.CanFocus = true;
		this.ExitButton.Name = "ExitButton";
		this.ExitButton.UseUnderline = true;
		this.ExitButton.Label = "Exit";
		this.ButtonHBox.Add (this.ExitButton);
		global::Gtk.Box.BoxChild w8 = ((global::Gtk.Box.BoxChild)(this.ButtonHBox[this.ExitButton]));
		w8.PackType = ((global::Gtk.PackType)(1));
		w8.Position = 3;
		w8.Expand = false;
		w8.Fill = false;
		// Container child ButtonHBox.Gtk.Box+BoxChild
		this.SaveButton = new global::Gtk.Button ();
		this.SaveButton.Sensitive = false;
		this.SaveButton.CanFocus = true;
		this.SaveButton.Name = "SaveButton";
		this.SaveButton.UseUnderline = true;
		this.SaveButton.Label = "Save";
		this.ButtonHBox.Add (this.SaveButton);
		global::Gtk.Box.BoxChild w9 = ((global::Gtk.Box.BoxChild)(this.ButtonHBox[this.SaveButton]));
		w9.PackType = ((global::Gtk.PackType)(1));
		w9.Position = 4;
		w9.Expand = false;
		w9.Fill = false;
		this.vbox1.Add (this.ButtonHBox);
		global::Gtk.Box.BoxChild w10 = ((global::Gtk.Box.BoxChild)(this.vbox1[this.ButtonHBox]));
		w10.Position = 2;
		w10.Expand = false;
		w10.Fill = false;
		// Container child vbox1.Gtk.Box+BoxChild
		this.SBar = new global::Gtk.Statusbar ();
		this.SBar.Name = "SBar";
		this.SBar.Spacing = 6;
		this.vbox1.Add (this.SBar);
		global::Gtk.Box.BoxChild w11 = ((global::Gtk.Box.BoxChild)(this.vbox1[this.SBar]));
		w11.PackType = ((global::Gtk.PackType)(1));
		w11.Position = 3;
		w11.Expand = false;
		w11.Fill = false;
		this.Add (this.vbox1);
		if ((this.Child != null)) {
			this.Child.ShowAll ();
		}
		this.Show ();
		this.DeleteEvent += new global::Gtk.DeleteEventHandler (this.OnDeleteEvent);
		this.OpenAction.Activated += new global::System.EventHandler (this.OnOpenClicked);
		this.ExitAction.Activated += new global::System.EventHandler (this.OnExitClicked);
		this.AboutAction.Activated += new global::System.EventHandler (this.OnAboutClicked);
		this.OpenAction1.Activated += new global::System.EventHandler (this.OnOpenClicked);
		this.AboutAction1.Activated += new global::System.EventHandler (this.OnAboutClicked);
		this.OpenButton.Clicked += new global::System.EventHandler (this.OnOpenButtonClicked);
		this.ExecButton.Clicked += new global::System.EventHandler (this.OnExecButtonClicked);
		this.ViewButton.Clicked += new global::System.EventHandler (this.OnViewButtonClicked);
		this.SaveButton.Clicked += new global::System.EventHandler (this.OnSaveButtonClicked);
		this.ExitButton.Clicked += new global::System.EventHandler (this.OnExitButtonClicked);
	}
}

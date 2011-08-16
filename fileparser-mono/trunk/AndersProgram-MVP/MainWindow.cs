using System;
using System.Reflection;
using Gtk;
using System.Text;

namespace AndersProgramMVP 
{
	public partial class MainWindow : Gtk.Window, IMainWindow
	{
		private string inputFile;
		private string outputFile;
		private StringBuilder sbarmessage; // Status bar messages
		
		public event DelegateStartCalculation EventStartCalculation;
		public event DelegateViewResults EventViewResults;
		public event DelegateFileIsOpened EventFileIsOpened;
		
		public MainWindow () : base(Gtk.WindowType.Toplevel)
		{
			Build ();
			mainStatusbar.Push (1, "Welcome to PnP");
			sbarmessage = new StringBuilder();
		}
	
		protected void OnDeleteEvent (object sender, DeleteEventArgs a)
		{
			Application.Quit ();
			a.RetVal = true;
		}
		protected virtual void openFileHandler (object sender, System.EventArgs e)
		{
			// Create and display a fileChooserDialog
			FileChooserDialog chooser = 
				new FileChooserDialog ("Select file to parse...",
				                      this,
				                      FileChooserAction.Open,
				                      "Cancel", ResponseType.Cancel,
				                      "Open", ResponseType.Accept);
			if (chooser.Run () == (int)ResponseType.Accept)
			{
				// Open the file for reading.
				System.IO.StreamReader file =
					System.IO.File.OpenText (chooser.Filename);
				
				//Some things we need for the resulting file name
				string fPath = System.IO.Path.GetDirectoryName (chooser.Filename);
				string fName = System.IO.Path.GetFileNameWithoutExtension (chooser.Filename);
				string fExt = System.IO.Path.GetExtension (chooser.Filename);
				
				// Set input file
				this.inputFile = chooser.Filename;
				
				// Contruct resulting file name 
				this.outputFile = 
					fPath + System.IO.Path.DirectorySeparatorChar + fName + 
						"-Results-" + DateTime.Now.ToString ("yyyy-MM-dd") + fExt;
				
				file.Close ();
				
				// Enable calculate and view buttons
				this.calculateButton.Sensitive = true;
				this.viewButton.Sensitive = false;
				
				// Update statusbar
				sbarmessage.Remove(0, sbarmessage.Length);
				sbarmessage.Append(String.Format ("File {0} opened", System.IO.Path.GetFileName (chooser.Filename)));
				mainStatusbar.Pop (1);
				mainStatusbar.Push(1, sbarmessage.ToString());
				
				// Signal that a new file has been opened.
				this.EventFileIsOpened (this);
			}
			else
			{
				this.calculateButton.Sensitive = false;
				this.viewButton.Sensitive = false;
			}
			
			chooser.Destroy();

		}
		
		protected virtual void quitHandler(object sender, EventArgs e)
		{
			Application.Quit();
			
		}
	
		protected virtual void calculateHandler (object sender, System.EventArgs e)
		{
			this.EventStartCalculation (this, new IOFilesArgs (inputFile, outputFile));
			this.calculateButton.Sensitive = false;
			this.viewButton.Sensitive = true;
			
			// Update statusbar
			mainStatusbar.Pop (1);
			mainStatusbar.Push (1, "File parsed");
		}
		
		protected virtual void viewHandler (object sender, System.EventArgs e)
		{
			this.EventViewResults(this);
		}
		protected virtual void onAboutButtonClicked (object sender, System.EventArgs e)
		{
			// Get version object for this assembly
			Version v = Assembly.GetExecutingAssembly ().GetName ().Version;
			AssemblyName name = Assembly.GetExecutingAssembly ().GetName();
			String message = 
				String.Format ("{0}"
					+ Environment.NewLine + "Version {1}"
				    + Environment.NewLine + "Licensed to Örebro University"
				    + Environment.NewLine + "(C) 2009 - 2010 Anders Lindén",
				    name.Name.ToString(), v.Major.ToString () + "." + v.Minor.ToString());
					MessageDialog md = new MessageDialog (this, DialogFlags.Modal, MessageType.Info,
				ButtonsType.Ok, message);
			ResponseType res = (ResponseType)md.Run ();
			if (res == ResponseType.Ok)
				md.Destroy ();
		}
		
		
	}
}

using System;
using Gtk;
using OruSharpReader;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Reflection;

public partial class MainWindow: Gtk.Window
{
	private Parser parser;
	private StringBuilder resultString;
	private string resultFileName;
	private Assembly asm;
	
	public MainWindow (ref Assembly asm): base (Gtk.WindowType.Toplevel)
	{
		this.asm = asm;
		Build ();
	}
	
	protected void OnDeleteEvent (object sender, DeleteEventArgs a)
	{
		Application.Quit ();
		a.RetVal = true;
	}

	protected virtual void OnExitClicked (object sender, System.EventArgs e)
	{
		Application.Quit ();
	}

	protected virtual void OnExecButtonClicked (object sender, System.EventArgs e)
	{
		resultString = new StringBuilder();
		try{
			parser.Execute(); // Parse selected file
		}
		catch(Exception exc){
			string errorText = "Ouch! Something bad happened and an exception" +
				" was thrown. The error message was: " + Environment.NewLine +
					exc.Message + Environment.NewLine + Environment.NewLine +
					"Make sure your input file is formatted correctly and try again.";
			
			MessageDialog md = new MessageDialog(this, DialogFlags.Modal, 
		                                     MessageType.Info, ButtonsType.Ok,
		                                     errorText);
			ResponseType res = (ResponseType)md.Run();
			if(res == ResponseType.Ok){
				md.Destroy();
				Application.Quit();
			}
		}
		
		// Append each line
		foreach(string str in parser.GetResults()){
			resultString.Append(str + Environment.NewLine);
		}
		resultString.Append(Environment.NewLine);
		// Enable View and Save buttons
		TextView.Buffer.Text = "File parsed. Press View to view results or Save to save results.";
		//TextView.Buffer.Text = "File parsed. Press Save to save the results.";
		ViewButton.Sensitive = true;
		SaveButton.Sensitive = true;
	}

	protected virtual void OnExitButtonClicked (object sender, System.EventArgs e)
	{
		this.OnExitClicked(sender, e);
	}

	protected virtual void OnOpenButtonClicked (object sender, System.EventArgs e)
	{
		 // Create and display a fileChooserDialog
		FileChooserDialog chooser = new FileChooserDialog(
        "Select file to parse...",
        this,
        FileChooserAction.Open,
        "Cancel", ResponseType.Cancel,
        "Open", ResponseType.Accept );
		
		if( chooser.Run() == ( int )ResponseType.Accept )
		{
        // Open the file for reading.
        System.IO.StreamReader file =
        System.IO.File.OpenText( chooser.Filename );
        
		// Some things we need for the resulting file name
		string fPath = System.IO.Path.GetDirectoryName(chooser.Filename);
		string fName = System.IO.Path.GetFileNameWithoutExtension(chooser.Filename);
		string fExt = System.IO.Path.GetExtension(chooser.Filename);
		
		// Contruct resulting file name 
		resultFileName = 
				fPath + System.IO.Path.DirectorySeparatorChar + fName + 
				"-Results-" + DateTime.Now.ToString("yyyy-MM-dd") + fExt;
		
		// Create parser supplying selected file
		parser = new Parser(chooser.Filename, resultFileName);
        
		//TextView.Buffer.Text = file.ReadToEnd();
        TextView.Buffer.Text = "File opened. Press Parse to process file.";
			
        // Set the MainWindow Title to the filename.
        this.Title = this.Title + " -- " + chooser.Filename.ToString();
        
        // Make the MainWindow bigger to accomodate the text in the logTextView
        //this.Resize( 640, 480 );
        
        // Close the file so as to not leave a mess.
        file.Close();
		// Enable Execute button
		ExecButton.Sensitive = true; 
     } // end if
     chooser.Destroy();
	}

	protected virtual void OnAboutClicked (object sender, System.EventArgs e)
	{
		string aboutText = "ORU File Parser aka The Anders Program " + 
			"v " + asm.GetName().Version.ToString() + Environment.NewLine +
				"(C) Anders Lindén 2008 - 2009. Licenced to Örebro University" + Environment.NewLine +
				"For questions and support, send a mail to: " + 
				"anders.linden@gmail.com";
		
		MessageDialog md = new MessageDialog(this, DialogFlags.Modal, 
		                                     MessageType.Info, ButtonsType.Ok,
		                                     aboutText);
		ResponseType res = (ResponseType)md.Run();
		if(res == ResponseType.Ok)
			md.Destroy();
	}

	protected virtual void OnViewButtonClicked (object sender, System.EventArgs e)
	{
		TextView.Buffer.Text = resultString.ToString();
	}

	protected virtual void OnOpenClicked (object sender, System.EventArgs e)
	{
		this.OnOpenButtonClicked(sender, e);
	}

	protected virtual void OnSaveButtonClicked (object sender, System.EventArgs e)
	{
		parser.WriteToFile("Results of parsing:" + Environment.NewLine +
		                   resultString.ToString(), resultFileName);
		MessageDialog md = new MessageDialog(this, DialogFlags.Modal, 
		                                     MessageType.Info, ButtonsType.Ok, "File saved as " + resultFileName);
		ResponseType res = (ResponseType)md.Run();
		if(res == ResponseType.Ok)
			md.Destroy();		
	}
}

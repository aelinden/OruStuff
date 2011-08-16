
using System;
using System.Text;
using System.Collections.Generic;
using OruSharpReader;
using Gtk;

namespace AndersProgramMVP
{
	/// <summary>
	/// The presenter in the Model-View-Presenter-design pattern.
	/// Deals with events from objects.
	/// </summary>
	public class Presenter
	{
		private Parser p;
		private MainWindow mainwin;
		private ResultViewWin resWin;
		private StringBuilder resultString;
		private string outputFile;
		private bool resultIsCurrent;

		/// <summary>
		/// The constructor accepts the main window as an argument. 
		/// It initializes some variables and connects events from 
		/// the main window to functions.
		/// </summary>
		/// <param name="mainwin">
		///  The main window of the application.
		/// </param>
		public Presenter (MainWindow mainwin, ResultViewWin resWin)
		{
			this.mainwin = mainwin;
			this.resWin = resWin;
			this.resultString = new StringBuilder ();
			
			this.mainwin.EventStartCalculation += StartCalculation;
			this.mainwin.EventViewResults += ViewResults;
			this.mainwin.EventFileIsOpened += InvalidateResult;
			
			this.resWin.EventSaveToFile += SaveToFile;
			
			this.resultIsCurrent = false;
		}
		
		#region Events from the main window
		
		/// <summary>
		/// StartCalculation supplies the parser with the input/output-files and
		/// starts to calculate data. The result is added to the stringbuilder resultString.
		/// </summary>
		/// <param name="sender">
		/// A <see cref="System.Object"/>
		/// </param>
		/// <param name="e">
		/// A <see cref="IOFilesArgs"/>
		/// </param>
		private void StartCalculation (object sender, IOFilesArgs e)
		{
			p = new Parser ();
			this.outputFile = e.outputFile;
			p.setIOFiles (e.inputFile, e.outputFile);
			
			// Parse selected file
			p.Execute ();
		
			/*
			 *  Append each line to result string.
			 * (This really needs to be rewritten so some sort of grid view
			 * can be used to view the results instead of a messy textbox.
			 */
			foreach (string str in p.GetResults ()) {
				resultString.Append(str + Environment.NewLine);
			}
			resultString.Append(Environment.NewLine);
		}
		
		/// <summary>
		/// ViewResult updates the tree view in the result window with the results string from
		/// StartCalculation above. 
		/// </summary>
		/// <param name="sender">
		/// A <see cref="System.Object"/>
		/// </param>
		private void ViewResults (object sender)
		{
			// Only if a new file has been processed should the view be
			// updated. Otherwise just show the current one again.
			if (!resultIsCurrent)
			{
				this.resWin.UpdateView (resultString.ToString ());
				this.resultIsCurrent = true;
			}
			resWin.ShowAll ();
		}
		
		// A new file has been opened. The current result is no
		// longer valid.
		private void InvalidateResult (object sender)
		{
			this.resultIsCurrent = false;
		}
		#endregion
		
		#region Events from the view window
		
		/// <summary>
		/// SaveToFile saves the result to a file.
		/// </summary>
		/// <param name="sender">
		/// A <see cref="System.Object"/>
		/// </param>
		private void SaveToFile (object sender)
		{
			
			p.WriteToFile("Results of parsing:" + Environment.NewLine +
		                   resultString.ToString(), outputFile);
			MessageDialog md = new MessageDialog(resWin, DialogFlags.Modal,
			                                     MessageType.Info, ButtonsType.Ok,
			                                     "File saved as " + outputFile);
			ResponseType res = (ResponseType)md.Run();
			if (res == ResponseType.Ok)
				md.Destroy();
					
		}
		#endregion
	}
}

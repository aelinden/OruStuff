
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
		private ResultViewWin rvw;
		private StringBuilder resultString;
		//private List<string> results;
		private string outputFile;

		/// <summary>
		/// The constructor accepts the main window as an argument. 
		/// It initializes some variables and connects events from 
		/// the main window to functions.
		/// </summary>
		/// <param name="mainwin">
		///  The main window of the application.
		/// </param>
		public Presenter (MainWindow mainwin)
		{
			this.mainwin = mainwin;
			this.resultString = new StringBuilder();
			//this.results = new List<string> ();
			mainwin.EventStartCalculation += StartCalculation;
			mainwin.EventViewResults += ViewResults;
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
		public void StartCalculation (object sender, IOFilesArgs e)
		{
			p = new Parser ();
			this.outputFile = e.outputFile;
			p.setIOFiles (e.inputFile, e.outputFile);
			
			// Parse selected file
			p.Execute ();
			// Parse selected file
		
			/*
			 *  Append each line to result string.
			 * (This really needs to be rewritten so some sort of grid view
			 * can be used to view the results instead of a messy textbox.
			 */
		foreach (string str in p.GetResults ()) {
				resultString.Append(str + Environment.NewLine);
				//results.Add (str);
			}
			resultString.Append(Environment.NewLine);
		}
		
		/// <summary>
		/// ViewResult creates a new ResultViewWin and connects its event to presenter functions.
		/// The TextView in the result window is then updated with the results string from
		/// StartCalculation above. If the user wishes to save the result (Most likely),
		/// the event EventSaveToFile is fired and caught here.
		/// </summary>
		/// <param name="sender">
		/// A <see cref="System.Object"/>
		/// </param>
		public void ViewResults (object sender)
		{
			rvw = new ResultViewWin ();
			rvw.EventSaveToFile += SaveToFile;
			this.rvw.updateTextView(resultString.ToString());
			rvw.Show();
		}
		#endregion
		
		#region Events från view-fönstret
		
		/// <summary>
		/// SaveToFile saves the result to a file.
		/// </summary>
		/// <param name="sender">
		/// A <see cref="System.Object"/>
		/// </param>
		public void SaveToFile (object sender)
		{
			
			p.WriteToFile("Results of parsing:" + Environment.NewLine +
		                   resultString.ToString(), outputFile);
			MessageDialog md = new MessageDialog(rvw, DialogFlags.Modal,
			                                     MessageType.Info, ButtonsType.Ok,
			                                     "File saved as " + outputFile);
			ResponseType res = (ResponseType)md.Run();
			if (res == ResponseType.Ok)
				md.Destroy();
					
		}
		#endregion
	}
}

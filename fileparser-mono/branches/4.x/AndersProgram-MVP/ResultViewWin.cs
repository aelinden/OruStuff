using System;
using System.Collections.Generic;
using Gtk;

namespace AndersProgramMVP
{

	/// <summary>
	/// The result window displays the calculated result and lets the user
	/// save it to a file.
	/// </summary>
	public partial class ResultViewWin : Gtk.Dialog, IResultViewWin
	{
		public event DelegateSaveToFile EventSaveToFile;
		private StoreHandler storeHandler;
		
		public ResultViewWin ()
		{
			this.Build ();
		}
		
		/// <summary>
		/// Updates the treeview by:
		/// 1. Splitting the result string into newline separated string.
		/// 2. Count the number of rows.
		/// 3. Split first string into tab separated substrings.
		/// 4. Count the number of columns.
		/// 5. Creates a new store for the resultView to read data from using
		/// 	number of columns and the string type (All data in result view
		/// 	are strings).
		/// 6. Set the model of the result view to the newly created store.
		/// 7. Add columns to the result view. Each new column will have
		/// 	the title of the corresponding column in the result string
		/// 	(s is the title, "text" means the cell renderer should display text and
		/// 	 currentColumn is what column from the store the result view column should
		/// 	 display data from).
		/// 8. Finally fill the store with data so that the result view can show something
		/// 	to the user.
		/// 
		/// This is horribly convoluted and can most likely be simplified.
		/// That however is for another day, and at the moment I'm just happy
		/// it actually works. 
		/// </summary>
		public void updateTextView (string resultString)
		{
			char[] delims = new char[] { '\r', '\n' };
			string[] splitResults = resultString.Split (delims, StringSplitOptions.None);
			int numberOfRows = splitResults.Length;
			string[] toprowsplit = splitResults[0].Split ('\t');
			int numberOfCols = toprowsplit.Length;
			storeHandler = new StoreHandler (numberOfCols, typeof(string));
			
			int currentColumn = 0;
			foreach (string s in toprowsplit)
			{
				resultView.AppendColumn (new TreeViewColumn (s, new CellRendererText (), "text", currentColumn));
				++currentColumn;
			}
			for (int i = 1; i < numberOfRows; ++i)
				storeHandler.listStore.AppendValues (splitResults[i].Split ('\t'));
			resultView.Model = storeHandler.listStore;
		}
		
		/// <summary>
		/// If the save file button is clicked, fire off this event.
		/// </summary>
		/// <param name="sender">
		/// A <see cref="System.Object"/>
		/// </param>
		/// <param name="e">
		/// A <see cref="System.EventArgs"/>
		/// </param>
		protected virtual void saveFileHandler (object sender, System.EventArgs e)
		{
			this.EventSaveToFile (this);
		}
		
		protected virtual void closeViewWinHandler (object sender, System.EventArgs e)
		{
			this.Destroy();
		}
		
	}
}

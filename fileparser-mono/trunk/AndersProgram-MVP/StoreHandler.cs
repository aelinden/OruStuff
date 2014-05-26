using System;
using Gtk;
namespace AndersProgramMVP
{
	/// <summary>
	/// The StoreHandler class deals with the store used by the result window.
	/// The store contains all the data that is displayed by the tree view in 
	/// that window.
	/// </summary>
	public class StoreHandler
	{
		private ListStore store;
		
		public StoreHandler (int numberOfCols, System.Type type)
		{
			this.prepareStore (numberOfCols, type);
		}
		
		public ListStore listStore
		{
			get { return this.store; }
		}
		
		/// <summary>
		/// Creates the store 'store' with numberofCols columns of type 'type'
		/// </summary>
		/// <param name="numberofCols">
		/// Number of columns the store should contain
		/// </param>
		/// <param name="store">
		/// Store to create
		/// </param>
		private void prepareStore (int numberofCols, System.Type type)
		{
			System.Type[] arrayOfSuppliedType = new System.Type[numberofCols];
			for (int i = 0; i < numberofCols; ++i)
			{
				arrayOfSuppliedType[i] = type;
			}
			this.store = new ListStore (arrayOfSuppliedType);
		}
	}
}


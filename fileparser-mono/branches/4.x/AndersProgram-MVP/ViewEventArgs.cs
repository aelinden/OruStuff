
using System;

namespace AndersProgramMVP
{

	/// <summary>
	/// Argument sent along to the view window
	/// </summary>
	public class ViewEventArgs : EventArgs
	{
		public readonly string text;

		public ViewEventArgs (string text)
		{
			this.text = text;
		}
	}
}


using System;

namespace AndersProgramMVP
{
	public delegate void DelegateSaveToFile(object sender);

	/// <summary>
	/// Interface for the result view window.
	/// </summary>
	public interface IResultViewWin
	{
		event DelegateSaveToFile EventSaveToFile;	
	}
}

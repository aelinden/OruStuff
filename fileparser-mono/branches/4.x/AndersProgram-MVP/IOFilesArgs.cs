
using System;

namespace AndersProgramMVP
{
	/// <summary>
	/// Arguments passed along to calculation
	/// </summary>
	public class IOFilesArgs : EventArgs
	{
		public readonly string inputFile;
		public readonly string outputFile;

		public IOFilesArgs (string i, string o)
		{
			this.inputFile = i;
			this.outputFile = o;
		}
	}
}

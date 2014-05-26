
using System;

namespace AndersProgramMVP
{
	public delegate void DelegateStartCalculation(object sender, IOFilesArgs e);
	public delegate void DelegateViewResults(object sender);
	
	public interface IMainWindow
	{
		event DelegateStartCalculation EventStartCalculation;
		event DelegateViewResults EventViewResults;
	}
}

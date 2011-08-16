using System;
using Gtk;
using System.Reflection;


namespace fileparsersharp
{
	class MainClass
	{
		private static Assembly asm;
		public static void Main (string[] args)
		{
			asm = Assembly.GetCallingAssembly();
			Application.Init ();
			MainWindow win = new MainWindow (ref asm);
			win.Show ();
			Application.Run ();
		}
	}
}
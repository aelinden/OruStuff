using System;
using Gtk;

namespace AndersProgramMVP
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			/*
			 * We only create the main window and the presenter here
			 * since for some reason if we create them all here and pass them along
			 * as arguments to the presenter, they all show up right away. It's 
			 * probably an issue on my end, but it's not really a biggie to create
			 * the windows in the presenter when needed.
			 */
			Application.Init ();
			MainWindow mainWin = new MainWindow ();
			ResultViewWin resWin = new ResultViewWin();
			Presenter presenter = new Presenter(mainWin, resWin);
			mainWin.Show ();
			Application.Run ();
		}
	}
}

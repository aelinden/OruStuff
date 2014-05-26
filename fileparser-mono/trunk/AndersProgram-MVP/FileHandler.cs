/*
 * FileHandler.cs
 * 
 * This file is responsible for file I/O.
 * 
 * Methods:
 * - ReadFromFile(ref List<string> l) : Opens a new filestream and streamreader and reads 
 *    data from it into List l. When finished, it then closes filestream and streamreader.
 * - WriteToFile(string s) : Writes string s to file
 */

using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;

namespace OruSharpReader
{	
	/// <summary>
	/// The Filehandler reads from the input file and
	/// writes to the output file. No more, no less.
	/// </summary>
	public class FileHandler
	{
		private FileStream fStream;
		private StreamReader reader;
		private TextWriter writer;
		private static FileHandler instance = null;
		private static readonly object padlock = new object();
		string iFile;
		string oFile;
		
		/*
		private FileHandler(string inputFile, string outputFile)
		{
			iFile = inputFile;
			oFile = outputFile;
		}
		*/
		
		/// <summary>
		/// Instance property for singleton
		/// </summary> 
		public static FileHandler Instance
		{
			get 
			{
				lock(padlock)
				{
					if(instance == null)
						instance = new FileHandler();
					return instance;
				}
			}
		}
		
		private FileHandler()
		{
		}
		
		/// <summary>
		/// Sets the input and output files
		/// </summary>
		/// <param name="iFile">
		/// A <see cref="System.String"/>
		/// The input file
		/// </param>
		/// <param name="oFile">
		/// A <see cref="System.String"/>
		/// The output file
		/// </param>
		public void SetIO(string iFile, string oFile)
		{
			this.iFile = iFile;
			this.oFile = oFile;
		}
		
		/// <summary>
		///  ReadFromFile reads file contents into fileContent list
		/// </summary>
		/// <param name="fileContent">
		/// A <see cref="List<System.String>"/>
		/// The list used by the parser containing the contents of the input file.
		/// </param>
		public void ReadFromFile(ref List<string> fileContent)
		{
			fStream = new FileStream(iFile, FileMode.Open, FileAccess.Read);
			reader = new StreamReader(fStream);
			fileContent.Clear();
            string line;
            while ((line = reader.ReadLine()) != null)
				if (String.IsNullOrEmpty(line) != true)
					fileContent.Add(line);
			reader.Close();
			fStream.Close();
		}
		
		/// <summary>
		/// WriteToFile writes string textToWrite into output file
		/// </summary>
		/// <param name="textToWrite">
		/// A <see cref="System.String"/>
		/// The text to write to the output file.
		/// </param> 
		public void WriteToFile(string textToWrite)
		{
			writer = new StreamWriter(oFile);
			writer.WriteLine(textToWrite);
			writer.Close();
		}
	}
}

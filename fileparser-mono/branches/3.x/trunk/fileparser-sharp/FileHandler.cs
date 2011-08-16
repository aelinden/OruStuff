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
	public class FileHandler
	{
		private FileStream fStream;
		private StreamReader reader;
		private TextWriter writer;
		string iFile;
		string oFile;
		
		public FileHandler(string inputFile, string outputFile)
		{
			iFile = inputFile;
			oFile = outputFile;
		}
		
		// ReadFromFile reads file contents into fileContent list
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
		
		// WriteToFile writes string textToWrite into output file
		public void WriteToFile(string textToWrite)
		{
			writer = new StreamWriter(oFile);
			writer.WriteLine(textToWrite);
			writer.Close();
		}
	}
}

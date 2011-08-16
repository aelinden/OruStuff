
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;

namespace OruSharpReader
{	
	public class FileHandler
	{
		private FileStream fileStreamer;
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
			fileStreamer = new FileStream(iFile, FileMode.Open, FileAccess.Read);
			reader = new StreamReader(fileStreamer);
			fileContent.Clear();
            string line;
            while ((line = reader.ReadLine()) != null)
				if (String.IsNullOrEmpty(line) != true)
					fileContent.Add(line);
			reader.Close();
			fileStreamer.Close();
		}
		
		// WriteToFile writes results into output file
		public void WriteToFile(string textToWrite)
		{
			writer = new StreamWriter(oFile);
			writer.WriteLine(textToWrite);
			writer.Close();
		}
	}
}

/*
 * Parser.cs
 * 
 * This class is responsible for parsing the input file.
 * 
 * Methods:
 * - GetClassSizes() - Returns sizes of classes
 * - SetInputFile(string s1) : Sets the file to parse from.
 * - Execute() : Parses the file and returns a ClassMember array.
 * - WriteToFile(string s1, string s2) : Writes the string s1 into file s2.
 * - ReadFromFile(string s1) : Reads from file s1 and splits up contents properly.
 * - GetResults() : Returns the results of parsing as a list.
 * - CalculateQuestionGroup(string, ClassMember) : Calculates percentage
 * - FillStudentPosts(List<string>) : Fills student posts with id and class
 * 
 */

#region Using statements
using System;
using System.Text;
using OruSharpReader;
using System.Collections;
using System.Collections.Generic;
using System.Globalization;
using System.Threading;
using Gtk;
#endregion

namespace OruSharpReader
{
	public class Parser
	{
		private int numCols; // Number of columns in the file.
		private int idCol;	// The column of the member id
		private int classCol;	// The column of the class id
		private int qColBegin;	// Column where questions start
		//private int cmpLen; // Length of question string we want to compare (Ex. SK1, not SK1A)
		private int rowCount;
		private int cmIndex;

		private string delimString; // Field delimiter. Use delimString[0] where char is needed.
		private string inputFile;
		private string outputFile;
		private ClassMember[] cm;
		private Dictionary<string, int> classSizes;
		private List<string> splitinlines;
		private List<string> topRowGrouped;
		private string[] topRow;
		private List<string> results;
		private FileHandler fh;
		
		public Parser(string iFile, string oFile)
		{
			
			// CurrentCulture is changed to make sure decimals are printed as x.xx instead of x,xx
			// (Messes up csv-file import into excel, openoffice etc.)
			// Yes, it's a hack but it works for now.
			//Thread.CurrentThread.CurrentCulture = new CultureInfo("sv-SE");

			inputFile = iFile;
			outputFile = oFile;
			splitinlines = new List<string>();	
			fh = new FileHandler(inputFile, outputFile);
			numCols = 0;
			idCol = 0;	
			classCol = 1;	
			qColBegin = 2;
			//cmpLen = 3; // compare length of 3 only valid for questions with 4 characters.
			delimString = "\t";
			rowCount = 0;
			cmIndex = 0;
			//delimString = ",";
			//delimString = ":";
		}
		
		public int GetNumCols() 
		{
			return numCols;
		}
		
		private Dictionary<string, int> GetClassSizes()
		{
			return classSizes;
		}
		
		
		public void SetInputFile(string f)
		{
			inputFile = f;
		}
		
		public void SetOutputFile(string f)
		{
			outputFile = f;
		}
		
		public void WriteToFile(string textToWrite, string fileToWrite)
		{
			fh.WriteToFile(textToWrite);
		}
		
		
		/*
		 * Puts each line in the input file in a list, making sure no empty lines are added
		 * (Elvis was here)
		 * If numCols turns out to be less than three (id, class and at least 1 question group)
		 *  an exception is thrown.
		 */
		private void ReadFromFile(string inputfile)
		{
			fh.ReadFromFile(ref splitinlines);
			topRow = splitinlines[0].Split(new char[] {delimString[0]});
			
			// Check number of columns in input file.
			foreach(String s in topRow)
				++numCols;
			if(numCols < 3){
				throw new System.Exception("Error in input file");				
			}
		}
		
		/*
		 * Parses the file
		 */
		public void Execute()
		{
			// List that contains question groups (SK1A/SK1B = SK1X and so on...)
			topRowGrouped = new List<string>();
			
			// Dictionary to keep track of class sizes (For percentage calculation).
			classSizes = new Dictionary<string, int>();
			
			//string currClass = String.Empty; // To keep track of current class (But never used?!)
			//int rowCount = 0;
			
			// Read lines from file into List splitinlines.
            // Also create array topRow which contains the first row of the file, split into strings.
            ReadFromFile(inputFile);
			
			// "Calculate" number of rows (and columns)
            int numRows = splitinlines.Count;
			//int numCols = topRow.Length;
			
			// Create top row with question groups
			/*
			 * (topRow[i].Length - 1) + "X" is used so that all questions belonging
			 * to the same group gets lumped together. That is, SK10A and SK10B
			 * becomes SK10X.
			 */
			topRowGrouped.Add(topRow[idCol]);
			topRowGrouped.Add(topRow[classCol]);
			for(int i = qColBegin; i < numCols; ++i)
			{
				if(!topRowGrouped.Contains(topRow[i].Substring(0, (topRow[i].Length - 1)) + "X"))
				{
					topRowGrouped.Add(topRow[i].Substring(0, (topRow[i].Length - 1)) + "X");
					topRowGrouped.Add("%");
				}
			}

			/*
			 * Create students
			 */
			cm = new ClassMember[numRows];
			for(int i = 0; i < numRows; ++i)
				cm[i] = new ClassMember();

			/*
			 * Fill student posts with id and class number.
			 * Fill class size dictionary with info.
			 */
			FillStudentPosts(ref splitinlines);
			
			/*
			 * Go through each line with questions
			 */
			GoThroughQuestions();

			// Finally summarize the number of times a student has been 
			// mentioned in each question group.
			foreach(ClassMember c in cm)
			{
				c.SumInstances();
			}
		}
	
		
		/*
		* Fill student posts with id and class number.
		* Fill class size dictionary with info.
		*/
		void FillStudentPosts(ref List<string> l)
		{
			foreach(string str in l)
			{
				if(str.Length != 0)
				{
					string[] currLineSplit = str.Split(new char[] {delimString[0]});
					/*
					 * Only do this after the first line.
					 */
					if(rowCount > 0)
					{
						cm[cmIndex].StudentId = currLineSplit[idCol];
						cm[cmIndex].ClassId = currLineSplit[classCol];
						++cmIndex;

						// Store size of each class for percentage calculation
						if(classSizes.ContainsKey(currLineSplit[classCol]))
						{
							classSizes[currLineSplit[classCol]] += 1;
						} else {
							classSizes.Add(currLineSplit[classCol], 1);
						}
					}
					++rowCount;
				}
			}
		}
		
		
		/*
		 * Go through each line with questions
		 */
		void GoThroughQuestions()
		{
			foreach(string str in splitinlines)
			{
				if(str.Length != 0)
				{
					string[] currLineSplit = str.Split(new char[] {delimString[0]});
					foreach(ClassMember c in cm)
					{
						/*
						 * Does the class match the current students class id?
						 */
						if(currLineSplit[classCol].Equals(c.ClassId))
						{
							for(int i = qColBegin; i < numCols; ++i)
							{
								/*
								 * Does the answer id match current students id?
								 * Also make sure a student cannot write down him/herself.
								 */
								if(currLineSplit[i].Equals(c.StudentId) && 
								   !currLineSplit[idCol].Equals(c.StudentId) && currLineSplit[idCol].Length != 0)
								{
									c.AddToInstance(topRow[i]);
								}
							}
						}
					}
				}
			}
		}

		
		/*
		 * Creates the correct string for the supplied question group qGroup.
		 *  - sr - A dictionary containing the number of times the supplied student c
		 * 			has been mentioned in each question group.
		 *  - cs - A dictionary containing the sizes of each class.
		 */
		private string CalculateQuestionGroup(string qGroup, ClassMember c)
		{
			Dictionary<string, int> sr = c.GetSumInstances();
			Dictionary<string, int> cs = GetClassSizes();
			StringBuilder sb = new StringBuilder();
			
			/*
			 * If the summarized instances dictionary contains the supplied question group (qGroup),
			 * then calculate the percentage of people in the students class that mentioned him/her.
			 * The resulting string will contain the number of times the student was mentioned
			 *  and the percentage separated by tabs.
			 * 
			 *  - sr[qGroup] - Number of times student was mentioned in this question group
			 *  - cs[c.GetClassId()] - The number of people in student c's class.
			 *  - percentage - The result of (sr[qGroup] / (cs[c.classId] - 1)) * 100
			 *  (cs[c.classId] -1 because a student cannot pick him/herself)
			 */			
			if(sr.ContainsKey(qGroup))
			{
				float percentage = ((float)sr[qGroup] / ((float)cs[c.ClassId] -1)) * 100;
				//sb.Append(sr[qGroup] + delimString + "\"" + string.Format("{0:0.00}", percentage) + "\"" + delimString);
				sb.Append(sr[qGroup] + delimString + 
				          string.Format("{0:0.00}", percentage) + delimString);
			}
			/*
			 * Student was never mentioned in the supplied question group. add 0 in both instances and percentage
			 * to the result string.
			 */ 
			else 
			{
				//sb.Append("\"0\"" + delimString + "\"0\"" + delimString);
				sb.Append("0" + delimString + "0" + delimString);
			}
			
			return sb.ToString();
		}
		
		
		/*
		 * Returns the result in a list of strings to be printed/written to file.
		 * <Quotation marks are added around each cell contents since
		 * in Swedish for instance, 10.5 is written as 10,5 which would confuse
		 * Excel/OpenOffice when importing the file.> <-- Not anymore. Using tabs again
		 */		
		public List<string> GetResults()
		{
			StringBuilder sb = new StringBuilder();
			results = new List<string>();
			
			// The top row
			foreach(string str in topRowGrouped)
				//sb.Append("\"" + str + "\"" + delimString[0]);
				sb.Append(str + delimString[0]);
			sb.Append(Environment.NewLine);
			
			/*
			 * Student by student, go through each question group and append the
			 * string returned by CalculateQuestionGroup() to the result string.
			 * Finally add the result string to the string list and return it to caller.
			 */
			foreach(ClassMember c in cm)
			{
				if(c.StudentId != "notset")
				{
					//sb.Append("\"" + c.StudentId + "\"" + delimString[0] + "\"" + c.ClassId + "\"" + delimString[0]);
					sb.Append(c.StudentId + delimString[0] + c.ClassId + delimString[0]);
					for(int i = qColBegin; i < topRowGrouped.Count; i += 2)
					{
						sb.Append(CalculateQuestionGroup(topRowGrouped[i], c));
					}
					sb.Append(Environment.NewLine);
				}
			}
			results.Add(sb.ToString());
			return results;
		}

	}
}

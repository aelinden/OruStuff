/*
 * Parser.cs
 * 
 * This class is responsible for parsing the input file.
 * 
 * Methods:
 * - GetClassSizes() : Returns sizes of classes
 * - SetInputFile(string s1) : Sets the file to parse from.
 * - Execute() : Parses the file and returns a ClassMember array.
 * - WriteToFile(string s1, string s2) : Writes the string s1 into file s2.
 * - ReadFromFile(string s1) : Reads from file s1 and splits up contents properly.
 * - GetResults() : Returns the results of parsing as a list.
 * - CalculateQuestionGroup(string, ClassMember) : Calculates percentage of possible nominations.
 * - FillStudentPosts(List<string>) : Fills student posts with id and class.
 * - CalculateClassNomAverage(string s1, string s2) : Calculates average nomination value for qGroup s1 in class s2.
 * - CalculateClassSpread(string s1, string s2, double d1) : Calculates standard deviation for question group s1 in class s2.
 * - CalculateStudentDiff(string s1, string s2, double d1, double d2) : Calculates difference for student s2 in question group s1.
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
	/*
	 * This class is responsible for most of the work. It should really
	 * be split up into smaller chunks at some point.
	 */
	public class Parser
	{
		private int numCols; // Number of columns in the file.
		private int idCol;	// The column of the member id
		private int classCol;	// The column of the class id
		private int qColBegin;	// Column where questions start
		private int numRows;  // Number of rows in the input file
		private int cmIndex;   // Used to index class member array. Replace with foreach()?

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
			
			/* CurrentCulture is changed to make sure decimals are printed as x.xx instead of x,xx
			 * (Messes up csv-file import into excel, openoffice etc.)
			 * Yes, it's a hack but it works for now.
			 * Thread.CurrentThread.CurrentCulture = new CultureInfo("sv-SE");
			 * 
			 * 100313 - Ignore above comment. Using tabs again which is just easier.
			 * CSV sucks monkey nuts (And you can quote me on that).
			 */ 

			inputFile = iFile;
			outputFile = oFile;
			splitinlines = new List<string>();	
			fh = new FileHandler(inputFile, outputFile);
			classCol = 1;	
			qColBegin = 2;
			delimString = "\t";
		}
		
		public uint GetCols(){
			return (uint)numCols;
		}
		
		public uint GetRows() {
			return (uint)numRows;
		}
		
		private Dictionary<string, int> GetClassSizes()
		{
			return classSizes;
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
						
			/*
			 *  Read lines from file into List splitinlines.
             * Also create array topRow which contains the first row of the file, split into strings.
             */
            ReadFromFile(inputFile);
			
			// "Calculate" number of rows (and columns)
            int numRows = splitinlines.Count;
			
			/*
			 *  Create top row with question groups
			 *
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
					
					// 100315 - For class nomination average
					topRowGrouped.Add("Class Average");
					// 100315 - For class spread (Standard deviation?)
					topRowGrouped.Add("Spread");
					// 100315 - For student difference
					topRowGrouped.Add("Difference");
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
			
			/*
			 * Finally summarize the number of times a student has been 
			 * mentioned in each question group.
			 */ 
			foreach(ClassMember c in cm)
			{
				c.SumInstances();
			}
		}
	
		
		/*
		* Fill student posts with id and class number.
		* Fill class size dictionary with info.
		*/
		private void FillStudentPosts(ref List<string> l)
		{
			foreach(string str in l)
			{
				if(str.Length != 0)
				{
					string[] currLineSplit = str.Split(new char[] {delimString[0]});
					/*
					 * Only do this after the first line.
					 */
					if(numRows > 0)
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
					++numRows;
				}
			}
		}
		
		
		/*
		 * Go through each line with questions
		 * 
		 * 100313 - Wow, this function looks horrible.
		 * Must rewrite it at some point.
		 */
		private void GoThroughQuestions()
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
									
									/*
									 * Add number of nomination per question and class for average calc
									 * FIX!
									 */
									
								}
							}
						}
					}
				}
			}
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
			double average;
			double spread;
			double diff;
			
			// The top row
			foreach(string str in topRowGrouped)
				// 100315 - Class average nomination
				sb.Append(str + delimString[0]);
			
			// 100314 - New!
			sb.Append("Class size" + delimString[0]);
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
					sb.Append(c.StudentId + delimString[0] + c.ClassId + delimString[0]);
					for(int i = qColBegin; i < topRowGrouped.Count; i += 5) // <-- WAS 2! 5 for nomination, percentage, avg, spread, diff
					{
						sb.Append(CalculateQuestionGroup(topRowGrouped[i], c));
						
						// 100315 - New feature, add average nomination value per question and class
						average = CalculateClassNomAverage(topRowGrouped[i], c.ClassId);
						sb.Append(string.Format("{0:0.00}", average) + delimString);
						
						// 100315 - New feature, add class spread
						spread = CalculateClassSpread(topRowGrouped[i], c.ClassId, average);
						sb.Append(string.Format("{0:0.00}", spread) + delimString);
						
						// 100315 - New feature, student differences
						diff = CalculateStudentDiff(topRowGrouped[i], c.StudentId, average, spread);
						sb.Append(string.Format("{0:0.0000}", diff) + delimString);
					}
						
					// 100314 - New feature, add number of students in class to output
					sb.Append(classSizes[c.ClassId].ToString());
					sb.Append(Environment.NewLine);
				}
			}
			
			results.Add(sb.ToString());
			return results;
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
			
			/*
			 * If student has not been nominated in question group, manually add question group 
			 * and set its value to zero.
			 */
			if(!sr.ContainsKey(qGroup))
				c.ZeroInstance(qGroup);
			float percentage = ((float)sr[qGroup] / ((float)cs[c.ClassId] -1)) * 100;
				sb.Append(sr[qGroup] + delimString + 
				          string.Format("{0:0.00}", percentage) + delimString);
			return sb.ToString();
		}
		
		/*
		 * Returns the average nomination value for question group qGroup in
		 * class classID
		 */
		private double CalculateClassNomAverage(string qGroup, string classID){
			int totalNominations = 0;
			double avg;
			foreach(ClassMember c in cm){
				if(c.ClassId == classID){
					totalNominations += c.GetNominations(qGroup);
				}
			}
			avg = (double)totalNominations / (double)classSizes[classID];
			return avg;
		}
		
		/*
		 * Calculates the spread of the class (Standard deviation?)
		 */
		private double CalculateClassSpread(string qGroup, string classID, double average){
			double nomMinusAvg = 0.0;
			double deviation;
			foreach(ClassMember c in cm){
				if(c.ClassId == classID){
					deviation = Math.Pow((c.GetNominations(qGroup) - average), 2);
					deviation /= (double)(classSizes[c.ClassId] - 1);
					nomMinusAvg += deviation;
				}
			}
			return Math.Sqrt(nomMinusAvg);			
		}
		
		/*
		 * Calculates student differences
		 */
		private double CalculateStudentDiff(string qGroup, string studentID, double average, double spread){
			double nomMinusAvg;
			double diff = 999;
			
			foreach(ClassMember c in cm){
				if(c.StudentId == studentID){
					nomMinusAvg = c.GetNominations(qGroup) - average;
					diff = nomMinusAvg / spread;
				}
			}
			return diff;
		}
				
	}
}

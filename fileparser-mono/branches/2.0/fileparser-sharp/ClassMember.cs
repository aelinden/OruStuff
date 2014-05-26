/*
 * ClassMember.cs
 * 
 * This class represents a student in the input file.
 * 
 * Methods:
 * - 
 */

# region using statements
using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
#endregion


namespace OruSharpReader
{
	public class ClassMember
	{
		private List<string> qList;
		private Dictionary<string, int> qInstances;
		private Dictionary<string, int> sumQuest;
		private string id; // Student id
		private string cId; // Class id
		//private int cmpLen;
		
		public ClassMember()
		{
			qInstances = new Dictionary<string, int>();
			sumQuest = new Dictionary<string, int>();
			//cmpLen = 3; // Length of keys to compare, only valid for 4 character question
			id = "notset"; // Set to "notset" before edited.
		}
		
		/*
		 * AddToInstance either adds the kvp qId (Question) and 1 if qId
		 * had not been entered into qInstances before, or it adds 1 to the
		 * already existing entry.
		 * 
		 * This means a student has been entered n times in question qId.
		 */ 
		public void AddToInstance(string qId)
		{
			if(!qInstances.ContainsKey(qId))
				qInstances.Add(qId, 1);
			else
				qInstances[qId] += 1;
		}
		
		public Dictionary<string, int> ReturnInstances() 
		{
			return qInstances;
		}
		
		// Properties for getting/setting id variable
		public string StudentId
		{
			get { return id; }
			set { this.id = value; }
		}
		
		// Properties for getting/setting classId variable
		public string ClassId
		{
			get { return cId; }
			set { this.cId = value; }
		}

		/*
		 * SumInstances() first creates a list of all questions this student
		 * has answered. It then checks whether the substring beween 0 and cmpLen
		 * exists in out result dictionary. If it does we add the instances of the
		 * whole string from qInstances to the already existing entry in sumQuest.
		 * If it does not exist we create this entry in sumQuest with the substring
		 * as key and qInstance value of the whole string as its value.
		 */
		public void SumInstances()
		{
			qList = new List<string>(qInstances.Keys);
			qList.Sort();
			string stb;
			foreach(string s in qList)
			{
				stb = s.Substring(0, (s.Length - 1)) + "X";
				if(sumQuest.ContainsKey(stb))
				{
					sumQuest[stb] += qInstances[s];
				}
				else 
				{
					sumQuest.Add(stb, qInstances[s]);
				}
			}
		}
		
		/* Returns the dictionary containing the number of times
		 * the student has been mentioned in each question group		 * 
		 */
		public Dictionary<string, int> GetSumInstances() 
		{
			return sumQuest;
		}
	}
}

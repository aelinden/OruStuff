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
	/// <summary>
	/// The classmember represents a student in the input file
	/// </summary>
	public class ClassMember
	{
		private List<string> qList;
		private Dictionary<string, int> qInstances;
		private Dictionary<string, int> sumQuest;
		private string id; // Student id
		private string cId; // Class id
		
		#region Constructor
		public ClassMember()
		{
			qInstances = new Dictionary<string, int>();
			sumQuest = new Dictionary<string, int>();
			id = "notset"; // Set to "notset" before edited.
		}
		#endregion
		
		/// <summary>
		/// AddToInstance either adds the kvp qId (Question) and 1 if qId
		/// had not been entered into qInstances before, or it adds 1 to the
		/// already existing entry.
		/// This means a student has been entered n times in question qId.
		/// </summary>
		/// <param name="qId">
		/// A <see cref="System.String"/>
		/// The question ID
		/// </param>
		public void AddToInstance(string qId)
		{
			if(!qInstances.ContainsKey(qId))
				qInstances.Add(qId, 1);
			else
				qInstances[qId] += 1;
		}
		
		#region Properties
		public string StudentId
		{
			get { return id; }
			set { this.id = value; }
		}
		
		public string ClassId
		{
			get { return cId; }
			set { this.cId = value; }
		}
		#endregion
				 
		/// <summary>
		/// SumInstances() first creates a list of all questions this student
		/// has answered. It then checks whether the substring beween 0 and cmpLen
		/// exists in out result dictionary. If it does we add the instances of the
		/// whole string from qInstances to the already existing entry in sumQuest.
		/// If it does not exist we create this entry in sumQuest with the substring
		/// as key and qInstance value of the whole string as its value.
		/// </summary>
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
		
		/// <summary>
		/// Returns the dictionary containing the number of times
		/// the student has been nominated in each question group. 
		/// </summary>
		/// <returns>
		/// A <see cref="Dictionary<System.String, System.Int32>"/>
		/// </returns>
		public Dictionary<string, int> GetSumInstances() 
		{
			return sumQuest;
		}
		
		/// <summary>
		/// Sets the number of nominations of a question group
		/// to zero. Used if a student has not been nominated in qGroup.
		/// </summary>
		/// <param name="qGroup">
		/// A <see cref="System.String"/>
		/// Question group student has not been nominated in.
		/// </param>
		public void ZeroInstance(string qGroup){
			sumQuest.Add(qGroup, 0);
		}
		
		/// <summary>
		/// Returns the nomination number for question group qGroup
		/// </summary>
		/// <param name="qGroup">
		/// A <see cref="System.String"/>
		/// Question group the student has been nominated in.
		/// </param>
		/// <returns>
		/// A <see cref="System.Int32"/>
		/// </returns>
		public int GetNominations(string qGroup){
			if(!sumQuest.ContainsKey(qGroup))
				return 0;
			return sumQuest[qGroup];
		}
	}
}

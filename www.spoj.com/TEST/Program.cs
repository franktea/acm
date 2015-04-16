using System;

namespace TEST
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			string line = Console.ReadLine ();
			while (line != null && line != "42") 
			{
				Console.WriteLine (line);
				line = Console.ReadLine ();
			}
		}
	}
}

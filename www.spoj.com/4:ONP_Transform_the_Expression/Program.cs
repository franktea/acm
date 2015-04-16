using System;
using System.Text;

namespace ONP_Transform_the_Expression
{
	class MainClass
	{
		static int Priority(char c)
		{
			switch(c)
			{
			case '+': case '-':
				return 1; 
			case '*': case '/': case '^':
				return 2; 
			case '(': case ')':
				return 3; 
			};

			return -1;
		}

		static void Infix2Postfix(string str, StringBuilder result)
		{
			StringBuilder str_stack = new StringBuilder ();
			foreach(char c in str)
			{
				if(c >= 'a' && c <= 'z')
				{
					result.Append (c);
				}
				else if(c == '(')
				{
					str_stack.Append(c);
				}
				else if(c == ')')
				{
					//char s = str_stack.back();
					char s = str_stack[str_stack.Length - 1];
					str_stack.Remove (str_stack.Length - 1, 1);
					do {
						result.Append(s);
						s = str_stack[str_stack.Length - 1];
						str_stack.Remove (str_stack.Length - 1, 1);
					} while(s != '(');
				}
				else // + = * / ^
				{
					if(str_stack.Length == 0 || str_stack[str_stack.Length-1] == '(' ||
						Priority(c) > Priority(str_stack[str_stack.Length-1]))
					{
						str_stack.Append (c);
					}
					else
					{
						result.Append (c);
						result.Append(str_stack[str_stack.Length-1]);
						str_stack.Remove (str_stack.Length - 1, 1);
					}
				}
			}
			while(str_stack.Length > 0)
			{
				result.Append(str_stack[str_stack.Length-1]);
				str_stack.Remove (str_stack.Length - 1, 1);
			}
		}

		public static void Main (string[] args)
		{
			int lines = int.Parse (Console.ReadLine ());
			while (lines-- > 0) 
			{
				string line = Console.ReadLine ();
				StringBuilder sb = new StringBuilder ();
				Infix2Postfix (line, sb);
				Console.WriteLine (sb.ToString ());
			}
		}
	}
}

using System;
using System.Text;

namespace PALIN_The_Next_Palindrome
{
    class MainClass
    {
        static void Inc(StringBuilder sb, int pos)
        {
            while (pos >= 0)
            {
                int val = (int)Char.GetNumericValue(sb[pos]);
                sb[pos] = Convert.ToChar(++val % 10 + '0');
                if (val < 10)
                    return;

                // val > 10
                --pos;
            }
            sb.Insert(0, "1");
        }

        static bool IsPalindrome(StringBuilder sb)
        {
            for (int i = 0; i <= sb.Length/2; ++i)           
                if (sb[i] != sb[sb.Length - 1 - i])
                    return false;
            return true;
        }

        static bool LeftGreater(StringBuilder sb)
        {
            for (int i = sb.Length / 2 - 1; i >= 0; --i)
            {
                if (sb[i] > sb[sb.Length - 1 - i])
                    return true;
                if (sb[i] < sb[sb.Length - 1 - i])
                    return false;
            }
            return false;
        }

        static void FindNext(StringBuilder sb)
        {
            if(! LeftGreater(sb))
            {
                int pos = (sb.Length % 2 != 0) ? sb.Length / 2 : sb.Length / 2 - 1;
                Inc(sb, pos);
            }

            for (int i = 0; i <= sb.Length / 2 - 1; ++i)
            {
                sb[sb.Length - 1 - i] = sb[i];
            }
        }

        public static void Main(string[] args)
        {
            int lines = int.Parse(Console.ReadLine());
            StringBuilder sb = new StringBuilder();
            while (lines-- > 0)
            {
                string line = Console.ReadLine();
                sb.Clear();
                sb.Append(line);
                if (IsPalindrome(sb))
                    Inc(sb, sb.Length - 1);
                if (!IsPalindrome(sb))
                    FindNext(sb);
                Console.WriteLine(sb.ToString());
            }
        }
    }
}

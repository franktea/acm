using System;

namespace PRIME1_Prime_Generator
{
	class MainClass
	{
        static bool IsPrime(int n) 
        {
            if (n <= 3)
                return n > 1;
            else if (n % 2 == 0 || n % 3 == 0)
                return false;
            else 
            {
                for (int i = 5; i * i <= n; i += 6) {
                    if (n % i == 0 || n % (i + 2) == 0) {
                        return false;
                    }
                }
                return true;
            }
        }

		public static void Main (string[] args)
		{
			int case_count = int.Parse(Console.ReadLine());
			for (int i = 0; i < case_count; ++i)
			{
				string[] tokens = Console.ReadLine().Split();
				int a = int.Parse(tokens[0]);
				int b = int.Parse(tokens[1]);
				if (i > 0)
					Console.WriteLine("");
				for (int x = a; x <= b; ++x)
				{
					if (IsPrime(x))
						Console.WriteLine(x);
				}
			}
		}
	}
}

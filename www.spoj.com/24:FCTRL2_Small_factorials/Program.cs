using System;
using System.Numerics;

namespace FCTRL2_Small_factorials
{
    class MainClass
    {
        static BigInteger BigFactorial(BigInteger x)
        {
            if (x < 0)
                return BigFactorial(-x);
            else if (x <= 1)
                return x;
            else
                return x * BigFactorial(--x);
        }

        public static void Main(string[] args)
        {
            int lines = int.Parse(Console.ReadLine());
            while (lines-- > 0)
            {
                BigInteger bi = BigInteger.Parse(Console.ReadLine());
                Console.WriteLine(bi.ToString());
            }
        }
    }
}

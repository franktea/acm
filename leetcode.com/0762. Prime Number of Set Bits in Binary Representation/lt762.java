import java.util.*;

class Solution {
	public static int Helper(int number)
	{
		BitSet bit = BitSet.valueOf(new long[] {number});
		int n = bit.cardinality();
		if(n == 2 || n == 3 || n == 5 || n == 7 || n == 11 || n == 13 || n == 17 || n == 19
				|| n == 23 || n == 29 || n == 31)
		{
			return 1;
		}
		return 0;
	}
    public int countPrimeSetBits(int L, int R) {
    	int ret = 0;
    	for(int i = L; i <= R; ++i)
    	{
    		ret += Helper(i);
    	}
    	return ret;
    }
}

public class lt762 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}

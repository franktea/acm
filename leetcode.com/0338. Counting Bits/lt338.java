import java.util.*;

class Solution {
    public int[] countBits(int num) {
    	int[] ret = new int[num+1];
    	for(int i = 0; i <= num; ++i)
    	{
    		BitSet b = BitSet.valueOf(new long[] {i});
    		ret[i] = b.cardinality();
    	}
    	return ret;
    }
}

public class lt338 {
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}

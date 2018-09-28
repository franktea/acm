import java.util.*;

class Solution {
    public boolean hasAlternatingBits(int n) {
        	BitSet bit = BitSet.valueOf(new long[] {n});
        	int last = 0;
        	for(int i = 0; i < 32; ++i)
        		if(bit.get(i))
        			last = i;

        	for(int i = 1; i <= last; ++i)
        	{
        		if(bit.get(i-1) == bit.get(i))
        			return false;
        	}
        	
        	return true;
    }
}

public class lt693 {

	public static void main(String[] args) {
		System.out.println(new Solution().hasAlternatingBits(7));
	}

}

import java.util.*;

class Solution {
    public boolean isPowerOfTwo(int n) {
       BitSet bs = BitSet.valueOf(new long[] {n});
       return bs.cardinality() == 1;
    }
}

public class lt231 {
	public static void main(String[] args) {
	}
}

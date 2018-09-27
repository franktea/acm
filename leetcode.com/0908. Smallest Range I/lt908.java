import java.util.Collections;
import java.util.Arrays;
import java.lang.Math;

class Solution {
    public int smallestRangeI(int[] A, int K) {
    	Integer numbers[] = new Integer[A.length];
    	for(int i = 0; i < A.length; ++i)
    		numbers[i] = A[i];
        int min = (int)Collections.min(Arrays.asList(numbers));
        int max = (int)Collections.max(Arrays.asList(numbers));
        K = Math.abs(K);
        if(max - min <= 2*K)
        	return 0;
        else
        	return max-min-2*K;
    }
}

public class lt908 {

	public static void main(String[] args) {
		Solution s = new Solution();
		System.out.println(s.smallestRangeI(new int[] {1, 2, 3, 4, 8}, 3));
	}

}

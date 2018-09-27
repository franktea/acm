
class Solution {
    public int peakIndexInMountainArray(int[] A) {
    	for(int i = 1; i < A.length - 1; ++i)
    	{
    		if(A[i] > A[i-1] && A[i] > A[i+1])
    			return i;
    	}
    	
    	return -1;
    }
}

public class lt852 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}

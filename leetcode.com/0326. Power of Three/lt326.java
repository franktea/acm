import java.util.*;

class Solution {
    public boolean isPowerOfThree(int n) {
    	if(n <= 0)
    		return false;
    	long l = n;
    	long i = 1;
    	while(i < l)
    	{
    		i *= 3;
    	}
    	return i == l;
    }
}

public class lt326 {

	public static void main(String[] args) {
		System.out.println(new Solution().isPowerOfThree(59048));
	}

}

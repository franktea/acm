
class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        	int ret = 0;
        	int max = 0;
        	for(int i = 0; i < nums.length; ++i)
        	{
        		if(nums[i] == 1)
        		{
        			++max;
        			if(max > ret)
        				ret = max;
        		}
        		else
        		{
        			max = 0;
        		}
        	}
        	return ret;
    }
}

public class lt485 {
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}

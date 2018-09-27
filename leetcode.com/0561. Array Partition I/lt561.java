import java.util.Arrays;

class Solution {
    public int arrayPairSum(int[] nums) {
        Arrays.sort(nums);
        int ret = 0;
        for(int i = 0; i < nums.length; i += 2)
        {
        	ret += nums[i];
        }
        return ret;
    }
}

public class lt561 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}

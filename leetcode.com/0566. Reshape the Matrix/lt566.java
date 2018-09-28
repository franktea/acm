import java.util.*;

class Solution {
    public int[][] matrixReshape(int[][] nums, int r, int c) {
        	if(nums.length == 0)
        		return nums;
        	if(nums.length*nums[0].length != r*c)
        		return nums;
        	
        	int[][] ret = new int[r][c];
        	for(int i = 0; i < r*c; ++i)
        	{
        		int x = i % nums[0].length;
        		int y = i / nums[0].length;
        		int x2 = i % c;
        		int y2 = i / c;
        		ret[y2][x2] = nums[y][x];
        	}
        	return ret;
    }
}

public class lt566 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}

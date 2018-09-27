
class Solution {
    public int projectionArea(int[][] grid) {
        int ret = 0;
        for(int i = 0;  i < grid.length; ++i)
        {
        	int max = 0;
        	for(int j = 0; j < grid[i].length; ++j)
        	{
        		if(grid[i][j] > 0)
        			++ ret;
        		if(grid[i][j] > max)
        			max = grid[i][j];
        	}
        	
        	ret += max;
        }
        
        for(int j = 0; j < grid[0].length; ++j)
        {
        	int max = 0;
        	for(int i = 0; i < grid.length; ++i)
        		if(grid[i][j] > max)
        			max = grid[i][j];
        	
        	ret += max;
        }
        
        return ret;
    }
}

public class lt883 {

	public static void main(String[] args) {
		Solution s = new Solution();
		int[][] grid = {{2,2,2},{2,1,2},{2,2,2}};
		System.out.println(s.projectionArea(grid));
	}

}

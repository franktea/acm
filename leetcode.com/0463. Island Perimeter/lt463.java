import java.util.*;

class Solution {
    public int islandPerimeter(int[][] grid) {
    	if(grid.length == 0)
    		return 0;
    	
    	int[] dy = {-1, 0, 1, 0};
    	int[] dx = {0, 1, 0, -1};
    	
    	int ret = 0;
        for(int i = 0; i < grid.length; ++i)
        {
        	for(int j = 0; j < grid[i].length; ++j)
        	{
        		if(grid[i][j] == 0)
        			continue;
        		
        		for(int index = 0; index < 4; ++index)
        		{
        			int x = j + dx[index];
        			int y = i + dy[index];
        			if(x < 0 || x >= grid[0].length || y < 0 || y >= grid.length
        					|| grid[y][x] == 0)
        			{
        				//System.out.format("i=%d, j=%d, x=%d, y=%d\n", i, j, x, y);
        				++ret;
        			}
        		}
        	}
        }
        return ret;
    }
}

public class lt463 {
	public static void main(String[] args) {
		int[][] grid = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
		System.out.println(new Solution().islandPerimeter(grid));
	}

}

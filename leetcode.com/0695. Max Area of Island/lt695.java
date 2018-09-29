import java.util.*;

class Solution {
    public int maxAreaOfIsland(int[][] grid) {
    	if(grid.length <= 0)
    		return 0;
    	
    	boolean[][] visited = new boolean[grid.length][grid[0].length];
    	for(int i = 0; i < visited.length; ++i)
    		Arrays.fill(visited[i], false);
    	
    	int ret = 0;
    	for(int i = 0; i < grid.length; ++i)
    	{
    		for(int j = 0; j < grid[0].length; ++j)
    		{
    			if(grid[i][j] == 1 && !visited[i][j])
    			{
    				int area = dfs(grid, visited, j, i);
    				if(area > ret)
    					ret = area;
    			}
    		}
    	}
    	return ret;
    }
    
    static int dfs(int[][] grid, boolean[][] visited, int x, int y)
    {
    	visited[y][x] = true;
    	int[] dx = {0, 1, 0, -1};
    	int[] dy = {-1, 0, 1, 0};
    	int ret = 0;
    	for(int i = 0; i < 4; ++i)
    	{
    		int x2 = dx[i] + x;
    		int y2 = dy[i] + y;
    		if(x2 < 0 || x2 >= grid[0].length || y2 < 0 || y2 >= grid.length)
    			continue;
    		
    		if(grid[y2][x2] == 0 || visited[y2][x2])
    			continue;
    		ret += dfs(grid, visited, x2, y2);
    	}
    	return ret + 1;
    }
}

public class lt695 {
	public static void main(String[] args) {
		int[][] grid = {{1,1,0,0,0},{1,1,0,0,0},{0,0,0,1,1},{0,0,0,1,1}};
		System.out.println(new Solution().maxAreaOfIsland(grid));
	}
}

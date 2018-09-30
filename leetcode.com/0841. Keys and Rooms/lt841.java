import java.util.*;

//bfs
class Solution {
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
    	boolean[] visited = new boolean[rooms.size()];
    	Arrays.fill(visited, false);
    	Queue<Integer> queue = new LinkedList<>();
    	visited[0] = true;
    	Iterator<Integer> it = rooms.get(0).iterator(); 
    	while(it.hasNext())
    	{
    		int i = it.next();
    		if(!visited[i])
    			queue.add(i);
    	}
    	while(!queue.isEmpty())
    	{
    		int index = queue.remove();
    		visited[index] = true;
    		it = rooms.get(index).iterator();
    		while(it.hasNext())
    		{
    			int i = it.next();
    			if(!visited[i])
    				queue.add(i);
    		}
    	}
    	
    	for(boolean b: visited)
    	{
    		if(!b)
    			return false;
    	}
    	return true;
    }
}

public class lt841 {
	public static void main(String[] args) {
	}
}

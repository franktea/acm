import java.util.*;

class Solution {
    public int leastBricks(List<List<Integer>> wall) {
    	Map<Integer, Integer> counts = new HashMap<>();
    	for(List<Integer> l: wall)
    	{
    		int sum = 0;
    		Iterator<Integer> it = l.iterator();
    		while(it.hasNext())
    		{
    			int i = it.next();
    			sum += i;
    			if(counts.containsKey(sum))
    				counts.put(sum, counts.get(sum)+1);
    			else
    				counts.put(sum, 1);
    		}
    		counts.remove(sum); // 把最后一个删掉。怎么才能不把最后一个放进去？
    	}
    	int min = wall.size();
    	for(Map.Entry<Integer, Integer> me: counts.entrySet())
    	{
    		int v = wall.size() - me.getValue();
    		if(v < min)
    			min = v;
    	}
    	return min;
    }
}

public class lt554 {

	public static void main(String[] args) {
	}
}

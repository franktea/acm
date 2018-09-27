import java.util.*;

class Solution {
    public String[] uncommonFromSentences(String A, String B) {
        Map<String, Integer> map1 = new HashMap<String, Integer>();
        Map<String, Integer> map2 = new HashMap<String, Integer>();
        
        for(String str: A.split(" "))
        {
        	if(map1.containsKey(str))
        		map1.put(str, map1.get(str) + 1);
        	else
        		map1.put(str, 1);
        }
        
        for(String str: B.split(" "))
        {
        	if(map2.containsKey(str))
	        	map2.put(str, map2.get(str) + 1);
        	else
        		map2.put(str, 1);
        }
        
        Set<String> ret = new HashSet<String>();
        for(Map.Entry<String, Integer> entry: map1.entrySet())
        {
        	String key = entry.getKey();
        	int value = entry.getValue();
        	if(value == 1 && !map2.containsKey(key))
        		ret.add(key);
        }
        
        for(Map.Entry<String, Integer> entry: map2.entrySet())
        {
        	String key = entry.getKey();
        	int value = entry.getValue();
        	if(value == 1 && !map1.containsKey(key))
        		ret.add(key);
        }
        
        return ret.toArray(new String[0]);
    }
}

public class lt884 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}

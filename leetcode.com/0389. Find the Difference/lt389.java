import java.util.*;

class Solution {
    public char findTheDifference(String s, String t) {
        	Map<Character, Integer> m1 = new HashMap<>();
        	for(char c: s.toCharArray())
        	{
        		if(m1.containsKey(c))
        			m1.put(c, m1.get(c)+1);
        		else
        			m1.put(c, 1);
        	}
        	
        	for(char c: t.toCharArray())
        	{
        		if(! m1.containsKey(c))
        			return c;
        		else
        			if(m1.get(c) > 1)
        			{
        				m1.put(c, m1.get(c)-1);
        			}
        			else
        			{
        				m1.remove(c);
        			}
        	}
        	
        	return t.charAt(0); // impossible
    }
}

public class lt389 {
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}

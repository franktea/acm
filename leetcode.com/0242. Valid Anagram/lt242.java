import java.util.*;

class Solution {
    public boolean isAnagram(String s, String t) {
    	if(s.length() != t.length())
    		return false;
    	
        Map<Character, Integer> m = new HashMap<>();
        for(char c: s.toCharArray())
        {
        	if(m.containsKey(c))
        		m.put(c, m.get(c)+1);
        	else
        		m.put(c, 1);
        }
        
        for(char c: t.toCharArray())
        {
        	if(!m.containsKey(c))
        		return false;
        	if(m.get(c) > 1)
        		m.put(c, m.get(c)-1);
        	else
        		m.remove(c);
        }
        
        return true;
    }
}

public class lt242 {
	public static void main(String[] args) {
	}
}

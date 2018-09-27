import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;

class Solution {
    public String[] findWords(String[] words) {
        Map<Character, Integer> m = new HashMap<Character, Integer>();
        String s = "QWERTYUIOPqwertyuiop";
        for(char c: s.toCharArray())
        {
        	m.put(c, 0);
        }
        s = "ASDFGHJKLasdfghjkl";
        for(char c: s.toCharArray())
        {
        	m.put(c, 1);
        }
        s = "ZXCVBNMzxcvbnm";
        for(char c: s.toCharArray())
        {
        	m.put(c, 2);
        }
        
        List<String> l = new ArrayList<String>();
        for(String str: words)
        {
        	if(str.isEmpty())
        		continue;
        	
        	int v = m.get(str.charAt(0));
        	boolean same = true;
        	for(char c: str.toCharArray())
        	{
        		if(m.get(c) != v)
        		{
        			same = false;
        			break;
        		}
        	}
        	if(same)
        		l.add(str);
        }
        
        return l.toArray(new String[0]);
    }
}

public class lt500 {
	public static void main(String[] args) {
	}

}

import java.util.*;

class Solution {
	class Item
	{
		char c;
		int index;

		Item(char ch, int i)
		{
			c = ch;
			index = i;
		}
	}
	
    public String customSortString(String S, String T) {
        Map<Character, Integer> m = new HashMap<>();
        for(int i = 0; i < S.length(); ++i)
        {
        	m.put(S.charAt(i), i);
        }
        
        List<Item> l = new ArrayList<>();
        for(char c: T.toCharArray())
        {
        	if(m.containsKey(c))
        	{
        		l.add(new Item(c, m.get(c)));
        	}
        	else
        	{
        		l.add(new Item(c, S.length()));
        	}
        }
        
        l.sort((lhs, rhs)->{ return lhs.index - rhs.index; });
        StringBuilder sb = new StringBuilder();
        for(Item i: l)
        {
        	sb.append(i.c);
        }
        return sb.toString();
    }
}

public class lt791 {
	public static void main(String[] args) {
		System.out.println(new Solution().customSortString("abcd", "dcde"));
	}
}

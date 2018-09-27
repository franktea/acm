import java.util.HashSet;
import java.util.Set;

class Solution {
    public int uniqueMorseRepresentations(String[] words) {
    	String morse[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    	Set<String> duplicates = new HashSet<String>();
    	for(String str: words)
    	{
    		String tmp = "";
    		for(char c: str.toCharArray())
    		{
    			tmp += morse[c-'a'];
    		}
    		duplicates.add(tmp);
    	}
    	return duplicates.size();
    }
}

public class lt804 {

	public static void main(String[] args) {
		String[] words = {"gin", "zen", "gig", "msg"};
		Solution s = new Solution();
		System.out.println(s.uniqueMorseRepresentations(words));
	}

}

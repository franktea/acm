
class Solution {
    public int numJewelsInStones(String J, String S) {
    	int ret = 0;
    	for(int i = 0; i < S.length(); ++i)
    	{
    		char c = S.charAt(i);
    		if(J.indexOf(c) >= 0)
    			++ret;
    	}
    	return ret;
    }
}

public class lt771 {

	public static void main(String[] args) {
		String J = "aA";
		String S = "aAAbbbb";
		Solution sl = new Solution();
		System.out.println(sl.numJewelsInStones(J, S));
	}

}

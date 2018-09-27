
class Solution {
    public int[] numberOfLines(int[] widths, String S) {
        int line = 0;
        int w = 0;
        for(char c: S.toCharArray())
        {
        	if(w + widths[c-'a'] > 100)
        	{
        		++line;
        		w = widths[c-'a'];
        	}
        	else
        	{
        		w += widths[c-'a'];
        	}
        }
        return new int[] {line+1, w};
    }
}

public class lt806 {

	public static void main(String[] args) {
		Solution s = new Solution();
		int[] widths = {4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
		String S = "bbbcccdddaaa";
		int[] ret = s.numberOfLines(widths, S);
		System.out.println(ret[0]);
		System.out.println(ret[1]);
	}

}

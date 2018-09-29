import java.util.*;

class Solution {
    public boolean rotateString(String A, String B) {
    	if(A.length() != B.length())
    		return false;
        String s = A + A;
        return s.indexOf(B) >= 0;
    }
}

public class lt796 {
	public static void main(String[] args) {
		System.out.println(new Solution().rotateString("aa", "a"));
	}

}

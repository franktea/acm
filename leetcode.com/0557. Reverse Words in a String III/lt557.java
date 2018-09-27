
class Solution {
    public String reverseWords(String s) {
    	String[] strs = s.split(" ");
    	for(int i = 0; i < strs.length; ++i)
    	{
    		strs[i] = new StringBuilder(strs[i]).reverse().toString();
    	}
    	return String.join(" ", strs);
    }
}

public class lt557 {

	public static void main(String[] args) {
		String s = "Let's take LeetCode contest";
		System.out.println(new Solution().reverseWords(s));
	}

}

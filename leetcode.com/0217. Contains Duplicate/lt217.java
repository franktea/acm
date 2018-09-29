import java.util.*;

class Solution {
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> s = new HashSet<>();
        for(int i: nums)
        {
        	if(s.contains(i))
        		return true;
        	s.add(i);
        }
        return false;
    }
}

public class lt217 {
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}

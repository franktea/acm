import java.util.*;

class Solution {
    public int distributeCandies(int[] candies) {
    	Set<Integer> s = new HashSet<>();
        	for(int i: candies)
        	{
        		s.add(i);
        	}
        	return (s.size() >= candies.length/2) ? candies.length/2 : s.size();
    }
}

public class lt575 {
	public static void main(String[] args) {
	}

}

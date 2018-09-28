import java.util.*;

class Solution {
    public List<String> fizzBuzz(int n) {
    	List<String> ret = new ArrayList<>();
        	for(int i = 1; i <= n; ++i)
        	{
        		String line = "";
                if(i % 15 == 0)
                    line = "FizzBuzz";
        		else if(i % 3 == 0)
        			line = "Fizz";
        		else if(i % 5 == 0)
        			line = "Buzz";
        		else
        			line = String.valueOf(i);
        		
        		ret.add(line);
        	}
        	return ret;
    }
}

public class lt412 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}

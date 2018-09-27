import java.util.Arrays;

class Solution {
    public int[] shortestToChar(String S, char C) {
    	int[] ret = new int[S.length()];
    	int max = S.length(); // magic
    	Arrays.fill(ret, max);
    	
    	int lastc = S.indexOf(C);
    	for(int i = lastc; i < ret.length; ++i)
    	{
    		if(S.charAt(i) == C)
    		{
    			lastc = i;
    			ret[i] = 0;
    			
    			int j = i-1;
    			while(j >= 0 && S.charAt(j) != C)
    			{
    				if(ret[j] > i - j)
    					ret[j] = i - j;
    				--j;
    			}
    		}
    		else
    		{
    			ret[i] = i - lastc;
    		}
    	}
    	
    	return ret;
    }
}

public class lt821 {

}

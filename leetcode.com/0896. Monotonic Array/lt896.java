import java.util.*;

class Solution {
    public boolean isMonotonic(int[] A) {
        	if(A.length <= 2)
        		return true;
        	
        	boolean ret = true;
        	for(int i = 1; i < A.length; ++i) // 检查是否增序
        	{
        		if(A[i] < A[i-1])
        		{
        			ret = false;
        			break;
        		}
        	}
        	
        	if(ret)
        		return true;
        	
        	ret = true;
        for(int i = 1; i < A.length; ++i) // 检查是否降序
        {
        		if(A[i] > A[i-1])
        			return false;
        }
        
        return true;
    }
}

public class lt896 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}

import java.util.List;
import java.util.ArrayList;

class Solution {
	public static boolean isSelfDividing(int number)
	{
		int n = number;
		while(n > 0)
		{
			int a = n % 10;
			if(a == 0)
				return false;
			if(number % a != 0)
				return false;
			n /= 10;
		}
		
		return true;
	}
	
    public List<Integer> selfDividingNumbers(int left, int right) {
        List<Integer> ret = new ArrayList<Integer>();
        for(int i = left; i <= right; ++i)
        {
        	if(isSelfDividing(i))
        		ret.add(i);
        }
        return ret;
    }
}

public class lt728 {

	public static void main(String[] args) {
		Solution s = new Solution();
		System.out.println(s.selfDividingNumbers(1, 50));
	}

}

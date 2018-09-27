
class Solution {
    public int findComplement(int num) {
        int count = 0;
        for(int i = 0; i < 32; ++i)
        {
        	int v = (num >> i) & 1;
        	if(v == 1)
        		count = i;
        }
        
        for(int i = 0; i <= count; ++i)
        {
        	num = num ^ ( 1 << i);
        }
        
        return num;
    }
}

public class lt476 {

	public static void main(String[] args) {
		System.out.println(new Solution().findComplement(1));
	}

}


class Solution {
	public static int getBit(int value, int position)
	{
		return (value >> position) & 1;
	}
	
    public int hammingDistance(int x, int y) {
    	int ret = 0;
        for(int i = 0; i < 32; ++i)
        {
        	int a = getBit(x, i);
        	int b = getBit(y, i);
        	ret += (a ^ b);
        }
        return ret;
    }
}

public class lt461 {

	public static void main(String[] args) {
		Solution s = new Solution();
		System.out.println(s.hammingDistance(1, 4));
	}

}

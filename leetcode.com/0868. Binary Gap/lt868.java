import java.util.*;

class Solution {
    public int binaryGap(int N) {
        List<Integer> l = new ArrayList<>();
        for(int i = 0; i < 32; ++i)
        {
        	int v = (N >> i) & 1;
        	if(v == 1)
        		l.add(i);
        }
        
        int ret = 0;
        for(int i = 1; i < l.size(); ++i)
        {
        	int r = l.get(i) - l.get(i-1);
        	if(r > ret)
        		ret = r;
        }
        
        return ret;
    }
}

public class lt868 {
	public static void main(String[] args) {
	}

}

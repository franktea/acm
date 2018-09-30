import java.util.*;

// 贪心法，先排序，然后再将相同的合并。唯一注意的一点：值为n的最多被合并n次。
// 比如说1 1 1，前两个1可以合并，但是不能合并第三个，否则相矛盾。
// 同理，10 10 10...最多可被合并10次，超过10次的要另算。
class Solution {
    public int numRabbits(int[] answers) {
        Arrays.sort(answers);
        int i = 0;
        int ret = 0;
        while(i < answers.length)
        {
        	int v = answers[i];
        	if(v == 0) // 值为0的单独处理，每个0都不可能和其它的相同，直接+1
        	{
        		ret += 1;
        		++i;
        		continue;
        	}
        	
        	if(i+1 >= answers.length || answers[i+1] != v) // 然后再处理和后面的值不一样的
        	{
        		ret += v+1;
        		++i;
        		continue;
        	}
        	
        	// 下面是和后面的值一样的，合并处理。由于当前值为v，所以最多合并v个。
        	int di = 1;
        	for(; di <= v && di + i < answers.length && answers[di+i] == v; ++di)
        		;
        	ret += v+1;
        	i += di;
        }
        
        return ret;
    }
}

public class lt781 {
	public static void main(String[] args) {
		System.out.println(new Solution().numRabbits(new int[] {0, 0, 1, 1, 1}));
	}
}

import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
    	List<List<Integer>> ret = new ArrayList<List<Integer>>();
    	
    	// 用一个数组，记录每个候选元素被选择的次数，次数可以为0，表示不选
    	int[] counts = new int[candidates.length]; // 从candidates中选择候选元素，第i个元素选择counts[i]次
    	
    	DFS(ret, counts, candidates, 0, target);
    	
    	return ret;
    }
    
    public void DFS(List<List<Integer>> result,
    		int[] counts,
    		int[] candidates, int candiIndex,
    		int target)
    {
    	if(candiIndex >= candidates.length)
    		return;
    	
    	for(int i = 0; i <= target / candidates[candiIndex]; ++i)
    	{	
    		counts[candiIndex] = i;
    		
    		final int left = target - candidates[candiIndex] * i;
    		
    		if(left < 0) // 此路不通，回溯到上一层
    		{
    			return;
    		}
    		
    		if(left == 0) // 找到一组解
    		{
    			List<Integer> tmp = new ArrayList<>();
    			for(int x = 0; x <= candiIndex; ++x)
    			{
    				for(int y = 0; y < counts[x]; ++y)
    				{
    					tmp.add(candidates[x]);
    				}
    			}
    			result.add(tmp);
    			return;
    		}
    		
    		// 继续找下一层
    		DFS(result, counts, candidates, candiIndex + 1, left);
    	}
    }
}

public class lt39 {
	public static void main(String[] args) {
		Solution s = new Solution();
		List<List<Integer>> ret = s.combinationSum(new int[] {2, 3, 5}, 8);
		for(int i = 0; i < ret.size(); ++i)
		{
			System.out.print("[");
			for(int j = 0; j < ret.get(i).size(); ++j)
			{
				if(j > 0)
					System.out.print(", ");
				System.out.print(ret.get(i).get(j));
			}
			System.out.print("]");
		}
	}
}

import java.util.*;

class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode(int x) { val = x; }
}

class Solution {
	void dfs(TreeNode root, List<Integer> l)
	{
		if(root.left != null)
			dfs(root.left, l);
		l.add(root.val);
		if(root.right != null)
			dfs(root.right, l);
	}
	
    public int minDiffInBST(TreeNode root) {
    	if(root == null) return 0;
    	List<Integer> l = new ArrayList<>();
    	dfs(root, l);
    	if(l.size() < 2) return 0;
    	int min = Integer.MAX_VALUE;
    	for(int i = 1; i < l.size(); ++i)
    	{
    		int v = l.get(i) - l.get(i-1);
    		if(v < min)
    			min = v;
    	}
    	return min;
    }
}

public class lt783 {
	public static void main(String[] args) {

	}
}

import java.util.*;

public class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode(int x) { val = x; }
}

class Solution {
	public static void preMid(TreeNode root, List<TreeNode> l)
	{
		if(root == null)
			return;
		
		preMid(root.left, l);
		l.add(root);
		preMid(root.right, l);
	}
	
    public TreeNode increasingBST(TreeNode root) {
        	if(root == null)
        		return root;
        	
        	List<TreeNode> l = new ArrayList<>();
        	preMid(root, l);
        	for(int i = 0; i < l.size(); ++i)
        	{
        		TreeNode n = l.get(i);
        		n.left = null;
        		if(i > 0)
        			l.get(i-1).right = n;
        	}
        	return l.get(0);
    }
}

public class lt897 {
	public static void main(String[] args) {

	}
}

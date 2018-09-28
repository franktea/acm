import java.util.*;

class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode(int x) { val = x; }
}

class Solution {
	public static void invert(TreeNode root)
	{
		if(root == null)
			return;
		
		TreeNode tmp = root.left;
		root.left = root.right;
		root.right = tmp;
		
		invert(root.left);
		invert(root.right);
	}
	
    public TreeNode invertTree(TreeNode root) {
    	invert(root);
    	return root;
    }
}

public class lt226 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}

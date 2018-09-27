
class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode(int x) { val = x; }
}

class Solution {
    public TreeNode searchBST(TreeNode root, int val) {
        while(root != null)
        {
        	if(root.val == val)
        		return root;
        	
        	if(val > root.val)
        		root = root.right;
        	else
        		root = root.left;
        }
        return null;
    }
}

public class lt700 {

	public static void main(String[] args) {

	}

}

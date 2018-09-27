import java.util.ArrayList;
import java.util.List;

class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode(int x) { val = x; }
}

class Solution {
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
    	if(root1 == null && root2 == null)
    		return true;
    	
    	if(root1 == null && root2 != null || root1 != null && root2 == null)
    		return false;
    	
        List<Integer> a1 = new ArrayList<Integer>();
        List<Integer> a2 = new ArrayList<Integer>();
        leaf(root1, a1);
        leaf(root2, a2);
        return a1.equals(a2);
    }
    
    public static void leaf(TreeNode root, List<Integer> arr)
    {
    	if(root.left == null && root.right == null)
    	{
    		arr.add(root.val);
    		return;
    	}
    	
    	if(root.left != null)
    		leaf(root.left, arr);
    	
    	if(root.right != null)
    		leaf(root.right, arr);
    }
}

public class lt872 {
	public static void main(String[] args) {

	}

}

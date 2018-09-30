import java.util.*;

class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode(int x) { val = x; }
}

// 题目意思不明确，只要没有左儿子的都算
class Solution {
	class Pair
	{
		TreeNode node;
		int level;
		Pair(TreeNode n, int l) { node = n; level = l;}
	}
    public int findBottomLeftValue(TreeNode root) {
    	if(root == null)
    		return 0;
    	
        TreeNode node = null; // the leftmost node
        int level = -1; // level of the left most node
        Queue<Pair> queue = new LinkedList<>();
        queue.add(new Pair(root, 0));
        while(!queue.isEmpty())
        {
        	Pair p = queue.remove();
        	if(p.node.left == null && p.node.right == null && p.level > level)
        	{
        		node = p.node;
        		level = p.level;
        	}
        	if(p.node.left != null)
        	{
        		queue.add(new Pair(p.node.left, p.level+1));
        	}
        	if(p.node.right != null)
        	{
        		queue.add(new Pair(p.node.right, p.level+1));
        	}
        }
        return node.val;
    }
}

public class lt513 {
	public static void main(String[] args) {
	}
}

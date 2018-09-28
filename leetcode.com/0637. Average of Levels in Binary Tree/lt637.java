import java.util.*;

class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode(int x) { val = x; }
}

class Pair
{
	TreeNode node;
	int level;
	Pair(int l, TreeNode n) { node = n; level = l; }
}

class Solution {
    public List<Double> averageOfLevels(TreeNode root) {
        	List<Double> ret = new LinkedList<>();
        	if(root == null)
        		return ret;
        	
        	Queue<Pair> queue = new LinkedList<>();
        queue.add(new Pair(0, root));
        	
        	int level = 0;
        	double sum = 0;
        	int count = 0;
        	while(! queue.isEmpty())
        	{
        		Pair p = queue.remove();
        		if(p.node.left != null)
        			queue.add(new Pair(p.level+1, p.node.left));
        		if(p.node.right != null)
        			queue.add(new Pair(p.level+1, p.node.right));
        		
        		if(p.level == level)
        		{
        			sum += p.node.val;
        			++count;
        		}
        		else
        		{
        			ret.add(sum/count);
        			sum = p.node.val;
        			count = 1;
        			level = p.level;
        		}
        	}
        	ret.add(sum/count);
        	return ret;
    }
}

public class lt637 {
	public static void main(String[] args) {

	}

}

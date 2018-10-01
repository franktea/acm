import java.util.*;

class TreeNode {
	int val;
 	TreeNode left;
 	TreeNode right;
 	TreeNode(int x) { val = x; }
}

// 参数不能传引用、函数也不能返回结构体，写起来麻烦得一逼
class Solution {
	class Result
	{
		boolean foundp = false;
		boolean foundq = false;
		boolean Check()
		{
			return foundp && foundq;
		}
		void merge(Result another)
		{
			if(another == null)
				return;
			
			this.foundp |= another.foundp;
			this.foundq |= another.foundq;
		}
	}
	
	private TreeNode node = null;
	
	private Result find(TreeNode root, TreeNode p, TreeNode q)
	{
		Result l = root.left!=null ? find(root.left, p, q) : null;
		Result r = root.right!=null ? find(root.right, p, q) : null;
		if(l != null && l.Check())
			return l;
		if(r != null && r.Check())
			return r;
		Result ret = new Result();
		if(root == p)
			ret.foundp = true;
		if(root == q)
			ret.foundq = true;
		ret.merge(l);
		ret.merge(r);
		if(ret.Check())
			node = root;
		return ret;
	}
	
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        	find(root, p, q);
        	return node;
    }
}

public class lt235 {
	public static void main(String[] args) {
	}
}

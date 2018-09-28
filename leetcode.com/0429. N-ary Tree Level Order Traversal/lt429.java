import java.util.*;

class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val,List<Node> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
	class Pair
	{
		int level;
		Node node;
		public Pair(int l, Node n) { level = l; node = n;}
	}
	
    public List<List<Integer>> levelOrder(Node root) {
    	List<List<Integer>> ret = new ArrayList<>();
    	if(root == null)
    		return ret;
    	
    	Queue<Pair> queue = new LinkedList<>();
    	int level = 0;
    	List<Integer> l = new ArrayList<>();
    	queue.add(new Pair(0, root));
    	while(! queue.isEmpty())
    	{
    		Pair p = queue.remove();
    		if(p.level != level)
    		{
    			ret.add(l);
    			l = new ArrayList<>();
    			++level;
    		}
    		l.add(p.node.val);
    		for(Node n: p.node.children)
    		{
    			if(n == null)
    				continue;
    			
    			queue.add(new Pair(p.level + 1, n));
    		}
    	}
    	ret.add(l);
    	return ret;
    }
}

public class lt429 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}

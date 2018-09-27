import java.util.List;

// Definition for a Node.
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
    public int maxDepth(Node root) {
    	if(root == null)
    		return 0;
    	
        if(root.children.isEmpty())
        	return 1;
        
        int max = 0;
        for(Node n: root.children)
        {
        	if(n == null)
        		continue;
        	
        	int ret = maxDepth(n);
        	if(ret > max)
        		max = ret;
        }
        
        return 1 + max;
    }
}

public class lt559 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}

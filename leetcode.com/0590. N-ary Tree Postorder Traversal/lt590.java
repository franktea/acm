import java.util.List;
import java.util.ArrayList;

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
    public List<Integer> postorder(Node root) {
        List<Integer> l = new ArrayList<Integer>();
    	if(root == null)
    		return l;
    	
        post(root, l);
        return l;
    }
    
    public static void post(Node root, List<Integer> l) {
    	for(Node n: root.children)
    	{
    		if(n != null)
    			post(n, l);
    	}
    	l.add(root.val);
    }
}

public class lt590 {

	public static void main(String[] args) {

	}

}

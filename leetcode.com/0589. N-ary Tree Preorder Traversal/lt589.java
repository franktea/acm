import java.util.List;
import java.util.Stack;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;

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
    public List<Integer> preorder(Node root) {
        List<Integer> ret = new ArrayList<Integer>();
        if(root == null)
        	return ret;
        Stack<Node> q = new Stack<Node>();
        q.add(root);
        while(! q.isEmpty())
        {
        	Node n = q.pop();
        	ret.add(n.val);
        	Collections.reverse(n.children);
        	for(Node c: n.children)
        	{
        		if(c == null)
        			continue;
        		
        		q.push(c);
        	}
        }
        
        return ret;
    }
}

public class lt589 {
	public static void main(String[] args) {

	}

}


class ListNode {
	int val;
	ListNode next;
	ListNode(int x) { val = x; }
}

class Solution {
    public ListNode middleNode(ListNode head) {
    	if(head == null)
    		return head;
        int len = 0;
        ListNode l = head;
        while(l != null)
        {
        	++len;
        	l = l.next;
        }
        
        len /= 2;
        
        l = head;
        for(int i = 0; i < len; ++i)
        	l = l.next;
        
        return l;
    }
}


public class lt876 {

	public static void main(String[] args) {

	}

}

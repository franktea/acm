import java.util.*;

class Solution {
    public int calPoints(String[] ops) {
        List<Integer> l = new ArrayList<>();
        for(String str: ops)
        {
        	if(str.equals("+"))
        	{
        		int v = l.get(l.size()-1) + l.get(l.size()-2);
        		l.add(v);
        	}
        	else if(str.equals("D"))
        	{
        		int v = 2*l.get(l.size()-1);
        		l.add(v);
        	}
        	else if(str.equals("C"))
        	{
        		l.remove(l.size()-1);
        	}
        	else
        	{
        		l.add(Integer.parseInt(str));
          	}
        }
        int ret = 0;
        for(int v: l)
        {
        	ret += v;
        }
        return ret;
    }
}


public class lt682 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}

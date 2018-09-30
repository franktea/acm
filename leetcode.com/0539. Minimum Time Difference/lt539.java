import java.util.*;

class Solution {
    public int findMinDifference(List<String> timePoints) {
        List<Integer> l = new ArrayList<>();
        for(String str: timePoints)
        {
        	String[] parts = str.split(":");
        	int v = 60*Integer.parseInt(parts[0]) + Integer.parseInt(parts[1]);
        	l.add(v);
        }
        Collections.sort(l); // 排序
        int ret = 24*60 + l.get(0) - l.get(l.size()-1); // 第一个减最后一个
        for(int i = 1; i < l.size(); ++i)
        {
        	int v = l.get(i) - l.get(i-1);
        	if(v < ret)
        		ret = v;
        }
        return ret;
    }
}

public class lt539 {
	public static void main(String[] args) {
		List<String> l = new ArrayList<>();
		l.add("23:59");
		l.add("00:00");
		System.out.println(new Solution().findMinDifference(l));
	}
}

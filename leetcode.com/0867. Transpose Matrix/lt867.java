
class Solution {
    public int[][] transpose(int[][] A) {
        int[][] ret = new int[A[0].length][A.length];
        for(int j = 0; j < A[0].length; ++j)
        {
        	for(int i = 0; i < A.length; ++i)
        	{
        		ret[j][i] = A[i][j];
        	}
        }
        return ret;
    }
}

public class lt867 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}

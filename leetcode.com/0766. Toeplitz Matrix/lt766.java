

class Solution {
    public boolean isToeplitzMatrix(int[][] matrix) {
        if(matrix.length <= 1)
        	return true;
        
        int[] arr = matrix[0];
        if(arr.length <= 1)
        	return true;
        
        for(int i = 1; i < matrix.length; ++i)
        {
        	int[] arr2 = matrix[i];
        	for(int index = 1; index < arr2.length; ++index)
        		if(arr2[index] != arr[index-1])
	        		return false;
        	arr = arr2;
        }
        
        return true;
    }
}

public class lt766 {

	public static void main(String[] args) {

	}

}


class Solution {
    public String addStrings(String num1, String num2) {
    	java.math.BigInteger a = new java.math.BigInteger(num1);
        java.math.BigInteger b = new java.math.BigInteger(num2);
        return a.add(b).toString();
    }
}

public class lt415 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}

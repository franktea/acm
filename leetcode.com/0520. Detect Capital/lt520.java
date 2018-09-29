import java.util.*;

class Solution {
    public boolean detectCapitalUse(String word) {
        if(word.isEmpty())
        	return false;
        
        if(Character.isUpperCase(word.charAt(0)))
        {
        	if(Character.isUpperCase(word.charAt(word.length()-1)))
        	{
        		for(int i = 1; i < word.length() - 1; ++i)
        		{
        			if(! Character.isUpperCase(word.charAt(i)))
        				return false;
        		}
        	}
        	else
        	{
        		for(int i = 1; i < word.length() - 1; ++i)
        		{
        			if(Character.isUpperCase(word.charAt(i)))
        				return false;
        		}
        	}
        }
        else
        {
        	for(int i = 1; i < word.length(); ++i)
        	{
        		if(Character.isUpperCase(word.charAt(i)))
        		{
        			return false;
        		}
        	}
        }
        
        return true;
    }
}

public class lt520 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}

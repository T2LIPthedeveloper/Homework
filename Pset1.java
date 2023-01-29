import java.util.Arrays;

public class Pset1 {

    public static boolean isAllCharacterUnique(String sIn) {
    char [] chArr = sIn.toCharArray();
    Arrays.sort(chArr);

    for (int i = 0; i < chArr.length -1; i++) {
        if(chArr[i] != chArr[i+1])
            continue;
        else
            return false;
    }
    return true;
    }
    
    public static boolean isPermutation(String sIn1, String sIn2) {
        if (sIn1.length() != sIn2.length())
            return false;
        
        return true;
    }
}
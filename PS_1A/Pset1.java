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
        char[] a = sIn1.toCharArray();
        char[] b = sIn2.toCharArray();
        Arrays.sort(a);
        Arrays.sort(b);
        for (int i = 0; i < a.length; i++) {
            if (a[i] != b[i])
                return false;
        }
        return true;
    }
}
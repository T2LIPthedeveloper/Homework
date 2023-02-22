import java.util.Arrays;

public class HWFunctions {
    public static void main(String[] args) {
        HWFunctions hw = new HWFunctions();
        System.out.println(HWFunctions.isPalindrome("abba".toCharArray()));
        System.out.println(HWFunctions.isPalindrome("abbab".toCharArray()));
        System.out.println(HWFunctions.isPalindrome("adbcba".toCharArray()));
        System.out.println(HWFunctions.isPalindrome("ZZaZZ".toCharArray()));
        System.out.println(HWFunctions.isPalindrome("123421".toCharArray()));
        
    }

    public static boolean isPalindrome(char[] S) {
        //recursive
        if (S.length == 0 || S.length == 1)
            return true;
        if (S[0] == S[S.length - 1])
            return isPalindrome(Arrays.copyOfRange(S, 1, S.length - 1));
        return false;
    }

    public static String tstException(int idx, String[] y) {
        try {
            return y[idx];
        } catch (ArrayIndexOutOfBoundsException e) {
            return "Out of Bounds";
        }
    }
}
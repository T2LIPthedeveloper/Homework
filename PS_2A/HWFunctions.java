package PS_2A;


public class HWFunctions {
    public static void main(String[] args) {
        HWFunctions hw = new HWFunctions();
        System.out.println(hw.isPalindrome("abba"));
        System.out.println(hw.isPalindrome("abbab"));
    }

    public static boolean isPalindrome(char[] S) {
        if (S.length == 1 || (S.length == 2 && S[0] == S[1])) {
            return true;
        }
        else if (S[0] == S[S.length - 1]) {
            return isPalindrome((S.toString().substring(1, S.length-2)).toCharArray());
        }
        else
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
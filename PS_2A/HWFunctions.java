package PS_2A;


public class HWFunctions {
    public static void main(String[] args) {
        HWFunctions hw = new HWFunctions();
        System.out.println(hw.isPalindrome("abba"));
        System.out.println(hw.isPalindrome("abbab"));
    }

    public  boolean isPalindrome(String s) {
        if (s.length() == 1 || (s.length() == 2 && s.charAt(0) == s.charAt(1))) {
            return true;
        }
        else if (s.charAt(0) == s.charAt(s.length() - 1)) {
            return isPalindrome(s.substring(1, s.length()-2));
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


import java.util.ArrayList;

public class Permutation {
    private final String in;
    private ArrayList<String> a = new ArrayList<String>();
    // additional attribute if needed

    Permutation(final String str){
        in = str;
        // additional initialization if needed
    }

    public void permute(){
        // produce the permuted sequences of 'in' and store in 'a', recursively
        permuteHelper("", in);
        
    }

    private void permuteHelper(String start, String end) {
        if (end.length() <= 1) {
            a.add(start + end);
        } else {
            for (int i = 0; i < end.length(); i++) {
                String newString = end.substring(0, i) + end.substring(i + 1);
                permuteHelper(start + end.charAt(i), newString);
            }
        }
    }



    public ArrayList<String> getA(){
        return a;
    }
}


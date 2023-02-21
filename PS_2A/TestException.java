package PS_2A;

public class TestException {
    public static void main(String[] args) {
        String [] in = { "hello", "good night", "good morning"};
        String ret = tstException(2, in);
        System.out.println(ret);
        ret = tstException(-1, in);
        System.out.println(ret);
        
    }

    public static String tstException(int idx, String[] y) {
        try {
            return y[idx];
            
        } catch (Exception e) {
            // TODO: handle exception
            return ("Out of Bounds");
        }
        
    }
}

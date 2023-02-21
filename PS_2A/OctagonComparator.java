package PS_2A;

import java.util.Comparator;

//Modify the class header to implement the appropriate interface
public class OctagonComparator implements Comparator<Octagon>{ 
    
    //then implement the method(s) in the interface
    @Override
    public int compare(Octagon o1, Octagon o2) {
        if (o1.getSide() > o2.getSide()) {
            return 1;
        } else if (o1.getSide() < o2.getSide()) {
            return -1;
        } else {
            return 0;
        }
    }
}




//Modify the class header and implement any necessary methods
public class Octagon implements Comparable<Octagon> {
    private double side;
    //setter constructor
    public Octagon(double side){
        this.side = side;
    }
    //getter method
    public double getSide() {
        return side;
    }
    //implement compareTo override
    @Override
    public int compareTo(Octagon o) {
        if (this.side > o.side) {
            return 1;
        } else if (this.side < o.side) {
            return -1;
        } else {
            return 0;
        }
    }


}
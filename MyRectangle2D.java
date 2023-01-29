public class MyRectangle2D {

    private double x, y, width, height;


    //constructors
    public MyRectangle2D() {
        this.x = 0;
        this.y = 0;
        this.width = 1;
        this.height = 1;
    }

    public MyRectangle2D(double x, double y, double width, double height) {
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
    }

    //getters and setters for height
    public double getHeight() {
        return height;
    }

    public void setHeight(double height) {
        this.height = height;
    }

    //getters and setters for width
    public double getWidth() {
        return width;
    }

    public void setWidth(double width) {
        this.width = width;
    }

    //getters and setters for Y
    public double getY() {
        return y;
    }

    public void setY(double y) {
        this.y = y;
    }

    //getters and setters for X
    public double getX() {
        return x;
    }

    public void setX(double x) {
        this.x = x;
    }

    //getters for area and perimeter
    public double getArea() {
        return (this.width * this.height);
    }

    public double getPerimeter() {
        return (2 * (this.width + this.height));
    }

    //object methods including overloading
    public boolean contains(double x, double y) {
        boolean result = false;
        if ((x < this.x + (this.width / 2) && (x > (this.x - this.width / 2))) && ((y < this.y + (this.height / 2)) && (y > this.y - (this.height / 2)))) {
            result = true;
        }
        return result;
    }

    public boolean contains(MyRectangle2D r) {
        //assume it's true
        boolean result = true;
        //lists of corner points as corresponding array indices in X array, Y array
        //multi-dimensiuon array could have been implemented but this makes more sense while debugging
        double[] arrayX = {(r.x + r.height/2),(r.x + r.height/2),(r.x - r.height/2),(r.x - r.height/2)};
        double[] arrayY = {(r.y + r.width/2),(r.y - r.width/2),(r.y + r.width/2),(r.y - r.width/2)};

        //if a corner is not within the current rectangle, then the second rectangle is definitely outside the current rectangle
        for (int i = 0; i < 4; i++) {
            if (!((arrayX[i] < this.x + (this.width / 2) && (arrayX[i] > (this.x - this.width / 2))) && ((arrayY[i] < this.y + (this.height / 2)) && (arrayY[i] > this.y - (this.height / 2))))) {
                result = false;
                break;
            }
        }

        return result;
    }

    public boolean overlaps(MyRectangle2D r) {
        //assume it's false
        boolean result = false;
        //lists of corner points as corresponding array indices in X array, Y array
        //multi-dimension array could have been implemented but this makes more sense while debugging
        double[] arrayX = {(r.x + r.height/2),(r.x + r.height/2),(r.x - r.height/2),(r.x - r.height/2)};
        double[] arrayY = {(r.y + r.width/2),(r.y - r.width/2),(r.y + r.width/2),(r.y - r.width/2)};

        //if a corner is within the current rectangle, then the second rectangle is definitely overlapping the current rectangle
        for (int i = 0; i < 4; i++) {
            if ((arrayX[i] < this.x + (this.width / 2) && (arrayX[i] > (this.x - this.width / 2))) && ((arrayY[i] < this.y + (this.height / 2)) && (arrayY[i] > this.y - (this.height / 2)))) {
                result = true;
                break;
            }
        }

        return result;
    }

    

}

/*
2. [20 points] Geometry: The MyRectangle2D class

Define the MyRectangle2D class that contains:

• Two double data fields named x and y that specify the center of the rectangle with get and set methods: getX, setX, getY, setY. (Assume that the rectangle sides are parallel to x- or y- axes.)

• The double data fields width and height with get and set methods: getWidth, setWidth, getHeight, setHeight.

• A no-arg constructor that creates a default rectangle with (0, 0) for (x, y) and 1 for both width and height.

• A constructor that creates a rectangle with the specified x, y, width, and height: MyRectangle2D(double x, double y, double width, double height)

• A method getArea() that returns the area of the rectangle.

• A method getPerimeter() that returns the perimeter of the rectangle.

• A method contains(double x, double y) that returns true if the specified point (x, y) is inside this rectangle. See Figure 1(a).

• A method contains(MyRectangle2D r) that returns true if the specified rectangle is inside this rectangle. See Figure 1(b).

• A method overlaps(MyRectangle2D r) that returns true if the specified rectangle overlaps with this rectangle. See Figure 1(c).

(a) (b) (c)

Figure 1: (a) A point is inside the rectangle. (b) A rectangle is inside another rectangle. (c) A rectangle overlaps another rectangle.

Implement data fields, all constructors, methods getArea(), getPerimeter(), and contains(double x, double y), contains(MyRectangle2D r), and overlaps(MyRectangle2D r)

Please develop test cases to test your code properly before submission.
 */
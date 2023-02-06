public class Triangle extends GeometricObject {
    double side1, side2, side3;
    public Triangle() {
        this.side1 = 1.0;
        this.side2 = 1.0;
        this.side3 = 1.0;
    }

    public Triangle(side1, side2, side3) {
        this.side1 = side1;
        this.side2 = side2;
        this.side3 = side3;
    }

    public double getArea() {
        double s = (this.side1 + this.side2 + this.side3)/2;
        return Math.sqrt((s*(s-this.side1)*(s-this.side2)*(s-this.side3)));
    }

    public double getPerimeter() {
        return (this.side1 + this.side2 + this.side3);
    }

    public String toString() {
        return "Triangle: side1 = 1.0 side2 = 1.0 side3 = 1.0";

    }
}

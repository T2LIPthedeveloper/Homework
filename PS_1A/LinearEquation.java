public class LinearEquation {
    private double a, b, c, d, e, f;

    //getter and setter for A
    public double getA() {
        return a;
    }

    public void setA(double a) {
        this.a = a;
    }
    //getter and setter for B
    public double getB() {
        return b;
    }

    public void setB(double b) {
        this.b = b;
    }
    //getter and setter for C
    public double getC() {
        return c;
    }

    public void setC(double c) {
        this.c = c;
    }
    //getter and setter for D
    public double getD() {
        return d;
    }

    public void setD(double d) {
        this.d = d;
    }
    //getter and setter for E
    public double getE() {
        return e;
    }

    public void setE(double e) {
        this.e = e;
    }
    //getter and setter for F
    public double getF() {
        return f;
    }

    public void setF(double f) {
        this.f = f;
    }

    //helper function
    private double getDeterminant() {
        return (this.a * this.d - this.b * this.c);
    }

    //constructor
    public LinearEquation(double a, double b, double c, double d, double e, double f) {
        this.a = a;
        this.b = b;
        this.c = c;
        this.d = d;
        this.e = e;
        this.f = f;
    }

    //methods
    public boolean isSolvable() {
        if (this.getDeterminant() != 0)
            return true;
        return false;
    }

    public double getX() {
        return ((this.e*this.d - this.b*this.f)/(this.getDeterminant()));
    }

    public double getY() {
        return ((this.a*this.f - this.e*this.c)/(this.getDeterminant()));
    }

}

/*
Title: 2 x 2 Linear Equations

1. [10 points] Design a class named LinearEquation for a 2x2 system equations of variables x,y:

ax+by=e

cx+dy=f

The class contains:

Private data fields a, b, c, d, e, and f, the coefficients.

A constructor with the arguments for a, b, c, d, e, and f.

Six get methods for a, b, c, d, e, and f.

A method named isSolvable() that returns true if ad - bc is not 0 (why?)

Methods getX() and getY() that return the solution for the equation

Write a test program that prompts user to enter a, b, c, d, e and f and displays the result.

If ad – bc is 0, report that “The equation has no solution.”

Test case:

public class TestLinearEquation {

public static void main(String[] args) {

double a = 1.0; double b = 2.0; double c = 3.0;

double d = 5.0; double e = 6.0; double f = 7.0;

LinearEquation equation = new LinearEquation(a, b, c, d, e, f);

if (equation.isSolvable()) {

System.out.println("x is " +

equation.getX() + " and y is " + equation.getY());

}

else {

System.out.println("The equation has no solution");

}

LinearEquation equation2 = new LinearEquation(1.25, 2.0, 2.0, 4.2, 3.0, 6.0);

if (equation2.isSolvable()) {

System.out.println("x is " + equation2.getX() + " y is " + equation2.getY());

}

LinearEquation equation3 = new LinearEquation(1.0, 2.0, 2.0, 4.0, 3.0, 6.0);

System.out.println(equation3.isSolvable());

}

}

Output:

x is -16.0 and y is 11.0

x is 0.48000000000000115 y is 1.2

false
*/
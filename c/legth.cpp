import java.lang.Math;
public class Point {
    private double x = 0;
    private double y = 0;

    public Point(int a, int b) {
        x = a;
        y = b;
    }

    public double getX()
     {
         return x;
     }

    public double getY()
    {   return y;
    }
}

public class Line {
    private Point p1;
    private Point p2;

    public Line (Point firstPoint, Point secondPoint) {
        p1 = firstPoint;
        p2 = secondPoint;
    }
    double length(double x1,double y1,double x2,double y2)
    {
        return (Math.sqrt((x2-x1)*(x2-x1)-(y2-y1)*(y2-y1)));
    }
}
class Length
{
    public static void main(String args[])
    {
        double x1,y1,x2,y2,len;
        Point pt1=new Point(2,1);
        Point pt2=new Point(6,2);
        x1=pt1.getX();
        y1=pt1.getY();
        x2=pt2.getX();
        y2=pt2.getY();
        Line l1=new Line(pt1,pt2);
        len=length(x1,y1,x2,y2);
        System.out.println("length of line = "+length);
    }
}

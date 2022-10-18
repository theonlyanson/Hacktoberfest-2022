
public class TestShapes {

    public static void main(String[] args) {
        
        Sphere sphere = new Sphere();
        Circle circle = new Circle();
        Shapes shapes = new Sphere();
        Shapes originalShapes = new Shapes();
        
        System.out.println("Area of Sphere is "+sphere.getArea(2.1));
        System.out.println("Area of Circle is "+circle.getArea(2.1));
        System.out.println(circle.getAStatement());
        System.out.println("Area of relevant Sphere is "+shapes.getArea(2.1));
        System.out.println("Area of relevant Sphere is "+originalShapes.getArea(2.1));  
        
    }
    
}

class Shapes{
    double getArea(double radius){
        return 0.0;
    }
    public String getAStatement(){
        return "I am a shape";
    }
}

class Sphere extends Shapes{
    @Override
    double getArea(double radius){
        return 4 * Math.PI * radius * radius;
    }    
}

class Circle extends Shapes{
    @Override
    double getArea(double radius){
        return Math.PI * radius * radius;
    }
}

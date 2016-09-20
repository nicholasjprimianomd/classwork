/**********************************************************************                                              
 *                                                                                                                                                        
 * Project 2: Shapes of Things                                                                                                                         
 * Driver file to test the Shapes hierarchy                                                                                                                     
 *                                                                                                                                                                
 * Author: Nicholas J. Primiano                                                                                                                        
 * Date:   28 January 2014                                                                                                                                       
 *                                                                                                                                                               
 **********************************************************************/                                                                                                                                                                                                                                                
public class Proj2 {                                                                                                                              
  public static void main(String args[])
  {
    /*                                                                                                                                                            
     * set up a few Shapes                                                                                                                                        
     */

    // specify extent (radius or side length) and origin                                                                                         
    Circle circle = new Circle(3.5, 6, 9);
    Square square = new Square(12, 2, 2);
    Sphere sphere = new Sphere(5, 1.5, 4.5, 2.2);

    // specify some objects using "default values"                                                                                                             
    // only specify side length of cube (origin is zero)                                                                                                         
    Cube cube = new Cube(2.2);
    // radius is zero, origin is zero                                                                                                                                                                       
    Circle circleDot = new Circle();
    // only specify the origin (radius is zero)                                                                                                                                                             
    Square squareDot = new Square(3.2, 1.6);

    /*                                                                                                                                           
     * An array of Shapes, holding all kinds of different Shapes                                                          
     */

    Shape shape[] = { circle, square, sphere, cube, circleDot, squareDot };

    /*                                                                                                                                                
     * Print out each Shape in the array ... long live polymorphism!                                                                                 
     */

    for (int j = 0; j < shape.length; ++j)
      System.out.println(shape[j] + "\n");   
  }
}

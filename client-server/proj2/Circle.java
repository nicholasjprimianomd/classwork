/**
 * The circle class is a class of two-dimensional shapes. Not
 * suprisingly the objects of this class are circles.
 * A cricle is a special specified by its center and radius.
 *
 * @version 1.0 28 Jan 2014
 * @author Nicholas Primiano 
 */

public class Circle extends Shape2D {
  
  private double radius = 0;
  private double centerX = 0;
  private double centerY = 0;

  /**
   * Zero-parameter constructor makes the origin the center of the circle
   * and makes the radius of the circle zero.
   */

  public Circle() {
    this.radius = 0;
    this.centerX = 0;
    this.centerY = 0;
  }

  /**
   * One-parameter constructor sets the radius, and makes the origin
   * the center of the circle.
   *
   * @param radius the radius of the circle
   */

  public Circle(double radius) {
    this.radius = radius;
    this.centerX = 0;
    this.centerY = 0;
  }

  /**
   * Two-parameter constructor sets the center, and makes the radius of
   * the circle zero.
   *
   * @param centerX the center's x-coordinate
   * @param centerY the center's y-coordinate
   */
  public Circle(double centerX, double centerY) {
    this.radius = 0;
    this.centerX = centerX;
    this.centerY = centerY;
  }

  /**
   * Three parameter constructor sets the radius and the center of the
   * circle.
   *
   * @param radius the radius of the circle
   * @param centerX the center's x-coordinate
   * @param centerY the center's y coordinate
   */

  public Circle(double radius, double centerX, double centerY) {
    this.radius = radius;
    this.centerX = centerX;
    this.centerY = centerY;
  }

  /**
   * Determine the circle's radius
   *
   * @return the radius of the circle
   */

  public double getRadius(){
    return radius;
  }

  /**
   * Determine the circle's perimeter.
   *
   * @return the perimeter of the circle
   */

    public double perimeter() {
      // perimeter of a circle 2*Pi*radius
      return 2 * Math.PI * radius;
  }

  /**
   * Determine the circle's area.
   *
   * @return the area of the circle
   */

    public double area() {
      // area of a circle Pi*radius*radius
      return Math.PI * radius * radius;
  }

  /**
   * Create a string verson of the circle, suitable for (e.g.)
   * printing
   *
   * @return the string representation of the circle
   */

    public String toString() {
      return String.format("Cricle with:\n   radius %.1f\n"+
			 "   center at (%.1f, %.1f)\n" + 
			 "   perimeter of %.3f \n   area of %.3f", 
			 radius, centerX, centerY, perimeter(), area());
  }
  
}

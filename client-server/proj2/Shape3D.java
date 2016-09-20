/**
 * An abstract class of three-dimensional shapes.
 *
 * @version 1.0 28 Jan 2014
 * @author Nicholas Primiano
 */

public abstract class Shape3D extends Shape {
  
  protected double centerX = 0;
  protected double centerY = 0;
  protected double centerZ = 0;
  
  /**
   * Zero-parameter constructor sets the center to be the origin (0.0,0.0,0.0).
   */

  public Shape3D(){
    this.centerX = 0;
    this.centerY = 0;
    this.centerZ = 0;
  }
  
  /**
   * Three-parameter constructor allows user to specify the center's
   * x-, y-, and the z-coordinates.
   *
   * @param centerX the center's x-coordinate
   * @param centerY the center's y-coordinates
   * @param centerZ the center's z-coordinate
   */

  public Shape3D(double centerX, double centerY, double centerZ){
    this.centerX = centerX;
    this.centerY = centerY;
    this.centerZ = centerZ;
  }

  /**
   * Get the center's x-coordinate.
   *
   * @return x-coordinate of the center
   */

  public double getCenterX(){
    return centerX;
  }

  /**
   * Get the center's y-coordinate
   *
   * @return y-coordinate of the center
   */

  public double getCenterY(){
    return centerY;
  }

  /** 
   * Get the cenr;s z-coordinate.
   *
   * @return z-coordinate of the center
   */
  
  public double getCenterZ(){
    return centerZ;
  }
  
  /**
   * Abstract method that computes the surface area of a
   * two-dimnsional shape.
   *
   * @return the area of the shape
   */

  public abstract double area();
  
  /**
   * Abstract method that computes the volume of a two-dimensional
   * shape.
   *
   * @return the volume of the shape
   */  

  public abstract double volume();
}

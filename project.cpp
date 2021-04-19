/** 
 * @author: 
 * 
 * You may add more private data if it helps (it probably would)
 * You may add more private methods if it helps (again, probably helpful)
 */
public class Rectangle implements Polygon
{
    private int x1, x2, x3, x4, y1, y2, y3, y4;

    public Rectangle(Location loc1, Location loc2, Location loc3, Location loc4) {
        x1 = loc1.row(); y1 = loc1.col();
        x2 = loc2.row(); y2 = loc2.col();
        x3 = loc3.row(); y3 = loc3.col();  
        x4 = loc4.row(); y4 = loc4.col();  
    }
    
    // these 5 methods must be implemented as part of the Polygon interface
    public boolean isPolygon() { return true;
    }
    public boolean isRegular() { return true;
    }
    public int numSides() { return 1;
    }
    public double area() { return 1.0;
    }
    public double perimeter() { return 1;
    }
    
    // these methods are specific to Rectangles
    public boolean isRectangle() { return true;
    }
    public boolean isSquare() { return true;
    }
    public double diagonalLength() { return 1.0;
    }
    public String toString() { return "";
    }
    
    //don't edit this method
    private boolean areDoublesEqual(double x, double y) {
        Double xObj = new Double(x);
        Double yObj = new Double(y);
        return xObj.equals(yObj);
    }
}
public interface Polygon
{
	/**
	  * Determines if the figure is a polygon
	  * @return Returns true if the figure is a polygon,
	  *         false otherwise
	  *
	  * For now, just return true for this method. If you think of a neat way to
	  * determine from a list of points whether those points form a legal polygon (convex),
	  * then let us know. For now, this sounds like too much math - but maybe you
	  * have a good idea.
	  */
	boolean isPolygon();

	/**
	  * Determines if the polygon is Regular
	  * @return Returns true if the figure is a polygon and is Regular,
	  *         false otherwise
	  */
	boolean isRegular();
	
	/**
	  * Returns the number of sides in the polygon
	  * @returns Returns the number of sides in the polygon
	  */
	int numSides();

	/**
	  * Returns the area of the polygon
	  * @returns Returns the area of the polygon
	  * @throws IllegalStateException If the figure is not a polygon
	  */
	double area();

	/**
	  * Returns the perimeter of the polygon
	  * @returns Returns the number of sides in the polygon
	  * @throws IllegalStateException If the figure is not a polygon
	  */
	double perimeter();
}
	


/**
 * The test class RectangleTest.
 *
 * @author  (your name)
 * @version (a version number or a date)
 */
public class RectangleTest extends junit.framework.TestCase
{
    /**
     * Default constructor for test class RectangleTest
     */
    public RectangleTest()
    {
    }

    /**
     * Sets up the test fixture.
     *
     * Called before every test case method.
     */
    protected void setUp()
    {
	}

    /**
     * Tears down the test fixture.
     *
     * Called after every test case method.
     */
    protected void tearDown()
    {
    }


	public void testTenByFive()
	{
		Rectangle tenByFiveRect = new Rectangle(new Location(0,0), new Location(0,5), new Location(10,5), new Location(10,0));
	assertEquals(50.0,tenByFiveRect.area(),.01);
	assertEquals(11.18,tenByFiveRect.diagonalLength(),.01);
	assertEquals(true,tenByFiveRect.isPolygon());
	assertEquals(true,tenByFiveRect.isRectangle());
	assertEquals(true,tenByFiveRect.isRegular());
	assertEquals(false,tenByFiveRect.isSquare());
	assertEquals(4,tenByFiveRect.numSides());
	assertEquals(30,tenByFiveRect.perimeter(),.01);
	assertEquals("[(0,0) (0,5) (10,5) (10,0)] [Rectangle] [area = 50] [perimeter = 30]", tenByFiveRect.toString());
	}
}



/**
 * The test class TriangleTest.
 *
 * @author  (your name)
 * @version (a version number or a date)
 */
public class TriangleTest extends junit.framework.TestCase
{
    /**
     * Default constructor for test class TriangleTest
     */
    public TriangleTest()
    {
    }

    /**
     * Sets up the test fixture.
     *
     * Called before every test case method.
     */
    protected void setUp()
    {
        
    }

    /**
     * Tears down the test fixture.
     *
     * Called after every test case method.
     */
    protected void tearDown()
    {
    }

    public void testIsoscelesRight()
    {
        Triangle isosRight = new Triangle(new Location(0,0), new Location(0,3), new Location(3,0));        
        assertEquals(4.5,isosRight.area(),.01);
        assertEquals(false,isosRight.isEquilateral());
        assertEquals(true,isosRight.isIsosceles());
        assertEquals(true,isosRight.isPolygon());
        assertEquals(false,isosRight.isRegular());
        assertEquals(true,isosRight.isRight());
        assertEquals(false,isosRight.isScalene());
        assertEquals(true,isosRight.isTriangle());
        assertEquals(3,isosRight.numSides());
        assertEquals(7.414,isosRight.perimeter(),.01);
        assertEquals("[(0,0) (0,3) (3,0)] [Isosceles Right] [area = 8] [perimeter = 14]",isosRight.toString());
        assertEquals("Isosceles Right",isosRight.triangleType());
    }
}

/**
 * @author:
 * 
 * You may add more private data if it helps (it probably would)
 * You may add more private methods if it helps (again, probably helpful)
 */
public class Triangle implements Polygon
{
    private int x1, x2, x3, y1, y2, y3;
    
    public Triangle(Location loc1, Location loc2, Location loc3) {
        x1 = loc1.row(); y1 = loc1.col();
        x2 = loc2.row(); y2 = loc2.col();
        x3 = loc3.row(); y3 = loc3.col();        
    }
    
    // these 5 methods must be implemented as part of the Polygon interface
    public boolean isPolygon() { return true;
    }
    public boolean isRegular() { return true;
    }
    public int numSides() { return 1;
    }
    public double area() { return 1.0;
    }
    public double perimeter() { return 1.0;
    }
    
    // these methods are specific to Triangles
    public String triangleType() { return "";
    }
    public boolean isTriangle() { return true;
    }
    public boolean isEquilateral() { return true;
    }
    public boolean isIsosceles() {return true;
    }
    public boolean isRight() { return true;
    }
    public boolean isScalene() { return true;
    }
    public String toString() { return "";
    }
   
    //don't edit this method
    private boolean areDoublesEqual(double x, double y) {
        Double xObj = new Double(x);
        Double yObj = new Double(y);
        return xObj.equals(yObj);
    }
}

public String toString(); // all well-written classes should override this 
                          // inherited method from Object 

// sample return strings:
// [(0,0) (0,5) (4,5) (4,0)] [Rectangle] [area = 20] [perimeter = 18] 
// [(0,0) (0,5) (5,5) (5,0)] [Square] [area = 25] [perimeter = 20] 

public boolean isRectangle(); 
public boolean isSquare(); 
public double diagonalLength(); // coordinates of vertices will have been 
                                // listed in consecutive order working 
                                // around the polygon – therefore, you’ll be able to easily find diagonal vertices


public String toString(); 
// sample return strings: 
// [(1,0) (1,4) (4,0)] [Isosceles Right] [area = 8] [perimeter = 14] 
// [(1,0) (1,4) (1,9)] [Not a Triangle] [area = none] [perimeter = none] 

/** 
 * Determine the type of triangle. 
 * @returns returns one of the following: Equilateral, Isosceles, Isosceles Right, Scalene, Right, Not a Triangle 

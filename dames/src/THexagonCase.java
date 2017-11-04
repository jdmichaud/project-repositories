import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import javax.swing.*;

/**
 * An original cell with 6 sides
 */
public class THexagonCase extends TCase
{
    /**
     * the size of one side of the hexagon
     */
    public final static int hexSize = 15;

    public THexagonCase (int i, TBoard B) { super (i, B); }
    
    /**
     * display the cell in the current frame according to its graphic context
     */
    public void display (Graphics2D g)
    {
	g.setRenderingHint (RenderingHints.KEY_ANTIALIASING, 
			    RenderingHints.VALUE_ANTIALIAS_ON);
	g.setPaint (_gc.getClr ());

	int xs [] = 
	{hexSize, 2 * hexSize, 3 * hexSize, 2 * hexSize, hexSize, 0};
	int ys [] = {0, 0, hexSize, 2 * hexSize, 2 * hexSize, hexSize};
	
	GeneralPath polygon = new GeneralPath(GeneralPath.WIND_EVEN_ODD,
					      xs.length);
	
	polygon.moveTo(xs [0] + _gc.getX (), ys [0] + _gc.getY ());
	for (int i = 1; i < xs.length; i++)
	    polygon.lineTo (xs [i] + _gc.getX (), ys [i] + _gc.getY ());
	
	polygon.closePath ();
	g.fill (polygon);

	g.setStroke (new BasicStroke (1.0f));
	g.setPaint (Color.black);
	g.draw (polygon);

	if (_focused == true)
	    {
		
	    }
    }

    /**
     * receives the mouse handlers to know if a cell is selected
     */
    public boolean onMouseEvent (MouseEvent e) { return false; }
    
    /**
     * Advise the game that this cell is focused
     */ 
    public void setFocus (boolean b) { _focused = b; }

    /**
     * to know if the cell is similar from another hexagon cell
     */
    public boolean compareTo (TCase C)
    {
	if (C instanceof TSquareCase)
	    return (C.getIndex () == getIndex ());
	
	return false;
    }
};

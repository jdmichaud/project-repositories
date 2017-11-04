import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import javax.swing.*;

/**
 * The default cell ... squared
 */

public class TSquareCase extends TCase
{
    /**
     * Width of the cell in pixels
     */
    public final static int hSize = 40;
    /**
     * Height of the cell in pixels
     */
    public final static int vSize = 40;

    public TSquareCase (int i, TBoard B) { super (i, B); }

    /**
     * display the cell in the current frame according to its graphic context
     */
    public void display (Graphics2D g)
    {
	g.setRenderingHint (RenderingHints.KEY_ANTIALIASING, 
			    RenderingHints.VALUE_ANTIALIAS_ON);

	g.setPaint (_gc.getClr ());
	g.fill (new Rectangle2D.Double 
	    (_gc.getX (), _gc.getY (), hSize, vSize));

	if (_focused == true)
	    {
		g.setPaint (Color.white);
		g.setStroke (new BasicStroke (3.0f));
		g.draw (new Rectangle2D.Double 
		    (_gc.getX () + 1, _gc.getY () + 1, hSize - 3, vSize - 3));
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
     * to know if the cell is similar from another squared cell
     */
    public boolean compareTo (TCase C)
    {
	if (C instanceof TSquareCase)
	    return (C.getIndex () == getIndex ());
	
	return false;
    }
};

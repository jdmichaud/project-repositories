import java.util.Vector;
import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import javax.swing.*;

/**
 * A Board with 3 sides and hexagonal cells
 */
public class THexagonBoard extends TBoard
{
    private int _height;
    
    public THexagonBoard (int height)
    {
	_height = height;

	_cases = new Vector ();
	for (int tmp = height, index = 0; tmp > 0; tmp--)
	    for (int i = 0; i < tmp; i++)
		_cases.addElement (new THexagonCase (index++, this));
		
    }

    public TCase createCase (int i) { return new THexagonCase (i, this); }

    public int getHOffset (TCase C)
    {
	int tmp = C.getIndex ();
	int i;
	for (i = _height; i != 0 && (tmp / i) > 0; i--)
	    tmp -= i;

	return 2 * (_height - i) * THexagonCase.hexSize;
    }

    public int getVOffset (TCase C)
    {
	int tmp = C.getIndex ();
	int i;
	for (i = _height; i != 0 && (tmp / i) > 0; i--)
	    tmp -= i;

	return (2 * tmp + (_height - i)) * THexagonCase.hexSize;
    }

    public Color getColorCase (TCase C) { return Color.orange; }

    /**
     * draw the board's cells
     */
    public void display (Graphics2D g)
    {
	for (int i = 0; i < _cases.size (); i++)
	    {
		TCase C = (TCase) _cases.get (i);

		int xCase = getHOffset (C);
		int yCase = getVOffset (C);

		C.setGC (new TGraphicContext (xCase, yCase, getColorCase (C)));
		C.display (g);
	    }
    }
    
    /**
     * allow to know if a cell have been selected.
     * It returns true if the display have to been refreshed.
     */
    public boolean onMouseEvent (MouseEvent e)
    {
	switch (e.getID ())
	    {
	    case MouseEvent.MOUSE_CLICKED:
		for (int i = 0; i < _cases.size (); i++)
		    {
			THexagonCase sq = (THexagonCase) _cases.get (i);
			int x = getHOffset (sq) + THexagonCase.hexSize;
			int y = getVOffset (sq);
			
			if (e.getX () > x && e.getX () < x + sq.hexSize &&
			    e.getY () > y && e.getY () < y + sq.hexSize)
			    {
				setFocus (false);
				sq.setFocus (true);
				return true;
			    }
		    }
	    }

	return false;
    }
    
    /**
     * Focus or unfocus all the board's cell.   
     */
    public void setFocus (boolean b)
    {
	for (int i = 0; i < _cases.size (); i++)
	    ((TCase) _cases.get (i)).setFocus (b);
    }

    public void displayText ()
    {
	
    }
};

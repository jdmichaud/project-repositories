import java.util.Vector;
import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import javax.swing.*;

/**
 * A Square board _width * _height
 */
public class TSquareBoard extends TBoard
{
    private int _width;
    private int _height;
    
    public TSquareBoard (int width, int height)
    {
	super (height * width);

	_width = width;
	_height = height;
    }

    public TCase createCase (int i) { return new TSquareCase (i, this); }

    public int getHOffset (TCase C)
    {
	return TSquareCase.hSize * (C.getIndex () % _width);
    }

    public int getVOffset (TCase C)
    {
	return TSquareCase.vSize * (C.getIndex () / _height);
    }

    public Color getColorCase (TCase C)
    {
	switch (_width % 2)
	    {
	    case 0:
		if ((C.getIndex () + C.getIndex () / _height) % 2 == 0)
		    return Color.orange;
		else
		    return Color.black;

	    default:
		if (C.getIndex () % 2 == 0)
		    return Color.orange;
		else
		    return Color.black;
	    }
    }

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

	g.setPaint (Color.black);
	g.setStroke (new BasicStroke (2.0f));
	g.draw (new Rectangle2D.Double
	    (0, 0, _width * TSquareCase.hSize, _height * TSquareCase.vSize));
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
			TSquareCase sq = (TSquareCase) _cases.get (i);
			int x = getHOffset (sq);
			int y = getVOffset (sq);
			
			if (e.getX () > x && e.getX () < x + sq.hSize &&
			    e.getY () > y && e.getY () < y + sq.vSize)
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

    public int getWidth ()
    {
	return _width;
    }

    public int getHeight ()
    {
	return _height;
    }

    public void displayText ()
    {
	for (int i = 0; i < _height; i++)
	    {
		String s = new String ("");
		
		for (int j = 0; j < _width; j++)
		    if (((TCase) _cases.get (i * _width + j)).getPion () != null)
			s += " X ";
		    else
			s += "   ";
		System.out.println (s);
	    }
    }
};

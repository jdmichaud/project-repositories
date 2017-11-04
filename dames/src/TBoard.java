import java.util.Vector;
import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import javax.swing.*;

/**
 * The game's board
 */
public abstract class TBoard implements TDrawable
{
    /**
     * a board is a list of cells, to allow many representations
     */
    protected Vector	_cases;
    protected int	_nbCases;

    public TBoard()
    { _cases = new Vector (); }

    public TBoard(int nbCases)
    {
	_nbCases = nbCases;
	
	_cases = new Vector ();
	for (int i = 0; i < nbCases; i++)
	    _cases.addElement (createCase(i));
    }

    /**
     * create the cell associated with the selected board
     */
    public abstract TCase createCase (int i);
    
    public int getNbCases ()
    { return _nbCases; }
    
    public Vector getCases ()
    { return _cases; }
    
    public TCase getCase (int i)
    { return (TCase) _cases.get (i); }

    /**
     * return the list of cells that can be reached by another cell,
     * and from a location
     */
    public Vector getCases (TCase src, TLocation loc)
    {
	return loc.getCases (this, src);
    }

    /**
     * return the cell selected by the user
     */
    public TCase getFocusedCase ()
    {
	for (int i = 0; i < _cases.size (); i++)
	    if (((TCase) _cases.get (i)).isFocused ())
		return ((TCase) _cases.get (i));

	return null;
    }

    /**
     * return the x position of a cell: the position of a cell
     * depends on the other cells (board)
     */
    public abstract int getHOffset (TCase C);

    /**
     * return the y position of a cell: the position of a cell
     * depends on the other cells (board)
     */
    public abstract int getVOffset (TCase C);

    /**
     * return the color of a case in one board (alternative colors)
     */
    public abstract Color getColorCase (TCase C);

    public abstract void displayText ();
};

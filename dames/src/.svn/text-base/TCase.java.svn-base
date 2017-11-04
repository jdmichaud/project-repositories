import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import javax.swing.*;

/**
 * A cell : an abstraction of one board's part
 */
public abstract class TCase implements TDrawable
{
    /**
     * index (position) of the cells in the board
     */
    protected int		_idx;
    
    /**
     * The graphicContext creates the caracteristics of the display
     */
    protected TGraphicContext	_gc;

    /**
     * to know if the cell is focused (selected)
     */
    protected boolean		_focused;
    
    /**
     * A cell can be attached to zero or one instance of TPion
     */
    protected TPion		_pion;
    
    /**
     * A cell knows the board that nests it
     */
    protected TBoard		_board;

    // -------------------------------------

    public TCase (int i, TBoard B)
    {
	_idx = i;
	_focused = false;
	_pion = null;
	_board = B;
    }

    public int getIndex () { return _idx; }

    public void setGC (TGraphicContext gc) { _gc = gc; }

    public TGraphicContext getGC () { return _gc; }

    public void setPion (TPion pion)
    { _pion = pion; }

    public TPion getPion ()
    { return _pion; }
    
    /**
     * return whether the cell is empty or not
     */
    public boolean isEmpty ()
    { return _pion == null; }

    /**
     * Return his x postion ... requesting his mother board
     */
    public int getHOffset ()
    { return _board.getHOffset (this); }

    /**
     * Return his y postion ... requesting his mother board
     */
    public int getVOffset ()
    { return _board.getVOffset (this); }

    public TBoard getBoard () { return _board; }

    /**
     * return whether the cell is focused or not
     */
    public boolean isFocused () { return _focused == true; }

    /**
     * to know if 2 cells are similar
     */
    public abstract boolean compareTo (TCase C);
};

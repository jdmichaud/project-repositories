import java.util.Vector;
import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import javax.swing.*;

/**
 * the default piece
 */
public class TPion extends TEntity
{
    /**
     * the offset to place the pion in a cell
     */
    public final static int offset = 5;

    /**
     * the pion is represented by an ellipse of horizontal size
     */
    public final static int hSize = 30;

    /**
     * the pion is represented by an ellipse of vertical size
     */
    public final static int vSize = 30;

    public TPion (TPlayer player, TCase initCase)
    {
	_player = player;
	_case = initCase;
    }

    /**
     * displays a pion
     */
    public void display (Graphics2D g)
    {
	g.setRenderingHint (RenderingHints.KEY_ANTIALIASING, 
			    RenderingHints.VALUE_ANTIALIAS_ON);
	
	_gc = new TGraphicContext (_case.getHOffset (),
				   _case.getVOffset (), 
				   _player.getClr ());
	
	g.setPaint (_gc.getClr ());
	g.fill (new Ellipse2D.Double 
	    (_gc.getX () + offset, _gc.getY () + offset, hSize, vSize));

	g.setStroke (new BasicStroke (1.0f));
	g.setPaint (Color.black);
	g.draw (new Ellipse2D.Double 
	    (_gc.getX () + offset, _gc.getY () + offset, hSize, vSize));
    }

    /**
     * returns the two default actions for a pion : move and eat
     */
    public Vector getActions (boolean dir)
    {
	Vector actions = new Vector ();	
	actions.addElement (new TDefaultMove (1, dir));
	actions.addElement (new TEat ());

	return actions;
    }
};

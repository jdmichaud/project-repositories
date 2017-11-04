import java.util.Vector;
import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import javax.swing.*;

/*
** An entity is a piece like a pion or a queen
*/
public abstract class TEntity implements TDrawable
{
    /**
     * the cell where the pion is located
     */ 
    protected TCase	_case;

    /**
     * the player that owns this entity
     */
    protected TPlayer	_player;

    /**
     * the graphical environment
     */
    protected TGraphicContext _gc;
    
    public void setGC (TGraphicContext gc) { _gc = gc; }
    
    public TGraphicContext getGC () { return _gc; }
    
    /**
     * displays the entity
     */    
    public abstract void display (Graphics2D g);
    
    /**
     * receive the mouse events
     */    
    public boolean onMouseEvent (MouseEvent e) { return false; }
    
    /**
     * select a piece
     */
    public void setFocus (boolean b) { }

    /**
     * return the actions possible for one specific entity :
     * a pion can move and eat, a queen ca move through many cells
     * this action are instanciated by the server rules
     */
    public abstract Vector getActions (boolean dir);   
    
    public TPlayer getPlayer () { return _player; }

    public TCase getCase () { return _case; }

    public void setCase (TCase C) { _case = C; } 
};

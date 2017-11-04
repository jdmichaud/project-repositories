import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import javax.swing.*;

/**
 * this interface give an object the capacity to display itself in a frame
 */
public interface TDrawable
{
    /**
     * the display function
     */
    public abstract void display (Graphics2D g);

    /**
     * the function that receives all the mouse events
     */
    public abstract boolean onMouseEvent (MouseEvent e);

    /**
     * interact with an object to select it
     */
    public abstract void setFocus (boolean b);
};

import java.util.Vector;
import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import javax.swing.*;

/**
 * create the frame, initialize the display
 */
public class TDisplayControler extends JApplet
{
    /**
     * current frame
     */
    private JFrame	_frame;
    private FontMetrics	_fontMetrics;

    /**
     * the window's width
     */
    private int		_width;
    
    /**
     * the window's height
     */
    private int		_height;

    final static int _maxCharHeight	= 15;
    final static int _minFontSize	= 6;

    /**
     * The component that implements the interface drawable
     * will be displayed by the controler
     */
    private Vector		_drawables;

    public TDisplayControler (Vector drawables)
    { _drawables = drawables; }

    // -------------------------------------

    /**
     * create the fonts
     */
    FontMetrics pickFont (Graphics2D g2, String longString, int xSpace)
    {
        boolean fontFits	= false;
        Font font		= g2.getFont();
        FontMetrics fontMetrics = g2.getFontMetrics();
        int size		= font.getSize();
        String name		= font.getName();
        int style		= font.getStyle();

        while (!fontFits)
	    {
		if ((fontMetrics.getHeight() <= _maxCharHeight)
		    && (fontMetrics.stringWidth(longString) <= xSpace))
		    fontFits = true;
		else
		    {
			if ( size <= _minFontSize )
			    fontFits = true;			
			else
			    {
				g2.setFont(font = new Font(name, style,
							   --size));
				fontMetrics = g2.getFontMetrics();
			    }
		    }
	    }
	
        return fontMetrics;
    }

    /**
     * init the display
     */
    public void initWindowDPY (int width, int height)
    {
	_width	= width;
	_height = height;

	_frame	= new JFrame("Un jeu de Dames qu'il est bien !");
	_frame.addWindowListener(new WindowAdapter()
	    {
		public void windowClosing(WindowEvent e)
		{ System.exit (0); }
	    });

	_frame.getContentPane ().add ("Center", this);
	setBackground (Color.white);
        setForeground (Color.black);
	_frame.pack ();
	_frame.setSize (new Dimension (width, height));
	_frame.show ();
	enableEvents (MouseEvent.MOUSE_CLICKED);
    }

    /**
     * method that is called when the frame have to be refreshed
     */
    public void paint (Graphics g)
    {
	for (int i = 0; i < _drawables.size (); i++)
	    ((TDrawable) _drawables.get (i)).display ((Graphics2D) g);
    }
    
    /**
     * receives the mouse events
     */
    protected void processMouseEvent (MouseEvent e)
    {
	boolean reDraw = false;

	for (int i = 0; i < _drawables.size (); i++)
	    reDraw |= ((TDrawable) _drawables.get (i)).onMouseEvent (e);

	if (reDraw == true)
	    repaint ();
    }
};


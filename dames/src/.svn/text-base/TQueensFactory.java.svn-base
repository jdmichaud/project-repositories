import java.util.Vector;
import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import javax.swing.*;

/**
 * The factory to play classical Queens
 */    
public class TQueensFactory implements TRulesFactory
{
    public final static int DIR_UP = 0;
    public final static int DIR_UPRIGHT = 1;
    public final static int DIR_RIGHT = 2;
    public final static int DIR_DOWNRIGHT = 3;
    public final static int DIR_DOWN = 4;
    public final static int DIR_DOWNLEFT = 5;
    public final static int DIR_LEFT = 6;
    public final static int DIR_UPLEFT = 7;
    
    /**
     * the number of rows that the pions will occupy
     */
    public final static int _nbPRows = 4;
	
    /**
     * width of the board
     */
    private int _width;

    /**
     * height of the board
     */
    private int _height;

    /**
     *
     */
    private int _pos;

    public TQueensFactory (Vector infos)
    {
	_width = ((Integer) infos.get (0)).intValue ();
	_height = ((Integer) infos.get (1)).intValue ();
    }
    
    /**
     * create the board
     */
    public TBoard getBoard ()
    {
	return new TSquareBoard (_width, _height);
    }

    /**
     *
     */
    public int getPosPlayer ()
    {
	return _pos;
    }

    /**
     * return the number of players
     */
    public int getNbPlayers () { return 2; }

    /**
     * return the hit in a string format 
     */
    public String encodeHit (THit H)
    {
	return new String ("");
    }
    
    /**
     * create a hit thanks to a string
     */
    public THit decodeHit (String s)
    {
	return new THit (new TPlayer (Color.yellow, 0));
    }
    
    /**
     * create the players
     */
    public Vector getPlayers (TBoard B)
    {	
	Vector players = new Vector ();
	
	TPlayer player = new TPlayer (new Color(220, 120, 50), 0);

	Vector pions	= new Vector ();
	for (int i = 0; i < _nbPRows; i++)
	    for (int j = i % 2; j < _width; j += 2)
		{
		    TPion P = new TPion 
			(player, B.getCase (i * _width + j));
		    pions.addElement (P);
		    B.getCase (i * _width + j).setPion (P);
		    
		}
	player.setPions (pions);

	players.addElement (player);

	player = new TPlayer (new Color(220, 220, 160), 1);

	pions = new Vector ();
	for (int i = 0; i < _nbPRows; i++)
	    for (int j = (i + 1) % 2; j < _width; j += 2)
		{
		    TPion P = new TPion 
			(player, B.getCase ((_height - i - 1) * _width + j));
		    pions.addElement (P);
		    B.getCase ((_height - i - 1) * _width + j).setPion (P);
		}
	player.setPions (pions);

	players.addElement (player);

	return players;
    }
};

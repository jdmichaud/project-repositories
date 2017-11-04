import java.util.Vector;
import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import javax.swing.*;

/**
 * the player class
 */
public class TPlayer implements TDrawable
{
    /**
     * a vector of pions
     */
    private Vector _pions;

    /**
     * the player id
     */
    private int _id;

    /**
     * the client id
     */
    private int _clientId;

    /**
     * the id of the game the player is living in
     */
    private int _gameId;

    /**
     * the name of the player
     */
    private String _nick;

    /**
     * the ELO score
     */
    private int _score;


    
    private Color _clr;

    public TPlayer(Vector pions, int id, String nick, int score, int gameId)
    {
	_pions = pions;
	_id = id;
	_gameId = gameId;
	_nick = nick;
	_score = score;
    }

    public TPlayer (Vector V)
    {
	_pions = V; 
    }

    public TPlayer (Color clr, int clientId)
    {
	_clr = clr; 
	_clientId = clientId;
    }

    public TPion getPion (int i)
    { return (TPion) _pions.get (i); }

    public Vector getPions ()
    { return _pions; }

    public int getId ()
    { return (_id); }

    public int getClientId ()
    { return (_clientId); }

    public void setPions (Vector V) { _pions = V; }

    public int getScore ()
    { return (_score); }

    public String getNick ()
    { return (_nick); }

    public int getGameId ()
    { return (_gameId); }

    public Color getClr () { return _clr; }


    /**
     * the display function
     */
    public void display (Graphics2D g)
    {
	for (int i = 0; i < _pions.size (); i++)
	    ((TPion) _pions.get (i)).display (g);
    }
    
    /**
     * receives the mouse events
     */
    public boolean onMouseEvent (MouseEvent e) { return false; }
    
    /**
     * receives the focus instruction
     */
    public void setFocus (boolean b) { }
};

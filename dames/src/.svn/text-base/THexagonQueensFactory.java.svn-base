import java.util.Vector;
import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import javax.swing.*;

public class THexagonQueensFactory implements TRulesFactory
{
    private int _height;
    private int _pos;

    public THexagonQueensFactory (Vector infos)
    {
	_height = ((Integer) infos.get (0)).intValue ();
	_pos = ((Integer) infos.get (1)).intValue ();
    }

    public int getPosPlayer ()
    {
	return _pos;
    }
    
    public TBoard getBoard ()
    {
	return new THexagonBoard (_height);
    } 

    public int getNbPlayers () { return 3; }

    public String encodeHit (THit H)
    {
	return new String ("");
    }
    
    public THit decodeHit (String s)
    {
	return new THit (new TPlayer (Color.red, 0));
    }

    public TPion createPion (TBoard board, TPlayer player, TCase initCase)
    {
	System.out.println ("Abort !!");
	System.exit (1);
	return null;
    }
    
    public Vector getPlayers (TBoard board)
    {
	Vector players = new Vector ();
	
	players.addElement (new TPlayer (Color.red, 0));
	players.addElement (new TPlayer (Color.blue, 1));
	players.addElement (new TPlayer (Color.green, 2));
	
	return players;
    }
};

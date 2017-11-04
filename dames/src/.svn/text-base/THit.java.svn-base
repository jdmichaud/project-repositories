import java.util.Vector;

public class THit
{
    protected Vector	_cases;
    protected TPlayer	_player;
    protected int	_nbSelec;
    
    public THit (TPlayer player)
    {
	_player = player;
	_nbSelec = 2;
	_cases = new Vector ();
    }

    public THit (TPlayer player, String hit, TBoard board)
    {
	_player = player;
	_cases = new Vector ();
	
	String str[] = hit.split (":");

	for (int i = 0; i < str.length; i++)
	    _cases.addElement
		(board.getCase (new Integer (str[i]).intValue ()));
    }

    public TCase getCase (int i)
    { return (TCase) _cases.get (i); }

    public void addCase (TCase C)
    { _cases.addElement (C); }

    public void addCase (Vector V)
    { 
	for (int i = 0; i < V.size (); ++i)
	    _cases.addElement (V.get (i)); 
    }

    public TPlayer getPlayer ()
    { return _player; }
    
    public void setPlayer (TPlayer P)
    { _player = P; }
    
    public TBoard getBoard ()
    {
	if (_cases.size () != 0)
	    return getCase (0).getBoard ();
	
	System.out.println ("Failed in THit.getBoard ()");
	System.exit (1);
	
	return null;
    }

    public int getNbCases () { return _cases.size (); }

    public boolean compareTo (THit H)
    {
	for (int i = 0; i < getNbCases () && i < H.getNbCases (); i++)
	    if (H.getCase (i).compareTo (getCase (i)) == false)		
		return false;
	
	return true;
    }

    public String toString ()
    {
	return new String (_player.getClientId () + ":" +
			   ((TCase) _cases.get (0)).getIndex () + ":" +
			   ((TCase) _cases.get (1)).getIndex ());
    }

    public boolean isCompleted ()
    {
	return _cases.size () == _nbSelec;
    }

    public void compute ()
    {
	Vector pions = _player.getPions ();
	
	for (int i = 0; i < pions.size (); i++)
	    {
		TCase oldPos = (TCase) _cases.get (0);
		TCase newPos = (TCase) _cases.get (1);
		TCase currPos = ((TPion) pions.get (i)).getCase ();

		if (currPos.compareTo (oldPos))
		    {
			((TPion) pions.get (i)).setCase (newPos);
			newPos.setPion ((TPion) pions.get (i));
			oldPos.setPion (null);
		    }
	    }
    }

    public void unFocusCases ()
    {
	for (int i = 0; i < _cases.size (); ++i)
	    ((TCase) _cases.get (i)).setFocus (false);
    }
};

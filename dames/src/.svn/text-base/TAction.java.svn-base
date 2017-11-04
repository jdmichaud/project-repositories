import java.util.Vector;

/**
 * the actions describes the behaviour of an entity
 */
public abstract class TAction
{
    /**
     * the cells that will be pointed
     */
    protected Vector _locations;

    /**
     * an action have conditions
     */
    protected Vector _conditions;

    public Vector getLocations ()
    { return _locations; }

    public TLocation getLocation (int i) 
    { return (TLocation) _locations.get (i); }

    public Vector getConditions ()
    { return _conditions; }

    public TCondition getCondition (int i) 
    { return (TCondition) _conditions.get (i); }

    /**
     * determines if this action can be reached with the giving hit
     */
    public boolean isAllowed (THit H)
    {
	TBoard board = H.getBoard ();

	for (int i = 0; i < _locations.size (); i++)
	    {
		Vector locs = board.getCases
		    (H.getCase (0), (TLocation) _locations.get (i));
		
		for (int j = 0; j < locs.size (); j++)
		    if (H.getCase (1).compareTo ((TCase) locs.get (j)) == true)
			return true;
	    }

	return false;
    }

    /**
     * determines all the possible hits that a player can make from one cell
     */
    public abstract Vector getPossibleHits (TPlayer P, TCase C);
};

import java.util.Vector;

/**
 * the default move that all pions will use
 */
public class TDefaultMove extends TAction
{
    public TDefaultMove (int dist, boolean clientDirection)
    {
	_locations = new Vector ();
	TLocation loc1;
	TLocation loc2;

	if (clientDirection == true)
	    {
		loc1 = new TLocation (TQueensFactory.DIR_UPLEFT, dist);
		loc2 = new TLocation (TQueensFactory.DIR_UPRIGHT, dist);
	    }
	else
	    {
		loc1 = new TLocation (TQueensFactory.DIR_DOWNLEFT, dist);
		loc2 = new TLocation (TQueensFactory.DIR_DOWNRIGHT, dist);
	    }
	
	_locations.addElement (loc1);
	_locations.addElement (loc2);
	
	_conditions = new Vector ();
	TCondition cond1 = new TCondition (loc1, TCondition.IS_EMPTY);
	TCondition cond2 = new TCondition (loc2, TCondition.IS_EMPTY);
	_conditions.addElement (cond1);	
	_conditions.addElement (cond2);
    }    
    
    /**
     * The default move is not prioritary
     */
    public Vector getPossibleHits (TPlayer P, TCase C)
    {
	return new Vector ();
    }
};

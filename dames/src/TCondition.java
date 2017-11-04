import java.util.Vector;

/**
 * this class is related to the TAction :
 * it is usefull to determines if an action can be done in only specific
 * situations
 */
public class TCondition
{
    /**
     * the location targeted by the condition
     */
    private TLocation	_location;

    /**
     * the type of condition
     */
    private int		_type;

    public final static int IS_EMPTY = 0;
    public final static int IS_ADV = 1;

    public TCondition (TLocation location, int flag)
    {
	_type = flag;
	_location = location;
    }

    public TLocation getLocation ()
    { return _location; }

    /**
     * return true if the condition is verified
     */
    public boolean isVerified (TCase C)
    {
	TBoard board = C.getBoard ();

	Vector cases = board.getCases (C, _location);

	for (int i = 0; i < cases.size (); i++)
	    switch (_type)
		{
		case IS_EMPTY:
		    if ((((TCase) cases.get (i)).isEmpty ()) == false)
			return false;
		case IS_ADV:
		    TCase C2 = (TCase) cases.get (i);
		    int id1 = C.getPion ().getPlayer ().getClientId ();
		    int id2 = C2.getPion ().getPlayer ().getClientId ();
		    
		    if (id1 == id2)
			return false;
		}
	
	return true;
    }
};

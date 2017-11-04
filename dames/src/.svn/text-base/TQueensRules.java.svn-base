import java.util.Vector;

/**
 * The queens rules allows the clients to play the traditionnal Queens game.
 * There are two players, playing on a sqaure board (10 x 10)
 * They have both 20 pions.
 */
public class TQueensRules extends TRules
{    
    public TQueensRules (Vector V)
    { _infos = V; }
    
    /**
     * Although a hit is allowed, the rules must determines if no others hits
     * must be played instead. Some hits are more prioritary.
     */
    public boolean isPlayable (TBoard B, THit H)
    {
	TCase target = H.getCase (0);
	
	if (target.getPion ().getPlayer () != H.getPlayer ())
	    return false;

	Vector act = target.getPion ().getActions
	    (H.getPlayer ().getClientId () == 0);
	
	for (int i = 0; i < act.size (); i++)
	    if (((TAction) act.get (i)).isAllowed (H))
		return true;
	    
	return false;
    }

    /**
     * Determines whether a hit is allowed or not by the rules
     */
    public boolean isAllowed (TBoard B, THit H)
    {
	if (!isPlayable (B, H))
	    return false;

	Vector hits = getHits (B, H.getPlayer ());
	for (int i = 0; i < hits.size (); i++)
	    if (H.compareTo ((THit) hits.get (i)) == true)
		return true;
	
	return false;
    }

    /**
     * Gives a list of hits of same priority that a player must play.
     */
    public Vector getHits (TBoard B, TPlayer P)
    {
	Vector pions = P.getPions ();
	TBoard board = ((TPion) pions.get (0)).getCase ().getBoard ();

	for (int i = 0; i < pions.size (); i++)
	    {
		TPion pion = (TPion) pions.get (i);
		TEat e = new TEat ();		
		//FIXME j'ai mis pour ke ca compil
		Vector hits = 
		    e.getPossibleHits (P, ((TPion) pions.get (0)).getCase ());

		for (int j = 0; j < hits.size (); j++)
		    if (e.isAllowed ((THit) hits.get (i)))
			{
			    
			}
	    }

	return new Vector ();
    }

    /**
     * return the name of the factory, and the informations that describes
     * the functionment of this factory
     */
    public String getFactory ()
    {
	String str = new String ("TQueensFactory:" +
			   (Integer) _infos.get (0) + ":" + 
			   (Integer) _infos.get (1));
	return str;
    }   

    /**
     *
     */
    public int nbPlayer ()
    {
	return 2;
    }
};

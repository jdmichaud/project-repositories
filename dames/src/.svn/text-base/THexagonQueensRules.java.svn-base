import java.util.Vector;

/**
 * This is quite the same thing than classical queens, but here the board has
 * hexagonals cells.
 */

public class THexagonQueensRules extends TRules
{    
    public THexagonQueensRules (Vector V)
    { _infos = V; }
    
    /**
     * Determines whether a hit is allowed or not by the rules
     */
    public boolean isAllowed (TBoard B, THit H)
    {
	return true;
    }

    /**
     * Although a hit is allowed, the rules must determines if no others hits
     * must be played instead. Some hits are more prioritary.
     */
    public boolean isPlayable (TBoard B, THit H)
    {
	return true;
    }
    
    /**
     * Gives a list of hits of same priority that a player must play.
     */
    public Vector getHits (TBoard B, TPlayer P)
    {
	return new Vector ();
    }

    /**
     * return the name of the factory, and the informations that describes
     * the functionment of this factory
     */
    public String getFactory ()
    {
	return new String ("THexagonQueensFactory:" +
			   (Integer) _infos.get (0));
    }    

    /**
     *
     */
    public int nbPlayer ()
    {
	return 3;
    }
};

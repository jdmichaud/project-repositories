import java.util.Vector;

/**
 * The rules are located only in the server.
 * It is the rules that determines whether a hit is playable or not
 * It returns a factory, allowing both the server and the client to instanciate
 * a component that will create the game : the board, the entities,
 * the players ...
 */

public abstract class TRules
{
    /**
     * Informations about the rules (width of the board, number of players...)
     */
    protected Vector _infos;
    
    /**
     * Determines whether a hit is allowed or not by the rules
     */
    public abstract boolean isAllowed (TBoard B, THit H);

    /**
     * Although a hit is allowed, the rules must determines if no others hits
     * must be played instead. Some hits are more prioritary.
     */
    public abstract boolean isPlayable (TBoard B, THit H);

    /**
     * Gives a list of hits of same priority that a player must play.
     */
    public abstract Vector getHits (TBoard B, TPlayer P);

    /**
     * return the name of the factory, and the informations that describes
     * the functionment of this factory
     */
    public abstract String getFactory ();
    
    /**
     *
     */
    public abstract int nbPlayer ();
};

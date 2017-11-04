import java.util.Vector;

/**
 * The Rules Factories creates the game's components:
 * - the board
 * - the players
 * - the pions
 * - ...
 */
public interface TRulesFactory
{
    /**
     * create the board
     */
    public abstract TBoard getBoard ();

    /**
     * create the players
     */
    public abstract Vector getPlayers (TBoard board);

    /**
     * return the number of players
     */
    public abstract int getNbPlayers ();

    /**
     * return the hit in a string format 
     */
    public abstract String encodeHit (THit H);

    /**
     * create a hit thanks to a string
     */
    public abstract THit decodeHit (String s);

    /**
     *
     */
    public abstract int getPosPlayer ();
};

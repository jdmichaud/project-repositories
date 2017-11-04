import java.util.Vector;

/**
 * The TDB is an abstract class which is the main actor of the game DB module.
 * It contains abstract needed methods that the duaghter class must at list 
 * implement.
 */


public abstract class TDB
{
    public abstract String getName ();
    public abstract void initTables () throws Exception;
    public abstract void saveGame (TGame game);
    public abstract void saveProfil (TPlayer player) throws Exception;
    public abstract TGame loadGame (int gameId) throws Exception;
    public abstract TPlayer loadProfil (int playerId) throws Exception;
    public abstract int newGameId ();
};

import java.util.Vector;

/**
 * the game owns all the informations about a game:
 * board, players, rules ...
 */
public class TGame
{
    /**
     * the list of players
     */
    protected Vector		_players;

    /**
     * the rules
     */
    protected TRules		_rules;

    /**
     * the number of players
     */
    protected int		_nbPlayers;

    /**
     * the id of the game
     */
    protected int		_id;

    /**
     * the rules factory that will create the game
     */
    protected TRulesFactory	_rf;

    /**
     * the board
     */
    protected TBoard		_board;

    /**
     *
     */
    protected int		_idPlayer;


    public TGame (int nb)
    { _nbPlayers = nb; }
    
    public TGame () {}

    public TGame (int gameId, String gameType, int nb)
    { 
	_nbPlayers = nb; 
	_id = gameId;
    }

    public void NIY ()
    { System.out.println ("Not Implemented Yet"); }

    public TBoard getBoard ()
    { return _board; }

    public void setBoard (TBoard board)
    { _board = board; }

    public TRules getRules()
    { return _rules; }

    public int getId()
    { return _id; }

    public void setRules(TRules rules)
    { _rules = rules; }

    public int getNbPlayers()
    { return _nbPlayers; }

    public Vector getPlayers()
    { return _players; }

    public void setPlayers(Vector players)
    { _players = players; }

    /**
     * instanciate a factory thanks to a string describing the factory name
     * and a vector of informations about the game rules
     */
    public void initRulesFactory (String rfName, Vector infos)
    {
	try {
	    Class rfClass = Class.forName (rfName);
	    
	    Class signature[] = new Class[1];
	    signature[0] = Vector.class;
	    
	    java.lang.reflect.Constructor c = rfClass.getConstructor
		(signature);
	    
	    Object args[] = new Object[1];
	    args[0] = infos;
	    
	    _rf = (TRulesFactory) c.newInstance (args);
	    if (_rf == null)
		throw new AssertionError ("Impossible to load RulesFactory");
	}
	catch (Exception e) {
	    System.exit (4);
	}
    }

    /**
     * create the game with the factory
     */
    public void initGame ()
    {
	_board = _rf.getBoard ();
	_players = _rf.getPlayers (_board);
	_nbPlayers = _rf.getNbPlayers ();
	_idPlayer = _rf.getPosPlayer ();
    }
    
    /**
     * returns a string describing the game and its rules
     */
    public String toNet () { return ("GAME"); }

    /**
     * return a player thanks to his id
     */ 
    public TPlayer getPlayerFromId (int id)
    {
	for (int i = 0; i < _players.size (); ++i)
	    if (((TPlayer) _players.get (i)).getClientId () == id)
		return (TPlayer) _players.get (i);

	System.err.println ("Internal error in getPlayerFromId (int id)");
	System.exit (8);
	return null;
    }

    /**
     * return a player thanks to his id
     */ 
    public TPlayer getPlayer (int idPl)
    {
	return (TPlayer) _players.get (idPl);
    }
};

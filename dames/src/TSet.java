import java.util.Vector;
import java.util.Iterator;

public class TSet
{
    private Vector _players;
    private Vector _observers;
    private TGame _game;
    private int _id = -1;
    private TServerGame _gameServer;

    /**
     * Counter
     */
    private int _counter = 0;

    /**
     * Constructor with the pre-created list of player 
     * and the Game associated
     */
    public TSet (Vector players, TGame game)
    {
	Iterator it = players.iterator ();

	_id = ((TNetServerThread) it.next ()).getId();
	_players = players;
	_game = game;
	_observers = new Vector ();
    }

    /**
     * Constructor players
     */
    public TSet (Vector players)
    {
	Iterator it = players.iterator ();

	_id = ((TNetServerThread) it.next ()).getId();
	_players = new Vector ();
	_observers = new Vector ();
    }

    /**
     * Constructor with only the Game
     */
    public TSet (TGame game)
    {
	_players = new Vector ();
	_game = game;
	_observers = new Vector ();
    }

    /**
     *
     */
    public void setGame (TGame game)
    {
	_game = game;
    }

    /**
     *
     */
    public int getCounter ()
    {
	_counter++;
	return (_counter - 1);
    }

    /**
     * Add a player number to the TSet
     */
    public void addPlayer (TNetServerThread p)
    {
	_players.add (p);
    }

    /**
     * Add a observer number to the TSet
     */
    public void addObserver (TNetServerThread p)
    {
	if (_id == -1)
	    _id = p.getId ();
	_observers.add (p);
    }

    /**
     * Get an iterator on the vector of player
     */
    public Iterator getPlayersIterator ()
    {
	return (_players.iterator ());
    }

    /**
     * Get the players
     */
    public Vector getPlayers ()
    {
	return (_players);
    }

    /**
     * Get an iterator on the vector of observer
     */
    public Iterator getObserversIterator ()
    {
	return (_observers.iterator ());
    }

    /**
     * Get the observers
     */
    public Vector getObservers ()
    {
	return (_observers);
    }

    /**
     * Get the game
     */
    public TGame getGame ()
    {
	return (_game);
    }

    /**
     * Return the game id
     */
    public int getGameId ()
    {
	return (_id);
    }

    public boolean isHere (TNetServerThread client)
    {
	Iterator it = _players.iterator ();

	for (int i = 0; i < _players.size (); ++i, it.hasNext ())
	    if (((TNetServerThread) it.next ()).getId () == client.getId ())
		return true;
	return false;
    }

    public boolean isHere (int client)
    {
	Iterator it = _players.iterator ();

	for (int i = 0; i < _players.size (); ++i, it.hasNext ())
	    if (((TNetServerThread) it.next ()).getId () == client)
		return true;
	return false;
    }

    /**
     *
     */
    public void setServerGame (TServerGame s)
    {
	_gameServer = s;
    }

    /**
     *
     */
    public TServerGame getServerGame ()
    {
	return _gameServer;
    }
}

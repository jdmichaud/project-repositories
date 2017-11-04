import java.io.*;
import java.net.*;
import java.util.HashMap;
import java.util.Vector;
import java.util.Iterator;

/**
 * communication modul for the server
 */
public class TNetServer
{

    /**
     * Communication Port 
     */
    private int _port;

    /**
     * Counter for player id
     * Each player have an unique id
     */
    private int _count;

    /**
     * Vector of TSet which contains the association
     * between players, observers and game
     */
    private Vector _games;

    /**
     * Waiting creator of game
     */
    private Vector _waiting_games;

    private TDB _db;

    /**
     * Constructor for TNetServer
     */
    public TNetServer (TDB db, int port)
    {
	_db = db;
	_port = port;
	_games = new Vector ();
	_waiting_games = new Vector ();
    }
    
    private void NIY ()
    {
	System.out.println ("Not Implemented Yet");
    }

    /**
     * Wait for client connection
     */
    public void create() throws IOException
    {
	ServerSocket serverSocket = null;
	boolean listening = true;         

	try 
	    {
		serverSocket = new ServerSocket(_port);
		while (listening)
		    {
			new TNetThread(_port, 
				       serverSocket.accept(), 
				       _count++,
				       this).start();
		    }
		serverSocket.close();
	    }
	catch (IOException e) 
	    {
		System.err.println("Could not listen on port: " + _port + ".");
		System.exit(-1);
	    }
    }

    /**
     * Games accessor
     */
    public Vector getGames ()
    {
	return (_games);
    }

    /**
     * Wainting_Games accessor
     */
    public Vector getWaitingGames ()
    {
	return (_waiting_games);
    }

    /**
     * Register a game
     */
    public TServerGame register (TNetServerThread pl, int creator)
    {
	Vector cl = new Vector ();

	Iterator it = _waiting_games.iterator ();
	for (int i = 0; i < _waiting_games.size (); ++i, it.hasNext ())
	    {
		TNetServerThread cr = (TNetServerThread) it.next ();
		if (creator == cr.getId ())
		    {
			TGame game = new TGame 
			    (0, 
			     cr.getServerGame ().getRules ().getFactory (),
			     2);
			cl.add (cr);
			cl.add (pl);
			it.remove ();
			TSet set = new TSet (cl, game);
			set.setServerGame (cr.getServerGame ());
			_games.add (set);
			cr.setIdPl (set.getCounter ());
			pl.setIdPl (set.getCounter ());
			return (cr.getServerGame ());
		    }
	    }
	it = _games.iterator ();
	for (int i = 0; i < _games.size (); ++i, it.hasNext ())
	    {
		TSet set = (TSet) it.next ();
		if (set.getGameId () == creator)
		    {
			set.addPlayer (pl);
			pl.setIdPl (set.getCounter ());
		    }
		return (set.getServerGame ());
	    }
	return null;
    }

    /**
     * Add an observer to the game
     */
    public boolean addObserver (TNetServerThread obs, int creator)
    {
	Iterator it = _games.iterator ();

	for (int i = 0; i < _games.size (); ++i, it.hasNext ())
	    {
		TSet set = (TSet) it.next ();
		if (set.getGameId () == creator)
		    set.addObserver (obs);
		return true;
	    }
	return false;
  
    }

    /**
     * Create a game on the server
     */
    public TServerGame createGame (TNetServerThread creator, String rules)
    {
	TServerGame server = new TServerGame ();
	String[] pinfos = rules.split(":");
	String factory = pinfos[0];
	
	Vector infos = new Vector ();
	for (int i = 1; i < pinfos.length; ++i)
	    infos.addElement (new Integer (pinfos[i]));
	
	server.setRules (factory, infos);
	String[] f = server.getRules ().getFactory ().split (":");
	server.initRulesFactory (f[0], infos);
	server.initGame ();
	_waiting_games.add (creator);
	return server;
    }

    /**
     * Broadcast the hit to all client involved
     */
    public void hitBroadcast (String hit, TNetServerThread origin)
    {
	Iterator it = _games.iterator ();

	System.out.println (_games.size ());
	for (int i = 0; i < _games.size (); ++i, it.hasNext ())
	    {
		TSet set = (TSet) it.next ();
		if (set.isHere (origin))
		    {
			Vector players = set.getPlayers ();
			Iterator vit = players.iterator ();
			for (int j = 0; j < players.size (); 
			     ++j, vit.hasNext ())
			    {
				TNetServerThread tnst = 
				    (TNetServerThread) vit.next ();
				tnst.hit (hit);
			    }
			Vector observers = set.getObservers ();
			vit = observers.iterator ();
			for (int j = 0; j < observers.size (); 
			     ++j, vit.hasNext ())
			    {
				TNetServerThread tnst = 
				    (TNetServerThread) vit.next ();
				tnst.hit (hit);
			    }
			return;
		    }
	    }
	
    }

    public void save (TNetServerThread tnst)
    {
	Iterator it = _games.iterator ();

	for (int i = 0; i < _games.size (); ++i, it.hasNext ())
	    {
		TSet set = (TSet) it.next ();
		if (set.isHere (tnst))
		    {
			_db.saveGame (set.getGame ());
			return;
		    }
	    }
    }

    public static void main (String[] av) throws Exception
    {
	/*if (av.length < 2)
	    {
		System.err.println("ERROR: Too few arguments.");
		System.err.println("Usage: [Environement Variable] " + 
				   "dames host login:pass");
		System.exit(0);
	    }
	try
	    {
	      	TDBLoader dbLoader = new TDBLoader ();
		TDB db = dbLoader.getTDB(av[0], av[1]);
		db.initTables();*/
	try {
		TNetServer netServer = new TNetServer (null, 6969);
		netServer.create ();
	    }
	catch (Exception e)
	    {
		System.err.println (e.getMessage ());
		System.exit (5);
	    }
	
    }

}


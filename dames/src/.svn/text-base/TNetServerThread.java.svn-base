import java.net.*;
import java.io.*; 
import java.util.Vector;
import java.util.Iterator;
import java.util.HashMap;
import java.util.Set;

/**
 * Class that implements the protocol
 */
public class TNetServerThread extends TNet
{
    private TNetServer _server;
    private TNetThread _thread;
    private TServerGame _gameServer;
    private int _idPl = 0;

    /**
     * Constructor
     */
    public TNetServerThread (int port, Socket socket, 
			     int id, TNetServer server, TNetThread thread)
    {
	super(port, socket);
	_id = id;
	_server = server;
	_thread = thread;
    }

    /**
     * Get the id of the Thread
     */
    public int getId ()
    {
	return _id;
    }

    /**
     *
     */
    public void setIdPl (int i)
    {
	_idPl = i;
    }
    
    /**
     * Function called to specify the fact that 
     * another function isn't implemented
     */
    private void NIY ()
    {
	System.out.println ("Not Implemented Yet");
    }

    /**
     * Ask the client for the name of the player
     */
    public String name ()
    {
	String str;

	send("NAME");
	str = receive ();
	if (str.substring (0, 3).compareTo ("NAME") != 0)
	    {
		protocolError ();
		return ("Error");
	    }
	return (str.substring (4));
    }

    /**
     * Answer No
     */
    public void no ()
    {
	send ("NO");
    }

    /**
     * Answer yes
     */
    public void ok ()
    {
	send ("OK");
    }

    /**
     * Inform the client that he win the game
     */
    public void win ()
    {
	send ("WIN");
    }

    /**
     * Inform the client that he lose the game
     */
    public void lose ()
    {
	send ("LOSE");
    }

    /**
     * Send the ELO player
     */
    public void elo (int level)
    {
	send ("ELO " + level);
    }

    /**
     * Send information about the game in progress
     */
    public void visualize (Vector games, Vector waiting)
    {
	String str;
	Iterator it = games.iterator();

	str = "VISUALIZE ";
	for (int i = 0; i < games.size(); ++i, it.hasNext())
	    {
		TSet set = (TSet) it.next ();
		Vector players = set.getPlayers ();
		Iterator vit = players.iterator ();
		for (int j = 0; j < players.size (); ++j, vit.hasNext ())
		    str += ((TNetServerThread) vit.next ()).getId () + ":";

		TGame game = set.getGame ();
		str += game.toNet ();
		if (i < games.size ())
		    str += "@";
	    }
	
	it = waiting.iterator ();
	for (int i = 0; i < waiting.size(); ++i, it.hasNext())
	    {
		str += "W" + ((TNetServerThread) it.next ()).getId () + ":";
		if (i < games.size ())
		    str += "@";
	    }
	send (str);
    }

    /**
     * Send a hit to play
     */
    public void hit (String h)
    {
	send ("HIT " + h);
    }

    /**
     * Send the id of the client
     */
    public void id ()
    {
	send ("ID " + _id);
    }

    /**
     * Register the game to the server
     */
    public TServerGame register (int creator)
    {
	return (_server.register (this, creator));
    }

    /**
     * Send the hit to all the client
     */
    public void sendHit (String hit)
    {
	_server.hitBroadcast (hit, this);
    }

    /**
     *
     */
    public TServerGame getServerGame ()
    {
	return _gameServer;
    }
    
    /**
     * Interpret the Net messages
     */
    public void interpret ()
    {
	String request;

	sync(false);
	while (true)
	{
	    request = receive (); /* <- program entry point */
	    if (request.compareTo ("COPY") == 0)
		send ("COPY");
	    if (request.compareTo ("ID") == 0)
		id ();
	    if (request.compareTo ("BYE") == 0)
		return;
	    if (request.compareTo ("VISUALIZE") == 0)
		visualize (_server.getGames (), _server.getWaitingGames ());
	    if (request.startsWith ("CREATE"))
		{
		    _gameServer = _server.createGame 
			(this, request.substring (7));
		    send ("OK " + 
			  _gameServer.getRules ().getFactory () + ":" +
			  _idPl);
		}
	    if (request.startsWith ("HIT"))
		{
		    String str[] = request.substring (4).split (":", 2);
		    Integer id = new Integer (str[0]);
		    THit hit = 
			new THit (_gameServer.getPlayerFromId (id.intValue ()),
				  str[1], _gameServer.getBoard ());

		    if (_gameServer.getRules ().isPlayable 
			(_gameServer.getBoard (), hit))
			{
			    hit.compute ();
			    send ("OK");
			    sendHit (hit.toString ());
			}
		    else
			send ("NO");
		}
	    if (request.startsWith ("PLAY"))
		{
		    Integer gameid = new Integer (request.substring (5));
		    _gameServer = register (gameid.intValue ());
		    send ("OK " + _gameServer.getRules ().getFactory () 
			  + ":" + _idPl);
		}
	    if (request.startsWith ("OBS"))
		{
		    Integer gameid = new Integer (request.substring (4));
		    _server.addObserver (this, gameid.intValue ());
		    ok ();
		}
	    if (request.compareTo ("SAVE") == 0)
		_server.save (this);
	}
    }
}


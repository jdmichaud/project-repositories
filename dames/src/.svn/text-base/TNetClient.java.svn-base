import java.io.*;
import java.net.*;
import java.util.Vector;
import java.util.Iterator;

public class TNetClient extends TNet
{
    private TClientGame _client;
    private TThreadHit _threadHit;
    private int _idPl;

    public TNetClient (int port, Socket socket)
    {
	super (port, socket);
    }

    /**
     * Assign l'identifiant a l'attribut id
     */
    public void setId (int id)
    {
	_id = id;
    }

    /**
     *
     */
    public int getIdPl ()
    {
	return _idPl;
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
     * Send the player's name to the client
     */
    public void name (String name)
    {
	send ("NAME " + name);
    }

    /**
     * Get the ELO player
     */
    public int elo (int level)
    {
	send ("ELO");
	Integer elo = new Integer (receive ());
	return (elo.intValue ());
    }

    /**
     * Ask if a is correct. If it is, the server valid it.
     */
    public boolean hit (String h)
    {
	send ("HIT " + h);
	if (receive ().compareTo ("OK") != 0)
	    return true;
	return false;
    }

    /**
     * Ask the server the game in progress
     */
    /* FIXME */
    public Vector visualize ()
    {
	send ("VISUALIZE");
	receive ();
	return (new Vector ());
    }

    /**
     * Ask the server to save the game
     */
    public void save (String gameName)
    {
	send ("NAME " + gameName);
    }

    /**
     * Last hit
     */
    /*    public THit last ()
    {
	send ("LAST");
	THit hit = new THit (receive ());
	return hit;
	}*/

    /**
     * Next hit
     */
    /*    public THit next ()
    {
	send ("NEXT");
	THit hit = new THit (receive ());
	return hit;
	}*/

    /**
     * Ask the id of the client
     */
    public int id ()
    {
	send ("ID");
	String id = receive ();
	Integer i = new Integer (id.substring (3));
	return (i.intValue ());
    }

    /**
     * Select a game to play
     */
    public boolean play (int gameno)
    {
	send ("PLAY " + gameno);
	String rep = receive ();
	if (rep.startsWith ("OK"))
	    {
		String arg = rep.substring(3);
		String[] pinfos = arg.split(":");
		String factory = pinfos[0];
		
		Vector infos = new Vector ();
		int i;
		for (i = 1; i < pinfos.length; ++i)
		    infos.addElement (new Integer (pinfos[i]));

		_idPl = (new Integer (pinfos[i - 1])).intValue ();
		_client = new TClientGame ();
		_client.initRulesFactory (factory, infos);
		_client.initGame ();
		_client.initDisplay ();

		_threadHit = new TThreadHit (this, _client.getBoard ());
		_threadHit.start ();
		return true;
	    }
	return false;
    }

    /**
     * Wait for another client play
     */
    public void waitForHit ()
    {
	String request = receive ();
	
	if (!request.startsWith ("HIT"))
	    return;

	String str[] = request.substring (4).split (":", 2);
	Integer id = new Integer (str[0]);
	(new THit (_client.getPlayerFromId (id.intValue ()),
			     str[1], _client.getBoard ())).compute ();
	_client.getDC ().repaint ();	
    }
    
    /**
     * Select a game to observe
     */
    public boolean observe (int gameno)
    {
	send ("OBS " + gameno);
	if (receive ().compareTo ("OK") == 0)
	    return true;
	return false;
    }

    /**
     * Create a game
     */
    public boolean create (String rules) 
    {
	send ("CREATE " + rules);
	String rep = receive ();
	if (rep.compareTo ("NO") == 0)
	    return false;	

	_client = new TClientGame ();

	rep = rep.substring(3);
	String[] pinfos = rep.split(":");
	String factory = pinfos[0];

	Vector infos = new Vector ();
	int i;
	for (i = 1; i < pinfos.length; ++i)
	    infos.addElement (new Integer (pinfos[i]));

	_idPl = (new Integer (pinfos[i - 1])).intValue ();
	_client.initRulesFactory (factory, infos);
	_client.initGame ();
	_client.initDisplay ();

	_threadHit = new TThreadHit (this, _client.getBoard ());
	_threadHit.start ();
	return true;
    }

    public TClientGame getClientGame ()
    {
	return _client;
    }

    /**
     *
     */
    public void waitForSomething ()
    {
	String request;

	while (true)
	{
	    request = receive (); /* <- program entry point */
	    if (request.compareTo ("COPY") == 0)
		send ("COPY");
	    if (request.compareTo ("BYE") == 0)
		close ();
	    if (request.startsWith ("HIT"))
		{
		    String str[] = request.substring (4).split (":", 2);
		    Integer id = new Integer (str[0]);
		    (new THit (_client.getPlayerFromId (id.intValue ()),
			       str[1], _client.getBoard ())).compute ();
		    _client.getDC ().repaint ();
		    return ;
		}
	}
    }

    /**
     * Command line
     */
    public void cmd () throws IOException
    {
	String outputLine;
	String request;

	try
	{
	    BufferedReader inClient = new BufferedReader 
		(new InputStreamReader(System.in));
	    
	    while (true)
		{
		    System.out.print ("] ");
		    outputLine = inClient.readLine();
		    if (outputLine.compareTo ("BYE") == 0)
			close ();
		    if (outputLine.startsWith ("CREATE"))
			{
			    create (outputLine.substring (7));
			    _threadHit.enable ();
			}
		    else if (outputLine.startsWith ("PLAY"))
			{
			    Integer i = new Integer (outputLine.substring (5));
			    play (i.intValue ());
			    waitForHit ();
			    _threadHit.enable ();
			}
		    else if (outputLine.startsWith ("HIT"))
			{
			    hit (outputLine.substring (4));
			    waitForHit ();
			}
		    else if (outputLine.startsWith ("OBS"))
			{
			    Integer i = new Integer (outputLine.substring (4));
			    observe (i.intValue ());
			    while (true)
				waitForHit ();
			}
		    else if (outputLine.startsWith ("VISUALIZE"))
			visualize ();
		    else if (outputLine.compareTo ("flush") == 0)
			receive ();
		    else if (outputLine.compareTo ("sync") == 0)
			sync (false);
		    else if (outputLine.compareTo ("wait") == 0)
			receive ();
		    else
			send (outputLine);
		}
	}
	catch (IOException e)
	{
	    System.out.println ("Input Error");
	}
    }
}








































































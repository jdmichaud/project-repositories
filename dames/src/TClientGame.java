import java.util.Vector;
import java.io.*;
import java.net.*;

public class TClientGame extends TGame
{
    /**
     * the display
     */
    private TDisplayControler _dc;

    public TClientGame () { }

    /**
     * the initialization of the display
     */
    public void initDisplay ()
    {
	Vector drawables = new Vector ();

	drawables.addElement (_board);
	for (int i = 0; i < _players.size (); i++)
	    drawables.addElement (_players.get (i));
	_dc = new TDisplayControler(drawables);

	_dc.initWindowDPY (500, 500);
    }

    public TDisplayControler getDC ()
    {
	return _dc;
    }

    public static void main (String[] av)
    {
	if (av.length != 1)
	    {
		System.err.println ("usage: client hostname");
		System.exit (3);
	    }
	
	try
	    {
		Socket socket = new Socket(av[0], 6969);
		TNetClient netClient = new TNetClient (6969, socket);
		
		netClient.sync (true);
		netClient.setId (netClient.id ());
		netClient.cmd ();
	    }
	catch (IOException e)
	    {
	    }
    }
};

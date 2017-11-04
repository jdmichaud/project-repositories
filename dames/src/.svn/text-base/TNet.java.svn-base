import java.io.*;
import java.net.*;

public class TNet
{
    /**
     * The communication port
     */
    public int _port;

    /**
     * The communication Socket
     */
    public Socket _socket = null;     

    /**
     * Buffer to output
     */
    private PrintWriter _outstream;

    /**
     * Buffer to input
     */
    private BufferedReader _instream;

    /**
     * Internal variable
     */
    private boolean _stop = false;

    /**
     * Id of the module
     */
    public int _id;

    /**
     * Constructor specifying communication port
     */
    public TNet (int port, Socket socket)
    {
	_port = port;
	_socket = socket;

	try
	    {
		_outstream = new PrintWriter(_socket.getOutputStream(), true);
		_instream = new BufferedReader 
		    (new InputStreamReader(_socket.getInputStream()));     
	    }
	catch (IOException e)
	    {
		System.out.println ("Socket error");
		System.exit (1);
	    }
    }
    
    /**
     * To recover from a protocole mistake
     */
    public void protocolError ()
    {
	if (_stop)
	    {
		System.out.println ("Protocol Error");
		System.exit (2);
	    }
	_stop = true;
	sync (true);
    }

    /**
     * Ask the client for a synchronisation
     */
    public void sync (boolean wait)
    {
	if (wait)
	    {
		if (receive ().compareTo ("COPY") != 0)
		    protocolError ();
		send("COPY");
	    }
	else
	    {
		send("COPY");
		if (receive ().compareTo ("COPY") != 0)
		    protocolError ();
	    }
    }

    /**
     * Close the connetion
     */
    public void bye ()
    {
	send ("BYE");
    }

    /**
     * Send a message to the client
     */
    public void send (String msg)
    {
	System.out.println ("SEND(" + _id + "): " + msg);
	_outstream.println (msg);
    }

    /**
     * Receive a message
     */
    public String receive ()
    {
	String str = "";

	System.out.println ("listening ...");
	try
	    {
		str = _instream.readLine ();
	    }
	catch (IOException e)
	    {
		System.out.println ("Socket error");
		System.exit (1);
	    }
	System.out.println ("RECEIVE: " + str);
	return str;
    }

    /**
     * Close the socket
     */
    public void close ()
    {
	try
	    {
		_outstream.close ();
		_instream.close ();
	    }
	catch (IOException e)
	    {
		System.out.println ("Socket error");
		System.exit (1);
	    }
    }
}

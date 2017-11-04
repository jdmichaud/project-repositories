import java.net.*;
import java.io.*; 

public class TNetThread extends Thread 
{
    /**
     * Constructor de TNetThread
     */
    private int _port;
    private Socket _socket;
    private int _id;
    private TNetServer _server;


    public TNetThread (int port, 
		       Socket socket, int id, 
		       TNetServer server) 
    {
	super("TNetThread");
	_id = id;
	_port = port;
	_server = server;
	_socket = socket;
    }

    /**
     * Run the thread
     */
    public void run()
    { 	
	System.out.println("new client connected");
	new TNetServerThread (_port, _socket, _id, _server, this).interpret ();
    }
}

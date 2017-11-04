import java.util.Vector;

public class TThreadHit extends Thread
{
    private TNetClient	_client;
    private TBoard	_board;
    private THit	_hit;
    private boolean	_enabled;

    public TThreadHit (TNetClient client, TBoard board)
    {
	super ("TThreadHit");
	_client = client;
	_board = board;
	_enabled = false;
    }
    
    public void run ()
    {
	while (true) {
	    if (_enabled) {
		Vector cases = _board.getCases ();		
		
		for (int i = 0; i < cases.size (); i++) {
		    TCase C = (TCase) cases.get (i);		
		    if (C.isFocused ()) {
			if (_hit == null)
			    _hit = new THit (_client.getClientGame ().
					     getPlayer (_client.getIdPl ()));
			
			if ((_hit.getNbCases () == 0) ||
			    !C.compareTo (_hit.getCase 
					  (_hit.getNbCases () - 1)))
			    {
				_hit.addCase (C);
				if (_hit.isCompleted ())
				    {
					_client.send ("HIT " + 
						      _hit.toString ());
					_hit.unFocusCases ();
					_hit = null;
					if ((_client.receive ()).compareTo 
					    ("OK") == 0)
					    {
						_client.waitForSomething ();
						System.out.println 
						    ("A vous de jouer");
						_client.waitForSomething ();
					    }
				    }
				
			    }
		    }    
		}
	    }
	}
    }
    public void enable ()
    { _enabled = true; }

    public void disable ()
    { _enabled = true; }
};

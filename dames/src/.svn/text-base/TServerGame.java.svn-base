import java.util.Vector;

/**
 * the game seen by the server
 */
public class TServerGame extends TGame
{
    /**
     * the server owns the rules that determines the validity of one hit
     */
    private TRules _rules;

    /**
     * a list of observers
     */
    private Vector _spectators;
    
    public TServerGame () { }

    /**
     * instanciante the rules thanks to a string describing the rules' name
     * and a vector of informations
     */
    public void setRules (String rName, Vector infosRules)
    {
	try {
	    Class rClass = Class.forName (rName);
	    
	    Class signature[] = new Class[1];
	    signature[0] = Vector.class;
	    java.lang.reflect.Constructor c =
		rClass.getConstructor (signature);
	    
	    Object args[] = new Object[1];
	    args[0] = infosRules;
	    
	    _rules = (TRules) c.newInstance (args);
	    if (_rules == null)
		throw new AssertionError ("Impossible to load TRules");
	}
	catch (Exception e) {
	    System.exit (4);
	}
    }

    public void setRules (TRules R) { _rules = R; }

    public TRules getRules () { return _rules; }
    
};

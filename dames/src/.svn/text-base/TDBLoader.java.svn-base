/**
 * The TDBLoader will instanciate a TDB daughter class.
 * To do so, the loader gets the environnement variable TDB value and create a 
 * new TDB named by the TDB variable value.
 */
    
public class TDBLoader {
    /**
     * The getTDB method needs two arguments to create a TDB.
     * The first one is the database address, the second one is the login the 
     * the password with the form login:password
     */
    
    public TDB getTDB(String arg1, String arg2) throws Exception
    {
	String name = System.getProperty("TDB");
	if (name == null || name == "")
	    throw new AssertionError("TDB not defined");

	Class n = Class.forName(name);
	Class wanted_signature[] = new Class[2];
	wanted_signature[0] = String.class;
	wanted_signature[1] = String.class;

	java.lang.reflect.Constructor c = n.getConstructor(wanted_signature);
	Object args[] = new Object[2];
	args[0] = arg1;
	args[1] = arg2;
	
	TDB r = (TDB) c.newInstance(args);
	if (r == null)
	    throw new AssertionError("Requested class is not a TDB");

	return r;
	
    }
    
};

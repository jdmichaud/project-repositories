public class DBQueryPerformerLoader {


    public DBQueryPerformer getPerformer(String arg1, String arg2) throws Exception
    {
	String name = System.getProperty("DB_PERFORMER");
	if (name == null || name == "")
	    throw new AssertionError("DB_PERFORMER not defined");
	
	Class n = Class.forName(name);

	Class wanted_signature[] = new Class[2];
	wanted_signature[0] = String.class;
	wanted_signature[1] = String.class;

	java.lang.reflect.Constructor c = n.getConstructor(wanted_signature);
	Object args[] = new Object[2];
	args[0] = arg1;
	args[1] = arg2;

	DBQueryPerformer r = (DBQueryPerformer)c.newInstance(args);
	if (r == null)
	    throw new AssertionError("Requested class is not a DBQueryPerformer");

	return r;
	
    }

};

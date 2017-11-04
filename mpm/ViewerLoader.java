
public class ViewerLoader {

    public DBView getViewer()  throws Exception
    {
	String name = System.getProperty("VIEWER_ANALYZER");
	if (name == null || name == "")
	    throw new AssertionError("VIEWER_ANALYZER not defined");

	Class n = Class.forName(name);

	DBView r = (DBView)n.newInstance();
	if (r == null)
	    throw new AssertionError("Requested class is not a ViewerAnalyzer");
	return r;
    }


};

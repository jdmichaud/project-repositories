
public class AnalyzerLoader {

    public ContentAnalyzer getContentAnalyzer()  throws Exception
    {
	String name = System.getProperty("CONTENT_ANALYZER");
	if (name == null || name == "")
	    throw new AssertionError("CONTENT_ANALYZER not defined");

	Class n = Class.forName(name);

	ContentAnalyzer r = (ContentAnalyzer)n.newInstance();
	if (r == null)
	    throw new AssertionError("Requested class is not a ContentAnalyzer");
	return r;
    }


};

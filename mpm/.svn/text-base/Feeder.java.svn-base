class Feeder
{
    public static void main(String[] av)
    {
	try
	    {
		AnalyzerLoader al = new AnalyzerLoader ();
		DBQueryPerformerLoader dpl = new DBQueryPerformerLoader ();
		ParseXML px = new ParseXML ();
		DBQueryFactory df = new StandardDBFactory ();
		ContentAnalyzer ca = al.getContentAnalyzer ();

		if (av.length != 3)
		    {
			System.out.println("usage:Feeder xmlfile hostaddr login:pass");
			System.exit(0);
		    }
		DBQueryPerformer dp = dpl.getPerformer (av[1], av[2]);
		dp.executeQuerySequence(df, ca.analyze(df, 
						       px.getDocument(av[0])));
	    }
	catch (Exception e)
	    {
		System.err.println("error :" + e.getMessage());
		System.exit(1);
	    }
    }
}

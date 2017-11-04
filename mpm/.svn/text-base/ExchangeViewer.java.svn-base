import java.util.Vector;

public class ExchangeViewer extends DBView 
{
    public ExchangeViewer () {}

    public void observe(DBQueryFactory df, DBQueryPerformer qp)
    {
	try
	    {
		DBQuery q;

		q = df.buildTupleFinderCommand("donne", 
					       new Vector(), 
					       new Vector());
		Vector res = qp.executeSingleQuery(df, q);
		for (int i = 0; i < res.size (); ++i)
		    {
			System.out.print(res.elementAt(i) + " ");
			if (((i + 1) % 4) == 0)
			    System.out.println("");
		    }

	    }
	catch (Exception e)
	    {
		System.err.println("error :" + e.getMessage());
	    }
    }
};

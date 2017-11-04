import java.util.Vector;

public class Observer
{
    public static void main(String[] av)
    {
	try
	    {
		if (av.length != 2)
		    {
			System.out.println("usage:Observer hostaddr login:pass");
			System.exit(0);
		    }

		DBQueryFactory df = new StandardDBFactory ();
		ViewerLoader vl = new ViewerLoader ();
		DBQueryPerformerLoader dpl = new DBQueryPerformerLoader ();
		DBQueryPerformer dp = dpl.getPerformer (av[0], av[1]);
		DBView dv = vl.getViewer ();
		
		dv.observe (df, dp);
	    }
	catch (Exception e)
	    {
		System.err.println("error :" + e.getMessage());
		System.exit(1);
	    }
    }
}

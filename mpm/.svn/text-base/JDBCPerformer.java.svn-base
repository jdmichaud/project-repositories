import java.util.Vector;
import java.util.Iterator;
import java.sql.*;

public class JDBCPerformer extends DBQueryPerformer
{
    public static final int TABLE_CREATION = 0;
    public static final int TUPLE_INSERTION = 1;
    public static final int TUPLE_FINDER = 2;
    public Connection conn;

    public JDBCPerformer (String addr, String idpass)
    {
	try
	    {
		String[] argv = idpass.split(":");
		Class.forName("org.gjt.mm.mysql.Driver");
		conn = DriverManager.getConnection("jdbc:mysql://" + addr + "/" + argv[0] + "?user=" + argv[0] + "&password=" + argv[1]);
	    }
	catch (Exception e)
	    {
		System.out.println("error: ");
	    }
    }

    public String getName()
    {
	return ("JDBCPerformer");
    }

    public Vector executeSingleQuery(DBQueryFactory f, DBQuery q) throws Exception
    {
	Vector v = new Vector ();
	ResultSet rs;
	java.sql.Statement stmt = conn.createStatement();

	if (f.getQueryType(q) == TABLE_CREATION)
	    {
		System.out.println("Creation de " + f.getTableName(q));
		
		rs = stmt.executeQuery("CREATE TABLE " + f.getTableName(q) + " ( date VARCHAR(255), createur VARCHAR(255), recepteur VARCHAR(255), objet VARCHAR(255));");
	    }
	if (f.getQueryType(q) == TUPLE_INSERTION)
	    {
		String Q = new String ();
		
		Q = "INSERT INTO " + f.getTableName(q) + " (date, createur, recepteur, objet) VALUES (";
		v = f.getFirstList (q);
		for (int i = 0; i < v.size (); ++i)
		    {
			Q += "\"" + v.get(i) + "\"";
			if ((i + 1) < v.size()) 
			    Q += ", ";
		    }
		Q += ");";
		System.out.println(Q);	
		rs = stmt.executeQuery(Q);
	    }
	if (f.getQueryType(q) == TUPLE_FINDER)
	    {
		rs = stmt.executeQuery("SELECT * FROM " + f.getTableName(q));
		while (rs.next())
		    {
			v.addElement(rs.getString("date"));
			v.addElement(rs.getString("createur"));
			v.addElement(rs.getString("recepteur"));
			v.addElement(rs.getString("objet"));
		    }
	    }
	return (v);
    }

    public void executeQuerySequence(DBQueryFactory f, Vector s) throws Exception
    {
       Iterator it = s.iterator();

       for (int i = 0; i < s.size(); ++i, it.hasNext())
	   executeSingleQuery(f, (DBQuery) it.next ());
    }
}

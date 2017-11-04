import java.util.Vector;
import java.sql.*;

/**
 * JDBCPerformer extends DBQuerPerfomer.
 * It executes abstract queries (DBQuery) using a DBQueryFactory.
 * To do so, trhe JDBCPerfomer connect a database using the driver jdbc:mysql; 
 * then format the query in SQL and execute this translation.
 */
 

public class JDBCPerformer extends DBQueryPerformer {
    // -------- METHODES ---------
   
    /**
     * When a JDBCPerfomer class is create, a conection to the database is 
     * opened.
     * To connect, the constructor need a database address (the fist argument) 
     * and a couple login:password (the second argument)
     */

    public JDBCPerformer(String datab, String id)
    {
	try
	    {
		Class.forName("org.gjt.mm.mysql.Driver");
		Connection conn = 
		    DriverManager.getConnection("jdbc:mysql://" + 
						datab + "/" + getLogin(id), 
						getLogin(id), getPass(id));
		_stmt = conn.createStatement();
	    }
	catch (Exception e)
	    {
		System.err.println("ERROR: " + e.getMessage());
	    }
    }
    
    /**
     * getName return a string that contains the type of the performer.
     * Here it is JDBCPerfomer.
     */

    public String getName() { return "JDBCPerformer"; }

    /**
     * The method executeSinglQuery looks the type of the DBQuery it recieves 
     * (in second argument) and then format, translate the DBQuery in a string 
     * that contains the SQL trnaslation of the astract query.
     * The method execute then the query and return the database answer 
     * in a vector.
     */

    public Vector executeSingleQuery(DBQueryFactory f, DBQuery q) 
	throws Exception
    {
	String myquery = new String();
	if (f.getQueryType(q) == f.TABLE_CREATION)
	    myquery = formatDBQueryInCreationTable(f, q);
	else
	    if (f.getQueryType(q) == f.TUPLE_INSERTION)
		myquery = formatDBQueryInTupleInsertion(f, q);
	    else
		if (f.getQueryType(q) == f.TUPLE_UPDATE)
		    myquery = formatDBQueryInTupleUpdate(f, q);
		else
		    if (f.getQueryType(q) == f.TUPLE_FINDER)
			myquery = formatDBQueryInTupleFinder(f, q);
		    else
			if (f.getQueryType(q) == f.TABLE_PRINT)
			    myquery = formatDBQueryInTablePrint(f, q);
			else
			    throw new AssertionError ("Unknown query type");
	
	ResultSet rs = _stmt.executeQuery(myquery);
	Vector res = new Vector(); 
	if (f.getQueryType(q) == f.TUPLE_FINDER)
	    {
		Vector params = (Vector) f.getParams (q);
		Vector selected_fields = (Vector) params.firstElement ();
		while (rs.next())
		    {
			Vector line_result = new Vector ();
			for (int i = 0; i < selected_fields.size (); ++i)
			    line_result.add (rs.getObject ((String) selected_fields.get (i)));
			res.add (line_result);
		    }
		return res;
	    }
	if (f.getQueryType(q) == f.TABLE_PRINT)
	    {
		if (rs.next ())
		    res.add (new String ("Full"));
		return res;
	    }
	return res;
	
    }
    
    /** 
     * The method executeQuerySequence calls in loop executeSingleQuery.
     */

    public void executeQuerySequence(DBQueryFactory f, Vector s) 
	throws Exception
    {
	for (int i = 0; i < s.size(); ++i)
	    {
		DBQuery dbq = (DBQuery) s.get(i);
		String myquery = new String();
		if (f.getQueryType(dbq) == f.TABLE_CREATION)
		    myquery = formatDBQueryInCreationTable(f, dbq);
		else
		    if (f.getQueryType(dbq) == f.TUPLE_INSERTION)
			myquery = formatDBQueryInTupleInsertion(f, dbq);
		    else
			if (f.getQueryType(dbq) == f.TUPLE_FINDER)
			    myquery = formatDBQueryInTupleFinder(f, dbq);
		ResultSet rs = _stmt.executeQuery(myquery);
	    }
    }
    
    /** 
     * The method formatBQueryInCreationTable translate an abstract DBQuery 
     * in a SQL creation table query.
     */

    public String formatDBQueryInCreationTable(DBQueryFactory f, DBQuery s)
    {
	String query = new String("CREATE TABLE ");
	
	query += (f.getTablesName(s)).firstElement () + " ";
	Vector params = (Vector) f.getParams(s);
	Vector fields_id = (Vector) params.firstElement ();
	Vector fields_type = (Vector) params.lastElement ();

	query = query + "( ";
	if (fields_id.size () > 0)
	    {
		query += (String) fields_id.get(0) + " " 
		    + (String) fields_type.get (0);
		for (int i = 1; i < fields_id.size(); ++i)
		    query += ", " + (String) fields_id.get(i) + " " + 
			(String) fields_type.get (i);
	    }
	query += " )";
	return query;
    }

    /** 
     * The method formatBQueryInTablePrint translate an abstract DBQuery 
     * in a SQL print table query. ("SHOW TABLES")
     */

    public String formatDBQueryInTablePrint(DBQueryFactory f, DBQuery s)
    {
	return new String("SHOW TABLES");
    }

    /** 
     * The method formatDBQueryInTupleInsertion translate an abstract DBQuery 
     * in a SQL Insertion tuple query. 
     */
    
    public String formatDBQueryInTupleInsertion(DBQueryFactory f, DBQuery s)
    {
	String query = new String("INSERT INTO ");
	query += f.getTablesName(s).firstElement () + " ";
	
	Vector params = (Vector) f.getParams (s);
	Vector fields_id = (Vector) params.firstElement ();
	Vector fields_value = (Vector) params.lastElement ();
	
	query += "( ";
	if (fields_id.size () > 0)
	    {
		query += (String) fields_id.get (0);
		for (int i = 1; i < fields_id.size(); ++i)
		    query += ", " + (String) fields_id.get(i);
	    }
	query += " ) VALUES ( ";
	if (fields_value.size() > 0)
	    {
		query += (String) fields_value.get(0);
		int i = 1;
		for (; i < fields_value.size(); ++i)
		    query += ", " + (String) fields_value.get(i);
	    }
	query += " )";
	return query;
    }

    /** 
     * The method formatDBQueryInTupleUpdate translate an abstract DBQuery 
     * in a SQL update tuple query.
     */


    public String formatDBQueryInTupleUpdate(DBQueryFactory f, DBQuery s)
    {
	String query = new String("UPDATE ");
	query += f.getTablesName(s).firstElement () + " SET ";
	
	Vector params = (Vector) f.getParams (s);
	Vector fields_id = (Vector) params.firstElement ();
	Vector fields_value = (Vector) params.get (1);
	
	if (fields_id.size () > 0)
	    {
		query += (String) fields_id.get (0) + " = ";
		query += (String) fields_value.get (0);
		for (int i = 1; i < fields_id.size(); ++i)
		    query += ", " + (String) fields_id.get(i) + " = " + 
			(String) fields_value.get (i);
	    }
	query += " WHERE ";
	fields_id = (Vector) params.get (2);
	fields_value = (Vector) params.get (3);
	
	if (fields_id.size() > 0)
	    {
		query += (String) fields_id.get(0) + " = ";
		query += (String) fields_value.get (0);
		int i = 1;
		for (; i < fields_id.size(); ++i)
		    query += "AND " + (String) fields_id.get(i) + " = " +
			(String) fields_value.get (i);
	    }
	return query;
    }
    
    /** 
     * The method formatBQueryInTupleFinder translate an abstract DBQuery 
     * in a SQL select query.
     */

    public String formatDBQueryInTupleFinder(DBQueryFactory f, DBQuery s)
    {
	Vector params = (Vector) f.getParams (s);
	Vector fields_id = (Vector) params.get (0);
	String query = new String("SELECT ");
	
	if (fields_id.size() > 0)
	    {
		query += (String) fields_id.get(0);
		for (int i = 1; i < fields_id.size(); ++i)
		    query += ", " + (String) fields_id.get(i);
		
	    }
	query += " FROM ";
	Vector tables = f.getTablesName (s);
	if (tables.size () > 0)
	    {
		query += (String) tables.get(0);
		for (int i = 1; i < tables.size (); ++i)
		    query += ", " + (String) tables.get(i);
	    }
	if (params.size () >= 3)
	    {
		query = query + " WHERE ( ";
		fields_id = (Vector) params.get (1);
		Vector fields_value = (Vector) params.get (2);
		query += " " + (String) fields_id.get (0) + " = " 
		    + (String) fields_value.get (0);
		int i = 1;
		for (; i < fields_id.size(); ++i)
		    query += " AND " + (String) fields_id.get (i) 
			+ " = " + (String) fields_value.get(i);
		query += " )";
	    }
	if (params.size () >= 4)
	    query += " GROUP BY " + 
		(String) ((Vector) params.get (3)).firstElement ();
	if (params.size() >= 6)
	    {
		query += " HAVING ( ";
		fields_id = (Vector) params.get (4);
		Vector fields_value = (Vector) params.get (5);
		query += " " + (String) fields_id.get (0) + " = " 
		    + (String) fields_value.get (0);
		int i = 1;
		for (; i < fields_id.size(); ++i)
		    query += " AND " + (String) fields_id.get (i) 
			+ " = " + (String) fields_value.get(i);
		query += " )";
	    }
	return query;
    }
    
    /**
     * getLogin is a private method to get the login from the string 
     * login:password.
     */

    private static String getLogin(String s)
    {
	String login = new String();
	
	for (int i = 0; (i < s.length()) && (s.charAt(i) != ':'); ++i)
	    login = login + s.charAt(i);
	return login;
    }

    /**
     * getPass is a private method to get the password from the string 
     * login:password.
     */

    private static String getPass(String s)
    {
	String pass = new String();
	int i = 0;
	
	for (; (i < s.length()) && (s.charAt(i) != ':'); ++i)
	    ;
	for (++i; (i < s.length()); ++i)
	    pass = pass + s.charAt(i);
	return pass;
    }

// -------- PROPERTIES ---------
    protected Statement _stmt;
};

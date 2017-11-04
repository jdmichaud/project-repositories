import java.util.*;
import java.lang.*;

/**
 * QueryBase are the abstract representation of the query. The QueryBase does 
 * not depends on a database language.
 * The QueryBase implements the DBQuery interface: it means that the QueryBase 
 * can be translate into a String.
 */

class QueryBase implements DBQuery
{
    public Vector _tables_name;
};

/**
 * A CreationQuery is the abstract representation of a creation table query. 
 * To create a table, the CreationQuery needs two arguments:
 * - a string that contains the name of the table to create
 * - a vector that contains a two vectors. The first one is a list of all the 
 * fields name, the second one is a list of the types of the fields of the 
 * first vector.
 */

class CreationQuery extends QueryBase
{
    public Vector _params;
    public CreationQuery (String table_name, Vector params)
    {
	Vector vectTable = new Vector ();
	vectTable.add (new String (table_name));
	_tables_name = vectTable;
	_params = params;
	if (params.size () != 2)
	    throw new AssertionError("params vector of CreationQuery " +
				     "must have a size = 2");
	Vector fields_id = (Vector) params.firstElement ();
	Vector fields_type = (Vector) params.lastElement();
	if (fields_type.size () != fields_id.size ())
	    throw new AssertionError("The 1st element and the 2nd element " +
				     " of params vector must have " +
				     "the same size");
	for (Iterator i = fields_id.iterator(); i.hasNext(); )
	    if (!((i.next()) instanceof String))
		throw new AssertionError("field name is not a string");
	for (Iterator i = fields_type.iterator(); i.hasNext(); )
	    if (!((i.next()) instanceof String))
		throw new AssertionError("field type is not a string");
    }

    public String toString()
    {
	String desc = 
	    "CreateTable using table name <" + 
	    (String)  _tables_name.firstElement () + "> and fields <";
	Vector fields_id = (Vector) _params.firstElement ();
	Vector fields_type = (Vector) _params.lastElement();
	Iterator i = fields_id.iterator();
	for (Iterator j = fields_type.iterator(); 
	     (i.hasNext()) && (j.hasNext()); )
	    {
		desc += ((String)i.next());
		desc += " of type " + ((String)j.next());
		if (i.hasNext())
		    desc += ", ";
	    }
	desc += ">";
	return desc;
    }
};

/**
 * A InsertionQuery is the abstract representation of a insertion tuple query. 
 * To insert a tuple in a table, the InsertionQuery needs two arguments:
 * - a string that contains the name of the table the tuple must be insert into
 * - a vector that contains a two vectors. The first one is a list of all the
 * fields name, the second one is a list of the valus of the fields of the 
 * first vector.
 */

class InsertionQuery extends QueryBase
{
    public Vector _params;

    public InsertionQuery(String table_name, Vector params)
    {
	Vector vectTable = new Vector ();
	vectTable.add (new String (table_name));
	_tables_name = vectTable;
	_params = params;
	if (params.size () != 2)
	    throw new AssertionError("params vector of InsertionQuery " +
				     "must have a size = 2");
	Vector fields_id = (Vector) params.firstElement ();
	Vector fields_type = (Vector) params.lastElement();
	if (fields_type.size () != fields_id.size ())
	    throw new AssertionError("The 1st element and the 2nd element " +
				     " of params vector must have " +
				     "the same size");
	for (Iterator i = fields_id.iterator(); i.hasNext(); )
	    if (!((i.next()) instanceof String))
		throw new AssertionError("field name is not a string");
	for (Iterator i = fields_type.iterator(); i.hasNext(); )
	    if (!((i.next()) instanceof String))
		throw new AssertionError("field value is not a string");
    }
    
    public String toString()
    {
	String desc = 
	    "InsertTuple using table name <" + _tables_name.firstElement ()
	    + ">, fields <";
	Vector fields_id = (Vector) _params.firstElement ();
	for (Iterator i = fields_id.iterator(); i.hasNext(); )
	    {
		desc += ((String)i.next());
		if (i.hasNext())
		    desc += ", ";
	    }
	desc += "> and values <";
	Vector fields_value = (Vector) _params.lastElement ();
	for (Iterator i = fields_value.iterator(); i.hasNext(); )
	    {
		desc += ((String)i.next());
		if (i.hasNext())
		    desc += ", ";
	    }
	desc += ">";
	return desc;
    }
};


/**
 * The UpdateQuery is the abstract representation of a udate tuple query. 
 * To update a tuple in a table, the UpdateQuery needs two arguments:
 * - a string that contains the name of the table the tuple must be update into
 * - a vector that contains a two vectors. The first one is a list of all the
 * fields name, the second one is a list of the valus of the fields of the 
 * first vector.
 */

class UpdateQuery extends QueryBase
{
    public Vector _params;

    public UpdateQuery(String table_name, Vector params)
    {
	Vector vectTable = new Vector ();
	vectTable.add (new String (table_name));
	_tables_name = vectTable;
	_params = params;
	if (params.size () != 4)
	    throw new AssertionError("params vector of InsertionQuery " +
				     "must have a size = 4");
	Vector fields_id = (Vector) params.firstElement ();
	Vector fields_value = (Vector) params.get(1);
	if (fields_value.size () != fields_id.size ())
	    throw new AssertionError("The 1st element and the 2nd element " +
				     " of params vector must have " +
				     "the same size");
	for (Iterator i = fields_value.iterator(); i.hasNext(); )
	    if (!((i.next()) instanceof String))
		throw new AssertionError("field type is not a string");
	for (Iterator i = fields_id.iterator(); i.hasNext(); )
	    if (!((i.next()) instanceof String))
		throw new AssertionError("field name is not a string");

	fields_id = (Vector) params.get (2);
	fields_value = (Vector) params.lastElement();
	if (fields_id.size () != fields_value.size ())
	    throw new AssertionError("The 3rd element and the 4th element " +
				     " of params vector must have " +
				     "the same size");
	for (Iterator i = fields_id.iterator(); i.hasNext(); )
	    if (!((i.next()) instanceof String))
		throw new AssertionError("field name is not a string");
	for (Iterator i = fields_value.iterator(); i.hasNext(); )
	    if (!((i.next()) instanceof String))
		throw new AssertionError("field value is not a string");

    }
    
    public String toString()
    {
	String desc = 
	    "UpdateTuple using table name <" + _tables_name.firstElement ()
	    + ">, set fields <";
	Vector fields_id = (Vector) _params.firstElement ();
	for (Iterator i = fields_id.iterator(); i.hasNext(); )
	    {
		desc += ((String)i.next());
		if (i.hasNext())
		    desc += ", ";
	    }
	desc += "> to values <";
	Vector fields_value = (Vector) _params.get (1);
	for (Iterator i = fields_value.iterator(); i.hasNext(); )
	    {
		desc += ((String)i.next());
		if (i.hasNext())
		    desc += ", ";
	    }
	desc += "> on tuple where fields <";
	fields_id = (Vector) _params.get (2);
	for (Iterator i = fields_id.iterator(); i.hasNext(); )
	    {
		desc += ((String)i.next());
		if (i.hasNext())
		    desc += ", ";
	    }
	desc += "> have values <";
	fields_value = (Vector) _params.get (3);
	for (Iterator i = fields_value.iterator(); i.hasNext(); )
	    {
		desc += ((String)i.next());
		if (i.hasNext())
		    desc += ", ";
	    }
	desc += ">";
	return desc;
    }
};

/**
 * A FinderQuery is the abstract representation of a select tuple query. 
 * To select a tuple in a table, the FinderQuery needs two arguments:
 * - a vector of strings that contains the name of the tables the search will 
 be done into.
 * - a vector that contains other vectors. The first one is a list of all the 
 * fields name, the second one is a list of the valus of the fields of the 
 * first vector. The following vector depends on the Performer. For exemple, 
 * using a SQL Performer, the third vector could be the fields name of a clause
 * having... The way the second arguments is a vector give you a freedom to 
 * create select query as comple as you want to.
 */

class FinderQuery extends QueryBase
{
    public Vector _params;
    
    public FinderQuery(Vector tables_name, Vector params)
    {
	if (tables_name.size () == 0)
	    throw new AssertionError("The SearchQuery must contain at list " + 
				     "one table name");
	_tables_name = tables_name;
	_params = params;
	for (int i = 0; i < params.size (); ++i)
	    {
		Vector elt = (Vector) params.get (i);
		for (int j = 0; j < elt.size (); ++j)
		    if (!(elt.get(j) instanceof String))
			throw 
			    new AssertionError("params field is not a string");
	    }
    }
    
    public String toString()
    {
	String desc = "FindTuple using table name <";
	for (Iterator i = _tables_name.iterator(); i.hasNext(); )
	    {
		desc += ((String)i.next());
		if (i.hasNext())
		    desc += ", ";
	    }
	int cpt = 0;
	for (int i = 0; i < _params.size (); ++i, ++cpt)
	    {
		desc += ">, clause " + cpt + "<";
		Vector elt = (Vector) _params.get (i);
		for (int j = 0; j < elt.size (); ++j)
		    {
			desc += ((String) elt.get (j));
			if ((j + 1) < elt.size ())
			    desc += ", ";
		    }
	    }
	desc += ">";
	return desc;
    }
};

/** The query TablePrint is a simple abstract query to reprepresent a query 
 * which give you the name aof all the tables in the database.
 */

class TablePrintQuery extends QueryBase
{
    public TablePrintQuery () {}

    public String toString()
    {
	return new String ("Print all tables");
    }
};


/**
 * The StandardDBFactory implements the only abstract methods i nthe abstract 
 * DBQueryFactory.
 * It create and return DBQuery.
 */ 

public class StandardDBFactory extends DBQueryFactory
{
    /** 
     * create a table print query. 
     */
    
    public DBQuery buildTablePrintCommand ()
    {
	return new TablePrintQuery ();
    }
    
    /**
     * create a table creation query. 
     */

    public DBQuery buildTableCreationCommand (String table_name, 
					      Vector params)
    {
	return new CreationQuery (table_name, params);
    }

    /**
     * create a tuple insetion query. 
     */

    public DBQuery buildTupleInsertionCommand (String table_name, 
					       Vector params)
    {
	return new InsertionQuery(table_name, params);
    }

    /**
     * create a select tuples query. 
     */

    public DBQuery buildTupleFinderCommand (Vector tables_name, 
					    Vector params)
    {
	return new FinderQuery(tables_name, params);
    }

    /**
     * create a update tuples query. 
     */

    public DBQuery buildTupleUpdateCommand (String table_name, 
					    Vector params)
    {
	return new UpdateQuery(table_name, params);
    }
    
    /**
     * returns the type of the DBQuery.
     * It can be a :
     * 1 -> creation query
     * 2 -> tuple insertion
     * 3 -> tuple finder
     * 4 -> table print
     */

    public int getQueryType(DBQuery q)
    {
	if (q instanceof CreationQuery)
	    return TABLE_CREATION;
	if (q instanceof InsertionQuery)
	    return TUPLE_INSERTION;
	if (q instanceof UpdateQuery)
	    return TUPLE_UPDATE;
	if (q instanceof FinderQuery)
	    return TUPLE_FINDER;
	if (q instanceof TablePrintQuery)
	    return TABLE_PRINT;
	throw 
	    new RuntimeException("unrecognized query passed to getQueryType");
    }

    /**
     * returns the vector that contains the name of the tables the query 
     * manipulates.
    */

    public Vector getTablesName(DBQuery q)
    {
	getQueryType(q);
	return ((QueryBase)q)._tables_name;
    }

    /**
     * returns the vector that contains the arguments that the query 
     * manipulates.
     */

    public Vector getParams(DBQuery q)
    {
	switch(getQueryType(q))
	    {
	    case TABLE_CREATION:
		return ((CreationQuery)q)._params;
	    case TUPLE_INSERTION:
		return ((InsertionQuery)q)._params;
	    case TUPLE_UPDATE:
		return ((UpdateQuery)q)._params;
	    case TUPLE_FINDER:
		return ((FinderQuery)q)._params;
	    case TABLE_PRINT:
		throw new AssertionError("No params for TablePrintQuery");
	    default:
		throw new AssertionError("unknown query");
	    }
    }
};
    



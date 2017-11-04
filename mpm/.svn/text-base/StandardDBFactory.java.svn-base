import java.util.*;
import java.lang.*;

class QueryBase implements DBQuery
{
    public String m_table_name;
};

class CreationQuery extends QueryBase
{
    public Vector m_field_names;
    public CreationQuery (String a, Vector b)
    {
	m_table_name = a;
	m_field_names = b;
	for (Iterator i = b.iterator(); i.hasNext(); )
	    if (!((i.next()) instanceof String))
		throw new AssertionError("field name is not a string");
    }

    public String toString()
    {
	String desc = 
	    "CreateTable using table name <" + m_table_name 
	    + "> and fields <";
	for (Iterator i = m_field_names.iterator(); i.hasNext(); )
	    {
		desc += ((String)i.next());
		if (i.hasNext())
		    desc += ", ";
	    }
	desc += ">";
	return desc;
    }
};

class InsertionQuery extends QueryBase
{
    public Vector m_field_values;

    public InsertionQuery(String a, Vector b)
    {
	m_table_name =a;
	m_field_values = b;
	for (Iterator i = b.iterator(); i.hasNext(); )
	    if (!((i.next()) instanceof String))
		throw new AssertionError("field value is not a string");
    }

    public String toString()
    {
	String desc = 
	    "InsertTuple using table name <" + m_table_name 
	    + "> and field values <";
	for (Iterator i = m_field_values.iterator(); i.hasNext(); )
	    {
		desc += ((String)i.next());
		if (i.hasNext())
		    desc += ", ";
	    }
	desc += ">";
	return desc;
    }
};

class SearchQuery extends QueryBase
{
    public Vector m_selected_field_names;
    public Vector m_selected_field_values;

    public SearchQuery(String a, Vector b, Vector c)
    {
	if (b.size() != c.size())
	    throw new AssertionError("mismatching number of selected fields and values");
	for (Iterator i = b.iterator(); i.hasNext(); )
	    if (!((i.next()) instanceof String))
		throw new AssertionError("field name is not a string");
	for (Iterator i = c.iterator(); i.hasNext(); )
	    if (!((i.next()) instanceof String))
		throw new AssertionError("field value is not a string");
	m_table_name = a;
	m_selected_field_names = b;
	m_selected_field_values = c;
    }

    public String toString()
    {
	String desc = 
	    "FindTuple using table name <" + m_table_name 
	    + ">, selected field names <";
	for (Iterator i = m_selected_field_names.iterator(); i.hasNext(); )
	    {
		desc += ((String)i.next());
		if (i.hasNext())
		    desc += ", ";
	    }
	desc += "> and values <";
	for (Iterator i = m_selected_field_values.iterator(); i.hasNext(); )
	    {
		desc += ((String)i.next());
		if (i.hasNext())
		    desc += ", ";
	    }
	desc += ">";
	return desc;
    }
};

public class StandardDBFactory extends DBQueryFactory
{
    public DBQuery buildTableCreationCommand(String table_name, Vector field_names)
    {
	return new CreationQuery(table_name, field_names);
    }

    public DBQuery buildTupleInsertionCommand(String table_name, Vector field_values)
    {
	return new InsertionQuery(table_name, field_values);
    }

    public DBQuery buildTupleFinderCommand(String table_name, Vector selected_fields, Vector selected_values)
    {
	return new SearchQuery(table_name, selected_fields, selected_values);
    }

    public int getQueryType(DBQuery q)
    {
	if (q instanceof CreationQuery)
	    return TABLE_CREATION;
	if (q instanceof InsertionQuery)
	    return TUPLE_INSERTION;
	if (q instanceof SearchQuery)
	    return TUPLE_FINDER;
	throw new RuntimeException("unrecognized query passed to getQueryType");
    }

    public String getTableName(DBQuery q)
    {
	getQueryType(q);
	return ((QueryBase)q).m_table_name;
    }

    public Vector getFirstList(DBQuery q)
    {
	switch(getQueryType(q))
	    {
	    case TABLE_CREATION:
		return ((CreationQuery)q).m_field_names;
	    case TUPLE_INSERTION:
		return ((InsertionQuery)q).m_field_values;
	    case TUPLE_FINDER:
		return ((SearchQuery)q).m_selected_field_names;
	    default:
		throw new AssertionError("unknown query");
	    }
    }
    public Vector getSecondList(DBQuery q)
    {
	switch(getQueryType(q))
	    {
	    case TABLE_CREATION:
		throw new AssertionError("no second sequence in query");
	    case TUPLE_INSERTION:
		throw new AssertionError("no second sequence in query");
	    case TUPLE_FINDER:
		return ((SearchQuery)q).m_selected_field_values;
	    default:
		throw new AssertionError("unknown query");
	    }
    }


};
    



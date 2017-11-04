import java.util.Vector;

/** 
 * The DBQueryFactory is an abstract class.
 * It contains methods to product the common queries to all the Database 
 * languages.
 * The common queries are : 
 * - table creation
 * - tables print
 * - tuple insertion
 * - tuple update
 * - tuple find
 */

public abstract class DBQueryFactory {
    
    public abstract DBQuery buildTableCreationCommand (String table_name, 
						       Vector params);
    public abstract DBQuery buildTupleInsertionCommand (String table_name, 
							Vector params);
    public abstract DBQuery buildTupleUpdateCommand (String table_name, 
							Vector params);
    public abstract DBQuery buildTupleFinderCommand (Vector tables_name, 
						     Vector params);
    public abstract DBQuery buildTablePrintCommand ();

    
    public static final int TABLE_CREATION = 0;
    public static final int TUPLE_INSERTION = 1;
    public static final int TUPLE_UPDATE = 2;
    public static final int TUPLE_FINDER = 3;
    public static final int TABLE_PRINT = 4;

    public abstract int getQueryType(DBQuery q);
    public abstract Vector getTablesName(DBQuery q);
    public abstract Vector getParams(DBQuery q);
};

    



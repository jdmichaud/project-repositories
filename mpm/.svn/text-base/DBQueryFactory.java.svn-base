import java.util.Vector;

public abstract class DBQueryFactory {

    public abstract DBQuery buildTableCreationCommand(String table_name, Vector field_names);
    public abstract DBQuery buildTupleInsertionCommand(String table_name, Vector field_values);
    public abstract DBQuery buildTupleFinderCommand(String table_name, Vector selected_fields, Vector selected_values);
    
    public static final int TABLE_CREATION = 0;
    public static final int TUPLE_INSERTION = 1;
    public static final int TUPLE_FINDER = 2;

    public abstract int getQueryType(DBQuery q);
    public abstract String getTableName(DBQuery q);
    public abstract Vector getFirstList(DBQuery q);
    public abstract Vector getSecondList(DBQuery q);
};

    



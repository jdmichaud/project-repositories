import java.util.Vector;

/** 
 * The DBQueryPerfomer executes the queries.
 * To use it, you need a DBQueryFactory which knows how to interprete the 
 * DBquery you are trying to execute.
 */

public abstract class DBQueryPerformer {
    /**
     * The method getName returns a string tahat contains the type of performer
     * you are using.
     */
    public abstract String getName();

    public abstract Vector executeSingleQuery(DBQueryFactory f, 
					      DBQuery q) throws Exception;

    public abstract void executeQuerySequence(DBQueryFactory f, 
					      Vector s) throws Exception;
};

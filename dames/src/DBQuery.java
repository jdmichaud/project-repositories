

/** 
 * A DBQuery is an abstract represation of a creation query, 
 * insertionquery, update query...
 * Abstract means that it is not dependant of the database language. 
 * You can use SQL for Oracle, or another language using the DBQuery. 
 */ 

public interface DBQuery {
    
    /** 
     * The toString method format the query in a description language.
     * For example: "Creation Query of the table <TableName> 
     * with the fields <Field> of type <TypeOfField>
     */
    public String toString();
};

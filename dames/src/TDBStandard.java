import java.util.Vector;

/**
 * The TDBStandard extends TDB is the main actor of the game DB module.
 * It contains abstract needed methods that the duaghter class must at list 
 * implement.
 */

public class TDBStandard extends TDB
{
    private DBQueryPerformer _dbqperf;
    private DBQueryFactory _dbfact;

    /** 
     * The constructor create a PerformreLoader which instanciate a 
     * new Performer.
     * To do so the constructor need a database adress and a couple 
     * (login, pass)
     */
    
    public TDBStandard (String login, String pass)
    {
	DBQueryPerformerLoader perfLoader = 
	    new DBQueryPerformerLoader();
	try 
	    {
		_dbqperf = perfLoader.getPerformer(login, pass);
		_dbfact = new StandardDBFactory();
	    }
	catch (Exception e)
	    {
		System.err.println (e.getMessage ());
	    }
    }

    /**
     * The method getName returns a string that contains the type of the TDB.
     * In this class it always returns "TDBStandard"
     */
    
    public String getName() { return "TBDStandard"; }
    

    /**
     * This method checks if the tables needed by the application exists on
     * the database. if the tables don't exist, initTables create it.
     */
    
    public void initTables ()
    {
	try 
	    {
		DBQuery myquery = _dbfact.buildTablePrintCommand();
		Vector res = _dbqperf.executeSingleQuery(_dbfact, myquery);
		if (res.size () > 0)
		    return;
		// Creation of the table TPlayer
		Vector fields_id = new Vector();
		fields_id.add("PlayerNum");
		fields_id.add("Nick");
		fields_id.add("Score");
		fields_id.add("GameNum");

		Vector fields_type = new Vector();
		fields_type.add("int");
		fields_type.add("char (50)");
		fields_type.add("int");
		fields_type.add("int");
		
		Vector params = new Vector ();
		params.add (fields_id);
		params.add (fields_type);
		
		myquery = _dbfact.buildTableCreationCommand("TPlayers", 
							    params);
		_dbqperf.executeSingleQuery(_dbfact, myquery);
		
		// Creation of the table THistory
		fields_id.clear ();
		fields_id.add("HistNum");
		fields_id.add("HitNum");
		fields_id.add("Move");
		
		fields_type.clear ();
		fields_type.add("int");
		fields_type.add("int");
		fields_type.add("char (50)");
		
		params.clear ();
		params.add (fields_id);
		params.add (fields_type);
		
		myquery = _dbfact.buildTableCreationCommand("THistory", 
							    params);
		_dbqperf.executeSingleQuery(_dbfact, myquery);
		
		// Creation of the table TGame
		fields_id.clear ();
		fields_id.add("GameNum");
		fields_id.add("History");
		fields_id.add("Rules");
		fields_id.add("NbPlayers");
		
		fields_type.clear ();
		fields_type.add("int");
		fields_type.add("int");
		fields_type.add("char (50)");
		fields_type.add("int");
		
		params.clear ();
		params.add (fields_id);
		params.add (fields_type);
		
		myquery = _dbfact.buildTableCreationCommand("TGames", params);
		_dbqperf.executeSingleQuery(_dbfact, myquery);
	    }
	catch (Exception e)
	    {
		System.err.println (e.getMessage ());
	    }
    }

    /**
     * Find a player in the database from the playerId.
     */

    public TPlayer loadProfil(int playerId) throws Exception
    {
	Vector selectedFields = new Vector();
	selectedFields.add("Nick");
	selectedFields.add("Score");
	selectedFields.add("GameNum");
	Vector tables = new Vector();
	tables.add("TPlayers");
	
	Vector where_id = new Vector();
	where_id.add("PlayerNum");
	Vector where_value = new Vector();
	where_value.add(new String ("" + playerId));

	Vector params = new Vector();
	params.add (selectedFields);
	params.add (where_id);
	params.add (where_value);
	
	DBQuery myquery = _dbfact.buildTupleFinderCommand(tables, params);
	Vector res = _dbqperf.executeSingleQuery(_dbfact, myquery);

	if (res.size () == 0)
	    throw new Exception ("The player " + playerId + " does not exist");
	Vector line_result = (Vector) res.firstElement ();
	Vector pions = new Vector (); // FIXME
	String nick = (String) line_result.get (0);
	Integer score = (Integer) line_result.get (1);
	Integer gameId = (Integer) line_result.get (1);
	return new TPlayer(pions, playerId, nick, score.intValue (), 
			   gameId.intValue ());
    }
    
    /**
     * Find a game in the database from the gameId.
     */

    public TGame loadGame(int gameId) throws Exception
    {
	Vector selectedFields = new Vector();
	selectedFields.add("Rules");
	selectedFields.add("NbPlayers");
	Vector tables = new Vector();
	tables.add("TGames");
	
	Vector where_id = new Vector();
	where_id.add("GameNum");
	Vector where_value = new Vector();
	where_value.add(new String ("" + gameId));
	
	Vector params = new Vector();
	params.add (selectedFields);
	params.add (where_id);
	params.add (where_value);
	
	DBQuery myquery = _dbfact.buildTupleFinderCommand(tables, params);

	Vector res = _dbqperf.executeSingleQuery(_dbfact, myquery);
	
	if (res.size () == 0)
	    throw new Exception ("The game " + gameId + " does not exist");
	Vector line_result = (Vector) res.firstElement ();
	String rules = (String) line_result.get (0);
	Integer nbPlayers = (Integer) line_result.get (1);
	return new TGame(gameId, rules, nbPlayers.intValue ());
    }

    /**
     * Save or update a game in the database.
     */
    
    public void saveGame(TGame game) 
    {
	try 
	    {
		loadGame (game.getId ());
		Vector fields_id = new Vector();
		fields_id.add ("GameNum");
		fields_id.add ("NbPlayers");

		Vector fields_value = new Vector();
		fields_value.add (new String ("" + game.getId ()));
		fields_value.add (new String ("" + game.getNbPlayers ()));
		
		Vector fields_id_sel = new Vector ();
		fields_id_sel.add ("GameNum");
		Vector fields_value_sel = new Vector ();
		fields_value_sel.add ("" + game.getId ());

		Vector params = new Vector ();
		params.add (fields_id);
		params.add (fields_value);
		params.add (fields_id_sel);
		params.add (fields_value_sel);
		
		DBQuery myquery = _dbfact.buildTupleUpdateCommand("TGames", 
								  params);
		_dbqperf.executeSingleQuery (_dbfact, myquery);
	    }
	catch (Exception e) // The player does not exist in the database.
	    {
		try {
		    Vector fields_id = new Vector();
		    fields_id.add ("GameNum");
		    fields_id.add ("NbPlayers");
		    
		    Vector fields_value = new Vector();
		    fields_value.add (new String ("" + game.getId ()));
		    fields_value.add 
			(new String ("'" + game.getNbPlayers ()+"'"));
		    
		    Vector params = new Vector ();
		    params.add (fields_id);
		    params.add (fields_value);
		    
		    DBQuery myquery = 
			_dbfact.buildTupleInsertionCommand("TGames", params);
		    _dbqperf.executeSingleQuery (_dbfact, myquery);
		}
		catch (Exception f)
		    {
			System.exit (6);
		    }
	    }
    }
    
    /**
     * Save or update a player in the database.
     */

    public void saveProfil(TPlayer player) throws Exception
    {
	try 
	    {
		loadProfil (player.getId ());
		Vector fields_id = new Vector();
		fields_id.add ("PlayerNum");
		fields_id.add ("Nick");
		fields_id.add ("Score");
		fields_id.add ("GameNum");

		Vector fields_value = new Vector();
		fields_value.add (new String ("" + player.getId ()));
		fields_value.add (new String ("'" + player.getNick () + "'"));
		fields_value.add (new String ("" + player.getScore ()));
		fields_value.add (new String ("" + player.getGameId ()));
		
		Vector fields_id_sel = new Vector ();
		fields_id_sel.add ("PlayerNum");
		Vector fields_value_sel = new Vector ();
		fields_value_sel.add ("" + player.getId ());

		Vector params = new Vector ();
		params.add (fields_id);
		params.add (fields_value);
		params.add (fields_id_sel);
		params.add (fields_value_sel);
	
		DBQuery myquery = _dbfact.buildTupleUpdateCommand("Tplayers", 
								  params);
		_dbqperf.executeSingleQuery (_dbfact, myquery);
	    }
	catch (Exception e) // The player does not exist in the database.
	    {		
		Vector fields_id = new Vector();
		fields_id.add ("PlayerNum");
		fields_id.add ("Nick");
		fields_id.add ("Score");
		fields_id.add ("GameNum");

		Vector fields_value = new Vector();
		fields_value.add (new String ("" + player.getId ()));
		fields_value.add (new String ("'" + player.getNick () + "'"));
		fields_value.add (new String ("" + player.getScore ()));
		fields_value.add (new String ("" + player.getGameId ()));
		
		Vector params = new Vector ();
		params.add (fields_id);
		params.add (fields_value);
	
		DBQuery myquery = _dbfact.buildTupleInsertionCommand("Tplayers"
								     , params);
		_dbqperf.executeSingleQuery (_dbfact, myquery);
	    }
    }

    public int newGameId ()
    {
	try 
	    {
		Vector fields_id = new Vector();
		fields_id.add ("Max(PlayerNum)");
		
		Vector params = new Vector ();
		params.add (fields_id);
		
		Vector tablename = new Vector ();
		tablename.add ("Tplayers");
		
		DBQuery myquery = _dbfact.buildTupleFinderCommand(tablename
							  , params);
		Vector res = _dbqperf.executeSingleQuery (_dbfact, myquery);
		Vector tuple_res = (Vector) res.firstElement ();
		Integer val = new Integer ((String) tuple_res.firstElement());
		return (val.intValue () + 1);
	    }
	catch (Exception e)
	    {
		System.err.println (e.getMessage ());
		System.exit (6);
	    }
	return 0;
    }

};
